// -*- c++ -*-
// $Header: /home/asanuma/lib/cvsroot/c/gnuplot/gp_base.h,v 1.5 2004/10/26 23:27:12 asanuma Exp $
//

#ifndef __gnuplot_sub_H__
#define __gnuplot_sub_H__

#ifndef lint
static char *RCSid_gp_base_h="$Header: /home/asanuma/lib/cvsroot/c/gnuplot/gp_base.h,v 1.5 2004/10/26 23:27:12 asanuma Exp $";
#endif

#include <iostream>
#include <string>
#include <sstream>
#include <utility>
#include <vector>

#include "gp_components.h"

namespace gnuplotpp{
    
	/// namespace for base classes 
  namespace detail{
      
    using namespace std;

    //// gpstream ////////////////////////////////
		/// stream buffers used in gnuplot++
    class gpstream: public ostringstream{
	
    public:
      gpstream( void ):           ostringstream(){};
      gpstream( const char *s):   ostringstream(){*this << s;};
      gpstream( const string &s): ostringstream(){*this << s;};
      gpstream( const gpstream &s ): ostringstream(){
				*this << s.str(); };
      gpstream& operator=( const gpstream &s ){
				// str(s.str()); // this does not work
				clear(); *this << s.str();
      }
		
    }; // gpstream


    //// axis class ///////////////////////////////
		/// axes that have labels, formats, tics, mtics, and log
		/**
		 *  <li> label( s )
		 *  <li> label( s, x, y )
		 *  <li> label( s, gpcoord() )
		 */
    class axis{
    private:
      string k;
      gpstream *__pre;

    public:
      axis( const char *s, gpstream &g ): k(s), __pre(&g){};

			void setbuf( gpstream &g ){ __pre=&g; };

      template<class C1, class C2>
      const axis& range( const C1 a, const C2 b ) const{
				(*__pre)<< gpsetrange( k, a, b ) << endl; return *this;
      }
      const axis& label( const char *s ) const;
      const axis& label( const char *s, double x, double y ) const;
      const axis& label( const char *s, const gpcoord &c ) const;
      const axis& format( const char *s ) const;
      const axis& tics( const double x ) const;
      const axis& mtics( const double x ) const;
      const axis& log( bool=true ) const;

    }; // axis
      
    //// axes, labels arrows /////
		/// giving an accsess to axes and setting labels & arrows
    class plotbase{

    private:
      static int _narrow, _nlbl;

    private:
      virtual gpstream & prebuf( void )=0;
      virtual gpstream & postbuf( void )=0;
      
    public:
      axis x, y, z, x2, y2, z2;

    public:
      plotbase(gpstream &_pre, gpstream &_post):
				x("x",_pre), x2("x2",_pre), y("y",_pre), y2("y2",_pre),
				z("z",_pre), z2("z2",_pre){};
			//       plotbase(const plotbase &p):
			// 	x("x",_pre), x2("x2",_pre), y("y",_pre), y2("y2",_pre){};
			void initialize( gpstream &_pre, gpstream &_post ){
				x.setbuf(_pre); x2.setbuf(_pre);
				y.setbuf(_pre); y2.setbuf(_pre);
				z.setbuf(_pre); z2.setbuf(_pre);
			}

		public:
      gpstream &arrow( const gpcoord &v1, const gpcoord &v2 );
      gpstream &arrow( void );
      gpstream &line ( const gpcoord &v1, const gpcoord &v2 );
      gpstream &line ( void  );
      gpstream &label( const char *s, const gpcoord &v );
      gpstream &label( void );
	 
    }; // plotbase

    //// size handing //////////////////////////////
		/// size handling of graph
    class sizebase{

    private:
      virtual gpstream & prebuf( void )=0;
      virtual gpstream & postbuf( void )=0;      

    protected:
      double _xsize, _ysize;

    public:
      sizebase(void ):  _xsize(1.), _ysize(1.){};

      void setsize( double, double );

    protected:
      virtual void outsize( void ) ;

    }; // class sizebase

		//// class contbase ////////////////   
    /// container of the subclass
    template<class C, class Alloc=std::vector<C> >
    class contbase{

    protected:
      typedef C sub_class;
      typedef Alloc _container;
	
     protected:
       _container  _p;
	
    public: // constructors
      contbase( void ):  _p(){};
      contbase( int n ): _p(n){			};
      contbase( int n, const sub_class &c ): _p(n,c){			};

    public: // accessors
      inline       _container& sub( void )     { return _p; }
      inline const _container& sub( void )const{ return _p; }

      inline const sub_class &operator[]( const int i )const{
				return _p[i];
      }
      inline sub_class       &operator[]( const int i ){
				return _p[i];
      }

      inline size_t size( void )const{ return _p.size(); }
	
    }; // conbase

		//// class setbufbase //////////////
    /// gives an access for buffers of setbuf, postsetbuf
		/**   <li> buf()    : access to the set buffer
		 *		<li> postbuf(): access to the postset buffer
		 *    <li> set( C ) : putting "set C" and endl
		 *    <li> g << C   : access to the set buffer   
		 */
    class setbufbase{
		
    protected:
      typedef gpstream stream_type;
	
    protected:
			stream_type _pre, _post;
	
    public:
			setbufbase( void ) {};

    public:
      // new interface
      inline const stream_type & buf    (void) const {return _pre;}
			inline stream_type &       buf    (void)       {return _pre;}
      inline const stream_type & postbuf(void) const {return _post;}
			inline stream_type &       postbuf(void)       {return _post;}
	
      template<class C>
      inline ostream & set( const C &c )
      {return _pre << "set " << c << endl; }

      template<class _T>
      inline ostream & operator<< ( const _T &x ){
				return _pre << x;
      }
	
      // left for backward compatibility
      stream_type & set(void) { return _pre;  };
      stream_type & postset(void) { return _post; };
	
	
    }; // setbufbase

    //// file handing ///////////////////////
		/// saving to file, executing external commands
    class filebase{

    protected:
      string _fn;

    public:
      filebase( void ): _fn(){};
      filebase( const string & _s ): _fn(_s){};
      filebase( const char * _s ):   _fn(_s){};

    public:
      filebase & save( void );
      filebase & save( const char * );
      filebase & save( const string & );
      filebase & save( ostream &o );
      virtual void print( ostream & )const{} ;
		
    public:
      const filebase & exec( void ) const;
      const filebase & gnu2eps( bool =true ) const;
      const filebase & gnu2ps ( void ) const;
      const filebase & gnu2gif( void ) const;
      const filebase & gnu2png( void ) const;
      const filebase & remove ( void ) const;

    }; // filebase

    ostream & operator << ( ostream &o, const filebase &p );

  } // gp_base

}// gnuplot
    
#endif // __gnuplot_sub_H__
  
  
