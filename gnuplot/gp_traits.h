// -*- c++ -*-
// $Header: /home/asanuma/lib/cvsroot/c/gnuplot/gp_traits.h,v 1.4 2004/10/26 23:27:12 asanuma Exp $
//

#ifndef __GP_TRAITS_H__
#define __GP_TRAITS_H__

#ifndef lint
static char *RCSid_gp_traits_h="$Header: /home/asanuma/lib/cvsroot/c/gnuplot/gp_traits.h,v 1.4 2004/10/26 23:27:12 asanuma Exp $";
#endif

namespace gnuplotpp{

 namespace detail{

	typedef gprange range;
	//	 typedef gpset set;
	typedef gpcoord coord;
	typedef gparrow arrow;
	typedef gpline  line;
	typedef gphline hline;
	typedef gpvline vline;

 } // gp_traits

} // namespace gnuplot

#endif // __GP_TRAITS_H__
