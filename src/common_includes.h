/***************************************************************************
 *  Pinfo is a ncurses based lynx style info documentation browser
 *
 *  Copyright (C) 1999  Przemek Borys <pborys@dione.ids.pl>
 *  Copyright (C) 2005  Bas Zoetekouw <bas@debian.org>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of version 2 of the GNU General Public License as
 *  published by the Free Software Foundation.
 *
 *  This program is distributed in the hope that it will be useful, but
 *  WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301
 *  USA
 ***************************************************************************/

#ifndef __COMMON_INCLUDES_H
#define __COMMON_INCLUDES_H

/* make sure unistd.h defines sbrk() */
#define _DEFAULT_SOURCE 1
#define _BSD_SOURCE 1

#include <assert.h>
#include <ctype.h>
#include <grp.h>
#include <libgen.h>
#include <pwd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include "config.h"

#if HAVE_NCURSESW_H /* if <ncursesw.h> should be used              */
#include <ncursesw.h>
#elif HAVE_NCURSESW_CURSES_H /* if <ncursesw/curses.h> should be used       */
#include <ncursesw/curses.h>
#elif HAVE_NCURSES_H /* if <ncurses.h> should be used               */
#include <ncurses.h>
#elif HAVE_NCURSES_CURSES_H /* if <ncurses/curses.h> should be used        */
#include <ncurses/curses.h>
#elif HAVE_CURSES_H /* if <curses.h> is present and should be used */
#include <curses.h>
#else
#error "No valid curses headers detected"
#endif

#include "localestuff.h"

#include "colors.h"
#include "datatypes.h"
#include "filehandling_functions.h"
#include "initializelinks.h"
#include "keyboard.h"
#include "mainfunction.h"
#include "manual.h"
#include "menu_and_note_utils.h"
#include "parse_config.h"
#include "printinfo.h"
#include "regexp_search.h"
#include "signal_handler.h"
#include "utils.h"
#include "video.h"

/* somewhat portable way of flagging unused vars
 * from
 * https://stackoverflow.com/questions/7090998/portable-unused-parameter-macro-used-on-function-signature-for-c-and-c
 */
#ifdef UNUSED
#elif defined(__GNUC__)
#define UNUSED(x) x __attribute__((unused))
#elif defined(__LCLINT__)
#define UNUSED(x) /*@unused@*/ x
#elif defined(__cplusplus)
#define UNUSED(x)
#else
#define UNUSED(x) x
#endif

#endif /* __COMMON_INCLUDES_H */
