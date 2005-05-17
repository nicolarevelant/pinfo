dnl Process this file with autoconf to produce a configure script.
AC_INIT

dnl The fairly useless --with-tags option to configure requires that
dnl C++ and F77 support be invoked; this makes configure horribly
dnl slow. Obliterating this macro pries the feature out of libtool 1.5; it
dnl is removed in 1.6 in favour of a different scheme.
m4_define([_LT_AC_TAGCONFIG], [])

PACKAGE=pinfo
VERSION=0.6.8
ALL_LINGUAS="pl cs sv de ru ja"

AM_INIT_AUTOMAKE($PACKAGE, $VERSION, no-define)

AM_MAINTAINER_MODE
AM_ACLOCAL_INCLUDE(macros)

AC_PROG_LIBTOOL
AM_INTL_SUBDIR


dnl Checks for programs.
AC_PROG_CC
AC_ISC_POSIX
AC_PROG_INSTALL
AC_PROG_LN_S
AC_PROG_MAKE_SET

dnl Checks for libraries.
AC_CHECK_CURSES
if  test "$has_curses" = false; then
AC_MSG_ERROR([Curses not found. You need curses to compile pinfo])
fi
LIBS="$LIBS $CURSES_LIBS"
CPPFLAGS="$CPPFLAGS $CURSES_INCLUDES"

AC_MSG_CHECKING(for KEY_END in curses)
KEY_END=""
AC_EGREP_CPP(HAVE_KEY_END,
[
#if defined(RENAMED_NCURSES) or !defined(USE_NCURSES)
#include <curses.h>
#else
#include <ncurses.h>
#endif

#ifdef KEY_END
	HAVE_KEY_END
#endif
],
	[AC_DEFINE(HAVE_KEY_END,1,[defined if curses has KEY_END definition]) 
	KEY_END="KEY_END" 
	MAN_KEY_END="End Key"
	AC_MSG_RESULT(yes)],
	[AC_MSG_RESULT(no) 
	KEY_END="\'E\'"
	MAN_KEY_END="E"])

AC_CHECK_READLINE
AM_CONDITIONAL(HAS_READLINE, test "$has_readline" = true)

dnl Checks for header files.

dnl Checks for typedefs, structures, and compiler characteristics.
AC_C_CONST

dnl Checks for library functions.
dnl AC_CHECK_FUNCS(strdup strstr)

dnl Checks for missing functions.
AC_CHECK_FUNCS(getopt_long snprintf)
AC_CHECK_FUNCS(curs_set use_default_colors bkgdset)
dnl AC_CHECK_LIB(ncurses, curs_set, AC_DEFINE(HAS_CURS_SET))
dnl AC_CHECK_LIB(ncurses, use_default_colors, AC_DEFINE(HAS_USE_DEFAULT_COLORS))
AM_CONDITIONAL(HAVE_SNPRINTF,test "x$ac_cv_func_snprintf" = "xyes")

AC_CHECK_FUNC(sigblock,,AC_CHECK_LIB(bsd, sigblock))
if test "x$ac_cv_lib_bsd_sigblock" = "xyes" -o \
	"x$ac_cv_func_sigblock" = "xyes" ; then
	AC_DEFINE(HAVE_SIGBLOCK,1,[Define if have sigblock function])
fi
AM_CONDITIONAL(HAVE_SIGBLOCK,test "x$ac_cv_lib_bsd_sigblock" = "xyes" -o \
        "x$ac_cv_func_sigblock" = "xyes" )

dnl i18n stuff
AM_GNU_GETTEXT_VERSION([0.14.4])
AM_GNU_GETTEXT([external])
dnl TVM:
dnl horrible *temporary* hack to make sure that if we found gettext() in
dnl -lintl that we add -lintl *back* to $LIBS.
dnl
if test X$gt_cv_func_gettext_libintl = Xyes ; then
    LIBS="-lintl $LIBS"
fi

dnl do you want to see cursor when working with pinfo?
AC_ARG_ENABLE(showcursor,[  --enable-cursor         enable cursor when working with pinfo [default=no]], , )

if test "x$enable_showcursor" != "xyes" ; then
	AC_DEFINE(HIDECURSOR,FALSE,[don't show cursor])
else
	AC_DEFINE(HIDECURSOR,TRUE,[don't show cursor])
fi

dnl If you consider pinfo being slow, the bellow definition will resign from
dnl dynamical allocation in critical places, and replace it with static buffers
dnl which should save few instructions to CPU ;)

AC_ARG_ENABLE(use_static,[  --disable-static        enable using static buffers ], ,enable_use_static=yes) 

if test "x$enable_use_static" = "xyes" ; then
	AC_DEFINE(___USE_STATIC___, 1, [don't use dynamic buffer])
fi

AC_ARG_WITH(regexp_search,[  --with-regexp-search    use regexp search [default=yes]])

if test "x$with_regexp_search" = "xno"; then
        AC_DEFINE(___DONT_USE_REGEXP_SEARCH___,1,
			[Don't use regexp search engine])
fi

dnl Specify locale stuff destination
AC_ARG_WITH(localedir,
	[  --with-localedir=PATH      specify where the locale stuff should go ])
if test "x$LOCALEDIR" = "x"; then
	if test "x$with_localedir" != "x"; then
		LOCALEDIR=$with_localedir
	else
		LOCALEDIR='$(prefix)/share/locale'
	fi
fi

CONFIGDIR=${sysconfdir}/pinforc
CPPFLAGS="$CPPFLAGS -DCONFIGDIR=\\\"${sysconfdir}/pinforc\\\" -DLOCALEDIR=\\\"${LOCALEDIR}\\\""

MANDIR="`eval MANDIR=$mandir;echo $MANDIR|sed -e \"s#NONE#$ac_default_prefix#\"`"
AC_DEFINE_UNQUOTED(VERSION,"$VERSION",[Package version])
AC_DEFINE_UNQUOTED(PACKAGE,"$PACKAGE",[Package name])
dnl AC_DEFINE_UNQUOTED(LOCALEDIR,"$LOCALDIR")

dnl export variables
dnl AC_SUBST(CURSES_INCLUDEDIR)
dnl AC_SUBST(CURSES_LIBS)
dnl AC_SUBST(READLINE_INCLUDEDIR)
dnl AC_SUBST(READLINE_LIBS)
AC_SUBST(KEY_END)
AC_SUBST(MAN_KEY_END)
AC_SUBST(EXTRA_SOURCES)
AC_SUBST(MANDIR)

dnl generate files dependig current configuration
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([Makefile doc/Makefile macros/Makefile src/Makefile  
	pinfo.spec po/Makefile.in src/pinforc
	doc/pinfo.1])
AC_OUTPUT