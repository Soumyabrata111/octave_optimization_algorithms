////////////////////////////////////////////////////////////////////////
//
// Copyright (C) 2018-2023 The Octave Project Developers
//
// See the file COPYRIGHT.md in the top-level directory of this
// distribution or <https://octave.org/copyright/>.
//
// This file is part of Octave.
//
// Octave is free software: you can redistribute it and/or modify it
// under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Octave is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Octave; see the file COPYING.  If not, see
// <https://www.gnu.org/licenses/>.
//
////////////////////////////////////////////////////////////////////////

#if defined (HAVE_CONFIG_H)
#  include "config.h"
#endif

#include "iconv.h"

#include "iconv-wrappers.h"

void *
octave_iconv_open_wrapper (const char *tocode, const char *fromcode)
{
  return (void *) iconv_open (tocode, fromcode);
}

int
octave_iconv_close_wrapper (void *cd)
{
  return iconv_close ((iconv_t) cd);
}

void
octave_iconvlist_wrapper (int (*do_one) (unsigned int namescount,
                                         const char * const *names,
                                         void *data),
                          void *data)
{
#if defined (HAVE_ICONVLIST)
  iconvlist (do_one, data);
#else
  octave_unused_parameter (do_one);
  octave_unused_parameter (data);
#endif

  return;
}

const char *
octave_iconv_canonicalize_wrapper (const char *name)
{
#if defined (HAVE_ICONV_CANONICALIZE)
  return iconv_canonicalize (name);
#else
  return name;
#endif
}
