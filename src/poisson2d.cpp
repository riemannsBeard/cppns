#include "poisson2d.h"

using namespace std;

void poisson2d() {
  double nx = 50;
  double ny = 50;
  double nt = 100;
  double xmin = 0;
  double xmax = 2;
  double ymin = 0;
  double ymax = 1;
  
  //double c = 1;
  double dx = (xmax-xmin)/(nx-1);
  double dy = (ymax-ymin)/(ny-1);
  //double linorm_target = .01;
  //double linorm = 1;
  
  // Make an output folder
  std::string dir = "step10/";
  mkdir(dir.c_str(),0755); //Make a folder to store results in
  
  Eigen::ArrayXd x; // Array containing our x values
  x.setLinSpaced(nx,xmin,xmax); // Array is linearly spaced values from 0 to 2
  
  Eigen::ArrayXd y; // Array containing our x values
  y.setLinSpaced(ny,ymin,ymax);
  
  // Arrays containing our calculated values
  Eigen::ArrayXXd p;
  Eigen::ArrayXXd pn;
  
  //Source term
  Eigen::ArrayXXd b;
  
  // Initial Conditions
  p.setZero(ny,nx);
  pn.setZero(ny,nx);
  b.setZero(ny,nx);
  
  // Source spikes
  b(ny/4,nx/4) = 100;
  b(3*ny/4,3*nx/4) = -100;
  
  for(int i=0;i<nt;i++) {
    pn << p;
    //p.block(1,1,ny-2,nx-2) = (pow(dy,2)/(2*(pow(dx,2)+pow(dy,2)))*(pn.block(2,1,ny-1,nx-1)+pn.block(0,1,ny-1,nx-1))+pow(dx,2)/(2*(pow(dx,2)+pow(dy,2))*pn.block(1,0,ny-1,nx-1)+pn.block(1,0,ny-1,nx-1))-b.block(1,1,ny-1,nx-1)*pow(dx,2)*pow(dy,2)/(2*(pow(dx,2)+pow(dy,2))));
    //(pow(dy,2)*(pn.block(2,1,ny-2,nx-2)+pn.block(0,1,ny-2,nx-2))+pow(dx,2)*(pn.block(1,2,ny-2,nx-2)+pn.block(1,0,ny-2,nx-2)))/(2*(pow(dx,2)+pow(dy,2)));   
    //Set Boundary Conditions
    p.block(0,0,ny,1) = Eigen::ArrayXXd::Constant(ny,1,0);
    p.block(ny-1,0,1,nx) = Eigen::ArrayXXd::Constant(1,nx,0);
    p.block(0,0,1,nx) = Eigen::ArrayXXd::Constant(1,nx,0);
    p.block(0,nx-1,ny,1) = Eigen::ArrayXXd::Constant(ny,1,0);
   
    //linorm = (p.cwiseAbs()-pn.cwiseAbs()).sum()/(pn.cwiseAbs()).sum();
    
  }
  
  ofstream writexdata((dir + "output.dat").c_str(), ios::out | ios::trunc);
  writexdata << p << endl;
  writexdata.close();
}
