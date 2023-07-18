#include <iostream>

struct pos
{
    int x;
    int y;
};

int main()
{
   char* mem_pool = new char[10*sizeof(pos)]; // space (for 10 pos objects in this case) is allocated only once, so spare syscall overhead
    pos* pos1 = new (mem_pool) pos(); // using the pre-existing memory pool
    pos1 -> x = 10;
    pos1 -> y = -20;

    std::cout << "X:" << pos1 -> x << ", Y: " << pos1 -> y << std::endl;

    delete[] mem_pool; // deallocating the whole memory pool
}  
