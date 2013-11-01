/*$Header: /home/asanuma/lib/cvsroot/c/gnuplot/mkgnu.h,v 1.7 1999/03/26 13:20:27 asanuma Exp $
   mkgnu.h
     declaration for mkgnu_sub.c mkgnu.c

     $Log: mkgnu.h,v $
     Revision 1.7  1999/03/26 13:20:27  asanuma
     *** empty log message ***

     Revision 1.6  1998/09/02 17:43:07  asanuma
     inclusion of asa.h etc.

     Revision 1.5  1995/09/15 17:59:07  jun
     RCSid

     Revision 1.4  1995/09/14 21:32:16  jun
     static Real calc_stats( struct gnu *x, struct reg_result *res );

     Revision 1.3  1995/06/21 20:43:13  jun
     of course this should include "asa.h"

 * Revision 1.2  1995/06/21  20:11:25  jun
 * declaration of put_range()
 *

*/
#ifndef __MKGNU_H__ 
#define __MKGNU_H__

#include "asa.h"
#include "gnuplot.h"
#include "statistics.h"

#ifndef lint
static char *RCSid_mkgnu_h="$Id: mkgnu.h,v 1.7 1999/03/26 13:20:27 asanuma Exp $";
#endif

#define NSTR 100
struct dataset{
    char dataname[NSTR];
    char xlabel[NSTR], ylabel[NSTR];
};
struct range{
    double xmin, xmax;
};
struct plot{
    char conds[NSTR], xy[NSTR], legend[NSTR], with[NSTR];
};
struct gnu{
    char gnuname[NSTR];
    struct dataset *set;
    struct range *x, *y;
    int log;
    char *func;
    int nplot;
    struct plot *pl;
    int ncmd;
    char *cmd[10];
};
#define XLOG    1
#define YLOG    2
#define XYLOG   3
#define LNR     0

void mkgnu( int nfile );

static void gnu_vline( FILE *, double, char* );
static void gnu_hline( FILE *, double, char* );
static void put_range( FILE *, struct gnu * );
static double calc_stats( struct gnu *, struct reg_result *);

#endif
