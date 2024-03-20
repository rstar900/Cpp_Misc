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
    if (std::expected<double, CalculationError> x; x = divide(3,10)) {
        std::cout << "You got " << *x << " as a result" << std::endl;
    }
    else if (x.error() == CalculationError::divide_by_zero){
        std::cout << "You just got divide by zero error" << std::endl;
    }

    // Error result
    if (std::expected<double, CalculationError> x; x = divide(3,0)) {
        std::cout << "You got " << *x << " as a result" << std::endl;
    }
    else if (x.error() == CalculationError::divide_by_zero){
        std::cout << "You just got divide by zero error" << std::endl;
    }
}
