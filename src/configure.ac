#                                               -*- Autoconf -*-
#
# Process this file with autoconf to produce a configure script.
#

# IBEN, An Interactive BDD Environment
# Copyright (C) 2003 Gerd Behrmann
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA


AC_PREREQ(2.57)
AC_INIT([iben],[1.1],[behrmann@cs.auc.dk])
AM_INIT_AUTOMAKE
AC_CONFIG_SRCDIR([input.ll])
AC_CONFIG_HEADER([config.h])

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC
AM_PROG_LEX
AC_PROG_YACC

# Checks for libraries.
VL_LIB_READLINE
AC_CHECK_LIB([m],[pow], [], [
  AC_MSG_ERROR("cannot find math library")
])
AC_CHECK_LIB([bdd], [bdd_init], [], [
  AC_MSG_ERROR("cannot find BuDDy library")
])

# Checks for libraries.

# Checks for header files.
AC_HEADER_STDC
AC_HEADER_SYS_WAIT
AC_CHECK_HEADERS([stddef.h stdlib.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_C_CONST
AC_HEADER_STDBOOL
AC_TYPE_SIZE_T

# Checks for library functions.
AC_FUNC_FORK
AC_FUNC_MALLOC
AC_FUNC_REALLOC

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
