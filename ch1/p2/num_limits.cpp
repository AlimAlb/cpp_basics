#include <iostream>
#include <limits>  // необходимо для numeric_limits

int main() {
    // посчитаем для типа int:
    std::cout << "minimum value: " << std::numeric_limits<unsigned long>::min() << "\n"
              << "maximum value: " << std::numeric_limits<unsigned long>::max() << "\n";
}