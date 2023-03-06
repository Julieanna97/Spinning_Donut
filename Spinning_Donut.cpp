// Spinning donut in your screen

#include <iostream>
#include <cmath>

const int width = 80;
const int height = 40;
const double speed = 0.05;

int main() {
    double A = 1.0, B = 2.0;
    char screen[height][width];

    while (true) {
        double cosA = cos(A), sinA = sin(A);
        double cosB = cos(B), sinB = sin(B);

        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                double z = 1.0 / (x * cosB + y * sinB + 5.0);
                double fX = x * cosA * z - y * sinA * z;
                double fY = x * sinA * z + y * cosA * z;
                int iX = static_cast<int>(fX + width / 2);
                int iY = static_cast<int>(fY + height / 2);

                if (iX >= 0 && iX < width && iY >= 0 && iY < height) {
                    screen[iY][iX] = '*';
                }
            }
        }

        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                std::cout << screen[y][x];
                screen[y][x] = ' ';
            }
            std::cout << '\n';
        }

        A += speed;
        B += speed;
    }

    return 0;
}
