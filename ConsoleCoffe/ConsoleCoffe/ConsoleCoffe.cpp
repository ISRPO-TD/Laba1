#include "Beverage.h"
#include <iostream>

using namespace std;
int main()
{
    std::cout << "Hello World!\n";

    HouseBlend hb;
    cout << hb.getDescription() << "\n";
    cout << hb.getCost();

    MilkDecorator hbMilk(hb);

    cout << hbMilk.getDescription() << "\n";
    cout << hbMilk.getCost();
}

