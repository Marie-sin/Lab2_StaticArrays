#include "menu.h"
#include <iostream>

int showMenu() {
    int choice;

    std::cout << "\n ===== MAIN MENU =====\n";
    std::cout << "\n ===== CHOOSE THE STAGE: =====\n";
    std::cout << "3 - Sorting algorithms\n";
    std::cout << "4 - Find minimum and maximum\n";
    std::cout << "5 - Find average and its indices\n";
    std::cout << "6 - Count elements less than a and greater than b\n";
    std::cout << "7 - Search for an element\n";
    std::cout << "8 - Exchange two elements\n";
    std::cout << "9 - Replace multiples of 3 with zero\n";
    std::cout << "0 - Exit\n";
    std::cout << "Your choice: ";

    while (!(std::cin >> choice)) {
        std::cout << "Invalid input! Enter a number: ";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }

    return choice;
}