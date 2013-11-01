// -*- c++ -*-
// $Header: /home/asanuma/lib/cvsroot/c/gnuplot/gp_plot.h,v 1.1 2004/10/26 23:27:12 asanuma Exp $
//

#ifndef __gp_plot_H__
#define __gp_plot_H__

#ifndef lint
static char *RCSid_gp_plot_h="$Header: /home/asanuma/lib/cvsroot/c/gnuplot/gp_plot.h,v 1.1 2004/10/26 23:27:12 asanuma Exp $";
#endif

#include <vector>
#include <cstdio>

#include "gp_base.h"
#include "gp_components.h"
#include "gp_traits.h"
#include "gp_subplot.h"

//! main namespace for gnuplot++
namespace gnuplotpp{
 
 namespace detail{

  using std::string;
  using std::ostream;
	using std::vector;

  /// core class of plotting corresponds to "plot" command in gnuplot
  /*! interfaces:
	 *    plotfile( ... )
	 *	  plotfunc( ... )
	 *	  set() << set( ... )
	 *	  postset() << set( ... )
	 */
  class plot: 
		 public setbufbase, 
		 // public vector<subplot>,	
		 public contbase<subplot>,
		 public plotbase
	{
		
	private:
		//     typedef vector<subplot> _contbase;
		// 		typedef vector<subplot> _container;
		typedef contbase<subplot>          _contbase;
		typedef _contbase::_container      _container;
		typedef setbufbase                 _bufbase;
		typedef plotbase                   _plotbase;
		typedef subplot                    _subclass;
    
	protected:
		static const int _omit=gpusing::omit;
    
	public:
		plot(void): _plotbase(_pre,_post) {};
		
	private:
		stream_type &prebuf( void ){ return _pre; }
		stream_type &postbuf( void ){ return _post; }
		
	public:
		void print(std::ostream &o )const;
		void initialize( void );
    
		subplot& _plot( void );
		subplot& plotfile( void );
		subplot& plotfunc( void );
		
		template<class C1>
			subplot& plotfile( const C1 fn, 
												 const int u1=gpusing::omit, 
												 const int u2=gpusing::omit ){
			_p.push_back(subfile(fn,u1,u2)); 
			return _p.back();
		}
		
		template<class C1>
			subplot& plotfunc( const C1 fn ){
			_p.push_back(subfunc(fn));
			return _p.back();
		}
      
	}; // class plot
    
  // std::ostream & operator << (std::ostream &o, const plot &p );	
    
  //// class singleplot //////////////
	/// graph with single plot
  class singleplot: public plot, 
										public filebase, 
										public sizebase
	{
		
  private:
    typedef plot                       _base;
    typedef filebase          _filebase;
    typedef sizebase          _sizebase;
		
  public:
    singleplot( void );
    singleplot( const std::string &_s );
    singleplot( const char *_s );

  private:
    singleplot( const singleplot & ){};

  private:
    stream_type &prebuf( void ){ return _pre; }
    stream_type &postbuf( void ){ return _post; }

  public: // output 
    void print( std::ostream & )const;
	
  }; // singleplot

  ///////// class multiplot //////////////////////////
	/////// new stream interface 
	// g.set() << set( .... )
	// g.x.range()
	/// graph with multipleplot
	/*! Each graph can be accessed as
	 *   g[0] ... g[n]
   */
	class multiplot: 
		 public setbufbase, 
		 public contbase<plot>, // _p is vector<plot>
		 public plotbase, 
		 public filebase, 
		 public sizebase
	{

	protected:
		typedef contbase<plot>    _contbase;
		typedef setbufbase        _bufbase;
		typedef plotbase          _plotbase;
		typedef filebase          _filebase;
		typedef sizebase          _sizebase;
		typedef _contbase::_container      _container;
		typedef plot                       _subclass;

	public: // constructor
		multiplot( int n=1 );
		multiplot( const std::string &_s, int n=1 );
		multiplot( const char *_s, int n=1 );

	private:
		//		multiplot( const multiplot & );

	private:
		stream_type &prebuf( void ){ return _pre; }
		stream_type &postbuf( void ){ return _post; }

	public: // iterator
		typedef _container::iterator        iterator;
		typedef _container::const_iterator  const_iterator;
		iterator       begin(void)     { return _p.begin();};
		const_iterator begin(void)const{ return _p.begin();};
		iterator       end  (void)     { return _p.end();};
		const_iterator end  (void)const{ return _p.end();};

		typedef _container::reverse_iterator       reverse_iterator;
		typedef _container::const_reverse_iterator const_reverse_iterator;
		reverse_iterator       rbegin(void)     { return _p.rbegin();};
		const_reverse_iterator rbegin(void)const{ return _p.rbegin();};
		reverse_iterator       rend  (void)     { return _p.rend();};
		const_reverse_iterator rend  (void)const{ return _p.rend();};

	public: // output 
		void print( std::ostream & )const;

	}; // class multiplot 

  ///////// class tableplot //////////////////////////
	/// graph with multiple plot in talbe-like form
		 /*! Each graph can be accessed as
			*   g[0][0] ... g[n][m]
			*    from upper-left to lower-right corner
			*/
  
	class tableplot:
		 public setbufbase, 
		 public contbase<vector<plot> >,
		 public plotbase, 
		 public filebase, 
		 public sizebase
	{
		
	private:
		typedef contbase<vector<plot> >    _contbase;
		typedef setbufbase        _bufbase;
		typedef plotbase          _plotbase;
		typedef filebase          _filebase;
		typedef sizebase          _sizebase;
		//    typedef _contbase::_container      _container;
		typedef vector<plot>          _subcontainer;
		typedef plot                       _subclass;
		
	private:
		int _nx, _ny;
		
	public:
		tableplot( int nx, int ny );
		tableplot( const char *_s, int nx, int ny );
		
	private:
		//tableplot( const tableplot & );
		
	private:
		stream_type &prebuf( void ){ return _pre; }
		stream_type &postbuf( void ){ return _post; }
		
	public:
		void print( std::ostream & )const;
		size_t xsize( void )const{ return _nx; };
		size_t ysize( void )const{ return _ny; };
		
	private:
		void outsize( void ) ;
		
	}; // class tableplot
 
	typedef tableplot gptable;

  ///////// class squareplot //////////////////////////
	/// sigle squared graph with "set size square"
  class squareplot: public singleplot{
  public:
    squareplot( void );
    squareplot( const char *_s ); // not implemented yet

  private:
    squareplot( const squareplot &){};

  public:
    void setsize( double x );
    template<typename C1, typename C2>
    void setrange( const C1 & c1, const C2 &c2 ){
      x.range( c1, c2 ); y.range( c1, c2 );
    }

  private:
    void outsize( void );
		
  }; // class squareplot

	typedef squareplot gpsquare;
 
 }// detail

} // namespace gnuplotpp

#endif // __gp_plot_H__

