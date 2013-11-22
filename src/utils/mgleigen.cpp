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

void mglEigen::Create(double mn, double my, double mz)
{
    nx=mx;
    ny=my;
    nz=mz;
    if(m)
    {
        delete []m;
    }

    Eigen::Matrix m(nx,ny);
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
}

double mglEigen::vthr(double i) const
{
}

double mglEigen::dvx(double i, double j, double k) const
{
}

double mglEigen::dvy(double i, double j, double k) const
{
}

double mglEigen::dvz(double i, double j, double k) const
{
}
