// Template array classes
/*

Copyright (C) 1996, 1997, 2000, 2002, 2003, 2004, 2005, 2006, 2007
              John W. Eaton
Copyright (C) 2008 Jaroslav Hajek

This file is part of Octave.

Octave is free software; you can redistribute it and/or modify it
under the terms of the GNU General Public License as published by the
Free Software Foundation; either version 3 of the License, or (at your
option) any later version.

Octave is distributed in the hope that it will be useful, but WITHOUT
ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
for more details.

You should have received a copy of the GNU General Public License
along with Octave; see the file COPYING.  If not, see
<http://www.gnu.org/licenses/>.

*/

#if !defined (octave_DiagArray2_h)
#define octave_DiagArray2_h 1

#include <cassert>
#include <cstdlib>

#include "Array.h"
#include "lo-error.h"

// A two-dimensional array with diagonal elements only.
//
// Idea and example code for Proxy class and functions from:
//
// From: kanze@us-es.sel.de (James Kanze)
// Subject: Re: How to overload [] to do READ/WRITE differently ?
// Message-ID: <KANZE.93Nov29151407@slsvhdt.us-es.sel.de>
// Sender: news@us-es.sel.de
// Date: 29 Nov 1993 14:14:07 GMT
// --
// James Kanze                             email: kanze@us-es.sel.de
// GABI Software, Sarl., 8 rue du Faisan, F-67000 Strasbourg, France

// Array<T> is inherited privately because we abuse the dimensions variable
// for true dimensions. Therefore, the inherited Array<T> object is not a valid
// Array<T> object, and should not be publicly accessible.

template <class T>
class
DiagArray2 : private Array<T>
{
private:

  T get (octave_idx_type i) { return Array<T>::xelem (i); }

  void set (const T& val, octave_idx_type i) { Array<T>::xelem (i) = val; }

  class Proxy
  {
  public:

    Proxy (DiagArray2<T> *ref, octave_idx_type r, octave_idx_type c)
      : i (r), j (c), object (ref) { } 

    const Proxy& operator = (const T& val) const
      {
	if (i == j)
	  {
	    if (object)
	      object->set (val, i);
	  }
	else
	  (*current_liboctave_error_handler)
	    ("invalid assignment to off-diagonal in diagonal array");

	return *this;
      }

    operator T () const
      {
	if (object && i == j)
	  return object->get (i);
	else
	  {
	    static T foo;
	    return foo;
	  }
      }

  private:

    // FIXME -- this is declared private to keep the user from
    // taking the address of a Proxy.  Maybe it should be implemented
    // by means of a companion function in the DiagArray2 class.

    T *operator& () const { assert (0); return 0; }

    octave_idx_type i;
    octave_idx_type j;

    DiagArray2<T> *object;

  };

friend class Proxy;

protected:

  DiagArray2 (T *d, octave_idx_type r, octave_idx_type c) : Array<T> (d, r < c ? r : c)
    { Array<T>::dimensions = dim_vector (r, c); }

public:

  typedef T element_type;

  DiagArray2 (void) : Array<T> (dim_vector (0, 0)) { }

  DiagArray2 (octave_idx_type r, octave_idx_type c) : Array<T> (r < c ? r : c)
    { this->dimensions = dim_vector (r, c); }

  DiagArray2 (octave_idx_type r, octave_idx_type c, const T& val) : Array<T> (r < c ? r : c)
    {
      this->dimensions = dim_vector (r, c);

      Array<T>::fill (val);
    }

  DiagArray2 (const Array<T>& a) : Array<T> (a)
    { this->dimensions = dim_vector (a.length (), a.length ()); }

  DiagArray2 (const DiagArray2<T>& a) : Array<T> (a)
    { this->dimensions = a.dims (); }

  template <class U>
  DiagArray2 (const DiagArray2<U>& a) : Array<T> (a.diag ())
    { this->dimensions = a.dims (); }

  ~DiagArray2 (void) { }

  DiagArray2<T>& operator = (const DiagArray2<T>& a)
    {
      if (this != &a)
	Array<T>::operator = (a);

      return *this;
    }


  octave_idx_type dim1 (void) const { return Array<T>::dimensions(0); }
  octave_idx_type dim2 (void) const { return Array<T>::dimensions(1); }

  octave_idx_type rows (void) const { return dim1 (); }
  octave_idx_type cols (void) const { return dim2 (); }
  octave_idx_type columns (void) const { return dim2 (); }

  octave_idx_type length (void) const { return Array<T>::length (); }
  octave_idx_type nelem (void) const { return dim1 () * dim2 (); }
  octave_idx_type numel (void) const { return nelem (); }

  size_t byte_size (void) const { return length () * sizeof (T); }

  dim_vector dims (void) const { return Array<T>::dimensions; }

  Array<T> diag (octave_idx_type k = 0) const;

  Proxy elem (octave_idx_type r, octave_idx_type c)
    {
      return Proxy (this, r, c);
    }

  Proxy checkelem (octave_idx_type r, octave_idx_type c)
    {
      if (r < 0 || c < 0 || r >= dim1 () || c >= dim2 ())
	{
	  (*current_liboctave_error_handler) ("range error in DiagArray2");
	  return Proxy (0, r, c);
	}
      else
	return Proxy (this, r, c);
    }

  Proxy operator () (octave_idx_type r, octave_idx_type c)
    {
      if (r < 0 || c < 0 || r >= dim1 () || c >= dim2 ())
	{
	  (*current_liboctave_error_handler) ("range error in DiagArray2");
	  return Proxy (0, r, c);
	}
      else
	return Proxy (this, r, c);
  }

  T elem (octave_idx_type r, octave_idx_type c) const
    {
      return (r == c) ? Array<T>::xelem (r) : T (0);
    }

  T checkelem (octave_idx_type r, octave_idx_type c) const;
  T operator () (octave_idx_type r, octave_idx_type c) const
    {
#if defined (BOUNDS_CHECKING)
      return checkelem (r, c);
#else
      return elem (r, c);
#endif
    }

  // No checking.

  T& xelem (octave_idx_type r, octave_idx_type c)
    {
      static T foo (0);
      return (r == c) ? Array<T>::xelem (r) : foo;
    }

  T xelem (octave_idx_type r, octave_idx_type c) const
    {
      return (r == c) ? Array<T>::xelem (r) : T (0);
    }

  void resize (octave_idx_type n, octave_idx_type m);
  void resize (octave_idx_type n, octave_idx_type m, const T& val);

  DiagArray2<T> transpose (void) const;
  DiagArray2<T> hermitian (T (*fcn) (const T&) = 0) const;

  const T *data (void) const { return Array<T>::data (); }

  const T *fortran_vec (void) const { return Array<T>::fortran_vec (); }

  T *fortran_vec (void) { return Array<T>::fortran_vec (); }

  void print_info (std::ostream& os, const std::string& prefix) const
    { Array<T>::print_info (os, prefix); }
};

#endif

/*
;;; Local Variables: ***
;;; mode: C++ ***
;;; End: ***
*/
