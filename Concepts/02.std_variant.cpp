// Inspiration taken from https://youtu.be/qCc_Vqg3hJk

    /* 
     std::variant was introduced in C++17
     It can contain n types of datatypes defined by the user
     Not a union as it allocates separate space for each type
     Hence type safe
   */

#include <iostream>
#include <variant>

int main()
{
    std::variant<std::string, int, float> myVariant;
    myVariant = 1.34f;
    
    // Cannot read directly, so need to use  std::get<T>() to read it
    std::cout << "myVariant is a float with a value: " << std::get<float>(myVariant) << std::endl;

    // But this can give error in case it is for example not a float, so we can check index
    // Here 0 -> std::string, 1 -> int, 2 -> float
    // We can reassign it to any of it's supported type (in this case std::string)
    myVariant = "Hello World"; // if this line is commented it will still be a float
    
    if (myVariant.index() == 2)
    {
        std::cout << "myVariant is a float with a value: " << std::get<float>(myVariant) << std::endl;
    }
    else if (myVariant.index() == 1)
    {
        std::cout << "myVariant is an int with a value: " << std::get<int>(myVariant) << std::endl;
    }
    else // Cannot tell by index if it contains something or not. By default it will have 0, so a std::string in this case
    {
        std::cout << "myVariant is a std::string with a value: " << std::get<std::string>(myVariant) << std::endl;
    }
    
    // Or you can check for a particular type (here float) and if it isn't, you get a nullptr (recommended way)
    // Note: here the address of myVariant is passed
    myVariant = 3;
    
    if (auto x = std::get_if<float>(&myVariant); x != nullptr)
    {
        std::cout << "myVariant is a float with a value: " << std::get<float>(myVariant) << std::endl;
    }
    else if (auto x = std::get_if<int>(&myVariant); x != nullptr)
    {
        std::cout << "myVariant is an int with a value: " << std::get<int>(myVariant) << std::endl;
    }
    else // By default it will be the first type, so a std::string in this case
    {
        std::cout << "myVariant is a std::string with a value: " << std::get<std::string>(myVariant) << std::endl;
    }
}
