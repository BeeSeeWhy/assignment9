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
    Patient()
        { priority = 0; name = ""; }
    Patient(int p, string n)
        { priority = p; name = n; }
    int getPriority(string n)
        { return priority; }
    void  printName () const
        { cout << name; }
    void setPriority(int p)
        { priority = p; }
    string getName () const
        { return name; }
    void setName(string n)
        { name = n; }
    friend bool operator < (const Patient& p1, const Patient& p2)
        { return p1.priority < p2.priority; }
    friend bool operator > (const Patient& p1, const Patient& p2)
        { return p1.priority < p2.priority; }
    friend bool operator <= (const Patient& p1, const Patient& p2)
        { return p1.priority <= p2.priority; }
}; // End Patient
#endif
