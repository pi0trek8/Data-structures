//
// Created by Piotr Szczypior on 10/04/2023.
//

#include "RedBlackTreeTests.h"
#include "../../../Utils/Utils.h"
#include "../../../../TimeTester/TimeTester.h"
#include "../../../../Collections/RedBlackTree/RedBlackTree.h"

void RedBlackTreeTests::program_loop() {
    bool exit_request = false;
    TimeTester timeTester;

    while (!exit_request) {
        menu();
        int input = Utils::get_input();

        switch (input) {
            case 1: {
                Utils::clear_console();
                std::cout << "Number of tests: ";
                int test_number = Utils::get_input();
                std::cout << "Collection size: ";
                int collection_size = Utils::get_input();
                timeTester.test_push_back<RedBlackTree>(collection_size, test_number);
                Utils::press_any_to_continue();
                break;
            }
            case 2: {
                Utils::clear_console();
                std::cout << "Number of tests: ";
                int test_number = Utils::get_input();
                std::cout << "Collection size: ";
                int collection_size = Utils::get_input();
                timeTester.test_remove_element<RedBlackTree>(collection_size, test_number);
                Utils::press_any_to_continue();
                break;
            }
            case 3: {
                Utils::clear_console();
                std::cout << "Number of tests: ";
                int test_number = Utils::get_input();
                std::cout << "Collection size: ";
                int collection_size = Utils::get_input();
                timeTester.test_find<RedBlackTree>(collection_size, test_number);
                Utils::press_any_to_continue();
                break;
            }
            case 4: {
                exit_request = true;
                break;
            }
            default:
                continue;
        }
    }
}

void RedBlackTreeTests::menu() {
    std::cout << "1. TEST - add" << std::endl;
    std::cout << "2. TEST - remove value" << std::endl;
    std::cout << "3. TEST - find value" << std::endl;
    std::cout << "4. Go back" << std::endl;
    std::cout << "Choice (1-4): ";
}
