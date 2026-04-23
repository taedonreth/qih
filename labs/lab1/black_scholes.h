#pragma once
#include "math_utils.h"

struct OptionParams {
    double S;   // spot
    double K;   // strike
    double r;   // risk-free rate
    double sigma; // volatility
    double T;   // time to maturity
};

class BlackScholes {
public:
    static double call_price(const OptionParams& p) {
        double d1 = (std::log(p.S / p.K) + (p.r + 0.5 * p.sigma * p.sigma) * p.T)
                    / (p.sigma * std::sqrt(p.T));

        double d2 = d1 - p.sigma * std::sqrt(p.T);

        return p.S * math::norm_cdf(d1)
             - p.K * std::exp(-p.r * p.T) * math::norm_cdf(d2);
    }

    static double put_price(const OptionParams& p) {
        double d1 = (std::log(p.S / p.K) + (p.r + 0.5 * p.sigma * p.sigma) * p.T)
                    / (p.sigma * std::sqrt(p.T));

        double d2 = d1 - p.sigma * std::sqrt(p.T);

        return p.K * std::exp(-p.r * p.T) * math::norm_cdf(-d2)
             - p.S * math::norm_cdf(-d1);
    }
};
