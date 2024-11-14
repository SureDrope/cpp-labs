#include "../include/Monitor.h"
#include <iostream>
#include <string>
#include <limits>

Monitor::Monitor(std::string brand, std::string model, float price, int lifespan,
                 std::string resolution)
    : Peripheral(brand, model, price, lifespan)
{
    this->resolution = resolution;
}
std::string Monitor::get_resolution()
{
    return resolution;
}
void Monitor::print_info()
{
    Peripheral::print_info();
    std::cout << "5. Разрешение: " << this->get_resolution() << std::endl;
    std::cout << "\n";
}

void Monitor::edit_fields()
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
    else if (field_name.compare("Разрешение") == 0 || field_name.compare("5") == 0)
    {
        std::cout << "Введите новое разрешение: ";
        std::cin >> this->lifespan;
    }
    else
    {
        std::cout << "Такого поля нет!" << std::endl;
    }
}