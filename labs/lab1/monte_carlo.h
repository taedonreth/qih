#pragma once
#include "math_utils.h"
#include "black_scholes.h"
#include <vector>

class MonteCarlo {
public:
    static double call_price(const OptionParams& p, int paths = 100000) {
        std::mt19937 gen(42);
        double sum = 0.0;

        for (int i = 0; i < paths; i++) {
            double z = math::random_normal(gen);

            double ST = p.S * std::exp(
                (p.r - 0.5 * p.sigma * p.sigma) * p.T +
                p.sigma * std::sqrt(p.T) * z
            );

            sum += std::max(ST - p.K, 0.0);
        }

        return std::exp(-p.r * p.T) * (sum / paths);
    }
};
