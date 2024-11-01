#pragma once

#include "Peripheral.h"
#include <string>

class Printer : public Peripheral
{
public:
    Printer(std::string brand, std::string model, float price, int lifespan,
            int paper_capacity);

    void print_info() override;
    void edit_fields() override;

    int get_paper_capacity();

protected:
    int paper_capacity;
};