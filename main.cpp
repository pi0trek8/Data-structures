#include <iostream>
#include "LinkedList/LinkedList.h"
#include "Array/Array.h"
#include "BinaryHeap/BinaryHeap.h"

using namespace std;

int main() {

//    Array array;
//    cout << "Size of array is "<< sizeof(array) << " and size in array: "<< array.getSize() << endl;
//    array.deleteIndex(0);
//
//   array.push_back(2);
//   array.print();
//
//   array.push_front(3);
//   array.print();
//
//   array.add(1, 69);
//   array.print();
//
//   array.pop_back();
//   array.print();
//
//   array.pop_front();
//   array.print();
//
//   array.pop_back();
//   array.print();
//
//   array.push_front(10);
//   array.print();

    BinaryHeap heap;

    heap.push(10);
    heap.push(5);
    heap.push(14);
    heap.push(4);
    heap.push(2);
    heap.push(30);

    heap.print();
    return 0;
}
