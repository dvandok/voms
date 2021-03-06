dnl Usage:
dnl AC_EXPAT(MINIMUM-VERSION, [ACTION-IF-FOUND [, ACTION-IF-NOT-FOUND]]])
dnl Test for expat, and defines
dnl - EXPAT_CFLAGS (compiler flags)
dnl - EXPAT_LIBS (linker flags, stripping and path)
dnl - EXPAT_STATIC_LIBS (linker flags, stripping and path for static library)
dnl - EXPAT_INSTALL_PATH
dnl prerequisites:

AC_DEFUN([AC_EXPAT],
[
    AC_ARG_WITH(expat_prefix, 
	[  --with-expat-prefix=PFX      prefix where 'expat' is installed.],
	[], 
        with_expat_prefix=${EXPAT_INSTALL_PATH:-/usr})

    AC_MSG_CHECKING([for EXPAT installation at ${with_expat_prefix:-/usr}])

    ac_save_CFLAGS=$CFLAGS
    ac_save_LIBS=$LIBS
    if test -n "$with_expat_prefix" -a "$with_expat_prefix" != "/usr" ; then
      EXPAT_CFLAGS="-I$with_expat_prefix/include"
    	EXPAT_LIBS="-L$with_expat_prefix/lib"
      EXPAT_LIBS64="-L$with_expat_prefix/lib64"
    else
    	EXPAT_CFLAGS=""
#      EXPAT_LIBS="-L/usr/lib"
#      EXPAT_LIBS64="-L/usr/lib64"
      EXPAT_LIBS=""
      EXPAT_LIBS64=""
    fi

    EXPAT_LIBS="$EXPAT_LIBS -lexpat"	
    EXPAT_LIBS64="$EXPAT_LIBS64 -lexpat"
    CFLAGS="$EXPAT_CFLAGS $CFLAGS"
    LIBS="$EXPAT_LIBS $LIBS"
    AC_TRY_LINK([ #include <expat.h> ],
    		   [ const XML_LChar *ev = XML_ExpatVersion() ],
    		   [ ac_cv_expat_valid=yes ], [ ac_cv_expat_valid=no ])

    LIBS=$ac_save_LIBS	
    LIBS="$EXPAT_LIBS64 $LIBS"
    AC_TRY_LINK([ #include <expat.h> ],
    		   [ const XML_LChar *ev = XML_ExpatVersion() ],
    		   [ ac_cv_expat_valid64=yes ], [ ac_cv_expat_valid64=no ])

    CFLAGS=$ac_save_CFLAGS
    LIBS=$ac_save_LIBS	

#    echo "ac_cv_expat_valid=$ac_cv_expat_valid"
#    echo "ac_cv_expat_valid64=$ac_cv_expat_valid64"
    if test x$ac_cv_expat_valid64 = xyes ; then
      EXPAT_INSTALL_PATH=$with_expat_prefix
    	EXPAT_STATIC_LIBS="$with_expat_prefix/lib/libexpat.a"
#      EXPAT_LIBS="-L$with_expat_prefix/lib64 -lexpat"
      EXPAT_LIBS=$EXPAT_LIBS64
      AC_MSG_RESULT([$ac_cv_expat_valid64 (in lib64)])
    	ifelse([$2], , :, [$2])
    elif test x$ac_cv_expat_valid = xyes ; then
      EXPAT_INSTALL_PATH=$with_expat_prefix
    	EXPAT_STATIC_LIBS="$with_expat_prefix/lib/libexpat.a"
      AC_MSG_RESULT([$ac_cv_expat_valid (in lib)])
    	ifelse([$2], , :, [$2])
    else
    	EXPAT_CFLAGS=""
    	EXPAT_LIBS=""
    	ifelse([$3], , :, [$3])
    fi

    AC_SUBST(EXPAT_INSTALL_PATH)
    AC_SUBST(EXPAT_CFLAGS)
    AC_SUBST(EXPAT_LIBS)
    AC_SUBST(EXPAT_STATIC_LIBS)
])

