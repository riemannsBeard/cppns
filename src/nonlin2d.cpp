#include "nonlin2d.h"

using namespace std;

void nonlin2d() {
  double nx = 101;
  double ny = 101;
  double nt = 80;
  double c = 1;
  double dx = 2/(nx-1);
  double dy = 2/(ny-1);
  double sigma = .2;
  double dt = sigma*dx;
  
  // Make an output folder
  std::string dir = "step5/";
  mkdir(dir.c_str(),0755); //Make a folder to store results in
  
  Eigen::ArrayXd x; // Array containing our x values
  x.setLinSpaced(nx,0,2);
  
  Eigen::ArrayXd y; // Array containing our x values
  y.setLinSpaced(ny,0,2);

  Eigen::ArrayXXd u;
  u.setOnes(ny,nx);
  Eigen::ArrayXXd v;
  v.setOnes(ny,nx);
  Eigen::ArrayXXd un;
  Eigen::ArrayXXd vn;
    
  u.block(.5/dy, .5/dx, 1/dy+1-.5/dy, 1/dx+1-.5/dx) = Eigen::ArrayXXd::Constant(1/dy+1-.5/dy,1/dx+1-.5/dx,2);
  
}