#include "Brent.hpp"
#include <iostream>
#include <limits>

using Function = SolverTraits::Function;
using ResultType = SolverTraits::ResultType;

// Brent type search
// If converging, it finds a zero with error below the given tolerance.
// If not returns a NaN and an error 

// constructor
Brent::Brent(const Function &fun, ResultType a, ResultType b, const ResultType tol, const unsigned int maxIter)
    : SolverBase(fun)
    , a(a)
    , b(b)
    , tol(tol)
    , maxIter(maxIter) {}

ResultType Brent::solve() {
  ResultType ya = fun(a);
  ResultType yb = fun(b);
  
  // First check.
  if((ya * yb) >= 0.0)
    {
      if(ya == 0.)
        return {a};
      else if(yb == 0.)
        return {b};
      else
      	{
      	std::cout << "Function must change sign at the two end values" << std::endl;
      	return std::numeric_limits<ResultType>::quiet_NaN();
      	} // precondition not met
    };
  //
  if(std::abs(ya) < std::abs(yb))
    {
      std::swap(a, b);
      std::swap(ya, yb);
    }
  //
  auto     c = a;
  auto     d = c;
  auto     yc = ya;
  bool     mflag{true};
  auto     s = b;
  auto     ys = yb;
  unsigned iter{0u};
  do
    {
      //
      if(ya != yc and yb != yc)
        {
          auto yab = ya - yb;
          auto yac = ya - yc;
          auto ycb = yc - yb;
          // inverse quadratic interpolation
          s = a * ya * yc / (yab * yac) + b * ya * yc / (yab * ycb) -
              c * ya * yb / (yac * ycb);
        }
      else
        {
          // secant
          s = b - yb * (b - a) / (yb - ya);
        }
      //
      if(((s - 3 * (a + b) / 4) * (s - b) >= 0) or // condition 1
         (mflag and
          (std::abs(s - b) >= 0.5 * std::abs(b - c))) or // condition 2
         (!mflag and
          (std::abs(s - b) >= 0.5 * std::abs(c - d))) or // condition 3
         (mflag and (std::abs(b - c) < tol)) or          // condition 4
         (!mflag and (std::abs(c - d) < tol))            // condition 5
      )
        {
          mflag = true;
          s = 0.5 * (a + b); // back to bisection step
        }
      else
        mflag = false;
      //
      ys = fun(s);
      d = c;
      c = b;
      yc = yb;
      //
      if(ya * ys < 0)
        {
          b = s;
          yb = ys;
        }
      else
        {
          a = s;
          ya = ys;
        }
      //
      if(std::abs(ya) < std::abs(yb))
        {
          std::swap(a, b);
          std::swap(ya, yb);
        }
      //
    }
  while(ys != 0. && std::abs(b - a) > tol && iter < maxIter);
  
  if (iter < maxIter)
    return s;
  else
    {
      	std::cout << "Function must change sign at the two end values" << std::endl;
      	return std::numeric_limits<ResultType>::quiet_NaN();
    } 
  
}
