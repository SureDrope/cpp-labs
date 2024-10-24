#pragma once

#include "Peripheral.h"
#include <string>

class Printer : public Peripheral
{
public:
    Printer(std::string brand, std::string model, float price, int lifespan,
            int paper_capacity);

    void print_info() override;

    int get_paper_level();
    void refill_paper();

protected:
    int paper_level;
    int paper_capacity;
};