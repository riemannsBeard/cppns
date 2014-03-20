#include "burgers2d.h"

using namespace std;

void burgers2d() {
  double nx = 41;
  double ny = 41;
  double nt = 120;
  double c = 1;
  double dx = 2/(nx-1);
  double dy = 2/(ny-1);
  double sigma = .0009;
  double nu = 0.01;
  double dt = sigma*dx*dy/nu;
  
  // Make an output folder
  std::string dir = "step8/";
  mkdir(dir.c_str(),0755); //Make a folder to store results in
  
  Eigen::ArrayXd x; // Array containing our x values
  x.setLinSpaced(nx,0,2);
  
  Eigen::ArrayXd y; // Array containing our x values
  y.setLinSpaced(ny,0,2);

  Eigen::ArrayXXd u;
  u.setOnes(ny,nx);
  u.block(.5/dy, .5/dx, 1/dy+1-.5/dy, 1/dx+1-.5/dx) = Eigen::ArrayXXd::Constant(1/dy+1-.5/dy,1/dx+1-.5/dx,2);
  Eigen::ArrayXXd v;
  v.setOnes(ny,nx);
  v.block(.5/dy, .5/dx, 1/dy+1-.5/dy, 1/dx+1-.5/dx) = Eigen::ArrayXXd::Constant(1/dy+1-.5/dy,1/dx+1-.5/dx,2);
  Eigen::ArrayXXd un;
  un.setOnes(ny,nx);
  Eigen::ArrayXXd vn;
  vn.setOnes(ny,nx);
  Eigen::ArrayXXd comb;
  comb.setOnes(ny,nx);
  
  for(int i=0;i<nt+1;i++) {
    un << u;
    vn << v;
    
    u.block(1,1,ny-2,nx-2) = un.block(1,1,ny-2,nx-2)+nu*dt/pow(dx,2)*(un.block(2,1,ny-2,nx-2)-2*un.block(1,1,ny-2,nx-2)+un.block(0,1,ny-2,nx-2))+nu*dt/pow(dy,2)*(un.block(1,2,ny-2,ny-2)-2*un.block(1,1,ny-2,nx-2)+un.block(1,0,ny-2,nx-2));
  
    // Gives boundary condition
    u.block(0,0,1,nx-1) = Eigen::ArrayXXd::Constant(1,nx-1,1);
    u.block(ny-1,0,1,nx-1) = Eigen::ArrayXXd::Constant(1,nx-1,1);
    u.block(0,0,ny-1,1) = Eigen::ArrayXXd::Constant(ny-1,1,1);
    u.block(0,nx-1,ny-1,1) = Eigen::ArrayXXd::Constant(ny-1,1,1);
    
        // Gives boundary condition
    v.block(0,0,1,nx-1) = Eigen::ArrayXXd::Constant(1,nx-1,1);
    v.block(ny-1,0,1,nx-1) = Eigen::ArrayXXd::Constant(1,nx-1,1);
    v.block(0,0,ny-1,1) = Eigen::ArrayXXd::Constant(ny-1,1,1);
    v.block(0,nx-1,ny-1,1) = Eigen::ArrayXXd::Constant(ny-1,1,1);
  }
  
  ofstream writexdata((dir + "output.dat").c_str(), ios::out | ios::trunc);
  writexdata << u << endl;
  writexdata.close();
  
}