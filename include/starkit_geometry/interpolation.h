#pragma once

#include <list>
#include <vector>

#include "starkit_geometry/parametric_line.h"

namespace starkit_geometry
{
/* Compute an interpolation of the line defined by the tuple x,y given by
 * using the least square method.
 */
ParametricLine leastSquareLine(std::vector<double> x, std::vector<double> y);

/* returns coef */
std::pair<unsigned long long, double> leastSquareLine(std::list<unsigned long long> x, std::list<unsigned long long> y);

}  // namespace starkit_geometry
