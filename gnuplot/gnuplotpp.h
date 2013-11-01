// -*- c++ -*-
// $Header: /home/asanuma/lib/cvsroot/c/gnuplot/gnuplotpp.h,v 1.1 2004/10/26 23:27:06 asanuma Exp $
//

#ifndef __gnuplotpp_H__
#define __gnuplotpp_H__

#ifndef lint
static char *RCSid_gnuplotpp_H="$Header: /home/asanuma/lib/cvsroot/c/gnuplot/gnuplotpp.h,v 1.1 2004/10/26 23:27:06 asanuma Exp $";
#endif

#include "gp_components.h"

namespace gnuplotpp{

 using detail::gprange;
 using detail::gpset;
 using detail::gpusing;
 using detail::gpcoord;
 
}

#include "gp_plot.h"

namespace gnuplotpp{

 using detail::singleplot;
 using detail::multiplot;
 using detail::tableplot;
 using detail::gptable;
 using detail::squareplot;
 using detail::gpsquare;

}

#include "gp_traits.h"

namespace gnuplotpp{

	using detail::range;
	//	 using detail::set;
	using detail::coord;
	using detail::arrow;
	using detail::line;
	using detail::hline;
	using detail::vline;
}


#endif // __gnuplotpp_H__
