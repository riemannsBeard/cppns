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

    Eigen::VectorXd u(nx);

    u.setOnes(nx); // Set ones everywhere

    //Eigen::VectorXd x(nx); // This will be our x-values
    //x.setLinSpaced(nx,0,2); //linearly spaced values between 0 and 2

    int r = (1/dx+1)-(.5/dx); // The number of rows for starting position.
    // r should always be int, right? ... right? maybe should add a check...

    Eigen::VectorXd x(nx); // This will set our x values to the first column in the matrix
    x.setLinSpaced(nx,0,2); // linearly spaced values between 0 and 2

    Eigen::VectorXd ic(r); // initial conditions block matrix
    // Needs to be only nt+1, because we don't want to modify our newly created x column

    ic.setConstant(r,2); // nt+1 again for same reason as above

    u.segment(.5/dx,r) = ic; // Substiutes the sb matrix into the overall matrix.

    Eigen::VectorXd un(nx);


    mkdir(dir.c_str(),0755); //Make a folder to store results in

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
