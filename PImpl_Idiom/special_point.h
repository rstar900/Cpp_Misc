#pragma once

#include <memory>

class SpecialPoint 
{
public:
    explicit SpecialPoint(float x, float y);
    ~SpecialPoint();
    void print_point();

private:
    struct SpecialPointImpl;
    std::unique_ptr<SpecialPointImpl> pImpl;
};