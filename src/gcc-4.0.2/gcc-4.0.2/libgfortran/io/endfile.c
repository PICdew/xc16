/* Copyright (C) 2002-2003 Free Software Foundation, Inc.
   Contributed by Andy Vaught

This file is part of the GNU Fortran 95 runtime library (libgfortran).

Libgfortran is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2, or (at your option)
any later version.

In addition to the permissions in the GNU General Public License, the
Free Software Foundation gives you unlimited permission to link the
compiled version of this file into combinations with other programs,
and to distribute those combinations without any restriction coming
from the use of this file.  (The General Public License restrictions
do apply in other respects; for example, they cover modification of
the file, and distribution when not linked into a combine
executable.)

Libgfortran is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Libgfortran; see the file COPYING.  If not, write to
the Free Software Foundation, 59 Temple Place - Suite 330,
Boston, MA 02111-1307, USA.  */

#include "config.h"
#include "libgfortran.h"
#include "io.h"

/* endfile.c--  Implement the ENDFILE statement */

extern void st_endfile (void);
export_proto(st_endfile);

void
st_endfile (void)
{
  gfc_unit *u;

  library_start ();

  u = get_unit (0);
  if (u != NULL)
    {
      current_unit = u;		/* next_record() needs this set */
      if (u->current_record)
	next_record (1);

      flush(u->s);
      struncate (u->s);
      u->endfile = AFTER_ENDFILE;
    }

  library_end ();
}
