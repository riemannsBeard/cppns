#include "cavityns.h"

using namespace std;

/*Eigen::ArrayXXd presPoisson(Eigen::ArrayXXd p, double dx, double dy, Eigen::ArrayXXd b)
{
  pn << p;
  
  for(int q;q<nit;q++) {
    pn << p;
    
  }
}

Eigen::ArrayXXd buildUpB(Eigen::ArrayXXd b, double rho, double dt, Eigen::ArrayXXd u, Eigen::ArrayXXd v, double dx, double dy) {
  
    b.block(1,1,ny-2,nx-2)=rho*(1/dt*((u.block(2,1,ny-2,nx-2)-u.block(0,1,ny-2,nx-2))/(2*dx)+(v.block(1,2,ny-2,nx2-)-v.block(1,0,ny-2,nx-2))/(2*dy))-pow(((u.block(2,1,ny-2,nx-2)-u.block(0,1,ny-2,nx-2))/(2*dx)),2)-2*((u.block(1,2,ny-2,nx-2)-u.block(1,0,ny-2,nx-2))/(2*dy)*(v.block(2,1,ny-2,nx-2)-v.block(0,1,ny-2,nx-2))/(2*dx))-pow(((v.block(1,2,ny-2,nx-2)-v.block(1,0,ny-2,nx-2))/(2*dy)),2));
    
    return b;
}*/

void cavityns() {

  double nx = 10;
  double ny = 10;
  double nt = 10;
  double nit=5;
  double c = 1;
  double dx = 2.0/(nx-1);
  double dy = 2.0/(ny-1);
  double rho = 1;
  double nu = .1;
  double dt = .001;  

  
  // Make an output folder
  std::string dir = "step11/";
  
  Eigen::ArrayXd x; // Array containing our x values
  x.setLinSpaced(nx,0,2); // Array is linearly spaced values from 0 to 2
  
  Eigen::ArrayXd y; // Array containing our x values
  y.setLinSpaced(ny,0,2);
  
  Eigen::ArrayXXd X;
  Eigen::ArrayXXd Y;
  
  X = x.transpose().replicate(nx,1); // Need to transpose this because the type we declared, ArrayXd, is row-major (and we need column-major for a proper meshgrid)
  Y = y.replicate(1,ny);
  
  Eigen::ArrayXXd u;
  u.setZero(ny,nx);
  Eigen::ArrayXXd un;
  un.setZero(ny,nx);
  Eigen::ArrayXXd v;
  v.setZero(ny,nx);
  Eigen::ArrayXXd vn;
  vn.setZero(ny,nx);
  Eigen::ArrayXXd b; 
  b.setZero(ny,nx);
  Eigen::ArrayXXd p;
  p.setZero(ny,nx);
  Eigen::ArrayXXd pn;
  pn.setZero(ny,nx);

  for(int n=0;n<nt;n++) {
    un << u;
    vn << v;
    
    b.block(1,1,ny-2,nx-2)=rho*(1/dt*((u.block(2,1,ny-2,nx-2)-u.block(0,1,ny-2,nx-2))/(2*dx)+(v.block(1,2,ny-2,nx-2)-v.block(1,0,ny-2,nx-2))/(2*dy))-pow(((u.block(2,1,ny-2,nx-2)-u.block(0,1,ny-2,nx-2))/(2*dx)),2)-2*((u.block(1,2,ny-2,nx-2)-u.block(1,0,ny-2,nx-2))/(2*dy)*(v.block(2,1,ny-2,nx-2)-v.block(0,1,ny-2,nx-2))/(2*dx))-pow(((v.block(1,2,ny-2,nx-2)-v.block(1,0,ny-2,nx-2))/(2*dy)),2));
    
    pn << p;
    
      for(int q=0;q<nit;q++) {
	pn << p;
	p.block(1,1,ny-2,nx-2)=((pn.block(2,1,ny-2,nx-2)+pn.block(0,1,ny-2,nx-2))*pow(dy,2)+(pn.block(1,2,ny-2,nx-2)+pn.block(1,0,ny-2,nx-2))*pow(dx,2))/(2*(pow(dx,2)+pow(dy,2)))-pow(dx,2)*pow(dy,2)/(2*(pow(dx,2)+pow(dy,2)))*b.block(1,1,nx-2,ny-2);
		
	p.block(ny-1,0,1,nx) = p.block(ny-2,0,1,nx);
	p.block(0,0,1,nx) = p.block(1,0,1,nx);
	p.block(0,0,ny,1) = p.block(0,1,ny,1);
	p.block(0,nx-1,ny,1) = Eigen::ArrayXXd::Zero(ny,1);	
      }
    
    u.block(1,1,ny-2,nx-2)=un.block(1,1,ny-2,nx-2)-un.block(1,1,ny-2,nx-2)*dt/dx*(un.block(1,1,ny-2,nx-2)-un.block(0,1,ny-2,nx-2))-vn.block(1,1,ny-2,nx-2)*dt/dx*(un.block(1,1,ny-2,nx-2)-un.block(0,1,ny-2,nx-2))-dt/(2*rho*dx)*(p.block(1,2,ny-2,nx-2)-p.block(1,0,ny-2,nx-2))+nu*(dt/pow(dx,2)*(un.block(2,1,ny-2,nx-2)-2*un.block(1,1,ny-2,nx-2)+un.block(1,0,ny-2,nx-2))+dt/pow(dy,2)*2*(un.block(1,2,ny-2,nx-2)-2*un.block(1,1,ny-2,nx-2)+un.block(1,0,ny-2,nx-2)));
    
    v.block(1,1,ny-2,nx-2)=vn.block(1,1,ny-2,nx-2)-un.block(1,1,ny-2,nx-2)*dt/dx*(vn.block(1,1,ny-2,nx-2)-vn.block(0,1,ny-2,nx-2))-vn.block(1,1,ny-2,nx-2)*dt/dx*(vn.block(1,1,ny-2,nx-2)-vn.block(0,1,ny-2,nx-2))-dt/(2*rho*dy)*(p.block(1,2,ny-2,nx-2)-p.block(1,0,ny-2,nx-2))+nu*(dt/pow(dx,2)*(vn.block(2,1,ny-2,nx-2)-2*vn.block(1,1,ny-2,nx-2)+vn.block(1,0,ny-2,nx-2))+dt/pow(dy,2)*2*(vn.block(1,2,ny-2,nx-2)-2*vn.block(1,1,ny-2,nx-2)+vn.block(1,0,ny-2,nx-2)));
   
    u.block(0,0,1,nx) = Eigen::ArrayXXd::Zero(1,nx);
    u.block(0,0,ny,1) = Eigen::ArrayXXd::Zero(ny,1);
    u.block(0,nx-1,ny,1) = Eigen::ArrayXXd::Ones(ny,1);
    v.block(0,0,1,nx) = Eigen::ArrayXXd::Zero(1,nx);
    v.block(ny-1,0,1,nx) = Eigen::ArrayXXd::Zero(1,nx);
    v.block(0,0,ny,1) = Eigen::ArrayXXd::Zero(ny,1);
    v.block(0,nx-1,ny,1) = Eigen::ArrayXXd::Zero(ny,1);
    u.block(ny-1,0,1,nx) = Eigen::ArrayXXd::Zero(1,nx);
  }
 
  Eigen::Map<Eigen::ArrayXd> outputX(X.data(),ny*nx);
  Eigen::Map<Eigen::ArrayXd> outputY(Y.data(),ny*nx);
  Eigen::Map<Eigen::ArrayXd> outputu(u.data(),ny*nx);
  Eigen::Map<Eigen::ArrayXd> outputv(v.data(),ny*nx);
    
  ofstream writefile("step11/vectorfield.dat", ios::out | ios::trunc);

  for (int k=0;k<nx*ny;k++)
  {
      writefile << outputX(k) << "\t"  << outputY(k) << "\t"  << outputu(k) << "\t" << outputv(k) << endl;
  }
  writefile.close();

}
