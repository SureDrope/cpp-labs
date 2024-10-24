#include <iostream>

#define MIN_ARR_VALUE -100
#define MAX_ARR_VALUE 100

int *create_int_array(int size);
void print_array(int *arr, int size);
void change_min_and_max_values_in_array(int *arr, int size, int min_change, int max_change);
int count_negative_values(int *arr, int size);

int main()
{
    srand(time(NULL));

    setlocale(LC_ALL, "Russian");

    const int ARR1_SIZE = 6;
    const int ARR2_SIZE = 8;

    int *arr1 = create_int_array(ARR1_SIZE);
    std::cout << "Первый массив до: ";
    print_array(arr1, ARR1_SIZE);
    change_min_and_max_values_in_array(arr1, ARR1_SIZE, 0, 100);
    std::cout << "Первый массив после: ";
    print_array(arr1, ARR1_SIZE);
    std::cout << "Количество отрицательных элементов в первом массиве: " << count_negative_values(arr1, ARR1_SIZE) << std::endl;

    std::cout << std::endl;

    int *arr2 = create_int_array(ARR2_SIZE);
    std::cout << "Второй массив до: ";
    print_array(arr2, ARR2_SIZE);
    change_min_and_max_values_in_array(arr2, ARR2_SIZE, 0, 100);
    std::cout << "Второй массив после: ";
    print_array(arr2, ARR2_SIZE);
    std::cout << "Количество отрицательных элементов вo втором массиве: " << count_negative_values(arr2, ARR2_SIZE) << std::endl;

    delete[] arr1;
    delete[] arr2;

    return 0;
}

int *create_int_array(int size)
{
    int *array = new int[size];

    for (size_t i = 0; i < size; i++)
    {
        array[i] = std::rand() % (MAX_ARR_VALUE - MIN_ARR_VALUE) + MIN_ARR_VALUE;
    }

    return array;
}

void print_array(int *arr, int size)
{
    std::cout << '[';
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i];
        if (i != size - 1)
        {
            std::cout << ", ";
        }
    }
    std::cout << ']' << std::endl;
}

void change_min_and_max_values_in_array(int *arr, int size, int min_change, int max_change)
{
    int min = 0;
    int max = 0;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }

        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == min)
        {
            arr[i] = min_change;
        }
        else if (arr[i] == max)
        {
            arr[i] = max_change;
        }
    }
}

int count_negative_values(int *arr, int size)
{
    int counter = 0;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] < 0)
        {
            counter++;
        }
    }

    return counter;
}
