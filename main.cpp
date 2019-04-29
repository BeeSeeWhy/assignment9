#include <iostream>
#include <string>
#include "Patient.h"
#include "Heap.h"
#include "PrecondViolatedExcept.h"
using namespace std;

int main ()
{
    Heap ER;
    ER.add(5, "Bob");
    ER.add(9, "Mary");
    cout << ER.peekTop() << " will now see the doctor.\n";
    ER.remove();
    ER.add(3, "Julio");
    ER.add(7, "Stacy");
    ER.add(4, "Paul");
    ER.add(2, "Reiko");
    ER.add(6, "Jennifer");
    ER.add(5, "Chang");
    cout << ER.peekTop() << " will now see the doctor.\n";
    ER.remove();
    cout << ER.peekTop() << " will now see the doctor.\n";
    ER.remove();
    cout << ER.peekTop() << " will now see the doctor.\n";
    ER.remove();
    return 0;
}
