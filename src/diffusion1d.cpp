#include "diffusion1d.h"

using namespace std;

void diffusion1d()
{
  const int nx = 41;
  const double dx = 2/(double (nx)-1);
  const int nt = 20;
  const double nu = .3;
  const double sigma = .2;
  const double dt = (sigma*pow(dx,2.0))/nu;
  string dir = "step3/";

  Eigen::ArrayXd u(nx);
  u.setOnes(nx); // Set ones everywhere``

  Eigen::ArrayXd x(nx); // This will set our x values to the first column in the matrix
  x.setLinSpaced(nx,0,2); // linearly spaced values between 0 and 2
  u.block(.5/dx,0,1/dx+1-.5/dx,1) = Eigen::ArrayXd::Constant(1/dx+1-.5/dx,1,2);

  Eigen::VectorXd un(nx);

  string step;

  for (int j=0;j<nt;j++) // From column 2 (Eigen is 0-indexed, so really column 3!) to end (of matrix, nt+2)
  {
      un << u;

      for (int k=1;k<nx-1;k++) // From row 1
      {
	  u(k) = un(k) + ((nu*dt)/(dx*dx))*(un(k+1)-(2*un(k))+un(k-1));

      }

  }

  ofstream writexdata((dir + "output.dat").c_str(), ios::out | ios::trunc);
  for (int i=0;i<nx;i++){
      writexdata << x(i) << "\t" << u(i) << endl;
  }

  writexdata.close();
}
