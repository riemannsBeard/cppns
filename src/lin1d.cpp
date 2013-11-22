#include "lin1d.h"

using namespace std;

void lin1d()
{

    double nx = 41; // Number of points
    double dx = 2/(nx-1); // Distance between points
    double nt = 25; // Number of timesteps
    double dt = .025; // Timestep difference
    double c = 1; // Wavespeed

    Eigen::VectorXd u(nx); // Contructs new eigen vector object called u, of size nx
    u.setOnes(nx); // Set to ones

    for (double i=.5/dx;i<(1/dx)+1;i++) // Set the elements between .05 and 1 as u=2
    {
        u[i] = 2;
    }

    Eigen::VectorXd x; // A vector to hold our x values
    x.setLinSpaced(nx,0,2);

    mkdir("step1",0755); //0755 is the permissions code. This works on linux only

    ofstream writefile("step1/data-before.dat", ios::out | ios::trunc);

    for (int j=0;j<nx;j++)
    {
        writefile << x[j] << "\t" << u[j] << endl;
    }
    writefile.close();

    Eigen::VectorXd un(nx); // Placeholder vector for temporary storage of values

    for (int j=0;j<nt;j++)
    {
        un << u; // Copy the contents of u into un

        for (int k=1;k<nx;k++)
        {
            u[k] = un[k]-c*dt/dx*(un[k]-un[k-1]);
        }
    }

    un.resize(0); // Frees the memory

    ofstream writefile2("step1/data-after.dat", ios::out | ios::trunc);

    for (int k=0;k<nx;k++)
    {
        writefile2 << x[k] << "\t" << u[k] << endl;
    }
    writefile2.close();

    u.resize(0); // Free the memory

    mglGraph gr; // Start mgl graph object that holds all graph stuff

    mglData y("step1/data-before.dat"); // Load one set of data
    mglData z("step1/data-after.dat"); // Load the other, I really better stick both of these in a single file... along with all the other steps.
    mglData xdat=y.SubData(0), ydat=y.SubData(1), y2dat=z.SubData(1);

    gr.SetOrigin(0,0,0);
    gr.Title("Linear 1 Dimension");
    gr.Box(); // Bounding box
    gr.AddLegend("Initial Condition", "bd"); // Pack into legend
    gr.AddLegend("Final Condition","g*");
    gr.Legend(); // Add legend to plot
    gr.SetRanges(0,2,0,3);
    gr.Axis(); // Creates ticks, I think
    gr.Plot(xdat,ydat,"bd"); // Puts the data into the graph
    gr.Plot(xdat,y2dat,"g*"); // Same as previous line
    gr.WriteGIF("step1/lin1d.gif");

}
