/* Implementation of the GETENV g77, and
   GET_ENVIRONMENT_VARIABLE F2003, intrinsics. 
   Copyright (C) 2004 Free Software Foundation, Inc.
   Contributed by Janne Blomqvist.

This file is part of the GNU Fortran 95 runtime library (libgfortran).

Libgfortran is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public
License as published by the Free Software Foundation; either
version 2 of the License, or (at your option) any later version.

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

You should have received a copy of the GNU General Public
License along with libgfortran; see the file COPYING.  If not,
write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
Boston, MA 02111-1307, USA.  */

#include "config.h"
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include "libgfortran.h"


/* GETENV (NAME, VALUE), g77 intrinsic for retrieving the value of
   an environment variable. The name of the variable is specified in
   NAME, and the result is stored into VALUE.  */

void PREFIX(getenv) (char *, char *, gfc_charlen_type, gfc_charlen_type);
export_proto_np(PREFIX(getenv));

void 
PREFIX(getenv) (char * name, char * value, gfc_charlen_type name_len, 
		gfc_charlen_type value_len)
{
  char *name_nt;
  char *res = NULL;
  int res_len;

  if (name == NULL || value == NULL)
    runtime_error ("Both arguments to getenv are mandatory.");

  if (value_len < 1 || name_len < 1)
    runtime_error ("Zero length string(s) passed to getenv.");
  else
    memset (value, ' ', value_len); /* Blank the string.  */

  /* Trim trailing spaces from name.  */
  while (name_len > 0 && name[name_len - 1] == ' ')
    name_len--;

  /* Make a null terminated copy of the string.  */
  name_nt = gfc_alloca (name_len + 1);
  memcpy (name_nt, name, name_len);
  name_nt[name_len] = '\0'; 

  res = getenv(name_nt);

  /* If res is NULL, it means that the environment variable didn't 
     exist, so just return.  */
  if (res == NULL)
    return;

  res_len = strlen(res);
  if (value_len < res_len)
    memcpy (value, res, value_len);
  else
    memcpy (value, res, res_len);
}


/* GET_ENVIRONMENT_VARIABLE (name, [value, length, status, trim_name])
   is a F2003 intrinsic for getting an environment variable.  */

/* Status codes specifyed by the standard. */
#define GFC_SUCCESS 0
#define GFC_VALUE_TOO_SHORT -1
#define GFC_NAME_DOES_NOT_EXIST 1

/* This is also specified by the standard and means that the
   processor doesn't support environment variables.  At the moment,
   gfortran doesn't use it.  */
#define GFC_NOT_SUPPORTED 2

/* Processor-specific failure code.  */
#define GFC_FAILURE 42

extern void get_environment_variable_i4 (char *, char *, GFC_INTEGER_4 *,
					 GFC_INTEGER_4 *, GFC_LOGICAL_4 *,
					 gfc_charlen_type, gfc_charlen_type);
iexport_proto(get_environment_variable_i4);

void
get_environment_variable_i4 (char *name, char *value, GFC_INTEGER_4 *length,
			     GFC_INTEGER_4 *status, GFC_LOGICAL_4 *trim_name,
			     gfc_charlen_type name_len,
			     gfc_charlen_type value_len)
{
  int stat = GFC_SUCCESS, res_len = 0;
  char *name_nt;
  char *res;

  if (name == NULL)
    runtime_error ("Name is required for get_environment_variable.");

  if (value == NULL && length == NULL && status == NULL && trim_name == NULL)
    return;

  if (name_len < 1)
    runtime_error ("Zero-length string passed as name to "
		   "get_environment_variable.");

  if (value != NULL)
    { 
      if (value_len < 1)
	runtime_error ("Zero-length string passed as value to "
		       "get_environment_variable.");
      else
	memset (value, ' ', value_len); /* Blank the string.  */
    }

  if ((!trim_name) || *trim_name)
    {
      /* Trim trailing spaces from name.  */
      while (name_len > 0 && name[name_len - 1] == ' ')
	name_len--;
    }
  /* Make a null terminated copy of the name.  */
  name_nt = gfc_alloca (name_len + 1);
  memcpy (name_nt, name, name_len);
  name_nt[name_len] = '\0'; 
  
  res = getenv(name_nt);

  if (res == NULL)
    stat = GFC_NAME_DOES_NOT_EXIST;
  else
    {
      res_len = strlen(res);
      if (value != NULL)
	{
	  if (value_len < res_len)
	    {
	      memcpy (value, res, value_len);
	      stat = GFC_VALUE_TOO_SHORT;
	    }
	  else
	    memcpy (value, res, res_len);
	}
    }

  if (status != NULL)
    *status = stat;

  if (length != NULL)
    *length = res_len;
}
iexport(get_environment_variable_i4);


/* INTEGER*8 wrapper for get_environment_variable.  */

extern void get_environment_variable_i8 (char *, char *, GFC_INTEGER_8 *,
					 GFC_INTEGER_8 *, GFC_LOGICAL_8 *,
					 gfc_charlen_type, gfc_charlen_type);
export_proto(get_environment_variable_i8);

void
get_environment_variable_i8 (char *name, char *value, GFC_INTEGER_8 *length,
			     GFC_INTEGER_8 *status, GFC_LOGICAL_8 *trim_name,
			     gfc_charlen_type name_len,
			     gfc_charlen_type value_len)
{
  GFC_INTEGER_4 length4, status4;
  GFC_LOGICAL_4 trim_name4;

  if (trim_name)
    trim_name4 = *trim_name;

  get_environment_variable_i4 (name, value, &length4, &status4, 
			       &trim_name4, name_len, value_len);

  if (length)
    *length = length4;

  if (status)
    *status = status4;
}
