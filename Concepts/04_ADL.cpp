// ADL stands for "Argument Dependent Lookup" (Also known as Koenig Lookup) and it searches the function (when :: in not used before the function call, also referred to as unqualified function call) in the namespace of the arguments provided. 
// More info: https://stackoverflow.com/questions/8111677/what-is-argument-dependent-lookup-aka-adl-or-koenig-lookup

#include <iostream>

namespace MySpace
{
  class MyClass{};
  void do_something(MyClass x)
  {
    std::cout << "Running do_something under MySpace namespace" << std::endl;
  }
}

int main()
{
  MySpace::MyClass obj;
  do_something(obj); // this works even though we haven't used MySpace::do_something(obj)
}
