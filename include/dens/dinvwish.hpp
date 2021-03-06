/*################################################################################
  ##
  ##   Copyright (C) 2011-2018 Keith O'Hara
  ##
  ##   This file is part of the StatsLib C++ library.
  ##
  ##   Licensed under the Apache License, Version 2.0 (the "License");
  ##   you may not use this file except in compliance with the License.
  ##   You may obtain a copy of the License at
  ##
  ##       http://www.apache.org/licenses/LICENSE-2.0
  ##
  ##   Unless required by applicable law or agreed to in writing, software
  ##   distributed under the License is distributed on an "AS IS" BASIS,
  ##   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  ##   See the License for the specific language governing permissions and
  ##   limitations under the License.
  ##
  ################################################################################*/

/*
 * pdf of the inverse-Wishart distribution
 */

#ifndef _statslib_dinvwish_HPP
#define _statslib_dinvwish_HPP

#ifdef STATS_WITH_MATRIX_LIB
template<typename Ta, typename Te = double>
statslib_inline
Te dinvwish(const Ta& X, const Ta& Psi_par, const uint_t nu_par, bool log_form = false);

#include "dinvwish.ipp"
#endif

#endif
