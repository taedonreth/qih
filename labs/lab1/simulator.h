#pragma once
#include "black_scholes.h"
#include <vector>
#include <iostream>

struct TradeResult {
    double pnl;
};

class Simulator {
public:
    // naive strategy: buy call and hold underlying
    static TradeResult run_strategy(const OptionParams& opt, double steps = 100) {
        double dt = opt.T / steps;

        double S = opt.S;
        double pnl = 0.0;

        for (int i = 0; i < steps; i++) {
            double dS = S * opt.sigma * 0.01; // toy movement

            S += dS;

            // delta approximation
            double d1 = (std::log(S / opt.K) + (opt.r + 0.5 * opt.sigma * opt.sigma) * opt.T)
                        / (opt.sigma * std::sqrt(opt.T));

            double delta = math::norm_cdf(d1);

            pnl += delta * dS;
        }

        return { pnl };
    }
};
