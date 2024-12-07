#include <iostream>
#include <string>
#include <vector>
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

    // Function to display the details of the Entertainment object
    void display() const {
        cout << "Name: " << name << ", Duration: " << duration << " minutes, Fare: " << fare << " INR" << endl;
    }
};

// Abstract Display Strategy Class (for OCP)
class IEntertainmentDisplay {
public:
    virtual void display(const Entertainment& e) const = 0;  // Pure virtual function for displaying entertainment
};

// Concrete Display Class 1: Standard Display
class EntertainmentDisplay : public IEntertainmentDisplay {
public:
    void display(const Entertainment& e) const override {
        cout << "Name: " << e.getName() << ", Duration: " << e.getDuration() << " minutes, Fare: " << e.getFare() << " INR" << endl;
    }
};

// Concrete Display Class 2: JSON Display
class EntertainmentDisplayJSON : public IEntertainmentDisplay {
public:
    void display(const Entertainment& e) const override {
        cout << "{\n"
             << "  \"Name\": \"" << e.getName() << "\",\n"
             << "  \"Duration\": " << e.getDuration() << ",\n"
             << "  \"Fare\": " << e.getFare() << "\n"
             << "}" << endl;
    }
};

// Concrete Display Class 3: CSV Display
class EntertainmentDisplayCSV : public IEntertainmentDisplay {
public:
    void display(const Entertainment& e) const override {
        cout << e.getName() << "," << e.getDuration() << "," << e.getFare() << endl;
    }
};

int main() {
    Entertainment e1("Roller Coaster", 10.0, 300);

    // Displaying using different strategies without modifying the existing EntertainmentDisplay code
    EntertainmentDisplay standardDisplay;
    EntertainmentDisplayJSON jsonDisplay;
    EntertainmentDisplayCSV csvDisplay;

    cout << "Standard Display:" << endl;
    standardDisplay.display(e1);

    cout << "\nJSON Display:" << endl;
    jsonDisplay.display(e1);

    cout << "\nCSV Display:" << endl;
    csvDisplay.display(e1);

    return 0;
}
