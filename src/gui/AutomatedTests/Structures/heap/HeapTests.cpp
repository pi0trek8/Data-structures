//
// Created by Piotr Szczypior on 10/04/2023.
//

#include "HeapTests.h"
#include "../../../Utils/Utils.h"
#include "../../../../TimeTester/TimeTester.h"
#include "../../../../Collections/BinaryHeap/BinaryHeap.h"

void HeapTests::program_loop() {
    bool exit_request = false;
    TimeTester timeTester;

    while (!exit_request) {
        menu();
        int input = Utils::get_input();

        switch (input) {
            case 1: {
                Utils::clear_console();
                std:: cout << "Number of tests: ";
                int test_number = Utils::get_input();
                std:: cout << "Collection size: ";
                int collection_size = Utils::get_input();
                timeTester.test_push_back<BinaryHeap>(collection_size, test_number);
                Utils::press_any_to_continue();
                break;
            }
            case 2: {
                Utils::clear_console();
                std:: cout << "Number of tests: ";
                int test_number = Utils::get_input();
                std:: cout << "Collection size: ";
                int collection_size = Utils::get_input();
                //TODO: implement
//                timeTester.test_push_back<BinaryHeap>(collection_size, test_number);
                Utils::press_any_to_continue();
                break;
            }
            case 3: {
                Utils::clear_console();
                std:: cout << "Number of tests: ";
                int test_number = Utils::get_input();
                std:: cout << "Collection size: ";
                int collection_size = Utils::get_input();
                timeTester.test_pop_front<BinaryHeap>(collection_size, test_number);
                Utils::press_any_to_continue();
                break;
            }
            case 4: {
                Utils::clear_console();
                std:: cout << "Number of tests: ";
                int test_number = Utils::get_input();
                std:: cout << "Collection size: ";
                int collection_size = Utils::get_input();
                timeTester.test_find<BinaryHeap>(collection_size, test_number);
                Utils::press_any_to_continue();
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

void HeapTests::menu() {
    std::cout << "1. TEST - add" << std::endl;
    std::cout << "2. TEST - remove_element from top" << std::endl;
    std::cout << "3. TEST - remove_element value NOT IMPLEMENTED!!!!!!" << std::endl;
    std::cout << "4. TEST - find value" << std::endl;
    std::cout << "5. Go back" << std::endl;
    std::cout << "Choice (1-7): ";
}
