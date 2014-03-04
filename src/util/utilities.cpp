/*#include "utilities.h"

template <typename Derived>
void dataToFile(const Eigen::EigenBase<Derived>&x, const Eigen::EigenBase<Derived>&y, std::string filename)
{
  double xnr = x.rows();
  double xnc = x.cols();
  
  double ynr = y.rows();
  double ync = y.cols();
  
  if(!(xnr == ynr) || !(xnc == ync))
  {
    std::cout << "We have a mismatching rows or cols problem. No files written." << std::endl;
    return;
  }
  
  ofstream writexdata(filename.c_str(), ios::out | ios::trunc);
  for (int i=0;i<xnr;i++){
    writexdata << x(i,1) << "\t" << y(i,1) << endl;
  }
  writexdata.close();
}
  */