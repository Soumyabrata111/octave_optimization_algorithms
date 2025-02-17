////////////////////////////////////////////////////////////////////////
//
// Copyright (C) 1993-2023 The Octave Project Developers
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

#if ! defined (octave_pager_h)
#define octave_pager_h 1

#include "octave-config.h"

#include <fstream>
#include <iosfwd>
#include <sstream>
#include <string>

class octave_value;
class octave_value_list;

OCTAVE_BEGIN_NAMESPACE(octave)

class interpreter;
class oprocstream;

class
OCTINTERP_API
pager_buf : public std::stringbuf
{
public:

  pager_buf () : std::stringbuf (), m_diary_skip (0) { }

  OCTAVE_DISABLE_COPY_MOVE (pager_buf)

  ~pager_buf () = default;

  void flush_current_contents_to_diary ();

  void set_diary_skip ();

protected:

  int sync ();

private:

  std::size_t m_diary_skip;
};

class
OCTINTERP_API
pager_stream : public std::ostream
{
public:

  pager_stream ();

  OCTAVE_DISABLE_COPY_MOVE (pager_stream)

  ~pager_stream ();

  void flush_current_contents_to_diary ();

  void set_diary_skip ();

  std::ostream& stream ();

  void reset ();

private:

  pager_buf *m_pb;
};

class
OCTINTERP_API
diary_buf : public std::stringbuf
{
public:

  OCTAVE_DEFAULT_CONSTRUCT_DELETE (diary_buf)
  OCTAVE_DISABLE_COPY_MOVE (diary_buf)

protected:

  int sync ();
};

class
OCTINTERP_API
diary_stream : public std::ostream
{
public:

  diary_stream ();

  OCTAVE_DISABLE_COPY_MOVE (diary_stream)

  ~diary_stream ();

  std::ostream& stream ();

  void reset ();

private:

  diary_buf *m_db;
};

extern OCTINTERP_API void flush_stdout ();

class output_system
{
public:

  output_system (interpreter& interp);

  OCTAVE_DISABLE_CONSTRUCT_COPY_MOVE (output_system)

  ~output_system () = default;

  pager_stream& pager () { return m_pager_stream; }

  diary_stream& diary () { return m_diary_stream; }

  std::string diary_file_name () const { return m_diary_file_name; }

  std::string diary_file_name (const std::string& nm)
  {
    std::string val = m_diary_file_name;
    m_diary_file_name = nm.empty () ? "diary" : nm;
    return val;
  }

  octave_value PAGER (const octave_value_list& args, int nargout);

  std::string PAGER () const { return m_PAGER; }

  std::string PAGER (const std::string& s)
  {
    std::string val = m_PAGER;
    m_PAGER = s;
    return val;
  }

  octave_value PAGER_FLAGS (const octave_value_list& args, int nargout);

  std::string PAGER_FLAGS () const { return m_PAGER_FLAGS; }

  std::string PAGER_FLAGS (const std::string& s)
  {
    std::string val = m_PAGER_FLAGS;
    m_PAGER_FLAGS = s;
    return val;
  }

  octave_value page_output_immediately (const octave_value_list& args,
                                        int nargout);

  bool page_output_immediately () const
  {
    return m_page_output_immediately;
  }

  bool page_output_immediately (bool flag)
  {
    bool val = m_page_output_immediately;
    m_page_output_immediately = flag;
    return val;
  }

  octave_value page_screen_output (const octave_value_list& args,
                                   int nargout);

  bool page_screen_output () const { return m_page_screen_output; }

  bool page_screen_output (bool flag)
  {
    bool val = m_page_screen_output;
    m_page_screen_output = flag;
    return val;
  }

  bool write_to_diary_file () const
  {
    return m_write_to_diary_file;
  }

  bool write_to_diary_file (bool flag)
  {
    bool val = m_write_to_diary_file;
    m_write_to_diary_file = flag;
    return val;
  }

  bool really_flush_to_pager () const
  {
    return m_really_flush_to_pager;
  }

  bool really_flush_to_pager (bool flag)
  {
    bool val = m_really_flush_to_pager;
    m_really_flush_to_pager = flag;
    return val;
  }

  bool flushing_output_to_pager () const
  {
    return m_flushing_output_to_pager;
  }

  bool flushing_output_to_pager (bool flag)
  {
    bool val = m_flushing_output_to_pager;
    m_flushing_output_to_pager = flag;
    return val;
  }

  std::string pager_command () const;

  std::ofstream& external_diary_file () { return m_external_diary_file; }

  void reset ();

  void flush_stdout ();

  bool sync (const char *msg, int len);

  void clear_external_pager ();

  void open_diary ();

  void close_diary ();

  std::ostream& __stdout__ () { return m_pager_stream.stream (); }

  std::ostream& __diary__ () { return m_diary_stream.stream (); }

private:

  interpreter& m_interpreter;

  pager_stream m_pager_stream;

  diary_stream m_diary_stream;

  // Our actual connection to the external pager.
  oprocstream *m_external_pager = nullptr;

  // The diary file.
  std::ofstream m_external_diary_file;

  // The name of the current diary file.
  std::string m_diary_file_name;

  // The shell command to run as the pager.
  std::string m_PAGER;

  // The options to pass to the pager.
  std::string m_PAGER_FLAGS;

  // TRUE means that if output is going to the pager, it is sent as soon
  // as it is available.  Otherwise, it is buffered and only sent to the
  // pager when it is time to print another prompt.
  bool m_page_output_immediately;

  // TRUE means all output intended for the screen should be passed
  // through the pager.
  bool m_page_screen_output;

  // TRUE means we write to the diary file.
  bool m_write_to_diary_file;

  bool m_really_flush_to_pager;

  bool m_flushing_output_to_pager;

  void start_external_pager ();

  void do_sync (const char *msg, int len, bool bypass_pager);
};

extern OCTINTERP_API std::ostream& __stdout__ ();

extern OCTINTERP_API std::ostream& __diary__ ();

OCTAVE_END_NAMESPACE(octave)

#define octave_stdout (octave::__stdout__ ())

#define octave_diary (octave::__diary__ ())

#endif
