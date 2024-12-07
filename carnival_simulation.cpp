#include <iostream>
#include <string>
using namespace std;

// Base Class: Entertainment
class Entertainment {
protected:
    string name;
    double duration;
    int fare;

public:
    // Default Constructor
    Entertainment() : name(""), duration(0.0), fare(0) {}

    // Constructor for Name Only
    Entertainment(string n) : name(n), duration(0.0), fare(0) {}

    // Constructor for Name and Duration
    Entertainment(string n, double d) : name(n), duration(d), fare(0) {}

    // Constructor for Name, Duration, and Fare
    Entertainment(string n, double d, int f) : name(n), duration(d), fare(f) {}

    // Getter functions
    string getName() const {
        return name;
    }

    double getDuration() const {
        return duration;
    }

    int getFare() const {
        return fare;
    }

    // Function to display the details of the Entertainment object
    virtual void display() const {
        cout << "Name: " << name << ", Duration: " << duration << " minutes, Fare: " << fare << " INR" << endl;
    }
};

// Derived Class 1: Rides
class Rides : public Entertainment {
public:
    // Constructor for Rides (inheriting from Entertainment)
    Rides(string n = "", double d = 0.0, int f = 0) : Entertainment(n, d, f) {}

    // Overriding display function
    void display() const override {
        cout << "Ride Name: " << name << ", Duration: " << duration << " minutes, Fare: " << fare << " INR" << endl;
    }
};

// Derived Class 2: Stalls
class Stalls : public Entertainment {
public:
    // Constructor for Stalls (inheriting from Entertainment)
    Stalls(string n = "", double d = 0.0, int f = 0) : Entertainment(n, d, f) {}

    // Overriding display function
    void display() const override {
        cout << "Stall Name: " << name << ", Duration: " << duration << " minutes, Fare: " << fare << " INR" << endl;
    }
};

// Main function demonstrating LSP (Liskov Substitution Principle)
int main() {
    // Create an array of Entertainment pointers
    Entertainment* entertainmentArray[3];

    // Create objects of Rides and Stalls
    entertainmentArray[0] = new Entertainment("Haunted House", 15.0, 200);
    entertainmentArray[1] = new Stalls("Food Stall", 5.0, 50);
    entertainmentArray[2] = new Rides("Ferris Wheel", 10.0, 300);

    // Use a loop to display all entertainment (this ensures LSP)
    cout << "Displaying all entertainment:" << endl;
    for (int i = 0; i < 3; ++i) {
        entertainmentArray[i]->display();  // Each object calls its respective display method
    }

    // Clean up memory
    for (int i = 0; i < 3; ++i) {
        delete entertainmentArray[i];
    }

    return 0;
}
