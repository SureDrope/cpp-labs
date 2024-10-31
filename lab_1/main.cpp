#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <limits>

struct Student
{
    std::string surname;
    std::string university;
    std::string faculty;
    int year;

    Student(std::string sur, std::string uni, std::string fac, int y)
        : surname(std::move(sur)), university(std::move(uni)), faculty(std::move(fac)), year(y)
    {
    }
};

std::vector<std::string> split(const std::string &str, char delimiter);
void print_students(const std::vector<Student> &students);
void find_second_year_students(const std::vector<Student> &students);
void edit_student(Student &student);
void save_to_file(const std::vector<Student> &students, const std::string &filename);

int main()
{
    std::vector<Student> students;

    std::ifstream file("table.txt");

    if (file.is_open())
    {
        std::string line;

        while (std::getline(file, line))
        {
            std::vector<std::string> fields = split(line, ' ');
            students.emplace_back(fields[0], fields[1], fields[2], std::stoi(fields[3]));
        }

        file.close();
    }
    else
    {
        throw std::runtime_error("Не удалось открыть файл");
    }

    int choice;
    std::string filename;

    do
    {
        std::cout << "\nВыберите действие: \n";
        std::cout << "0. Выход\n";
        std::cout << "1. Отображение студентов\n";
        std::cout << "2. Редактирование студента\n";
        std::cout << "3. Найти количество студентов 2 курса\n";
        std::cout << "4. Сохранение студентов в файл\n";
        std::cout << "Ваш выбор: ";
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очистка буфера ввода
        switch (choice)
        {
        case 1:
            print_students(students);
            break;
        case 2:
        {
            int index;
            std::cout << "Введите номер студента для редактирования (1-" << students.size() << "): ";
            std::cin >> index;
            if (index > 0 && index <= students.size())
            {
                edit_student(students[index - 1]);
            }
            else
            {
                std::cout << "Некорректный номер студента." << std::endl;
            }
            break;
        }
        case 3:
            find_second_year_students(students);
            break;
        case 4:

            std::cout << "Введите имя файла для работы: ";
            std::getline(std::cin, filename);
            save_to_file(students, filename);
            std::cout << "Данные сохранены в файл." << std::endl;
            break;
        case 0:
            std::cout << "Выход из программы." << std::endl;
            break;
        default:
            std::cout << "Некорректный выбор" << std::endl;
        }
    } while (choice != 0);

    return 0;
}

std::vector<std::string> split(const std::string &str, char delimiter)
{
    std::vector<std::string> result;
    std::string::size_type word_start = 0;
    std::string::size_type word_end = str.find(delimiter);

    while (word_end != std::string::npos)
    {
        result.push_back(str.substr(word_start, word_end - word_start));
        word_start = word_end + 1;
        word_end = str.find(delimiter, word_start);
    }
    // Add the last field after the final delimiter
    result.push_back(str.substr(word_start));

    return result;
}

void print_students(const std::vector<Student> &students)
{
    for (size_t i = 0; i < students.size(); ++i)
    {
        const Student &p = students[i];
        std::cout << i + 1 << ". Фамилия: " << p.surname << ", Университет: " << p.university
                  << ", Факультет: " << p.faculty << " Год обучения: " << p.year << "\n";
    }
}

void find_second_year_students(const std::vector<Student> &students)
{
    int second_year_students_count = 0;
    for (const Student &student : students)
    {
        if (student.year == 2)
        {
            second_year_students_count++;
        }
    }
    std::cout << "\nКоличество студентов второго курса: " << second_year_students_count << std::endl;
}

void edit_student(Student &student)
{
    std::cout << "\nВведите новую фамилию студента: ";
    std::cin >> student.surname;

    std::cout << "\nВведите новый университет: ";
    std::cin >> student.university;

    std::cout << "\nВведите новый факультет: ";
    std::cin >> student.faculty;

    std::cout << "\nВведите новый год обучения: ";
    std::cin >> student.year;
}

void save_to_file(const std::vector<Student> &students, const std::string &filename)
{
    std::ofstream file(filename);
    if (!file)
    {
        std::cerr << "Не удалось открыть файл для записи: " << filename << std::endl;
        return;
    }

    for (const auto &p : students)
    {
        file << p.surname << " " << p.university << " " << p.faculty << " " << p.year << "\n";
    }

    file.close();
}