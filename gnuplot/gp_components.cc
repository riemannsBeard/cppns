// -*- c++ -*-
// $Header: /home/asanuma/lib/cvsroot/c/gnuplot/gp_components.cc,v 1.3 2004/10/26 23:27:11 asanuma Exp $

#ifndef lint
static char *RCSid_gp_components_cc="$Header: /home/asanuma/lib/cvsroot/c/gnuplot/gp_components.cc,v 1.3 2004/10/26 23:27:11 asanuma Exp $";
#endif

#include <string>
#include <sstream>

#include "gp_components.h"

namespace gnuplotpp{
    
 namespace detail{
      
	using namespace std;
	//// helpers //////

	string quote( const char *s ){
	 string x("\""); x+=s; x+="\"";
	 return x;
	}
	string quote( const string &s ){
	 string x("\""); x+=s; x+="\"";
	 return x;
	}

	//// gprange ////
	ostream& operator<< (ostream &s, const gprange &a){  
	 s << " ["<< a.first << ":" << a.second << "]";
	}

	//// gpusing ////

	gpusing::gpusing( const int u1, const int u2): string() {
	 ostringstream os;
	 if     ( u1==omit ) os << "";
	 else if( u2==omit ) os << " using " << u1;
	 else  os << " using " << u1 << ":" << u2;
	 assign( os.str() );
	}

	//// lines and arrows ////////

	gparrow::gparrow( int n, const gpcoord &v1, const gpcoord &v2 ): 
	 gpset( "arrow", n ){
	 ostringstream o;
	 o << " from " << v1 << " to " << v2;
	 append(o.str());
	}

	gpline::gpline( int n, const gpcoord &v1, const gpcoord &v2 ): 
	 gparrow( n, v1, v2 ){
	 append(" nohead");
	}

 } // components

} // gnuplot
