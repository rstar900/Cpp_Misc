#pragma once

#include <memory>

class SpecialPoint 
{
public:
    explicit SpecialPoint(float x, float y);
    // It is mandatory to mention destructor but not implement here
    // This is because, SpecialPointImpl's size is not known for destructing unique ptr, hence
    // default destructor cannot be used right away. So we tell the compiler that it will be implemented somewhere for now 
    // (in our special_point.cpp file where it is known)
    ~SpecialPoint();
    void print_point();

private:
    struct SpecialPointImpl; // Forward declaration of type used for PImpl
    std::unique_ptr<SpecialPointImpl> pImpl; // Our Pointer to Implementation (PImpl)
};
