#include <iostream>
#include <string>
#include <math.h>

void placeValue(int num)
{
    std::string placeValues[] = {
        "Ones",
        "Tens",
        "Hundreds",
        "Thousands",
        "Ten Thousands",
        "Hundred Thousands",
        "Millions",
    };
    int temp = num;
    int placeValue = 0;

    while (num > 0)
    {
        num /= 10;
        ++placeValue;
    }

    std::cout << "Highest place value is '" << placeValues[placeValue - 1] << "'\n\n";

    for (int i = placeValue - 1; i >= 0; --i)
    {
        std::cout << "i: " << i << "\n";
        std::cout << "temp: " << temp << "\n";
        int p = pow(10, i);
        std::cout << "p: " << p << "\n";
        int cur = temp / p;
        std::cout << "cur: " << cur << "\n";
        int placeValue = cur * p;
        std::cout << "placeValue: " << placeValue << "\n";
        std::cout << cur << " is in the " << placeValues[i] << " place and has a place value of " << placeValue << "\n\n";
        temp %= p;
    }
}

int main(void)
{
    int num = 0;

    std::cout << "Input a number: ";
    std::cin >> num;

    placeValue(num);
    return EXIT_SUCCESS;
}