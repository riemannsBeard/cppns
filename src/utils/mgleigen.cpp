#include "mgleigen.h"

mglEigen::mglEigen(double xx, double yy, double zz)
{
    m=0;
    Create(xx, yy, zz);
}

double mglEigen::GetNx() const
{
    return nx;
}

double mglEigen::GetNy() const
{
    return ny;
}

double mglEigen::GetNz() const
{
    return nz;
}

void mglEigen::Create(double mx, double my, double mz)
{
    nx=mx;
    ny=my;
    nz=mz;
    if(m)
    {
        delete []m;
    }

    Eigen::MatrixXd m(nx,ny);
}

double mglEigen::Maximal() const
{
    return m.maxCoeff();
}

double mglEigen::Minimal() const
{
    return m.minCoeff();
}


double mglEigen::v(double i, double j, double k) const
{
    if(j==0) {
        return m(i);
    } else {
        return m(i,j);
    }
}

double mglEigen::vthr(double i) const
{
    return m.data();
}

double mglEigen::dvx(double i, double j, double k) const
{
    return 0; //Need to figure out how to implement this...
}

double mglEigen::dvy(double i, double j, double k) const
{
    return 0;
}

double mglEigen::dvz(double i, double j, double k) const
{
    return 0;
}
