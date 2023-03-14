#include <iostream>
#include "LinkedList/LinkedList.h"
#include "Array/Array.h"
#include "BinaryHeap/BinaryHeap.h"

using namespace std;

int main() {

    Array array;
//    cout << "Size of array is "<< sizeof(array) << " and size in array: "<< array.getSize() << endl;
//    array.deleteIndex(0);
//
    array.push_back(2);
    array.push_front(3);
    array.push_front(59);
    array.print();
    array.swap(0, 2);

    array.print();

    BinaryHeap heap;

    heap.push(10);
    heap.push(5);
    heap.push(14);
    heap.push(30);
    heap.push(40);

    heap.print();
    cout << endl;
    heap.pop();

    heap.print();
    heap.printHeap();



    return 0;
}
