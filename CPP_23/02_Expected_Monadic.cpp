#include <iostream>
#include <expected>

enum class CalculationError {
    divide_by_zero,
    // Maybe more errors ...
};

auto divide(double a, double b) -> std::expected<double, CalculationError> {
    if (b == 0) {
        return std::unexpected(CalculationError::divide_by_zero);
    } else {
        return a / b;
    }
}

auto main() -> int {
    // Correct result
    auto x1 = divide(3,10)
             .and_then([](double x) -> std::expected<double, CalculationError> {
                      std::cout << "You got " << x << " as a result" << std::endl;
                      return 0;
           }).or_else([](CalculationError err) -> std::expected<double, CalculationError>{
                std::cout << "You just got divide by zero error" << std::endl;
                return std::unexpected(err);    
           });

    // Error result
    auto x2 = divide(3,0)
             .and_then([](double x) -> std::expected<double, CalculationError> {
                      std::cout << "You got " << x << " as a result" << std::endl;
                      return 0;
           }).or_else([](CalculationError err) -> std::expected<double, CalculationError>{
                std::cout << "You just got divide by zero error" << std::endl;
                return std::unexpected(err);    
           });
}
