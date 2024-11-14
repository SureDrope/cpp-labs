#include "../include/Peripheral.h"
#include <iostream>
#include <string>
#include <limits>

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
    std::cout << "1. Бренд: " << this->brand << std::endl;
    std::cout << "2. Модель: " << this->model << std::endl;
    std::cout << "3. Цена: " << this->price << std::endl;
    std::cout << "4. Срок службы: " << this->lifespan << std::endl;
};

void Peripheral::edit_fields()
{
    std::string field_name;
    std::cout << "Доступные поля:\n";
    this->print_info();
    std::cout << "Введите название поля или цифру для редактирования: ";

    std::getline(std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'), field_name);

    if (field_name.compare("Бренд") == 0 || field_name.compare("1") == 0)
    {
        std::cout << "Введите новый бренд: ";
        std::getline(std::cin, this->brand);
    }
    else if (field_name.compare("Модель") == 0 || field_name.compare("2") == 0)
    {
        std::cout << "Введите новую модель: ";
        std::getline(std::cin, this->model);
    }
    else if (field_name.compare("Цена") == 0 || field_name.compare("3") == 0)
    {
        std::cout << "Введите новую цену: ";
        float new_price;
        std::cin >> new_price;
        this->set_price(new_price);
    }
    else if (field_name.compare("Срок службы") == 0 || field_name.compare("4") == 0)
    {
        std::cout << "Введите новый срок службы: ";
        std::cin >> this->lifespan;
    }
    else
    {
        std::cout << "Такого поля нет!" << std::endl;
    }
}