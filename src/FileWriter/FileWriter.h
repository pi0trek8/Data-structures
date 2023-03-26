//
// Created by Piotr Szczypior on 25/03/2023.
//

#ifndef LIST_FILEWRITER_H
#define LIST_FILEWRITER_H

#include <string>
#include <fstream>
#include <iostream>

class FileWriter {

public:
    void write_to_file(std::string file_name, int elements_number, long argument);
};

void FileWriter::write_to_file(std::string file_name, int elements_number, long argument) {
    file_name += std::to_string(elements_number) + ".csv";

    std::cout<<"writing to: " << file_name << std::endl;

    std::ofstream file;
    file.open(file_name, std::ios::in | std::ios::app);

    if(file.is_open()) {
        std::string line = std::to_string(argument) + "\n";
        file << line;
    }

    file.close();
}


#endif //LIST_FILEWRITER_H
