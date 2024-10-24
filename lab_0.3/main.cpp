#include <iostream>
#include <cmath>

using std::cout, std::cin, std::endl, std::pow, std::cos;

int main()
{
    const double X = 1.64;
    const int N = 12;
    const double cos_of_X_squared = pow(cos(X), 2);

    char user_input;
    double y = 0;

    cout << "Введите:" << endl;
    cout << " * 1/f/F для использования цикла for" << endl;
    cout << " * 2/w/W для использования цикла while" << endl;
    cout << " * 3/d/D для использования цикла do while" << endl;
    cout << " * q/Q для выхода из программы" << endl;

    while (true)
    {
        cout << "Ваш выбор: ";
        cin >> user_input;

        if (user_input == 'q' || user_input == 'Q')
        {
            break;
        }

        switch (user_input)
        {
        case '1':
        case 'f':
        case 'F':
        {
            y = 0;
            for (int i = 3; i <= N; i++)
            {
                y += cos_of_X_squared + 2.8 * pow(cos(i), 2);
            }

            cout << pow(y, 4) << endl;
            break;
        }
        case '2':
        case 'w':
        case 'W':
        {
            y = 0;
            int i = 3;

            while (i <= N)
            {
                y += cos_of_X_squared + 2.8 * pow(cos(i), 2);
                i++;
            }

            cout << pow(y, 4) << endl;
            break;
        }
        case '3':
        case 'd':
        case 'D':
        {
            y = 0;
            int i = 3;

            do
            {
                y += cos_of_X_squared + 2.8 * pow(cos(i), 2);
                i++;
            } while (i <= N);

            cout << pow(y, 4) << endl;
            break;
        }
        default:
        {
            cout << "НЕВЕРНЫЙ СИМВОЛ!" << endl;
        }
        }
    }

    return 0;
}