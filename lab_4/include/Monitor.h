#pragma once

#include "Peripheral.h"
#include <string>

class Monitor : public Peripheral
{
public:
    Monitor(std::string brand, std::string model, float price, int lifespan,
            std::string resolution);

    void print_info() override;
    void edit_fields() override;

    std::string get_resolution();

protected:
    std::string resolution;
};