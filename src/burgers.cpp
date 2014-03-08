#include "burgers.h"

using namespace std;

double ufunc(double t, double x, double nu)
{
  
  /* This is the equation -2*nu*(phiprime/phi)+4, C++ doesn't seem to have a nice and easy CAS system unless you want to dive into Maxima (I don't want to) so we calculate this before hand %/ */
  /* I'll be screwed if we need to calculate this stuff on the fly in future steps */
  return -2*nu*(-(-8*t + 2*x)*exp(-pow((-4*t + x),2)/(4*nu*(t + 1)))/(4*nu*(t + 1)) - (-8*t + 2*x - 12.5663706143592)*exp(-pow((-4*t + x - 6.28318530717959),2)/(4*nu*(t + 1)))/(4*nu*(t + 1)))/(exp(-pow((-4*t + x - 6.28318530717959),2)/(4*nu*(t + 1))) + exp(-pow((-4*t + x),2)/(4*nu*(t + 1)))) + 4;

}

void burgers()
{
  const double PI = 3.141592653589793238463; // Precalculate this too...
  double nx = 101;
  double nt = 100;
  double dx = 2*PI/(nx-1);
  double nu = .07;
  double dt = dx/nu;
  double t = 0;
  
  // Make an output folder
  string dir = "step4/";
  mkdir(dir.c_str(),0755); //Make a folder to store results in
  
  Eigen::ArrayXd x; // Array containing our x values
  x.setLinSpaced(nx,0,2*PI);
  
  Eigen::ArrayXd y; // Array containing our y values
  Eigen::ArrayXd yn; // Temporary storage for y values
  
  y.setZero(nx,1);
  yn.setZero(nx,1);
  
  //std::cout << "X Cols: " << x.cols() << " X rows: " << x.rows() << std::endl;
  //std::cout << "Y Cols: " << y.cols() << " Y rows: " << y.rows() << std::endl;
  
  //std::cout << "X Col1: "  << x(1,0) << std::endl;
   
  for(int i=0; i<nx;i++)
  {
    //std::cout << ufunc(t,x(i,0),nu) << std::endl;
    y(i,0) = ufunc(t,x(i,0),nu); // Uses our function we defined
  }
  
  //std::cout << y << std::endl;
  double ynvalue;
  for (int j=0; j<nt; j++)
  {
    yn = y; // By default C++ copies the contents, we have to use pointers if we wanted two variables with the same address space
    
    for (int k=0; k<(nx-1); k++)
    {
      if (k<1) {
	y(k,0) = yn(k,0) - yn(k,0) * dt/dx * (yn(k,0) - yn.bottomRows(0)) + nu*dt/pow(dx,2)*(yn(k+1,0)-2*yn(k,0)+yn.bottomRows(0));
      } else if (k>=1) {
	y(k,0) = yn(k,0) - yn(k,0) * dt/dx * (yn(k,0) - yn(k-1)) + nu*dt/pow(dx,2)*(yn(k+1,0)-2*yn(k,0)+yn(k-1));
      } else {
	std::cout << "Error determining previous row." << std::endl;
	return;
      }
	
      
    }
    
    y.bottomRows(0) = yn.bottomRows(0) - yn.bottomRows(0) * dt/dx * (yn.bottomRows(0)-yn.bottomRows(1)) + nu*dt/pow(dx,2)*(yn(0,0)-2*yn.bottomRows(0)+yn.bottomRows(2));
    
  }
  
  std::cout << y << std::endl;
  
    
  /* 
    ofstream writexdata((dir + "output.dat").c_str(), ios::out | ios::trunc);
    for (int i=0;i<nx;i++){
        writexdata << x(i) << "\t" << y(i) << endl;
    }

    writexdata.close(); */
  
}