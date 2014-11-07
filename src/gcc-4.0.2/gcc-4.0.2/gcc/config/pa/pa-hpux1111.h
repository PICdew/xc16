/* Definitions of target machine for GNU compiler, for HP PA-RISC
   Copyright (C) 2004 Free Software Foundation, Inc.

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2, or (at your option)
any later version.

GCC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with GCC; see the file COPYING.  If not, write to
the Free Software Foundation, 59 Temple Place - Suite 330,
Boston, MA 02111-1307, USA.  */

/* HP-UX 11i multibyte and UNIX 98 extensions.  */
#undef TARGET_HPUX_11_11
#define TARGET_HPUX_11_11 1

#undef SUBTARGET_OPTIONS
#define SUBTARGET_OPTIONS						\
  { "unix=",			&pa_unix_string,			\
    N_("Specify UNIX standard for predefines and linking.\n"		\
       "Supported values are 93, 95 and 98."), 0}

#undef STARTFILE_SPEC
#define STARTFILE_SPEC \
  "%{!shared:%{pg:gcrt0%O%s}%{!pg:%{p:mcrt0%O%s}%{!p:crt0%O%s}} \
     %{munix=95:unix95%O%s}%{!munix=93:%{!munix=95:unix98%O%s}}}"
