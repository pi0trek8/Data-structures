#include <iostream>

#include "Collections/DoubleList/DoubleList.h"
#include "FileReader/FileReader.h"
#include "TimeTester/TimeTesterppp.h"
#include "Collections/BinaryHeap/BinaryHeap.h"
#include "TimeTester/TimeTester.h"

using namespace std;

int main() {
//    FileReader fileReader;
//    DoubleList list = fileReader.read_collection_from_file<DoubleList>("List_push_front_100.csv");
//
//    list.print();
//    cout << list.get_size();
    FileReader reader;
    BinaryHeap heap = reader.read_collection_from_file<BinaryHeap>("test.txt");

    heap.print();
//    TimeTesterppp<BinaryHeap>::make_test(100,3);
    return 0;
}
