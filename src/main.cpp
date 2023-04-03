#include <iostream>

#include "Collections/DoubleList/DoubleList.h"
#include "FileReader/FileReader.h"
#include "TimeTester/TimeTesterppp.h"
#include "Collections/BinaryHeap/BinaryHeap.h"
#include "TimeTester/TimeTester.h"

using namespace std;

int main() {

    DoubleList list;
    TimeTester timeTester;
    timeTester.test_insert<DoubleList>(1000000, 5);



    return 0;
}
