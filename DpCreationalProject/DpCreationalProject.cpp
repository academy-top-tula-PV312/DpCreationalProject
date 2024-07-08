#include <iostream>
#include <thread>

#include "Examples.h"
#include "Singleton.h"



void CompLaunch(std::string name)
{
    using namespace std::chrono_literals;
    Computer* computer = new Computer();

    computer->Launch(name);
    std::this_thread::sleep_for(1000ms);
    std::cout << computer->OS()->Name() << "\n";
}


int main()
{
    //Examples::FactoryMethod();
        
    /*Singleton* s1 = Singleton::getInstance();
    std::cout << s1 << "\n";

    Singleton* s2 = Singleton::getInstance();
    std::cout << s2 << "\n";*/

    
    /*CompLaunch("Windows");
    CompLaunch("Linux");*/

    std::jthread th1(CompLaunch, "Windows");
    std::jthread th2(CompLaunch, "Linux");
    
}


