#include <iostream>

#include "Collections/DoubleList/DoubleList.h"
#include "FileReader/FileReader.h"
#include "TimeTester/TimeTesterppp.h"
#include "Collections/BinaryHeap/BinaryHeap.h"
#include "TimeTester/TimeTester.h"
#include "Collections/RedBlackTree/RedBlackTree.h"

using namespace std;

int main() {

    RedBlackTree redBlackTree;
    redBlackTree.push_back(10);
    redBlackTree.push_back(11);
    redBlackTree.push_back(13);

    redBlackTree.print();
    redBlackTree.push_back(12);
    redBlackTree.print();

    redBlackTree.push_back(16);
    redBlackTree.print();
    redBlackTree.push_back(15);
    redBlackTree.print();

    return 0;
}
