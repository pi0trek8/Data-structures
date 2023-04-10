//
// Created by Piotr Szczypior on 09/04/2023.
//

#include "Gui.h"
#include "../Collections/Array/Array.h"
#include "../Collections/DoubleList/DoubleList.h"
#include "../Collections/BinaryHeap/BinaryHeap.h"
#include "Utils/Utils.h"
#include "CollectionUi/ArrayUi/ArrayUi.h"
#include "CollectionUi/ListUi/ListUi.h"
#include "CollectionUi/HeapUi/HeapUi.h"
#include "CollectionUi/RBTreeUi/RedBlackTreeUi.h"
#include "AutomatedTests/AutomatedTests.h"
#include <iostream>

void Gui::program_loop() {
    bool program_exit_requested = false;

    while (!program_exit_requested) {
        Utils::clear_console();
        show_menu();
        int program_input = Utils::get_input();

        switch (program_input) {
            case 1: {
                Utils::clear_console();
                AutomatedTests::program_loop();
                break;
            }
            case 2: {
                Utils::clear_console();
                bool go_back_request = false;
                while (!go_back_request) {
                    collection_menu();
                    int input = Utils::get_input();
                    switch (input) {
                        case 1: {
                            ArrayUi::program_loop();
                            break;
                        }
                        case 2: {
                            ListUi::program_loop();
                            break;
                        }
                        case 3: {
                            HeapUi::program_loop();
                            break;
                        }
                        case 4: {
                            RedBlackTreeUi::program_loop();
                            break;
                        }
                        case 5: {
                            go_back_request = true;
                            break;
                        }
                        default:
                            continue;
                    }
                }
            }
            case 3:
                program_exit_requested = true;
            default:
                continue;
        }
    }
}

void Gui::show_menu() {
    std::cout << "1. Automated tests" << std::endl;
    std::cout << "2. Manual tests" << std::endl;
    std::cout << "3. Exit" << std::endl;
    std::cout << "Choice (1-3): ";
}

void Gui::collection_menu() {
    std::cout << "1. Dynamic array" << std::endl;
    std::cout << "2. Two way list" << std::endl;
    std::cout << "3. Maximum heap" << std::endl;
    std::cout << "4. Red black tree" << std::endl;
    std::cout << "5. Go back" << std::endl;
    std::cout << "Choice (1-5): ";
}

