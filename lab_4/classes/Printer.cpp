#include "../include/Printer.h"
#include <iostream>
#include <limits>

Printer::Printer(std::string brand, std::string model, float price, int lifespan,
                 int paper_capacity)
    : Peripheral(brand, model, price, lifespan)
{

    this->paper_capacity = paper_capacity;
}

int Printer::get_paper_capacity()
{
    return this->paper_capacity;
}

void Printer::print_info()
{
    Peripheral::print_info();
    std::cout << "Максимальное кол-во бумаги: " << this->paper_capacity << std::endl;
    std::cout << "\n";
}

void Printer::edit_fields()
{
    std::string field_name;
    std::cout << "Доступные поля:\n";
    this->print_info();
    std::cout << "Введите название поля или цифрудля редактирования: ";

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
        std::cin >> this->price;
    }
    else if (field_name.compare("Срок службы") == 0 || field_name.compare("4") == 0)
    {
        std::cout << "Введите новый срок службы: ";
        std::cin >> this->lifespan;
    }
    else if (field_name.compare("Максимальное кол-во бумаги") == 0 || field_name.compare("5") == 0)
    {
        std::cout << "Введите новое максимальное кол-во бумаги: ";
        std::cin >> this->paper_capacity;
    }
    else
    {
        std::cout << "\nТакого поля нет!" << std::endl;
    }
}
