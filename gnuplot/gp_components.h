// -*- c++ -*-
// $Header: /home/asanuma/lib/cvsroot/c/gnuplot/gp_components.h,v 1.4 2004/10/26 23:27:06 asanuma Exp $
//

#ifndef __GP_COMPONENTS_H__
#define __GP_COMPONENTS_H__

#ifndef lint
static char *RCSid_gp_components="$Header: /home/asanuma/lib/cvsroot/c/gnuplot/gp_components.h,v 1.4 2004/10/26 23:27:06 asanuma Exp $";
#endif

#include <utility>

namespace gnuplotpp{

 namespace detail{

	using namespace std;

	//// helpers //////

	string quote( const char *s );
	string quote( const string &s );

	////////////////////////////////////////////////////
	class gplimit: public string{
		
	public:
	 gplimit( void ): string(){};
		
	 template<class C>
	 gplimit( const C x ){	
		ostringstream o; o<<x;	append(o.str() );
	 };
	 //	  template<>
	 gplimit( const bool b ){ if(b) append("*"); };
	 gplimit( const char *s){  assign( quote(s) ); };
	 gplimit( const string &s){assign( quote(s) ); };
	
	}; // class gplimit
      
	////////////////////////////////////////////////////
	class gprange: public pair<gplimit,gplimit>{
	private:
	 typedef pair<gplimit,gplimit> _base;
	
	public:
	 explicit gprange(void): _base() {};
	
	 template <class T1, class T2>
	 gprange( T1 x1, T2 x2 ): _base(x1,x2){};
	
	 template<class C1, class C2>
	 gprange& set( const C1 &c1, const C2 &c2){
		first=c1; second=c2;
	 }
	
	}; // class gprange
      
	ostream& operator<< (std::ostream &s, const gprange &a);
	///////////// set command//////////////////////////////////////
      
	class gpset: public string{ // set command interpreter
	private:
	
	public:
	 gpset( void ): string(){};
	
	 template<class C>
	 gpset( const C &s ): string("set "){ 
		append( string(s) ); append( "\n" );}
	
	 template<class C1, class C2>
	 gpset( const C1 k, const C2 v ): string("set "){
		ostringstream o;
		o << k <<  " " << v; 
		append(o.str()); 
	 };
	
	 template<class C1, class C2, class C3>
	 gpset( const C1 k, const C2 a, const C3 b ): string("set "){
		ostringstream o;
		o << k << " " << a << " " << b;
		*this +=o.str();
	 };
	
	 template<class C1, class C2, class C3, class C4>
	 gpset( const C1 k, const C2 a, const C3 b, const C4 c ): string("set "){
		ostringstream o;
		o << k << " " << a << " " << b << " " << c;
		*this +=o.str();
	 };
	
	}; // class gpset
      
	class gpsetrange: public gpset{
	
	public:
	 template <class C, class T1, class T2>
	 gpsetrange( const C k, const T1 x1, const T2 x2 ):
		gpset( string(k)+"range", gprange(x1,x2) ){};
	
	}; // class gpsetrange
      

	////////// using ///////////////
      
	class gpusing: public string{
	public:
	 static const int omit=-1;

	 template<typename C1, typename C2>
	 gpusing( const C1& u1, const C2 u2 ): string() {
		ostringstream os;	os << " using " << u1 << ":" << u2;
		assign( os.str() );
	 }

	 template<typename C1>
	 gpusing( const C1& u1 ): string() {
		ostringstream os;	os << " using " << u1;
		assign( os.str() );
	 }

	 gpusing( const int u1=omit, const int u2=omit );

	}; // class gpusing

	//// class gpcoord ///////////
	class gpcoord: public string{
	 //// gpcoord( x, y );
	public:
	 gpcoord( void ): string(){};

	 template<class C1, class C2>
	 gpcoord( const C1& x, const C2& y ): string(){
		ostringstream o;
		o << x <<  ", " << y; 
		assign(o.str()); 
	 };
	 template<class C1, class C2>
	 gpcoord( const char *c, const C1& x, const C2& y ): string(){
		ostringstream o;
		o << c << " " << x <<  ", " << y; 
		assign(o.str()); 
	 };

	 template<class C1, class C2>
	 gpcoord( const char *c1, const C1& x, const char *c2, const C2& y ): 
		string(){
		ostringstream o;
		o << c1 << " " << x <<  ", " << c2 << " " << y; 
		assign(o.str()); 
	 };

	}; // gpcoord

	//// lines & arrows ///////
	//// class gpline //////
	class gparrow: public gpset{
	public:
	 gparrow( int n, const gpcoord &v1, const gpcoord &v2 );
	}; // gparrow

	class gpline: public gparrow{
	public:
	 gpline( int n, const gpcoord &v1, const gpcoord &v2 );
	}; // gpline

	class gpvline: public gpline{

	public:
	 template<typename C1, typename C2, typename C3>
	 gpvline( int n, const C1& x, const C2& y1, const C3& y2 ): 
		gpline( n, gpcoord(x,y1), gpcoord(x,y2) ){
	 }
	}; // gpvline

	class gphline: public gpline{

	public:
	 template<typename C1, typename C2, typename C3>
	 gphline( int n, const C1& x1, const C2& x2, const C3& y ): 
		gpline( n, gpcoord(x1,y), gpcoord(x2,y) ){
	 }

	}; // gphline

	 
	 


 }// components

}// gnuplot
      
#endif // __GP_PARTS_H__
      
