// Inspiration from https://www.youtube.com/watch?v=fK1hsU2M7tU&ab_channel=WarwickRSE

#include <iostream>
#include <type_traits>

// We want to define the same function for intergral and non intergral types

// For integral types
template <typename T>
// Same as using typename std::enable_if<std::is_integral<T>::value>::type
// typename is used as enable_if::type returns a void type if true or none if false
typename std::enable_if_t<std::is_integral_v<T>> func(T &v) {
    std::cout << "func() called for an integral type: " << v << std::endl;
}

// For other types (non-integral like float, string, etc.)
// If this function definition is commented, then template substitution for non-integral types will fail
template <typename T>
typename std::enable_if_t<!std::is_integral_v<T>> func(T &v) {
    std::cout << "func() called for a non-integral type: " << v << std::endl;
}

int main()
{
    // Some integral types
    int a{34};
    short b{16};
    uint64_t c{6400000000000000000};

    func(a);
    func(b);
    func(c);

    // Some non-integral types
    float d{3.14};
    double e{6.28e-10};
    std::string f{"Hällå"}; 

    func(d);
    func(e);
    func(f);
}
