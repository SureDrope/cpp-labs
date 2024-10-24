#pragma once

#include "Peripheral.h"
#include <string>

class Monitor : public Peripheral
{
public:
    Monitor(std::string brand, std::string model, float price, int lifespan,
            int width_pixels, int height_pixels);

    void print_info() override;

    std::string get_resolution();

protected:
    int width_pixels;
    int height_pixels;
};