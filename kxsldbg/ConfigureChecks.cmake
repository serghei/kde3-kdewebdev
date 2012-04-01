#################################################
#
#  (C) 2012 Serghei Amelian
#  serghei (DOT) amelian (AT) gmail.com
#
#  Improvements and feedback are welcome
#
#  This file is released under GPL >= 2
#
#################################################

include( CheckFunctionExists )
include( CheckIncludeFiles )


check_include_files( "string.h" HAVE_STRING_H )
check_include_files( "sys/time.h" HAVE_SYS_TIME_H )
check_include_files( "sys/stat.h" HAVE_SYS_STAT_H )
check_include_files( "unistd.h" HAVE_UNISTD_H )
check_include_files( "stdlib.h" HAVE_STDLIB_H )
check_include_files( "stdarg.h" HAVE_STDARG_H )
check_include_files( "time.h" HAVE_TIME_H )
check_include_files( "stdio.h;readline/readline.h" HAVE_READLINE )
check_include_files( "stdio.h;readline/history.h" HAVE_HISTORY )
check_function_exists( gettimeofday HAVE_GETTIMEOFDAY )


# exslt
find_library( EXSLT_LIBRARY exslt )
if( NOT EXSLT_LIBRARY )
  kde_message_fatal( "exslt library (part of libxslt) is required, but was not found on your system" )
endif( )


# pthread
find_library( PTHREAD_LIBRARY pthread )
if( NOT PTHREAD_LIBRARY )
  kde_message_fatal( "pthread library is required, but was not found on your system" )
endif( )


# readline
if( HAVE_READLINE )
  find_library( READLINE_LIBRARY readline )
endif( )
