//
// Created by Piotr Szczypior on 09/04/2023.
//

#include <iostream>
#include "ArrayUi.h"
#include "../../Utils/Utils.h"
#include "../../../Collections/Array/Array.h"
#include "../../../FileReader/FileReader.h"

void ArrayUi::program_loop() {
    bool go_back_request = false;
    auto *array = new Array();

    while (!go_back_request) {
        Utils::clear_console();
        show_menu();
        int input = Utils::get_input();

        switch (input) {
            case 1: {
                Utils::clear_console();
                std::cout << "Value: ";
                int value = Utils::get_input();
                std::cout << "Index: ";
                int index = Utils::get_input();
                array->insert(value, index);
                break;
            }
            case 2: {
                Utils::clear_console();
                std::cout << "Value: ";
                int value = Utils::get_input();
                array->push_front(value);
                break;
            }
            case 3: {
                Utils::clear_console();
                std::cout << "Value: ";
                int value = Utils::get_input();
                array->push_back(value);
                break;
            }
            case 4: {
                Utils::clear_console();
                std::cout << "Index: ";
                int index = Utils::get_input();
                array->remove(index);
                Utils::press_any_to_continue();
                break;
            }
            case 5: {
                Utils::clear_console();
                array->pop_front();
                Utils::press_any_to_continue();
                break;
            }
            case 6: {
                Utils::clear_console();
                array->pop_back();
                Utils::press_any_to_continue();
                break;
            }
            case 7: {
                Utils::clear_console();
                std::cout << "Value: ";
                int value = Utils::get_input();
                std::cout << (array->find(value) ? "Value has been found" : "Value has not been found") << std::endl;
                Utils::press_any_to_continue();
                break;
            }
            case 8: {
                Utils::clear_console();
                std::cout << "Wrong index will trigger exception. Index: ";
                int index = Utils::get_input();
                std::cout << "Found value: ";
                std::cout << array->get(index) << std::endl;
                Utils::press_any_to_continue();
                break;
            }
            case 9: {
                Utils::clear_console();
                std::cout << "First index: ";
                int index1 = Utils::get_input();
                std::cout << "Second index: ";
                int index2 = Utils::get_input();
                array->swap(index1, index2);
                Utils::press_any_to_continue();
                break;
            }
            case 10: {
                Utils::clear_console();
                array->print();
                Utils::press_any_to_continue();
                break;
            }
            case 11: {
                FileReader fileReader;
                Utils::clear_console();
                std::cout << "Enter file path: ";
                std::cin.clear();
                std::string file_name;
                std::cin >> file_name;
                delete array;
                array = fileReader.read_collection_from_file<Array>(file_name);
                break;
            }
            case 12: {
                delete array;
                go_back_request = true;
                break;
            }
            default:
                continue;
        }
    }
}

void ArrayUi::show_menu() {
    std::cout << "1. Add at index" << std::endl;
    std::cout << "2. Add at front" << std::endl;
    std::cout << "3. Add at end" << std::endl;
    std::cout << "4. Remove at index" << std::endl;
    std::cout << "5. Remove at front" << std::endl;
    std::cout << "6. Remove at end" << std::endl;
    std::cout << "7. Find value" << std::endl;
    std::cout << "8. Get by index" << std::endl;
    std::cout << "9. Swap values" << std::endl;
    std::cout << "10. Print array" << std::endl;
    std::cout << "11. Read collection from file" << std::endl;
    std::cout << "12. Go back" << std::endl;
    std::cout << "Choice (1-12): ";
}
