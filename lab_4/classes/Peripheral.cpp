#include "../include/Peripheral.h"
#include <string>
#include <iostream>

Peripheral::Peripheral(std::string brand, std::string model, float price, int lifespan)
{
    this->brand = brand;
    this->model = model;
    this->price = price;
    this->lifespan = lifespan;
};
std::string Peripheral::get_brand()
{
    return this->brand;
};
std::string Peripheral::get_model()
{
    return this->model;
};

int Peripheral::get_lifespan()
{
    return this->lifespan;
};
float Peripheral::get_price()
{
    return this->price;
};

void Peripheral::set_price(float price)
{
    if (price < 0)
    {
        std::cout << "Цена не может быть отрицательной!" << std::endl;
        return;
    }
    this->price = price;
};

void Peripheral::print_info()
{
    std::cout << "Бренд: " << this->brand << std::endl;
    std::cout << "Модель: " << this->model << std::endl;
    std::cout << "Цена: " << this->price << std::endl;
    std::cout << "Срок службы: " << this->lifespan << std::endl;
};