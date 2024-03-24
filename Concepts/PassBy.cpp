#include <iostream>
#include <string>

// Call by value or pass by value.
void passByValue(int x, int y) // Values passed in are newly created instance variables.
{
    int z = x;
    x = y;
    y = z;
}
// Call by reference or pass by reference.
void passByReference(int &x, int &y) // Values passed in are a reference to the variables found in main.
{
    int z = x;
    x = y;
    y = z;
}

void passByAddress(int *x, int *y)
{
    int z = *x;
    *x = *y;
    *y = z;
}

int main(int argc, char const *argv[])
{

    int a = 5, b = 6;

    std::cout << "Before swapping: " << std::endl
              << "a: " << a << " b: " << b << std::endl;

    passByAddress(&a, &b);

    std::cout << "After swapping: " << std::endl
              << "a: " << a << " b: " << b << std::endl;

    return 0;
}