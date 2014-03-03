#include "burgers.h"

using namespace std;

double u(double t, double x, double nu)
{
  

  return -2*nu*(-(-8*t + 2*x)*exp(-pow((-4*t + x),2)/(4*nu*(t + 1)))/(4*nu*(t + 1)) - (-8*t + 2*x - 12.5663706143592)*exp(-pow((-4*t + x - 6.28318530717959),2)/(4*nu*(t + 1)))/(4*nu*(t + 1)))/(exp(-pow((-4*t + x - 6.28318530717959),2)/(4*nu*(t + 1))) + exp(-pow((-4*t + x),2)/(4*nu*(t + 1)))) + 4;

}

void burgers()
{
  double t = 1;
  double x = 4;
  double nu = 3;
  double result;
  result = u(t,x,nu);
  std::cout << result << std::endl;
}