//
// Created by Piotr Szczypior on 09/04/2023.
//

#include "HeapUi.h"
#include "../../Utils/Utils.h"
#include "../../../Collections/BinaryHeap/BinaryHeap.h"
#include "../../../FileReader/FileReader.h"
#include <iostream>

void HeapUi::program_loop() {
    bool go_back_request = false;
    auto *heap = new BinaryHeap();

    while (!go_back_request) {
        Utils::clear_console();
        show_menu();
        int input = Utils::get_input();

        switch (input) {
            case 1: {
                Utils::clear_console();
                std::cout << "Value: ";
                int value = Utils::get_input();
                heap->push_back(value);
                break;
            }
            case 2: {
                Utils::clear_console();
                heap->pop_front();
                break;
            }
            case 3: {
                Utils::clear_console();
                //TODO: implement remove(value)
                break;
            }
            case 4: {
                Utils::clear_console();
                std::cout << "Value: ";
                int value = Utils::get_input();
                bool isSuccess = heap->find_element(value);
                std::cout << "Value " << value << (isSuccess ? "has been found." : "has not been found") << std::endl;
                Utils::press_any_to_continue();
                break;
            }
            case 5: {
                Utils::clear_console();
                heap->print();
                Utils::press_any_to_continue();
                break;
            }
            case 6: {
                FileReader fileReader;
                Utils::clear_console();
                std::cout << "Enter file path: ";
                std::cin.clear();
                std::string file_name;
                std::cin >> file_name;
                delete heap;
                heap = fileReader.read_collection_from_file<BinaryHeap>(file_name);
                break;
            }
            case 7: {
                Utils::clear_console();
                go_back_request = true;
                break;
            }
            default:
                continue;
        }
    }
}

void HeapUi::show_menu() {
    std::cout << "1. Add" << std::endl;
    std::cout << "2. Remove from top" << std::endl;
    std::cout << "3. Remove value NOT IMPLEMENTED!!!!!!" << std::endl;
    std::cout << "4. Find value" << std::endl;
    std::cout << "5. Display" << std::endl;
    std::cout << "6. Read collection from file" << std::endl;
    std::cout << "7. Go back" << std::endl;
    std::cout << "Choice (1-7): ";
}
