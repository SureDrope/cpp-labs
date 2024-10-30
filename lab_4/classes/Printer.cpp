#include "../include/Printer.h"
#include <iostream>

Printer::Printer(std::string brand, std::string model, float price, int lifespan,
                 int paper_capacity)
    : Peripheral(brand, model, price, lifespan)
{

    this->paper_capacity = paper_capacity;
    this->paper_level = paper_capacity;
}

void Printer::refill_paper()
{
    this->paper_level = this->paper_capacity;
    std::cout << "Бумага заправлена!" << std::endl;
}

int Printer::get_paper_level()
{
    return this->paper_level;
}

void Printer::print_info()
{
    Peripheral::print_info();
    std::cout << "Максимальное кол-во бумаги: " << this->paper_capacity << std::endl;
}
