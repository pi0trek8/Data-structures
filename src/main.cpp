#include <iostream>

#include "Collections/DoubleList/DoubleList.h"
#include "FileReader/FileReader.h"
#include "TimeTester/TimeTesterppp.h"
#include "Collections/BinaryHeap/BinaryHeap.h"
#include "TimeTester/TimerTester.h"

using namespace std;

int main() {
//
//    TimerTester timerTester;
//
//    timerTester.test_get<DoubleList>(100, 3);

    TimeTesterppp<BinaryHeap>::make_test(100,3);
    return 0;
}
