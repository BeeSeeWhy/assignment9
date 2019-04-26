#ifndef HEAP_
#define HEAP_
#include <memory>
//#include "Patient.h"
#include "PrecondViolatedExcept.h"

class Heap 
{
private:
    static const int ROOT_INDEX = 0;        // Helps with readability
    static const int DEFAULT_CAPACITY = 21; // Small Capacity for testing
    string items[DEFAULT_CAPACITY];       // Array of heap items
    int itemCount;                          // Current count of heap items
    int maxItems;                           // Maximum capacity of the heap

    int getLeftChildIndex(const int nodeIndex) const;
    int getRightChildIndex(const int nodeIndex) const;
    int getParentIndex(int nodeIndex) const;
    bool isLeaf(int nodeIndex) const;

    // Converts semiheap to heap
    void heapRebuild(int nodeIndex);

    // Creates a heap from an array
    void heapCreate();

public:
    Heap();
    Heap(const string someArray[], const int arraySize);
    //~Heap();

    // Heap interface public methods
    bool isEmpty() const;
    int getNumberOfNodes() const;
    int getHeight() const;
    string peekTop() const throw(PrecondViolatedExcept);
    bool add(const string& newData);
    bool remove();
    void clear();
}; // End Heap
#endif
