#include "include/Peripheral.h"
#include "include/Monitor.h"
#include "include/Printer.h"
#include <iostream>

int main()
{
    Monitor monitor1("Samsung", "S24C366EAU", 22000, 5, 2560, 1440);
    Monitor monitor2("LG", "LS27C330GAUXEN", 15999.90, 7, 1920, 1080);

    Printer printer1("HP", "LaserJet CP5225dn", 74799, 6, 100);
    Printer printer2("Epson", "L8050", 45799, 5, 150);

    Peripheral *peripherals[] = {&monitor1, &monitor2, &printer1, &printer2};

    int sum_lifespan = 0;
    for (Peripheral *peripheral : peripherals)
    {
        sum_lifespan += peripheral->get_lifespan();
    }

    std::cout << "Средний срок службы всех периферийных устройств: " << (float)sum_lifespan / 4 << std::endl;

    return 0;
}