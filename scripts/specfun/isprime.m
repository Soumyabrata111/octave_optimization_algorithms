## Copyright (C) 2000, 2006, 2007, 2009 Paul Kienzle
## Copyright (C) 2010 VZLU Prague
##
## This file is part of Octave.
##
## Octave is free software; you can redistribute it and/or modify it
## under the terms of the GNU General Public License as published by
## the Free Software Foundation; either version 3 of the License, or (at
## your option) any later version.
##
## Octave is distributed in the hope that it will be useful, but
## WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
## General Public License for more details.
##
## You should have received a copy of the GNU General Public License
## along with Octave; see the file COPYING.  If not, see
## <http://www.gnu.org/licenses/>.

## -*- texinfo -*-
## @deftypefn {Function File} {} isprime (@var{n})
## Return true if @var{n} is a prime number, false otherwise.
##
## If max(n) is very large, then you should be using special purpose 
## factorization code.
##
## @seealso{primes, factor, gcd, lcm}
## @end deftypefn

function t = isprime (n)

  if (nargin == 1)
    if (any ((n != floor (n) | n < 0)(:)))
      error ("isprime: needs positive integers");
    endif
    maxn = max (n(:));
    ## generate prime table of suitable length.
    maxp = min (maxn, max (sqrt (maxn), 1e7)); # FIXME: threshold not optimized.
    pr = primes (maxp);
    ## quick search for table matches.
    t = lookup (pr, n, "b");
    ## take the rest.
    m = n(n > maxp);
    if (! isempty (m))
      ## there are still possible primes. filter them out by division.
      if (maxn <= intmax ("uint32"))
        m = uint32 (m);
      elseif (maxn <= intmax ("uint64"))
        m = uint64 (m);
      else
        warning ("isprime: too large integers being tested");
      endif
      pr = cast (pr(pr <= sqrt (maxn)), class (m));
      for p = pr
        m = m(rem (m, p) != 0);
        if (length (m) < length (pr) / 10)
          break;
        endif
      endfor
      pr = pr(pr > p);
      mm = arrayfun (@(x) all (rem (x, pr)), m);
      m = m(mm);
      if (! isempty (m))
        m = cast (sort (m), class (n));
        t |= lookup (m, n, "b");
      endif
    endif

  else
    print_usage ();
  endif

endfunction

%!assert (isprime (4), logical (0));
%!assert (isprime (3), logical (1));
%!assert (isprime (magic (3)), logical ([0, 0, 0; 1, 1, 1; 0, 0, 1]));
%!error isprime ()
%!error isprime (1, 2)
