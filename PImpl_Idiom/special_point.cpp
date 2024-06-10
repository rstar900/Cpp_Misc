#include "special_point.h"
#include <iostream>

struct SpecialPoint::SpecialPointImpl 
{
    float x;
    float y;
    float z;
};

SpecialPoint::SpecialPoint(float x, float y)
{
    pImpl = std::make_unique<SpecialPointImpl>(SpecialPointImpl{x, y, x + y});
}

SpecialPoint::~SpecialPoint(){}

void SpecialPoint::print_point()
{
    std::cout << "x: " << pImpl->x << ", y: " << pImpl->y << ", z: " << pImpl->z << std::endl;
}
