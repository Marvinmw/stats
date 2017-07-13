/*################################################################################
  ##
  ##   Copyright (C) 2011-2017 Keith O'Hara
  ##
  ##   This file is part of the StatsLib C++ library.
  ##
  ##   StatsLib is free software: you can redistribute it and/or modify
  ##   it under the terms of the GNU General Public License as published by
  ##   the Free Software Foundation, either version 2 of the License, or
  ##   (at your option) any later version.
  ##
  ##   StatsLib is distributed in the hope that it will be useful,
  ##   but WITHOUT ANY WARRANTY; without even the implied warranty of
  ##   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  ##   GNU General Public License for more details.
  ##
  ################################################################################*/

// g++-mp-7 -O3 -Wall -std=c++11 -DSTATSLIB_GO_CONST -I./../../include -I/opt/local/include pbern.cpp -o pbern.test -framework Accelerate

#include <cmath>
#include <iomanip>
#include "stats.hpp"

int main()
{
    double err_tol = 1E-06;
    int round_digits_1 = 3;
    int round_digits_2 = 5;

    constexpr double prob_par = 0.4;

    // x = 1
    constexpr int x_1 = 1;
    double val_1 = 1.0;
    constexpr double dens_1 = stats::pbern(x_1,prob_par,false);

    bool success_1 = (std::abs(dens_1 - val_1) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1-1) << "pbern(" << x_1 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << dens_1 << ". Success = " << success_1 << std::endl;

    // x = 1, return log
    constexpr int x_2 = 1;
    double val_2 = 0.0;
    constexpr double dens_2 = stats::pbern(x_2,prob_par,true);

    bool success_2 = (std::abs(dens_2 - val_2) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1-1) << "pbern(" << x_2 << ",log=true): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << dens_2 << ". Success = " << success_2 << std::endl;

    if (success_1 && success_2) {
        printf("\npbern: all tests passed.\n");
    }

    //
    // coverage tests

    stats::pbern(x_1);
    stats::pbern(x_1,true);
    stats::pbern(x_1,prob_par);

    arma::mat x_mat(2,1);
    x_mat(0,0) = 0;
    x_mat(1,0) = 1;

    stats::pbern(x_mat);
    stats::pbern(x_mat,true);
    stats::pbern(x_mat,prob_par);
    stats::pbern(x_mat,prob_par,true);

    return 0;
}