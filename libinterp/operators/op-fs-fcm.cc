////////////////////////////////////////////////////////////////////////
//
// Copyright (C) 1996-2023 The Octave Project Developers
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

#include "mx-fs-fcm.h"
#include "mx-fcm-fs.h"
#include "mx-fs-fcnda.h"
#include "mx-fcnda-fs.h"

#include "ovl.h"
#include "ov.h"
#include "ov-scalar.h"
#include "ov-float.h"
#include "ov-cx-mat.h"
#include "ov-flt-cx-mat.h"
#include "ov-flt-re-mat.h"
#include "ov-typeinfo.h"
#include "ops.h"
#include "xdiv.h"
#include "xpow.h"

OCTAVE_BEGIN_NAMESPACE(octave)

// scalar by complex matrix ops.

DEFNDBINOP_OP (add, float_scalar, float_complex_matrix, float_scalar,
               float_complex_array, +)
DEFNDBINOP_OP (sub, float_scalar, float_complex_matrix, float_scalar,
               float_complex_array, -)
DEFNDBINOP_OP (mul, float_scalar, float_complex_matrix, float_scalar,
               float_complex_array, *)

DEFBINOP (div, float_scalar, float_complex_matrix)
{
  OCTAVE_CAST_BASE_VALUE (const octave_float_scalar&, v1, a1);
  OCTAVE_CAST_BASE_VALUE (const octave_float_complex_matrix&, v2, a2);

  FloatMatrix m1 = v1.float_matrix_value ();
  FloatComplexMatrix m2 = v2.float_complex_matrix_value ();
  MatrixType typ = v2.matrix_type ();

  FloatComplexMatrix ret = xdiv (m1, m2, typ);

  v2.matrix_type (typ);
  return ret;
}

DEFBINOP_FN (pow, float_scalar, float_complex_matrix, xpow)

DEFBINOP (ldiv, float_scalar, float_complex_matrix)
{
  OCTAVE_CAST_BASE_VALUE (const octave_float_scalar&, v1, a1);
  OCTAVE_CAST_BASE_VALUE (const octave_float_complex_matrix&, v2, a2);

  return octave_value (v2.float_complex_array_value () / v1.float_value ());
}

DEFNDCMPLXCMPOP_FN (lt, float_scalar, float_complex_matrix, float_scalar,
                    float_complex_array, mx_el_lt)
DEFNDCMPLXCMPOP_FN (le, float_scalar, float_complex_matrix, float_scalar,
                    float_complex_array, mx_el_le)
DEFNDCMPLXCMPOP_FN (eq, float_scalar, float_complex_matrix, float_scalar,
                    float_complex_array, mx_el_eq)
DEFNDCMPLXCMPOP_FN (ge, float_scalar, float_complex_matrix, float_scalar,
                    float_complex_array, mx_el_ge)
DEFNDCMPLXCMPOP_FN (gt, float_scalar, float_complex_matrix, float_scalar,
                    float_complex_array, mx_el_gt)
DEFNDCMPLXCMPOP_FN (ne, float_scalar, float_complex_matrix, float_scalar,
                    float_complex_array, mx_el_ne)

DEFNDBINOP_OP (el_mul, float_scalar, float_complex_matrix, float_scalar,
               float_complex_array, *)
DEFNDBINOP_FN (el_div, float_scalar, float_complex_matrix, float_scalar,
               float_complex_array, elem_xdiv)
DEFNDBINOP_FN (el_pow, float_scalar, float_complex_matrix, float_scalar,
               float_complex_array, elem_xpow)

DEFBINOP (el_ldiv, float_scalar, float_complex_matrix)
{
  OCTAVE_CAST_BASE_VALUE (const octave_float_scalar&, v1, a1);
  OCTAVE_CAST_BASE_VALUE (const octave_float_complex_matrix&, v2, a2);

  return octave_value (v2.float_complex_array_value () / v1.float_value ());
}

DEFNDBINOP_FN (el_and, float_scalar, float_complex_matrix, float_scalar,
               float_complex_array, mx_el_and)
DEFNDBINOP_FN (el_or,  float_scalar, float_complex_matrix, float_scalar,
               float_complex_array, mx_el_or)

DEFNDCATOP_FN (fs_fcm, float_scalar, float_complex_matrix, float_array,
               float_complex_array, concat)

DEFNDCATOP_FN (s_fcm, scalar, float_complex_matrix, float_array,
               float_complex_array, concat)

DEFNDCATOP_FN (fs_cm, float_scalar, complex_matrix, float_array,
               float_complex_array, concat)

DEFCONV (float_complex_matrix_conv, float_scalar, float_complex_matrix)
{
  OCTAVE_CAST_BASE_VALUE (const octave_float_scalar&, v, a);

  return new octave_float_complex_matrix (FloatComplexMatrix
                                          (v.float_matrix_value ()));
}

void
install_fs_fcm_ops (octave::type_info& ti)
{
  INSTALL_BINOP_TI (ti, op_add, octave_float_scalar, octave_float_complex_matrix,
                    add);
  INSTALL_BINOP_TI (ti, op_sub, octave_float_scalar, octave_float_complex_matrix,
                    sub);
  INSTALL_BINOP_TI (ti, op_mul, octave_float_scalar, octave_float_complex_matrix,
                    mul);
  INSTALL_BINOP_TI (ti, op_div, octave_float_scalar, octave_float_complex_matrix,
                    div);
  INSTALL_BINOP_TI (ti, op_pow, octave_float_scalar, octave_float_complex_matrix,
                    pow);
  INSTALL_BINOP_TI (ti, op_ldiv, octave_float_scalar,
                    octave_float_complex_matrix, ldiv);
  INSTALL_BINOP_TI (ti, op_lt, octave_float_scalar, octave_float_complex_matrix,
                    lt);
  INSTALL_BINOP_TI (ti, op_le, octave_float_scalar, octave_float_complex_matrix,
                    le);
  INSTALL_BINOP_TI (ti, op_eq, octave_float_scalar, octave_float_complex_matrix,
                    eq);
  INSTALL_BINOP_TI (ti, op_ge, octave_float_scalar, octave_float_complex_matrix,
                    ge);
  INSTALL_BINOP_TI (ti, op_gt, octave_float_scalar, octave_float_complex_matrix,
                    gt);
  INSTALL_BINOP_TI (ti, op_ne, octave_float_scalar, octave_float_complex_matrix,
                    ne);
  INSTALL_BINOP_TI (ti, op_el_mul, octave_float_scalar,
                    octave_float_complex_matrix, el_mul);
  INSTALL_BINOP_TI (ti, op_el_div, octave_float_scalar,
                    octave_float_complex_matrix, el_div);
  INSTALL_BINOP_TI (ti, op_el_pow, octave_float_scalar,
                    octave_float_complex_matrix, el_pow);
  INSTALL_BINOP_TI (ti, op_el_ldiv, octave_float_scalar,
                    octave_float_complex_matrix, el_ldiv);
  INSTALL_BINOP_TI (ti, op_el_and, octave_float_scalar,
                    octave_float_complex_matrix, el_and);
  INSTALL_BINOP_TI (ti, op_el_or, octave_float_scalar,
                    octave_float_complex_matrix, el_or);

  INSTALL_CATOP_TI (ti, octave_float_scalar, octave_float_complex_matrix, fs_fcm);
  INSTALL_CATOP_TI (ti, octave_scalar, octave_float_complex_matrix, s_fcm);
  INSTALL_CATOP_TI (ti, octave_float_scalar, octave_complex_matrix, fs_cm);

  INSTALL_ASSIGNCONV_TI (ti, octave_float_scalar, octave_float_complex_matrix,
                         octave_float_complex_matrix);
  INSTALL_ASSIGNCONV_TI (ti, octave_scalar, octave_float_complex_matrix,
                         octave_complex_matrix);

  INSTALL_WIDENOP_TI (ti, octave_float_scalar, octave_float_complex_matrix,
                      float_complex_matrix_conv);
}

OCTAVE_END_NAMESPACE(octave)
