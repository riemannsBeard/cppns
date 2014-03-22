#include "nonlin1d.h"

using namespace std;

void nonlin1d()
{
  int nx = 41;
  double dx = 2/(double (nx)-1);
  int nt = 20;
  double dt = .025;

  Eigen::ArrayXd u(nx);
  u.setOnes(nx); // Set ones everywhere
  u.block(.5/dx,0,1/dx+1-.5/dx,1) = Eigen::ArrayXd::Constant(1/dx+1-.5/dx,1,2); // Starting conditions

  Eigen::ArrayXd x(nx);
  x.setLinSpaced(nx,0,2);
  
  Eigen::ArrayXd un(nx);
  un.setOnes(nx); // Set ones everywhere

  for (int n=0;n<nt;n++)
  {
    un << u;
      for (int i=1;i<nx;i++) // From row 1, apparently we can't touch the left side wall (yet, maybe in 2d or diffusion)
      {
	  u(i) = un(i)-un(i)*dt/dx*(u(i)-u(i-1));
      }
  }

  mkdir("step2",0755); //0755 is the permissions code. This works on linux only

  ofstream writefile("step2/data.dat", ios::out | ios::trunc);
    for (int j=0;j<nx;j++)
    {
	writefile << x[j] << "\t" << u[j] << endl;
    }
  writefile.close();
}
