#include "include/Peripheral.h"
#include "include/Monitor.h"
#include "include/Printer.h"
#include <iostream>
#include <limits>
#include <array>
#include <span>

void print_periferals(std::span<Peripheral *> peripherals);
void get_average_lifespan(std::span<Peripheral *> peripherals);

int main()
{

    Monitor monitor1("Samsung", "S24C366EAU", 22000, 5, "2560x1440");
    Monitor monitor2("LG", "LS27C330GAUXEN", 15999.90, 7, "1920x1080");

    Printer printer1("HP", "LaserJet CP5225dn", 74799, 6, 100);
    Printer printer2("Epson", "L8050", 45799, 5, 150);

    std::array<Peripheral *, 4> peripherals = {&monitor1, &monitor2, &printer1, &printer2};

    int choice;
    do
    {
        std::cout << "Выберите действие: \n";
        std::cout << "0. Выход\n";
        std::cout << "1. Отображение объектов\n";
        std::cout << "2. Редактирование объектов\n";
        std::cout << "3. Найти среднюю продолжительность жизни периферии\n";
        std::cout << "Ваш выбор: ";

        // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очистка буфера ввода
        std::cin >> choice;
        std::cout << "\n";

        switch (choice)
        {
        case 1:
            print_periferals(peripherals);
            break;
        case 2:
        {
            int index;
            std::cout << "Введите номер периферии для редактирования (1-" << peripherals.size() << "): ";
            std::cin >> index;
            if (index > 0 && index <= peripherals.size())
            {
                peripherals[index - 1]->edit_fields();
            }
            else
            {
                std::cout << "Некорректный номер периферии." << std::endl;
            }
            break;
        }
        case 3:
            get_average_lifespan(peripherals);
            break;
        case 0:
            break;
        default:
            std::cout << "Некорректный выбор" << std::endl;
        }
    } while (choice != 0);
    return 0;
}

void print_periferals(std::span<Peripheral *> peripherals)
{
    for (Peripheral *peripheral : peripherals)
    {
        peripheral->print_info();
    }
}

void get_average_lifespan(std::span<Peripheral *> peripherals)
{
    int sum_lifespan = 0;
    for (Peripheral *peripheral : peripherals)
    {
        sum_lifespan += peripheral->get_lifespan();
    }

    std::cout << "Средний срок службы всех периферийных устройств: " << (float)sum_lifespan / peripherals.size() << "\n\n";
}