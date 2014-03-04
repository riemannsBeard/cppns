#ifndef BURGERS_H

#define BURGERS_H
#include <iostream>
#include <Eigen/Dense>
#include <math.h>
#include <fstream>
#include <sys/stat.h>
#include <string>
//#include "util/utilities.h"

void burgers();
double ufunc(double t, double x, double nu);

#endif // BURGERS_H
