//
// Created by Piotr Szczypior on 09/04/2023.
//

#include "RedBlackTreeUi.h"
#include "../../../Collections/RedBlackTree/RedBlackTree.h"
#include "../../Utils/Utils.h"
#include "../../../FileReader/FileReader.h"
#include <iostream>


void RedBlackTreeUi::program_loop() {
    bool go_back_request = false;
    auto *redBlackTree = new RedBlackTree();

    while (!go_back_request) {
        Utils::clear_console();
        show_menu();
        int input = Utils::get_input();

        switch (input) {
            case 1: {
                Utils::clear_console();
                std::cout << "Value: ";
                int value = Utils::get_input();
                redBlackTree->push_back(value);
                break;
            }
            case 2: {
                Utils::clear_console();
                std::cout << "Value: ";
                int value = Utils::get_input();
                redBlackTree->remove_element(value);
                break;
            }
            case 3: {
                Utils::clear_console();
                std::cout << "Value: ";
                int value = Utils::get_input();
                std::cout << (
                        redBlackTree->find(value) ?
                        "Value has been found." : "Value has not been found"
                ) << std::endl;
                Utils::press_any_to_continue();
                break;
            }
            case 4: {
                Utils::clear_console();
                redBlackTree->print();
                Utils::press_any_to_continue();
                break;
            }
            case 5: {
                FileReader fileReader;
                Utils::clear_console();
                std::cout << "Enter file path: ";
                std::cin.clear();
                std::string file_name;
                std::cin >> file_name;
                delete redBlackTree;
                redBlackTree = fileReader.read_collection_from_file<RedBlackTree>(file_name);
                break;
            }
            case 6: {
                Utils::clear_console();
                delete redBlackTree;
                go_back_request = true;
                break;
            }
            default:
                continue;
        }
    }
}

void RedBlackTreeUi::show_menu() {
    std::cout << "1. Add" << std::endl;
    std::cout << "2. Remove value" << std::endl;
    std::cout << "3. Find value" << std::endl;
    std::cout << "4. Display" << std::endl;
    std::cout << "5. Read collection from file" << std::endl;
    std::cout << "6. Go back" << std::endl;
    std::cout << "Choice (1-6): ";
}

