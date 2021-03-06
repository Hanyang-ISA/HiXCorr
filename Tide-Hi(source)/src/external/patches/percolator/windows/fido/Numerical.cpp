// Written by Oliver Serang 2009
// see license for more information

#include "Numerical.h"

// Needed on windows beause of Microsoft non-standard names
bool isinf(double x) {
  return !_finite(x);
}
double log2(double x) {
  return log(x) / log(2.0);
}

bool Numerical::isPos(double d)
{
  return d > epsilon;
}

bool Numerical::isNonpos(double d)
{
  return d <= epsilon;
}

bool Numerical::isNeg(double d)
{
  return d < -epsilon;
}

bool Numerical::isNonneg(double d)
{
  return d >= -epsilon;
}

bool Numerical::isZero(double d)
{
  return fabs(d) <= epsilon;
}

bool Numerical::isNonzero(double d)
{
  return fabs(d) > epsilon;
}

bool Numerical::isEqual(double a, double b)
{
  return isZero( b - a );
}

bool Numerical::isInequal(double a, double b)
{
  return isNonzero( b - a );
}

bool Numerical::isDifferentSign(double a, double b)
{
  return isPos(a) && isNeg(b) || isNeg(a) && isPos(b);
}
// Written by Oliver Serang 2009
// see license for more information
