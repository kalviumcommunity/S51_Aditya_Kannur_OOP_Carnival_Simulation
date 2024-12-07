#include <iostream>
#include <string>
using namespace std;

// Abstract Class for Display
class IEntertainmentDisplay {
public:
    virtual void display() const = 0;  // Pure virtual function for displaying details
    virtual ~IEntertainmentDisplay() {} // Virtual destructor for proper cleanup
};

// Base Class: Entertainment
class Entertainment : public IEntertainmentDisplay {
protected:
    string name;
    double duration;
    int fare;

public:
    // Constructors
    Entertainment() : name(""), duration(0.0), fare(0) {}
    Entertainment(string n) : name(n), duration(0.0), fare(0) {}
    Entertainment(string n, double d) : name(n), duration(d), fare(0) {}
    Entertainment(string n, double d, int f) : name(n), duration(d), fare(f) {}

    // Virtual display function
    virtual void display() const override {
        cout << "Name: " << name << ", Duration: " << duration 
             << " minutes, Fare: " << fare << " INR" << endl;
    }

    virtual ~Entertainment() {} // Virtual destructor
};

// Derived Class 1: Rides
class Rides : public Entertainment {
private:
    static int totalRides;

public:
    Rides(string n = "", double d = 0.0, int f = 0)
        : Entertainment(n, d, f) {
        if (f > 0) {
            totalRides++;
        }
    }

    static int getTotalRides() {
        return totalRides;
    }

    // Override display function
    void display() const override {
        cout << "Ride Name: " << name << ", Duration: " << duration 
             << " minutes, Fare: " << fare << " INR" << endl;
    }
};

// Static member initialization for totalRides
int Rides::totalRides = 0;

// Derived Class 2: Stalls
class Stalls : public Entertainment {
public:
    Stalls(string n = "", double d = 0.0, int f = 0)
        : Entertainment(n, d, f) {}

    // Override display function
    void display() const override {
        cout << "Stall Name: " << name << ", Duration: " << duration 
             << " minutes, Fare: " << fare << " INR" << endl;
    }
};

// Main function demonstrating abstract class and virtual function
int main() {
    // Array of IEntertainmentDisplay pointers
    IEntertainmentDisplay* items[3];

    // Storing objects of derived classes in the array
    items[0] = new Rides("Ferris Wheel", 5.0, 300);
    items[1] = new Stalls("Food Stall", 2.0, 50);
    items[2] = new Entertainment("Haunted House", 15.0, 200);

    // Displaying details using polymorphism
    cout << "Entertainment Details:\n";
    for (int i = 0; i < 3; ++i) {
        items[i]->display();
    }

    // Cleanup
    for (int i = 0; i < 3; ++i) {
        delete items[i];
    }

    // Displaying total number of rides
    cout << "\nTotal Rides: " << Rides::getTotalRides() << endl;

    return 0;
}
