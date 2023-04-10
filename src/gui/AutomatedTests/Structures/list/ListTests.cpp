//
// Created by Piotr Szczypior on 10/04/2023.
//

#include "ListTests.h"
#include "../../../Utils/Utils.h"

void ListTests::program_loop() {
    bool exit_request = false;

    while (!exit_request) {
        menu();
        int input;
        input = Utils::get_input();

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

void ListTests::menu() {

}
