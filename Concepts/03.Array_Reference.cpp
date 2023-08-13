#include <iostream>

void func(int (&array_ref)[4])
{
    std::cout << "Size of array inside func: "<< sizeof(array_ref) << std::endl;
    return;
}

int main()
{
    int array[4] = {1, 2, 3, 4};

    std::cout << "Size of array outside func: "<< sizeof(array) << std::endl;

    func(array);
}
