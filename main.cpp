#include <chrono>
#include <iostream>
#include <random>

float calculate_pi(int simulation_count) {
    // auto random_device        = std::random_device{};
    std::random_device random_device{};
    auto random_engine        = std::default_random_engine{random_device()};
    auto uniform_distribution = std::uniform_real_distribution<>{0.0F, 1.0F};

    auto count_inside_circle = int{0};

    for (auto i = int{0}; i < simulation_count; i++) {
        auto x = uniform_distribution(random_engine);
        auto y = uniform_distribution(random_engine);

        // Equation of a circle: radius^2 = x^2 + y^2
        // for unit circle, 1 = x^2 + y^2
        if (x*x + y*y <= 1) {
            count_inside_circle++;
        }
    }

    auto pi_estimate = 4.0F * count_inside_circle / simulation_count;

    return pi_estimate;
}

auto main() -> int {
    auto start = std::chrono::high_resolution_clock::now();
    auto pi = calculate_pi(1'000'000);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = end - start;
    std::cout << "Pi estimate: " << pi << '\n';
    std::cout << "Execution time (ms): " << std::chrono::duration_cast<std::chrono::milliseconds>(duration).count() << '\n';
}