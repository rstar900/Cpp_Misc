#include "special_point.h"
#include <iostream>

struct SpecialPoint::SpecialPointImpl 
{
    // So instead of revealing the private members via header file
    // they can simply be declared in this struct and hence, when
    // provided as a precompiled library, the user only gets the header
    // without any obvious revealation of private members
    float x;
    float y;
    float z;

    // Same applies to functions, then the class object just calls the function within
    // the pImpl object via indirection as shown below in SpecialPoint::print_point()
    void print_point()
    {
        std::cout << "x: " << x << ", y: " << y << ", z: " << z << std::endl;
    }
};

SpecialPoint::SpecialPoint(float x, float y)
{
    pImpl = std::make_unique<SpecialPointImpl>(SpecialPointImpl{x, y, x + y});
}

SpecialPoint::~SpecialPoint(){}

void SpecialPoint::print_point()
{
    pImpl->print_point();
}
