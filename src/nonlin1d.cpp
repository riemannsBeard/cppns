#include "nonlin1d.h"

using namespace std;

void nonlin1d()
{
    int nx = 41;
    double dx = 2/(double (nx)-1);
    int nt = 20;
    double dt = .025;

    Eigen::MatrixXd u(nx,nt+2); // Creates a matrix with a column for every point and a column for every timestep. This will make plotting a lot easier than step1 (hopefully...)
    // The more I think about this, the more I think this is a bad idea. It is nonsensical to store 1d data in a 2d matrix, also mixing x data and transient y data in the same matrix, also it creates problems such as:
    // Needs to be nt+2 because 1 column is used by our x values, and a second column is used by our initial conditions, and we want to make 20 timesteps (i.e. calculate at 20 new time periods)

    u.setOnes(nx,nt+2); // Set ones everywhere

    Eigen::VectorXd x(nx); // This will set our x values to the first column in the matrix
    u.col(0) = x.setLinSpaced(nx,0,2); // Sets the 0 column (1st column, but eigen is 0-indexed) to a linearly spaced values between 0 and 2

    int s = (1/dx+1)-(.5/dx); // The number of rows for starting position.
    // s should always be int, right? ... right? maybe should add a check...

    Eigen::MatrixXd sb(s,nt+1); // initial conditions block matrix
    // Needs to be only nt+1, because we don't want to modify our newly created x column

    sb.setConstant(s,nt+1,2); // nt+1 again for same reason as above

    u.block(.5/dx,1,s,nt+1) = sb; // Substiutes the sb matrix into the overall matrix.

    for (int j=2;j<nt+2;j++) // From column 2 (Eigen is 0-indexed, so really column 3!) to end (of matrix, nt+2)
    {

        for (int k=1;k<nx;k++) // From row 1, apparently we can't touch the left side wall (yet, maybe in 2d or diffusion)
        {
            // the index (k,j) should give is row k, colum j... backwards from usual because I initialized the matrix as column major but you access elemnts in a row major fashion
            u(k,j) = u(k,j-1)-u(k,j-1)*dt/dx*(u(k,j-1)-u(k-1,j-1));
        }
    }

    mkdir("step2",0755); //0755 is the permissions code. This works on linux only

    ofstream writefile2("step2/data.dat", ios::out | ios::trunc);
    writefile2 << u << endl;
    writefile2.close();


    mglGraph gr; // Start mgl graph object that holds all graph stuff

    mglData y("step2/data.dat"); // Load one set of data
    mglData xdat=y.SubData(0), ydat=y.SubData(21);

    gr.SetOrigin(0,0,0);
    gr.Title("Non-Linear 1 Dimension");
    gr.Box(); // Bounding box
    gr.AddLegend("Final Condition","r*");
    gr.Legend(); // Add legend to plot
    gr.SetRanges(0,2,0,3);
    gr.Axis(); // Creates ticks, I think
    gr.Plot(xdat,ydat,"r*"); // Same as previous line
    gr.WriteGIF("step2/nonlin1d.gif");

}
