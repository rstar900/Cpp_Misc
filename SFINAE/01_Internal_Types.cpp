// Inspiration from https://www.youtube.com/watch?v=fK1hsU2M7tU&ab_channel=WarwickRSE

#include <iostream>

class A 
{
public:
    using val = char; // This aliasing needs to be in public, so it is visible to outside world i.e. external functions   
    val v = 'R';
};

class B 
{
public:
    using val2 = int;
    val2 v = 27;
};

template <typename T>
void func(typename T::val& v) // typename needs to be there as we are using an internal type of a class
{
    std::cout << "func for class A called: " << v << std::endl;
}

// Try commenting this function, Substitution for B's internal val2 type will fail at compilation
template <typename T>
void func(typename T::val2& v) 
{
    std::cout << "func for class B called: " << v << std::endl;
}

int main() 
{
    A aObj;
    B bObj;

    func<A>(aObj.v);
    func<B>(bObj.v);
}
