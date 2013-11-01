/* $Header: /home/asanuma/lib/cvsroot/c/process.c,v 1.2 2002/06/18 12:16:45 asanuma Exp $ */
/*   $Log: process.c,v $
/*   Revision 1.2  2002/06/18 12:16:45  asanuma
/*   just for compatibility
/*
/*   Revision 1.1  1999/03/26 13:20:45  asanuma
/*   Initial revision
/*  */

#ifndef lint
static char *RCSid_Spawn_C="$Header: /home/asanuma/lib/cvsroot/c/process.c,v 1.2 2002/06/18 12:16:45 asanuma Exp $";
#endif

#ifdef unix
#include <unistd.h>
#include <sys/wait.h>
#endif
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#ifndef   __TURBOC__
#include "process.h"

#ifdef unix
int spawnv( const char *path, char *const argv[] ){
  int pid, status;
  if( (pid=fork()) < 0 ){
    perror( "fork" );
    exit(1);
  }
  if( pid==0 ){
    execv( path, argv );
    perror( path );
    exit(1);
  }
  while( wait(&status) != pid );
  return( status );
}

int spawnl( const char *path, ... ){
  va_list argp;
  char *p, **cmd;
  int n=0, i;
  va_start( argp, path );
  while( (p=va_arg(argp, char *)) != NULL )
    n++;
  va_end(argp);
  cmd=calloc( n+2, sizeof(char *) );
  
  va_start( argp, path );
  for( i=0;  i<=n; i++ ){
    p=va_arg(argp, char *);
    cmd[i]=p;
  }
  cmd[n+1]=NULL;
  va_end(argp);
  
  free(cmd);
  
  return( spawnv( path, cmd ) );
}

int spawnvp( const char *path, char *const argv[] ){
  /* check the type of second argument */
  int pid, status;
  if( (pid=fork()) < 0 ){
    perror( "fork" );
    exit(1);
  }
  if( pid==0 ){
    execvp( path, argv );
    perror( path );
    exit(1);
  }
  while( wait(&status) != pid );
  if( status!=0 ){
    perror("Exec:");
    exit(1);
  } 
  return( status );
}

int spawnlp( const char *path, ... ){
  va_list argp;
  char *p, **cmd;
  int n=0, i;
  va_start( argp, path );
  while( (p=va_arg(argp, char *)) != NULL )
    n++;
  va_end(argp);
  cmd=calloc( n+2, sizeof(char *) );
  
  va_start( argp, path );
  for( i=0;  i<=n; i++ ){
    p=va_arg(argp, char *);
    cmd[i]=p;
  }
  cmd[n+1]=NULL;
  va_end(argp);
  
  free( cmd );
  
  return( spawnvp( path, cmd ) );
}
#endif  /* unix */
#endif  /* TURBO_C */
