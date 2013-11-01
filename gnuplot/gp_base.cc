// -*- c++ -*-
// $Header: /home/asanuma/lib/cvsroot/c/gnuplot/gp_base.cc,v 1.5 2004/10/26 23:27:12 asanuma Exp $

#ifndef lint
static char *RCSid="$Header: /home/asanuma/lib/cvsroot/c/gnuplot/gp_base.cc,v 1.5 2004/10/26 23:27:12 asanuma Exp $";
#endif

#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstdio>
#include "process.h"
#include "gp_base.h"
#include "gp_components.h"

namespace gnuplotpp{

  namespace detail{

    using namespace std;

    //// class axis
    const axis& axis::label( const char *s ) const{
      *__pre << gpset( k+"label", quote( s ) ) << endl; 
      return *this;
    }

    const axis& axis::label( const char *s, const double x, const double y ) const{
      *__pre << gpset( k+"label", quote( s ), gpcoord(x, y) )<< endl; 
      return *this;
    }

    const axis& axis::label( const char *s, const gpcoord &c ) const{
      *__pre << gpset( k+"label", quote( s ), c )<< endl; 
      return *this;
    }

    const axis& axis::format( const char *s ) const{
      *__pre << gpset( "format", k, quote( s ) )<< endl; 
      return *this;
    }
	 
    const axis& axis::tics( const double x ) const{
      *__pre << gpset( k+"tics", x )<< endl; 
      return *this;
    }

    const axis& axis::mtics( const double x ) const{
      *__pre << gpset( string("m")+k+"tics", x )<< endl; 
      return *this;
    }

		const axis& axis::log( const bool b ) const {
			string s("log"); if(!b) s.insert(0,"no");
			*__pre << gpset( s, k ) << endl;
			return *this;
		}
	 
    //// labels & arrows /////
    int plotbase::_narrow=100; 
    int plotbase::_nlbl=100; 
    
    gpstream & plotbase::arrow( void ){
      prebuf() << "set arrow " << _narrow << " ";
      postbuf() << "set noarrow " << plotbase::_narrow++ << endl;
      return prebuf();
    }
    gpstream & plotbase::arrow( const gpcoord &v1, const gpcoord &v2 ){
      prebuf() << gparrow( _narrow, v1, v2 )<< endl;
      postbuf() << "set noarrow " << plotbase::_narrow++ << endl;
      return prebuf();
    }
	 
    gpstream & plotbase::line( const gpcoord &v1, const gpcoord &v2 ){
      prebuf() << gpline( _narrow, v1, v2 )<< endl;
      postbuf() << "set noarrow " << _narrow++ << endl;
      return prebuf();
    }

    gpstream & plotbase::label( void ){
      prebuf()  << "set label " << _nlbl << " ";
      postbuf() << "set nolabel " << _nlbl++ << endl;
      return prebuf();
    }

    gpstream & plotbase::label( const char *s, const gpcoord &v ){
      prebuf()  << "set label " << _nlbl << " " << quote(s) << " at " << v << endl;
      postbuf() << "set nolabel " << _nlbl++ << endl;
      return prebuf();
    }
	 

    //// class sizebase
    void sizebase::setsize( double x, double y ){
      _xsize=x; _ysize=y;
      outsize();
    }
    void sizebase::outsize( void ){
      prebuf() << std::setiosflags( std::ios::fixed ) 
	       << std::setprecision(2)
	       << "_xsize=" << _xsize << endl
	       << "_ysize=" << _ysize << endl
	       << "set size _xsize, _ysize" << endl;
    }
    
    //// class filebase

    filebase& filebase::save( void ){ 
      std::ofstream out(_fn.c_str());
      out << *this;
      return *this;
    }
    
    filebase& filebase::save( const char *_n ){
      _fn=_n;
      std::ofstream out(_fn.c_str());
      out << *this;
      return *this;
    }  

    filebase& filebase::save( const string& _n ){
      _fn=_n;
      std::ofstream out(_fn.c_str());
      out << *this;
      return *this;
    }  

    filebase& filebase::save( ostream &o ){ 
      print(o); 
      return *this;
    }
    
    ostream & operator << ( ostream &o, const filebase &p ){
      p.print( o ); return o;
    }
    
    ///// file manipulations ///////////////////////////
    const filebase& filebase::exec( void ) const{
#ifdef __TURBOC__
      if( spawnl( P_WAIT, GNUPLOT, GNUPLOT, _fname, NULL ) != 0 ){
	perror("exec:");    exit(1);
      }
#endif
#ifdef unix
      const char *cmd[4]={"gnuplot",_fn.c_str(),0};
      if( spawnvp( cmd[0], (char *const *) cmd ) ){
	perror("gnuplot.exec():");    
	cerr << cmd[0] << "," << cmd[1] << "," << cmd[2] << endl;
	exit(1);
      } 
      return *this;
#endif //unix
    }

    const filebase& filebase::gnu2eps( bool opt ) const{
#ifdef unix
      const char *cmd[4]={"gnu2psl2eps",_fn.c_str(),0};
      if(!opt){
	cmd[1]=_fn.c_str();
	cmd[2]=0;
      }
      if( spawnvp( cmd[0], (char *const *) cmd ) ){
	perror("exec:");
      }
      return *this;
# endif //unix
    }

    const filebase& filebase::gnu2ps( void ) const{
# ifdef unix
      const char *cmd[]={"gnu2ps",_fn.c_str(),0};
      if( spawnvp( cmd[0], (char *const *) cmd ) ){
	perror("exec:");
      } 
      return *this;
# endif //unix
    }

    const filebase& filebase::gnu2gif( void ) const{
# ifdef unix
      const char *cmd[]={"gnu2gif",_fn.c_str(),0};
      if( spawnvp( cmd[0], (char *const *) cmd ) ){
	perror("exec:");
      } 
      return *this;
# endif //unix
    }

    const filebase& filebase::gnu2png( void ) const{
# ifdef unix
      const char *cmd[]={"gnu2png",_fn.c_str(),0};
      if( spawnvp( cmd[0], (char *const *) cmd ) ){
	perror("exec:");
      } 
      return *this;
# endif //unix
    }

    const filebase& filebase::remove ( void ) const{
      std::remove(_fn.c_str());
      return *this;
    };



  } // gp_base

} // gnuplot

