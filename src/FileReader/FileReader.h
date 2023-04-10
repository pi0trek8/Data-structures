//
// Created by Piotr Szczypior on 25/03/2023.
//

#ifndef LIST_FILEREADER_H
#define LIST_FILEREADER_H

#include <string>
#include <fstream>
#include <algorithm>
#include "iostream"

using namespace std;

class FileReader {
public:

    template<class T>
    T* read_collection_from_file(std::string file_path);
};

template<class T>
T* FileReader::read_collection_from_file(std::string file_path) {
    T *collection = new T();
    fstream file;
    file.open(file_path, ios::in);

    if (!file.is_open()) {
        cout << "File " << file_path << " not found. Aborting operation - 'reading Collections from file' ..." << endl;
        return collection;
    }

    for (std::string line; getline(file, line);) {
        try {
            line.erase(std::remove_if(line.begin(), line.end(), ::isspace),
                       line.end());
            collection->push_back(std::stoi(line));
        } catch (std::invalid_argument ex) {
            cout << "Invalid argument: " << line << " in " << ex.what() << endl;
        }
    }
    file.close();

    return collection;
}

#endif //LIST_FILEREADER_H
