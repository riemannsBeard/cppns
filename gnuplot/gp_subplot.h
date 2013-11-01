// -*- c++ -*-
// $Header: /home/asanuma/lib/cvsroot/c/gnuplot/gp_subplot.h,v 1.1 2004/10/26 23:27:06 asanuma Exp $
//

#ifndef __gp_subplot_H__
#define __gp_subplot_H__

#ifndef lint
static char *RCSid_gp_subplot_H="$Header: /home/asanuma/lib/cvsroot/c/gnuplot/gp_subplot.h,v 1.1 2004/10/26 23:27:06 asanuma Exp $";
#endif

#include "gp_base.h"
#include "gp_components.h"
#include "gp_traits.h"

namespace gnuplotpp{
namespace detail{

  //// class subplot ///////////
	/// each components of plot command
  class subplot: public gpstream{ // one plot
  protected:
    virtual string _quote( const string &s ){	return string(s); }
	
  public:
    subplot( void ): gpstream() {};
    subplot( const subplot &s ): gpstream(s.str()){};
	
    template<class C1>
    subplot( const C1 fn, 
	     const int u1=gpusing::omit, 
	     const int u2=gpusing::omit ):
      gpstream( fn ){
      *this << gpusing(u1,u2);
    }
	
  };
      
	/// file plotting
  class subfile: public subplot{
  private:
    template<class C>
    string _quote( const C &s ){ 
      std::ostringstream o; o<<"\""<<s<< "\"";
      return o.str();
    }
	
  public:
    template<class C1>
    subfile( const C1 fn, 
	     const int u1=gpusing::omit, 
	     const int u2=gpusing::omit  ):
      subplot(_quote(fn),u1,u2){};
    // note this cannot be done in the initialization list.
	
  };
      
	/// function plotting
  class subfunc: public subplot{
  private:
    //	  string _quote( const string &s ){ return s; }
  public:
    template<class C1>
    subfunc( const C1 fn ):
      subplot(fn,gpusing::omit,gpusing::omit){};
	
  };

}// namespace detail
}// namespace gnuplotpp

#endif // __gp_subplot_H__
