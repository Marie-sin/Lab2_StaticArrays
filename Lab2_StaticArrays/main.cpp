#include "menu.h"
#include "array.h"
#include "sorting.h"
#include "search.h"
#include "individualTask.h"
#include "stages.h"

#include <iostream>

int main() {

    //==== ЭТАП 2 ====
    std::cout << " ==== STAGE 2 ====\n\n";
    int arr[MAX_N];
    int N; 
    int choice;

    do {
        std::cout << "Choose array creation method:\n";
        std::cout << "1 - Manual input\n";
        std::cout << "2 - Random array (100 elements)\n";
        std::cout << "Your choice: ";

        if (!(std::cin >> choice)) {
            std::cout << "Invalid input! Enter 1 or 2.\n";

            std::cin.clear();
            std::cin.ignore(10000, '\n');
            choice = 0;
        }
        else if (choice != 1 && choice != 2) {
            std::cout << "Invalid choice! Enter 1 or 2.\n";
        }
    } while (choice != 1 && choice != 2);

    if (choice == 1) {
        std::cout << "Enter array size (1-100): ";
        std::cin >> N;

        if (N < 1 || N > MAX_N) {
            std::cout << "Invalid array size!\n";
            return 0;
        }

        std::cout << "Enter array elements:\n";
        for (int i = 0; i < N; i++) {
            std::cin >> arr[i];
        }
    }
    else if (choice == 2) {
        N = MAX_N;
        fillArray(arr, N);
    }

    std::cout << "Original array:\n";
    printArray(arr, N);

    int menuChoice;

    do {
        menuChoice = showMenu();

        switch (menuChoice) {
        case 3:
            runStage3(arr, N);
            break;

        case 4:
            runStage4(arr, N);
            break;

        case 5:
            runStage5(arr, N);
            break;

        case 6:
            runStage6(arr, N);
            break;

        case 7:
            runStage7(arr, N);
            break;

        case 8:
            runStage8(arr, N);
            break;

        case 9:
            runStage9(arr, N);
            break;

        case 0:
            std::cout << "Exiting...\n";
            break;

        default:
            std::cout << "Invalid choice!\n";
        }

    } while (menuChoice != 0);

    return 0;
}