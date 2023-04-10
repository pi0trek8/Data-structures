//
// Created by Piotr Szczypior on 10/04/2023.
//

#include "ArrayTests.h"
#include "../../../Utils/Utils.h"
#include "../../../../TimeTester/TimeTester.h"
#include "../../../../Collections/Array/Array.h"

void ArrayTests::program_loop() {
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
                timeTester.test_insert<Array>(collection_size, test_number);
                Utils::press_any_to_continue();
                break;
            }
            case 2: {
                Utils::clear_console();
                std:: cout << "Number of tests: ";
                int test_number = Utils::get_input();
                std:: cout << "Collection size: ";
                int collection_size = Utils::get_input();
                timeTester.test_push_front<Array>(collection_size, test_number);
                Utils::press_any_to_continue();
                break;
            }
            case 3: {
                Utils::clear_console();
                std:: cout << "Number of tests: ";
                int test_number = Utils::get_input();
                std:: cout << "Collection size: ";
                int collection_size = Utils::get_input();
                timeTester.test_push_back<Array>(collection_size, test_number);
                Utils::press_any_to_continue();
                break;
            }
            case 4: {
                Utils::clear_console();
                std:: cout << "Number of tests: ";
                int test_number = Utils::get_input();
                std:: cout << "Collection size: ";
                int collection_size = Utils::get_input();
                timeTester.test_remove<Array>(collection_size, test_number);
                Utils::press_any_to_continue();
                break;
            }
            case 5: {
                Utils::clear_console();
                std:: cout << "Number of tests: ";
                int test_number = Utils::get_input();
                std:: cout << "Collection size: ";
                int collection_size = Utils::get_input();
                timeTester.test_pop_front<Array>(collection_size, test_number);
                Utils::press_any_to_continue();
                break;
            }
            case 6: {
                Utils::clear_console();
                std:: cout << "Number of tests: ";
                int test_number = Utils::get_input();
                std:: cout << "Collection size: ";
                int collection_size = Utils::get_input();
                timeTester.test_pop_back<Array>(collection_size, test_number);
                Utils::press_any_to_continue();
                break;
            }
            case 7: {
                Utils::clear_console();
                std:: cout << "Number of tests: ";
                int test_number = Utils::get_input();
                std:: cout << "Collection size: ";
                int collection_size = Utils::get_input();
                timeTester.test_find<Array>(collection_size, test_number);
                Utils::press_any_to_continue();
                break;
            }
            case 8: {
                Utils::clear_console();
                std:: cout << "Number of tests: ";
                int test_number = Utils::get_input();
                std:: cout << "Collection size: ";
                int collection_size = Utils::get_input();
                timeTester.test_get<Array>(collection_size, test_number);
                Utils::press_any_to_continue();
                break;
            }
            case 9: {
                exit_request = true;
                break;
            }
            default:
                continue;
        }
    }
}

void ArrayTests::menu() {
    std::cout << "1. TEST - add at index" << std::endl;
    std::cout << "2. TEST - add at front" << std::endl;
    std::cout << "3. TEST - add at end" << std::endl;
    std::cout << "4. TEST - remove_element at index" << std::endl;
    std::cout << "5. TEST - remove_element at front" << std::endl;
    std::cout << "6. TEST - remove_element at end" << std::endl;
    std::cout << "7. TEST - find value" << std::endl;
    std::cout << "8. TEST - get by index" << std::endl;
    std::cout << "9. Go back" << std::endl;
    std::cout << "Choice (1-9): ";
}
