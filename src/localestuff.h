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

/* locale support. Adapted from binutils */

#ifndef __LOCALESTUFF_H
#define __LOCALESTUFF_H

/* Take care of NLS matters.  */

#ifdef ENABLE_NLS

#include <libintl.h>
#include <locale.h>
#define _(Text) gettext(Text)

#else

#define setlocale(Category, Locale)		  /* empty */
#define bindtextdomain(Domain, Directory) /* empty */
#define textdomain(Domain)				  /* empty */
#define _(Text) Text

#endif

#endif
