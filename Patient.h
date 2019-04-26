#ifndef PATIENT_
#define PATIENT_
#include <iostream>
using namespace std;


class Patient
{
private:
    int priority;   // Priority number
    string name;    // Patient name
public:
    Patient();
    Patient(int p, string n)
        { priority = p; name = n; }
    int getPriority(string n)
        { return priority; }
    void printPatient() const
        { cout << name; }
    bool operator<(const Patient& name) const;
}; // End Patient
#endif
