#include "laplace2d.h"

using namespace std;

void laplace2d() {
  double nx = 31;
  double ny = 31;
  double c = 1;
  double dx = 2/(nx-1);
  double dy = 2/(ny-1);
  double linorm_target = .01;
  double linorm = 1;
  
  // Make an output folder
  std::string dir = "step9/";
  mkdir(dir.c_str(),0755); //Make a folder to store results in
  
  Eigen::ArrayXd x; // Array containing our x values
  x.setLinSpaced(nx,0,2); // Array is linearly spaced values from 0 to 2
  
  Eigen::ArrayXd y; // Array containing our x values
  y.setLinSpaced(ny,0,1);
  
  // Arrays containing our calculated values
  Eigen::ArrayXXd p;
  Eigen::ArrayXXd pn;
  
  // Initial Conditions
  p.setZero(ny,nx);
  pn.setZero(ny,nx);
  
  //Set Boundary Conditions
  p.block(0,0,ny,1) = Eigen::ArrayXXd::Constant(ny,1,0);
  p.block(0,nx-1,ny,1) = y.block(0,0,ny,1);
  p.block(0,0,1,nx) = p.block(1,0,1,nx);
  p.block(ny-1,0,1,nx) = p.block(ny-2,0,1,nx);

  while(linorm>linorm_target)
  {
    pn << p;
    p.block(1,1,ny-2,nx-2) = (pow(dy,2)*(pn.block(2,1,ny-2,nx-2)+pn.block(0,1,ny-2,nx-2))+pow(dx,2)*(pn.block(1,2,ny-2,nx-2)+pn.block(1,0,ny-2,nx-2)))/(2*(pow(dx,2)+pow(dy,2)));
    p(0,0) = (pow(dy,2)*(pn(1,0)+pn(ny-1,0))+pow(dx,2)*(pn(0,1)+pn(0,nx-1)))/(2*(pow(dx,2)+pow(dy,2)));
    p(ny-1,nx-1) = (pow(dy,2)*(pn(0,nx-1)+pn(ny-2,nx-1))+pow(dx,2)*(pn(ny-1,0)+pn(ny-1,nx-2)))/(2*(pow(dx,2)+pow(dy,2)));
    
    //Set Boundary Conditions
    p.block(0,0,ny,1) = Eigen::ArrayXXd::Constant(ny,1,0);
    p.block(0,nx-1,ny,1) = y.block(0,0,ny,1);
    p.block(0,0,1,nx) = p.block(1,0,1,nx);
    p.block(ny-1,0,1,nx) = p.block(ny-2,0,1,nx);
    
  }
  
  ofstream writexdata((dir + "output.dat").c_str(), ios::out | ios::trunc);
  writexdata << p << endl;
  writexdata.close();
}