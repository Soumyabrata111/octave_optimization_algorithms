// DO NOT EDIT!  Generated automatically by subst-default-vals.
/*

Copyright (C) 1996-2017 John W. Eaton

This file is part of Octave.

Octave is free software; you can redistribute it and/or modify it
under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3 of the License, or
(at your option) any later version.

Octave is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Octave; see the file COPYING.  If not, see
<http://www.gnu.org/licenses/>.

*/

#if defined (HAVE_CONFIG_H)
#  include "config.h"
#endif

#include <cstdlib>

#include <algorithm>
#include <iostream>
#include <string>

#include "dir-ops.h"
#include "oct-env.h"
#include "file-stat.h"
#include "pathsearch.h"
#include "str-vec.h"

#include "defaults.h"
#include "defun.h"
#include "error.h"
#include "file-ops.h"
#include "errwarn.h"
#include "help.h"
#include "input.h"
#include "load-path.h"
#include "ovl.h"
#include "ov.h"
#include "parse.h"
#include "interpreter.h"
#include "unwind-prot.h"
#include "variables.h"
#include "version.h"

// These are used by functions declared in defaults.h and defined in
// defaults.cc.

#if ! defined (OCTAVE_CANONICAL_HOST_TYPE)
#  define OCTAVE_CANONICAL_HOST_TYPE %OCTAVE_CANONICAL_HOST_TYPE%
#endif

#if ! defined (OCTAVE_RELEASE)
#  define OCTAVE_RELEASE %OCTAVE_RELEASE%
#endif

#if ! defined (OCTAVE_DEFAULT_PAGER)
#  define OCTAVE_DEFAULT_PAGER %OCTAVE_DEFAULT_PAGER%
#endif

#if ! defined (OCTAVE_PREFIX)
#  define OCTAVE_PREFIX %OCTAVE_PREFIX%
#endif

#if ! defined (OCTAVE_EXEC_PREFIX)
#  define OCTAVE_EXEC_PREFIX %OCTAVE_EXEC_PREFIX%
#endif

#if ! defined (OCTAVE_BINDIR)
#  define OCTAVE_BINDIR %OCTAVE_BINDIR%
#endif

#if ! defined (OCTAVE_DATADIR)
#  define OCTAVE_DATADIR %OCTAVE_DATADIR%
#endif

#if ! defined (OCTAVE_DATAROOTDIR)
#  define OCTAVE_DATAROOTDIR %OCTAVE_DATAROOTDIR%
#endif

#if ! defined (OCTAVE_INCLUDEDIR)
#  define OCTAVE_INCLUDEDIR %OCTAVE_INCLUDEDIR%
#endif

#if ! defined (OCTAVE_LIBDIR)
#  define OCTAVE_LIBDIR %OCTAVE_LIBDIR%
#endif

#if ! defined (OCTAVE_LIBEXECDIR)
#  define OCTAVE_LIBEXECDIR %OCTAVE_LIBEXECDIR%
#endif

#if ! defined (OCTAVE_LOCALVERARCHLIBDIR)
#  define OCTAVE_LOCALVERARCHLIBDIR %OCTAVE_LOCALVERARCHLIBDIR%
#endif

#if ! defined (OCTAVE_LOCALAPIARCHLIBDIR)
#  define OCTAVE_LOCALAPIARCHLIBDIR %OCTAVE_LOCALAPIARCHLIBDIR%
#endif

#if ! defined (OCTAVE_LOCALARCHLIBDIR)
#  define OCTAVE_LOCALARCHLIBDIR %OCTAVE_LOCALARCHLIBDIR%
#endif

#if ! defined (OCTAVE_ARCHLIBDIR)
#  define OCTAVE_ARCHLIBDIR %OCTAVE_ARCHLIBDIR%
#endif

#if ! defined (OCTAVE_LOCALVEROCTFILEDIR)
#  define OCTAVE_LOCALVEROCTFILEDIR %OCTAVE_LOCALVEROCTFILEDIR%
#endif

#if ! defined (OCTAVE_LOCALAPIOCTFILEDIR)
#  define OCTAVE_LOCALAPIOCTFILEDIR %OCTAVE_LOCALAPIOCTFILEDIR%
#endif

#if ! defined (OCTAVE_LOCALOCTFILEDIR)
#  define OCTAVE_LOCALOCTFILEDIR %OCTAVE_LOCALOCTFILEDIR%
#endif

#if ! defined (OCTAVE_OCTFILEDIR)
#  define OCTAVE_OCTFILEDIR %OCTAVE_OCTFILEDIR%
#endif

#if ! defined (OCTAVE_LOCALVERFCNFILEDIR)
#  define OCTAVE_LOCALVERFCNFILEDIR %OCTAVE_LOCALVERFCNFILEDIR%
#endif

#if ! defined (OCTAVE_LOCALAPIFCNFILEDIR)
#  define OCTAVE_LOCALAPIFCNFILEDIR %OCTAVE_LOCALAPIFCNFILEDIR%
#endif

#if ! defined (OCTAVE_LOCALFCNFILEDIR)
#  define OCTAVE_LOCALFCNFILEDIR %OCTAVE_LOCALFCNFILEDIR%
#endif

#if ! defined (OCTAVE_FCNFILEDIR)
#  define OCTAVE_FCNFILEDIR %OCTAVE_FCNFILEDIR%
#endif

#if ! defined (OCTAVE_OCTDATADIR)
#  define OCTAVE_OCTDATADIR %OCTAVE_OCTDATADIR%
#endif

#if ! defined (OCTAVE_OCTETCDIR)
#  define OCTAVE_OCTETCDIR %OCTAVE_OCTETCDIR%
#endif

#if ! defined (OCTAVE_OCTINCLUDEDIR)
#  define OCTAVE_OCTINCLUDEDIR %OCTAVE_OCTINCLUDEDIR%
#endif

#if ! defined (OCTAVE_OCTLIBDIR)
#  define OCTAVE_OCTLIBDIR %OCTAVE_OCTLIBDIR%
#endif

#if ! defined (OCTAVE_OCTLOCALEDIR)
#  define OCTAVE_OCTLOCALEDIR %OCTAVE_OCTLOCALEDIR%
#endif

#if ! defined (OCTAVE_OCTTESTSDIR)
#  define OCTAVE_OCTTESTSDIR %OCTAVE_OCTTESTSDIR%
#endif

#if ! defined (OCTAVE_INFODIR)
#  define OCTAVE_INFODIR %OCTAVE_INFODIR%
#endif

#if ! defined (OCTAVE_MANDIR)
#  define OCTAVE_MANDIR %OCTAVE_MANDIR%
#endif

#if ! defined (OCTAVE_MAN1DIR)
#  define OCTAVE_MAN1DIR %OCTAVE_MAN1DIR%
#endif

#if ! defined (OCTAVE_MAN1EXT)
#  define OCTAVE_MAN1EXT %OCTAVE_MAN1EXT%
#endif

#if ! defined (OCTAVE_IMAGEDIR)
#  define OCTAVE_IMAGEDIR %OCTAVE_IMAGEDIR%
#endif

#if ! defined (OCTAVE_LOCALSTARTUPFILEDIR)
#  define OCTAVE_LOCALSTARTUPFILEDIR %OCTAVE_LOCALSTARTUPFILEDIR%
#endif

#if ! defined (OCTAVE_STARTUPFILEDIR)
#  define OCTAVE_STARTUPFILEDIR %OCTAVE_STARTUPFILEDIR%
#endif

// These are used by variables defined in other files.  Maybe they
// should be moved?  Or maybe it is best to have just one generated file
// containing variable substitutions?

#if ! defined (OCTAVE_INFOFILE)
#  define OCTAVE_INFOFILE %OCTAVE_INFOFILE%
#endif

#if ! defined (OCTAVE_TEXI_MACROS_FILE)
#  define OCTAVE_TEXI_MACROS_FILE %OCTAVE_TEXI_MACROS_FILE%
#endif

#if ! defined (OCTAVE_DOC_CACHE_FILE)
#  define OCTAVE_DOC_CACHE_FILE %OCTAVE_DOC_CACHE_FILE%
#endif

static bool initialized = false;

static std::string Voctave_home;
static std::string Voctave_exec_home;

static std::string Vbin_dir;
static std::string Vdata_dir;
static std::string Vdataroot_dir;
static std::string Vinclude_dir;
static std::string Vlib_dir;
static std::string Vlibexec_dir;

static std::string Vlocal_ver_arch_lib_dir;
static std::string Vlocal_api_arch_lib_dir;
static std::string Vlocal_arch_lib_dir;
static std::string Varch_lib_dir;

static std::string Vlocal_ver_oct_file_dir;
static std::string Vlocal_api_oct_file_dir;
static std::string Vlocal_oct_file_dir;
static std::string Voct_file_dir;

static std::string Vlocal_ver_fcn_file_dir;
static std::string Vlocal_api_fcn_file_dir;
static std::string Vlocal_fcn_file_dir;
static std::string Vfcn_file_dir;

static std::string Voct_data_dir;
static std::string Voct_etc_dir;
static std::string Voct_include_dir;
static std::string Voct_lib_dir;
static std::string Voct_locale_dir;
static std::string Voct_tests_dir;

static std::string Vinfo_dir;

static std::string Vman_dir;
static std::string Vman1_dir;
static std::string Vman1_ext;

static std::string Vimage_dir;

static std::string Vlocal_startupfile_dir;
static std::string Vstartupfile_dir;

static std::string Vlocal_site_defaults_file;
static std::string Vsite_defaults_file;

// FIXME: these may be changed by users.  Maybe they should be defined
// somewhere else?

std::string Vbuilt_in_docstrings_file;

// The path that will be searched for programs that we execute.
// (--exec-path path)
std::string VEXEC_PATH;

// Name of the editor to be invoked by the edit_history command.
std::string VEDITOR;

std::string VIMAGE_PATH;

// Variables that name directories or files are substituted into source
// files with "${prefix}/" stripped from the beginning of the string.

// All configure variables of this form should be specified as absolute
// directory names.  The only ones that should not be absolute here are
// ones that have had "${prefix}/" or "${exec_prefix} stripped.

static std::string
prepend_home_dir (const std::string& hd, const std::string& s)
{
  std::string retval = s;

  char dir_sep_char = octave::sys::file_ops::dir_sep_char ();

  if (! octave::sys::env::absolute_pathname (retval))
    retval = hd + dir_sep_char + s;

  if (dir_sep_char != '/')
    std::replace (retval.begin (), retval.end (), '/', dir_sep_char);

  return retval;
}

static std::string
prepend_octave_home (const std::string& s)
{
  return prepend_home_dir (Voctave_home, s);
}

static std::string
prepend_octave_exec_home (const std::string& s)
{
  return prepend_home_dir (Voctave_exec_home, s);
}

static void
set_octave_home (void)
{
  std::string op = OCTAVE_PREFIX;
  std::string oep = OCTAVE_EXEC_PREFIX;

  std::string oh = octave::sys::env::getenv ("OCTAVE_HOME");
  std::string oeh = octave::sys::env::getenv ("OCTAVE_EXEC_HOME");

  // If OCTAVE_HOME is set in the enviornment, use that.  Otherwise,
  // default to ${prefix} from configure.

  Voctave_home = (oh.empty () ? op : oh);

  // If OCTAVE_EXEC_HOME is set in the environment, use that.
  // Otherwise, if ${prefix} and ${exec_prefix} from configure are set
  // to the same value, use OCTAVE_HOME from the environment if it is set.
  // Othewise, default to ${exec_prefix} from configure.

  if (! oeh.empty ())
    Voctave_exec_home = oeh;
  else
    {
      if (op == oep && ! oh.empty ())
        Voctave_exec_home = oh;
      else
        Voctave_exec_home = oep;
    }
}

static void
set_local_site_defaults_file (void)
{
  std::string lsf = octave::sys::env::getenv ("OCTAVE_SITE_INITFILE");

  if (lsf.empty ())
    Vlocal_site_defaults_file = Vlocal_startupfile_dir + "/octaverc";
  else
    Vlocal_site_defaults_file = lsf;
}

static void
set_site_defaults_file (void)
{
  std::string sf = octave::sys::env::getenv ("OCTAVE_VERSION_INITFILE");

  if (sf.empty ())
    Vsite_defaults_file = Vstartupfile_dir + "/octaverc";
  else
    Vsite_defaults_file = sf;
}

void
init_defaults (void)
{
  if (initialized)
    return;

  // OCTAVE_HOME must be set first!

  set_octave_home ();

  Vbin_dir = prepend_octave_exec_home (OCTAVE_BINDIR);
  Vdata_dir = prepend_octave_home (OCTAVE_DATADIR);
  Vdataroot_dir = prepend_octave_home (OCTAVE_DATAROOTDIR);
  Vinclude_dir = prepend_octave_home (OCTAVE_INCLUDEDIR);
  Vlib_dir = prepend_octave_exec_home (OCTAVE_LIBDIR);
  Vlibexec_dir = prepend_octave_exec_home (OCTAVE_LIBEXECDIR);

  Vlocal_ver_arch_lib_dir = prepend_octave_exec_home (OCTAVE_LOCALVERARCHLIBDIR);
  Vlocal_api_arch_lib_dir = prepend_octave_exec_home (OCTAVE_LOCALAPIARCHLIBDIR);
  Vlocal_arch_lib_dir = prepend_octave_exec_home (OCTAVE_LOCALARCHLIBDIR);
  Varch_lib_dir = prepend_octave_exec_home (OCTAVE_ARCHLIBDIR);

  Vlocal_ver_oct_file_dir = prepend_octave_exec_home (OCTAVE_LOCALVEROCTFILEDIR);
  Vlocal_api_oct_file_dir = prepend_octave_exec_home (OCTAVE_LOCALAPIOCTFILEDIR);
  Vlocal_oct_file_dir = prepend_octave_exec_home (OCTAVE_LOCALOCTFILEDIR);
  Voct_file_dir = prepend_octave_exec_home (OCTAVE_OCTFILEDIR);

  Vlocal_ver_fcn_file_dir = prepend_octave_home (OCTAVE_LOCALVERFCNFILEDIR);
  Vlocal_api_fcn_file_dir = prepend_octave_home (OCTAVE_LOCALAPIFCNFILEDIR);
  Vlocal_fcn_file_dir = prepend_octave_home (OCTAVE_LOCALFCNFILEDIR);
  Vfcn_file_dir = prepend_octave_home (OCTAVE_FCNFILEDIR);

  Voct_data_dir = prepend_octave_home (OCTAVE_OCTDATADIR);
  Voct_etc_dir = prepend_octave_home (OCTAVE_OCTETCDIR);
  Voct_include_dir = prepend_octave_home (OCTAVE_OCTINCLUDEDIR);
  Voct_lib_dir = prepend_octave_exec_home (OCTAVE_OCTLIBDIR);
  Voct_locale_dir = prepend_octave_home (OCTAVE_OCTLOCALEDIR);
  Voct_tests_dir = prepend_octave_home (OCTAVE_OCTTESTSDIR);

  Vinfo_dir = prepend_octave_home (OCTAVE_INFODIR);

  Vman_dir = prepend_octave_home (OCTAVE_MANDIR);
  Vman1_dir = prepend_octave_home (OCTAVE_MAN1DIR);
  Vman1_ext = OCTAVE_MAN1EXT;

  Vimage_dir = prepend_octave_home (OCTAVE_IMAGEDIR);

  Vlocal_startupfile_dir = prepend_octave_home (OCTAVE_LOCALSTARTUPFILEDIR);
  Vstartupfile_dir = prepend_octave_home (OCTAVE_STARTUPFILEDIR);

  set_local_site_defaults_file ();

  set_site_defaults_file ();

  initialized = true;
}

static void
set_default_info_file (void)
{
  if (Vinfo_file.empty ())
    {
      std::string std_info_file = prepend_octave_home (OCTAVE_INFOFILE);

      std::string oct_info_file = octave::sys::env::getenv ("OCTAVE_INFO_FILE");

      Vinfo_file = (oct_info_file.empty () ? std_info_file : oct_info_file);
    }
}

static void
set_default_info_prog (void)
{
  if (Vinfo_program.empty ())
    {
      std::string oct_info_prog = octave::sys::env::getenv ("OCTAVE_INFO_PROGRAM");

      if (oct_info_prog.empty ())
        Vinfo_program = "info";
      else
        Vinfo_program = std::string (oct_info_prog);
    }
}

static void
set_default_texi_macros_file (void)
{
  if (Vtexi_macros_file.empty ())
    {
      std::string def_file = prepend_octave_home (OCTAVE_TEXI_MACROS_FILE);

      std::string env_file = octave::sys::env::getenv ("OCTAVE_TEXI_MACROS_FILE");

      Vtexi_macros_file = (env_file.empty () ? def_file : env_file);
    }
}

static void
set_default_doc_cache_file (void)
{
  if (Vdoc_cache_file.empty ())
    {
      std::string def_file = prepend_octave_home (OCTAVE_DOC_CACHE_FILE);

      std::string env_file = octave::sys::env::getenv ("OCTAVE_DOC_CACHE_FILE");

      Vdoc_cache_file = (env_file.empty () ? def_file : env_file);
    }
}

static void
set_built_in_docstrings_file (void)
{
  if (Vbuilt_in_docstrings_file.empty ())
    {
      std::string df = octave::sys::env::getenv ("OCTAVE_BUILT_IN_DOCSTRINGS_FILE");

      if (df.empty ())
        Vbuilt_in_docstrings_file
          = Voct_etc_dir + octave::sys::file_ops::dir_sep_str () + "built-in-docstrings";
      else
        Vbuilt_in_docstrings_file = df;
    }
}

void
install_defaults (void)
{
  // In case this hasn't been done yet...
  init_defaults ();

  set_default_info_file ();

  set_default_info_prog ();

  set_default_texi_macros_file ();

  set_default_doc_cache_file ();

  set_built_in_docstrings_file ();
}

#define RETURN(VAR)                             \
  if (! initialized)                            \
    init_defaults ();                           \
  return VAR;

namespace octave
{
  namespace config
  {
    std::string canonical_host_type (void) { return OCTAVE_CANONICAL_HOST_TYPE; }

    std::string release (void) { return OCTAVE_RELEASE; }

    std::string default_pager (void) { return OCTAVE_DEFAULT_PAGER; }

    std::string octave_home (void) { RETURN (Voctave_home); }
    std::string octave_exec_home (void) { RETURN (Voctave_exec_home); }

    std::string bin_dir (void) { RETURN (Vbin_dir); }
    std::string data_dir (void) { RETURN (Vdata_dir); }
    std::string dataroot_dir (void) { RETURN (Vdataroot_dir); }
    std::string include_dir (void) { RETURN (Vinclude_dir); }
    std::string lib_dir (void) { RETURN (Vlib_dir); }
    std::string libexec_dir (void) { RETURN (Vlibexec_dir); }
    std::string arch_lib_dir (void) { RETURN (Varch_lib_dir); }
    std::string info_dir (void) { RETURN (Vinfo_dir); }

    std::string local_ver_arch_lib_dir (void) { RETURN (Vlocal_ver_arch_lib_dir); }
    std::string local_api_arch_lib_dir (void) { RETURN (Vlocal_api_arch_lib_dir); }
    std::string local_arch_lib_dir (void) { RETURN (Vlocal_arch_lib_dir); }

    std::string local_ver_oct_file_dir (void) { RETURN (Vlocal_ver_oct_file_dir); }
    std::string local_api_oct_file_dir (void) { RETURN (Vlocal_api_oct_file_dir); }
    std::string local_oct_file_dir (void) { RETURN (Vlocal_oct_file_dir); }
    std::string oct_file_dir (void) { RETURN (Voct_file_dir); }

    std::string local_ver_fcn_file_dir (void) { RETURN (Vlocal_ver_fcn_file_dir); }
    std::string local_api_fcn_file_dir (void) { RETURN (Vlocal_api_fcn_file_dir); }
    std::string local_fcn_file_dir (void) { RETURN (Vlocal_fcn_file_dir); }
    std::string fcn_file_dir (void) { RETURN (Vfcn_file_dir); }

    std::string oct_data_dir (void) { RETURN (Voct_data_dir); }
    std::string oct_etc_dir (void) { RETURN (Voct_etc_dir); }
    std::string oct_include_dir (void) { RETURN (Voct_include_dir); }
    std::string oct_lib_dir (void) { RETURN (Voct_lib_dir); }
    std::string oct_locale_dir (void) { RETURN (Voct_locale_dir); }
    std::string oct_tests_dir (void) { RETURN (Voct_tests_dir); }

    std::string man_dir (void) { RETURN (Vman_dir); }
    std::string man1_dir (void) { RETURN (Vman1_dir); }
    std::string man1_ext (void) { RETURN (Vman1_ext); }

    std::string image_dir (void) { RETURN (Vimage_dir); }

    std::string local_startupfile_dir (void) { RETURN (Vlocal_startupfile_dir); }
    std::string startupfile_dir (void) { RETURN (Vstartupfile_dir); }

    std::string local_site_defaults_file (void) { RETURN (Vlocal_site_defaults_file); }
    std::string site_defaults_file (void) { RETURN (Vsite_defaults_file); }
  }
}

#undef RETURN

DEFUN (OCTAVE_HOME, args, ,
       doc: /* -*- texinfo -*-
@deftypefn {} {} OCTAVE_HOME ()
Return the name of the top-level Octave installation directory.
OCTAVE_HOME corresponds to the configuration variable @var{prefix}.
@seealso{EXEC_PATH, IMAGE_PATH, OCTAVE_EXEC_HOME}
@end deftypefn */)
{
  if (args.length () != 0)
    print_usage ();

  return ovl (octave::config::octave_home ());
}

/*
%!assert (ischar (OCTAVE_HOME ()))
%!error OCTAVE_HOME (1)
*/

DEFUN (OCTAVE_EXEC_HOME, args, ,
       doc: /* -*- texinfo -*-
@deftypefn {} {} OCTAVE_HOME ()
Return the name of the top-level Octave installation directory for
architecture-dependendent files.  If not specified separately, the value
is the same as OCTAVE_HOME.  OCTAVE_EXEC_HOME corresponds to the
configuration variable @var{exec_prefix}.
@seealso{EXEC_PATH, IMAGE_PATH, OCTAVE_HOME}
@end deftypefn */)
{
  if (args.length () != 0)
    print_usage ();

  return ovl (octave::config::octave_exec_home ());
}

/*
%!assert (ischar (OCTAVE_EXEC_HOME ()))
%!error OCTAVE_EXEC_HOME (1)
*/

DEFUNX ("OCTAVE_VERSION", FOCTAVE_VERSION, args, ,
        doc: /* -*- texinfo -*-
@deftypefn {} {} OCTAVE_VERSION ()
Return the version number of Octave as a string.
@seealso{ver, version}
@end deftypefn */)
{
  if (args.length () != 0)
    print_usage ();

  return ovl (OCTAVE_VERSION);
}

/*
%!assert (ischar (OCTAVE_VERSION ()))
%!error OCTAVE_VERSION (1)
*/
