#include "channelns.h"

using namespace std;

void channelns() {
  double nx = 41;
  double ny = 41;
  double nt = 10;
  double nit = 50;
  double c  = 1;
  double dx = 2/(nx-1);
  double dy = 2/(ny-1);
  
  double rho = 1;
  double nu =.1;
  double F = 1;
  double dt = .01;
  
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
  
  
}