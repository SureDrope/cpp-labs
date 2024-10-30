#include "../include/Monitor.h"
#include <string>
#include <iostream>

Monitor::Monitor(std::string brand, std::string model, float price, int lifespan,
                 int width_pixels, int height_pixels)
    : Peripheral(brand, model, price, lifespan)
{
    this->width_pixels = width_pixels;
    this->height_pixels = height_pixels;
}
std::string Monitor::get_resolution()
{
    return std::to_string(this->width_pixels) + "x" + std::to_string(this->height_pixels);
}
void Monitor::print_info()
{
    Peripheral::print_info();
    std::cout << "Resolution: " << this->get_resolution() << std::endl;
}