/* $Header: /home/asanuma/lib/cvsroot/c/process.h,v 1.2 2001/08/28 12:47:57 asanuma Exp $ */
/*   $Log: process.h,v $
/*   Revision 1.2  2001/08/28 12:47:57  asanuma
/*   *** empty log message ***
/* */
/*   Revision 1.1  1999/03/26 13:20:27  asanuma */
/*   Initial revision */
/*  */

#ifndef lint
static char *RCSid_Process_h="$Header: /home/asanuma/lib/cvsroot/c/process.h,v 1.2 2001/08/28 12:47:57 asanuma Exp $";
#endif

#include <stdarg.h>

#ifdef __cplusplus
extern "C" {
#endif

#if !defined(__TURBOC__)
#ifdef unix
int spawnv( const char *path, char *const argv[] ); /* check this later */
int spawnl( const char *path, ... );
int spawnvp( const char *path, char *const argv[] );
int spawnlp( const char *path, ... );
#endif /* unix */
#endif

#ifdef __cplusplus
	   }
#endif

