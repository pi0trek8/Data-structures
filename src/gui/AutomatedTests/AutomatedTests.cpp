//
// Created by Piotr Szczypior on 10/04/2023.
//

#include "AutomatedTests.h"
#include "../Utils/Utils.h"

void AutomatedTests::program_loop() {
    bool exit_request = false;

    while (!exit_request) {
        menu();
        int input = Utils::get_input();

        switch (input) {
            case 1: {

            }
            case 2: {

            }
            case 3: {

            }
            case 4: {

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
