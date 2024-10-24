#pragma once

#include <string>
#include <ctime>

class Peripheral
{
public:
    Peripheral(std::string brand, std::string model, float price, int lifespan);

    std::string get_brand();
    std::string get_model();

    int get_lifespan();
    float get_price();

    void set_price(float price);

    virtual void print_info();

protected:
    std::string brand;
    std::string model;

    int lifespan;
    float price;
};