#include <iostream>
#include <string>
using namespace std;

// Base Class with Constructor Overloading and Function Overloading
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

    // Function to display the details of the Entertainment object (Overloaded)
    void display() const {
        cout << "Name: " << name << ", Duration: " << duration << " minutes, Fare: " << fare << " INR" << endl;
    }

    // Overloaded function to display only the Name
    void display(string n) const {
        cout << "Name: " << n << endl;
    }

    // Overloaded function to display only the Duration
    void display(double d, int f) const {
        cout << "Duration: " << d << " minutes" << endl;
        cout << "Fare: " << f << " INR" << endl;

    }
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
};

// Static member initialization for totalRides
int Rides::totalRides = 0;

// Derived Class 2: Stalls
class Stalls : public Entertainment {
public:
    Stalls(string n = "", double d = 0.0, int f = 0)
        : Entertainment(n, d, f) {}
};

// Main function demonstrating constructor overloading and function overloading
int main() {

    // Demonstrating Constructor Overloading
    Entertainment e1;  // Default constructor
    Entertainment e2("Haunted House");  // Name only constructor
    Entertainment e3("Roller Coaster", 10.0, 300);  // Name, duration and fare constructor
    Entertainment e4("ferris wheel", 15.0, 200);  // Duration, and fare constructor

    // Displaying all the Entertainment objects using overloaded functions
    e1.display();
    e2.display("Haunted House");
    e3.display();
    e4.display(15.0, 200);

    // Creating objects of Rides and Stalls to demonstrate the derived class functionality
    Rides r1("Ferris Wheel", 5.0, 300);
    Stalls s1("Food Stall", 2.0, 50);

    // Displaying details of Rides and Stalls objects
    cout << "\nRides and Stalls Details:" << endl;
    r1.display();  // Default display for Rides
    s1.display();  // Default display for Stalls

    // Displaying total number of rides
    cout << "Total Rides: " << Rides::getTotalRides() << endl;

    return 0;
}
