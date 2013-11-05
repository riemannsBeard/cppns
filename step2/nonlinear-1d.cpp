#include <iostream>
#include <Eigen/Dense>
#include <mgl2/mgl.h>
#include <fstream>

using namespace std;

int main()
{
    int nx = 41;
    double dx = 2/(nx-1);
    int nt = 20;
    double dt = .025;

    Eigen::MatrixXd u(nx,nt+1); // Creates a matrix with a column for every point and a column for every timestep. This will make plotting a lot easier than step1 (hopefully...)
    // The more I think about this, the more I think this is a bad idea. It is nonsensical to store 1d data in a 2d matrix

    u.setOnes(nx,nt+1);

    Eigen::VectorXd x(nx); // This will set our x values to the first column in the matrix
    u.col(0) = x.setLinSpaced(nx,0,2);

    double s = (1/dx+1)-(.5/dx); // The number of rows for starting position.

    Eigen::MatrixXd sb(s,nt); // initial conditions block matrix

    sb.setConstant(s,nt,2);

    u.block(.5/dx,1,s,nt) = sb;

    cout << u << endl;

    return 0;
}
