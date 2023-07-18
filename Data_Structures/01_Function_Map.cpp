#include <iostream>
#include <functional>
#include <map>
#include <string>

void func_one()
{
    std::cout << "Function 1 executed :)" << std::endl;
}

void func_two()
{
    std::cout << "Function 2 executed <<>>" << std::endl;
}

void func_three()
{
    std::cout << "Function 3 executed :>" << std::endl;
}

int main()
{
    std::string input;
    
    // creating a map for mapping function names to their respective functions
    std::map<std::string, std::function<void(void)>> func_map;

    // filling functions with their respective keys into the map
    func_map["one"] = func_one;
    func_map["two"] = func_two;
    func_map["three"] = func_three;

    do 
    {
        std::cout << "Enter the function name to be executed (quit to exit): ";
        std::cin >> input;

        if (func_map.find(input) != func_map.end())
        {
            func_map[input]();
        } 
        else 
        {
            std::cout << "Invalid function name try again!" << std::endl;
        }
    } while (input != "quit");
   
}   
