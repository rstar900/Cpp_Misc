// Inspiration from https://www.youtube.com/watch?v=fK1hsU2M7tU&ab_channel=WarwickRSE
// Compile with -std=c++17

#include <iostream>
#include <type_traits>

// Similar to 02_Enable_If.cpp, but we can use constexpr if statements starting from C++17 to evaluate these conditions during compilation
// within the same function and compile the branches only they are required

template <typename T>
void func(T &v)
{
    if constexpr (std::is_integral_v<T>)
    {
        // For integral types
        std::cout << "func() called for an integral type: " << v << std::endl;
    }
    else
    {
        // For non-integral types
        std::cout << "func() called for a non-integral type: " << v << std::endl;
    }
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
