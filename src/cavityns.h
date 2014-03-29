#ifndef CAVITYNS_H

#define CAVITYNS_H
#include <iostream>
#include <Eigen/Dense>
#include <math.h>
#include <fstream>
#include <sys/stat.h>
#include <string>
//#include "util/utilities.h"

Eigen::ArrayXXd prespoisson(Eigen::ArrayXXd *p, Eigen::ArrayXXd *b);
void cavityns();

#endif // CAVITYNS_H
