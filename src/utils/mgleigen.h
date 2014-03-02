#ifndef MGLEIGEN_H
#define MGLEIGEN_H

#include <mgl2/mgl.h>
#include <Eigen/Dense>

class mglEigen : public mglDataA
{
public:
    double nx;
    double ny;
    double nz;
    Eigen::MatrixXd m;

    mglEigen(double xx=1, double yy=1, double zz=1);

    // Functions to get the size of the thing
    double GetNx() const;
    double GetNy() const;
    double GetNz() const;

    void Create(double mx, double my=1, double mz=1);

    double Maximal() const;
    double Minimal() const;

protected:
    double v(double i, double j=0, double k=0) const;
    double vthr(double i) const;
    double dvx(double i, double j=0, double k=0) const;
    double dvy(double i, double j=0, double k=0) const;
    double dvz(double i, double j=0, double k=0) const;
};

#endif // MGLEIGEN_H
