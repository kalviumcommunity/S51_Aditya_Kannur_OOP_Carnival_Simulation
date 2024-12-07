#include <iostream>
#include <string>
using namespace std;

// Class to handle entertainment details (focuses only on the data)
class Entertainment {
protected:
    string name;
    double duration;
    int fare;

public:
    Entertainment() : name(""), duration(0.0), fare(0) {}
    Entertainment(string n, double d, int f) : name(n), duration(d), fare(f) {}

    // Getter functions
    string getName() const { return name; }
    double getDuration() const { return duration; }
    int getFare() const { return fare; }
};

// Class to handle the display logic (responsible only for displaying information)
class EntertainmentDisplay {
public:
    void display(const Entertainment& e) {
        cout << "Name: " << e.getName() << ", Duration: " << e.getDuration() << " minutes, Fare: " << e.getFare() << " INR" << endl;
    }

    void displayNameOnly(const Entertainment& e) {
        cout << "Name: " << e.getName() << endl;
    }

    void displayDurationAndFare(const Entertainment& e) {
        cout << "Duration: " << e.getDuration() << " minutes" << endl;
        cout << "Fare: " << e.getFare() << " INR" << endl;
    }
};

// Class to track ride count (focuses only on the count)
class RideCounter {
private:
    static int totalRides;

public:
    static void increment() {
        totalRides++;
    }

    static int getTotalRides() {
        return totalRides;
    }
};

// Static member initialization for RideCounter
int RideCounter::totalRides = 0;

// Derived Class 1: Rides (handles specific ride data)
class Rides : public Entertainment {
public:
    Rides(string n, double d, int f) : Entertainment(n, d, f) {
        RideCounter::increment();
    }
};

// Derived Class 2: Stalls (handles specific stall data)
class Stalls : public Entertainment {
public:
    Stalls(string n, double d, int f) : Entertainment(n, d, f) {}
};

int main() {
    // Demonstrating SRP by creating separate objects for entertainment, display, and ride counting
    Entertainment e1("Roller Coaster", 10.0, 300);
    Entertainment e2;
    EntertainmentDisplay display;
    display.display(e1);
    display.display(e2);
    display.displayNameOnly(e1);  // Using the display class to show entertainment details

    Rides r1("Ferris Wheel", 5.0, 300);
    Stalls s1("Food Stall", 2.0, 50);

    // Displaying the number of total rides
    cout << "Total Rides: " << RideCounter::getTotalRides() << endl;

    return 0;
}
