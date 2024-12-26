#include <iostream>
#include <chrono>
#include <thread>
#include <csignal>
#include <cstdlib> // for system()

// Make the cursor appear again and clear the terminal
void signal_handler(int signal_num) 
{ 
    system("tput cvvis"); // To get the cursor back (Works on Linux)
    system("tput rmcup"); // To exit alternate screen (exit_ca_mode) (Works on Linux)
    exit(signal_num); 
} 

int main()
{
    // In this program, we will use carriage return ('\r'), to overwrite the same line again and again with new characer sequence
    // Along with sleeps between each rewrite to give the effect of animation

    // In case the program is killed or interrupted, we want our cursor back and return to the terminal state before execution of the program
    signal(SIGABRT, signal_handler);
    signal(SIGTERM, signal_handler);
    signal(SIGINT, signal_handler);

    // The commands used with tput utility can be referred from "man 5 terminfo"
    system("tput smcup"); // To enter alternate screen (enter_ca_mode) (Works on Linux)
    system("tput clear"); // To start from the top of this alternate screen, we clear the terminal (Works on Linux) 
    system("tput civis"); // To remove cursor (Works on Linux)

    while (true)
    {
        // We are using flush to display the stdout buffer immediately, else it waits for newline and we might not see the desired output
        
        std::cout << "\rLOADING [     ]" << std::flush;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "\rLOADING [*    ]" << std::flush;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "\rLOADING [**   ]" << std::flush;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "\rLOADING [***  ]" << std::flush;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "\rLOADING [**** ]" << std::flush;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "\rLOADING [*****]" << std::flush;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "\rLOADING [**** ]" << std::flush;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "\rLOADING [***  ]" << std::flush;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "\rLOADING [**   ]" << std::flush;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "\rLOADING [*    ]" << std::flush;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    
    return 0;
}
