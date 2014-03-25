#include "laplace2d.h"

using namespace std;

void laplace2d() {
  double nx = 41;
  double ny = 41;
  double nt = 120;
  double c = 1;
  double dx = 2/(nx-1);
  double dy = 2/(ny-1);
  
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
  p.block(0,0,ny-1,1) = Eigen::ArrayXXd::Constant(ny-1,1,0);
  p.block(0,nx-1,ny-1,1) = y;
  p.block(0,0,1,nx-1) = p.block(1,0,1,nx-1);
  p.block(ny-1,0,1,nx-1) = p.block(ny-2,0,1,nx-1);
  
  /*for (int i=0;i<nt+1;i++)
  {
    
  }*/
  
  ofstream writexdata((dir + "output.dat").c_str(), ios::out | ios::trunc);
  writexdata << p << endl;
  writexdata.close();
}