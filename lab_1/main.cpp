#include <string>
#include <vector>
#include <fstream>
#include <iostream>

struct Student
{
    std::string surname;
    std::string university;
    int year;
    std::string faculty;

    Student(std::string sur, std::string uni, int y, std::string fac)
        : surname(std::move(sur)), university(std::move(uni)), year(y), faculty(std::move(fac))
    {
    }
};

std::vector<std::string> split(const std::string &str, char delimiter);
// Student createStudent(const std::vector<std::string> &fields);

int main()
{
    std::vector<Student> students;

    std::ifstream file("table.txt");

    if (file.is_open())
    {
        std::string line;

        std::cout << "Студенты: " << std::endl;

        while (std::getline(file, line))
        {
            std::cout << "* " << line << std::endl;

            std::vector<std::string> fields = split(line, ' ');
            // Student student{.surname = fields[0], .university = fields[1], .year = std::stoi(fields[2]), .faculty = fields[3]};
            // students.push_back(student);
            students.emplace_back(fields[0], fields[1], std::stoi(fields[2]), fields[3]);
        }

        file.close();
    }
    else
    {
        throw std::runtime_error("Не удалось открыть файл");
    }

    int second_year_students_count = 0;
    for (const Student &student : students)
    {
        if (student.year == 2)
        {
            second_year_students_count++;
        }
    }
    std::cout << "\nКоличество студентов второго курса: " << second_year_students_count << std::endl;

    std::string file_name;

    std::cout << "\nВведите название файла: ";
    std::cin >> file_name;

    std::ofstream new_file(file_name);

    if (new_file.is_open())
    {
        new_file << "Количество студентов второго курса: " << second_year_students_count;

        new_file.close();
    }
    else
    {
        throw std::runtime_error("Не удалось создать файл");
    }

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

// Student createStudent(const std::vector<std::string> &fields)
// {
//     if (fields.size() != 4)
//         throw std::runtime_error("Неверное количество полей для создания структуры студента");

//     return {fields[0], fields[1], std::stoi(fields[2]), fields[3]};
// }
