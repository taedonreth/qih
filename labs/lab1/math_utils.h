#pragma once
#include <cmath>
#include <random>

namespace math {

inline double norm_cdf(double x) {
    return 0.5 * std::erfc(-x / std::sqrt(2.0));
}

inline double norm_pdf(double x) {
    return (1.0 / std::sqrt(2.0 * M_PI)) * std::exp(-0.5 * x * x);
}

inline double random_normal(std::mt19937& gen) {
    std::normal_distribution<> d(0.0, 1.0);
    return d(gen);
}

}
