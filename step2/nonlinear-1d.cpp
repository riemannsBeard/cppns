#include <iostream>
#include <Eigen/Dense>
#include <mgl2/mgl.h>
#include <fstream>

using namespace std;

int main()
{
    double nx = 41;
    double dx = 2/(nx-1);
    double nt = 20;
    double dt = .025;

    Eigen::MatrixXd u(2,7); // Creates a matrix with a for for every point and a column for every timestep. This will make plotting a lot easier than step1 (hopefully...)

    u.setOnes(5,7);
    cout << u << endl;
    cout << u.block<2,2>(1,1) << endl;

    Eigen::MatrixXd m(2,2);
    m << 2,4,
         5,9;

     u.block<2,2>(1,1) = m;

    std::cout << u.rows() << std::endl;

    std::cout << u << std::endl;

    return 0;
}
