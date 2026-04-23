#include <iostream>
#include "black_scholes.h"
#include "monte_carlo.h"
#include "simulator.h"

int main() {
    OptionParams p{
        100.0,  // S
        100.0,  // K
        0.05,   // r
        0.2,    // sigma
        1.0     // T
    };

    std::cout << "Black-Scholes Call Price: "
              << BlackScholes::call_price(p) << std::endl;

    std::cout << "Monte Carlo Call Price: "
              << MonteCarlo::call_price(p, 100000) << std::endl;

    auto result = Simulator::run_strategy(p);

    std::cout << "Strategy PnL: " << result.pnl << std::endl;

    return 0;
}
