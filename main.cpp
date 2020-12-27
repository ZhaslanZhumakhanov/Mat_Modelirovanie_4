#include <iostream>
#include <iomanip>
#include <cmath>
#include <windows.h>

double Eiler(double x, double y) {
    return 2 * x * std::sqrt(y) - y;
}

int Rounding(double error) {
    int count = 0;
    while (true) {
        double tmp = error;
        if (static_cast<int>(tmp) % 10 != 0 || static_cast<int>(tmp) < 1) {
            error *= 10;
            count++;
        } else {
            count--;
            break;
        }
    }
    return count--;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    double a, b, s, error;
    std::cout << "Please enter a" << std::endl;
    std::cin >> a;
    std::cout << "Please enter s" << std::endl;
    std::cin >> s;

    while (s < 0) {
        std::cout << "Please enter new s (s>=0)" << std::endl;
        std::cin >> s;
    }

    std::cout << "Please enter b" << std::endl;
    std::cin >> b;
    std::cout << "Please enter error" << std::endl; // Погрешность
    std::cin >> error;

    while (error <= 0 || error >= 1) {
        std::cout << "Please enter new Error (0;1)" << std::endl;
        std::cin >> error;
    }

    double x_i = a;
    double y_i = s;
    double d_yi;
    double k_1, k_2, k_3, k_4;

    int n = ceil((b - a) / sqrt(sqrt(error)));
    double h = (b - a) / n;

    for (int i = 0; i < n; i++) {
        k_1 = Eiler(x_i, y_i) * h;
        k_2 = Eiler(x_i + h / 2, y_i + k_1 / 2) * h;
        k_3 = Eiler(x_i + h / 2, y_i + k_2 / 2) * h;
        k_4 = Eiler(x_i + h, y_i + k_3) * h;
        d_yi = (k_1 + 2 * k_2 + 2 * k_3 + k_4) / 6;
        y_i += d_yi;
        x_i += h;
    }

    std::cout << "n = " << n << std::endl;
    std::cout << "h = " << h << std::endl;
    std::cout << "Last value = " << std::fixed << std::setprecision(Rounding(error)) << y_i
              << std::endl;

    return 0;
}
