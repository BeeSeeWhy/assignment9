#include <cmath>
#include <string>
#include <utility>
#include "Heap.h"
//#include "Patient.h"

// -----------------------------------------------------------------------------
// Private member definitions
// -----------------------------------------------------------------------------


int Heap :: getLeftChildIndex(const int nodeIndex) const
{
    return 2 * nodeIndex + 1;
} // End getLeftChildIndex

int Heap :: getRightChildIndex(const int nodeIndex) const
{
    return 2 * nodeIndex + 2;
} // End getRightChildIndex

int Heap :: getParentIndex(const int nodeIndex) const
{
    return (nodeIndex - 1)/ 2;
} // End getParentIndex

bool Heap :: isLeaf(int nodeIndex) const
{
    if (items[2 * nodeIndex + 1] > items[itemCount - 1])
        return true;
    else
        return false;
} // End isLeaf

void Heap :: heapRebuild(int nodeIndex)
{
    if (!isLeaf(nodeIndex))
    {
        // The root must have a left child; assume it is the larger child
        int largerChildIndex = 2 * nodeIndex + 1;   // left child index

        // Now see if there is a right child which is larger than left child
        if (items[(2 * nodeIndex) + 2] <= items[itemCount - 1])
        {
            int rightChildIndex = 2 * nodeIndex + 2; // right child index
            if (items[rightChildIndex] > items[largerChildIndex])
                largerChildIndex = rightChildIndex;  // larger child index
        } // End if
        // If item in root is smaller than item in larger child, swap items
        if (items[nodeIndex] < items[largerChildIndex])
        {
            std::swap(items[nodeIndex], items[largerChildIndex]);
            // Transform the semiheap rooted at largerChildIndex into a heap
            heapRebuild (largerChildIndex);
        } // End if
    } // End if
    // Else root if a leaf, so we are done
} // End heapRebuild

void Heap :: heapCreate()
{
    for (int index = itemCount / 2 - 1; index >= 0; index--)
        heapRebuild(index);
} // End heapCreate

//------------------------------------------------------------------------------
// Public member definitions
//------------------------------------------------------------------------------

//
Heap :: Heap()
{
    itemCount = 0;
} // End default constructor

//
Heap ::
Heap(const string someArray[], const int arraySize):
    itemCount(arraySize), maxItems(2 * arraySize)
{
    // Copy given values into the array
    for (int i = 0; i < itemCount; i++)
        items[i] = someArray[i];

    // Reorganize the array into a heap
    heapCreate();
} // End array to heap constructor

bool Heap :: isEmpty() const
{
    if (itemCount == 0)
        return true;
    else
        return false;
} // End isEmpty

//
int Heap :: getNumberOfNodes() const
{
    return itemCount;
} // End getNumberOfNodes

int Heap :: getHeight() const
{
    return ceil(log2(itemCount + 1)) - 1;
} // End getHeight

string Heap :: peekTop() const throw(PrecondViolatedExcept)
{
    if (isEmpty())
        throw PrecondViolatedExcept("Attempted peak into an empty heap.");
    return items[0];
} // End peekTop

bool Heap :: add(const string& newData)
{
    if (itemCount == maxItems)
        return false;
    // Insert newData into the bottom of the tree
    items[itemCount] = newData;

    // Trickle new item up to the right spot in the tree
    int newDataIndex = itemCount;
    bool inPlace = false;
    while ( (newDataIndex > 0) && !inPlace)
    {
        int parentIndex = (newDataIndex - 1) / 2;
        if (items[newDataIndex] < items[parentIndex])
            inPlace = true;
        else
        {
            swap(items[newDataIndex], items[parentIndex]);
            newDataIndex = parentIndex;
        } // End else
    }  // End while
    itemCount++;
    return true;
} // End add


bool Heap :: remove()
{
        if (itemCount == 0)
            return false;
        else
        {
            // Copy the item from the last node and place it in the root
            items[0] = items[itemCount - 1];

            // Remove the last node
            itemCount--;
            // Make the semiheap a heap again
            heapRebuild(0);
            return true;
        }
} // End remove

void Heap :: clear()
{
    itemCount = 0;
} // End clear
