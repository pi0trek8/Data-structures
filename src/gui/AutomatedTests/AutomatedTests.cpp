//
// Created by Piotr Szczypior on 10/04/2023.
//

#include "AutomatedTests.h"
#include "../Utils/Utils.h"
#include "Structures/array/ArrayTests.h"
#include "Structures/redBlackTree/RedBlackTreeTests.h"
#include "Structures/heap/HeapTests.h"
#include "Structures/list/ListTests.h"

void AutomatedTests::program_loop() {
    bool exit_request = false;

    while (!exit_request) {
        menu();
        int input = Utils::get_input();

        switch (input) {
            case 1: {
                Utils::clear_console();
                ArrayTests::program_loop();
                break;
            }
            case 2: {
                Utils::clear_console();
                ListTests::program_loop();
                break;
            }
            case 3: {
                Utils::clear_console();
                HeapTests::program_loop();
                break;
            }
            case 4: {
                Utils::clear_console();
                RedBlackTreeTests::program_loop();
                break;
            }
            case 5: {
                exit_request = true;
                break;
            }
            default:
                continue;
        }
    }
}

void AutomatedTests::menu() {
    cout << "1. Dynamic array" << std::endl;
    cout << "2. Two way list" << std::endl;
    cout << "3. Maximum heap" << std::endl;
    cout << "4. Red black tree" << std::endl;
    cout << "5. Go back" << std::endl;
    cout << "Choice (1-5): ";
}
