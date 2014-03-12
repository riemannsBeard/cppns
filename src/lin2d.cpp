#include "lin2d.h"

void lin2d() {
  double nx = 81;
  double ny = 81;
  double nt = 100;
  double c = 1;
  double dx = 2/(nx-1);
  double dy = 2/(ny-1);
  double sigma = .2;
  double dt = sigma*dx;
  
  Eigen::ArrayXd x; // Array containing our x values
  x.setLinSpaced(nx,0,2);
  
  Eigen::ArrayXd y; // Array containing our x values
  y.setLinSpaced(ny,0,2);

  Eigen::ArrayXXd u;
  u.setOnes(ny,nx);
  
  Eigen::ArrayXXd un;
  un.setOnes(ny,nx);
  
  //u.block(.5/dy, .5/dx, (dy+1)-.5/dy, (dx+1)-.5/dx) < 2;
  
  std::cout << u << std::endl;
}

