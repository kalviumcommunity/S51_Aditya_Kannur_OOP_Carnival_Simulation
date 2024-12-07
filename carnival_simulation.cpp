#include <iostream>
#include <string>
using namespace std;

// Base Class
class Entertainment {
protected:
    string name;
    double duration;
    int fare;

public:
    Entertainment(string n = "", double d = 0.0, int f = 0)
        : name(n), duration(d), fare(f) {}

    string getName() const {
        return name;
    }

    double getDuration() const {
        return duration;
    }

    int getFare() const {
        return fare;
    }
};

// Derived Class 1: Hierarchical Inheritance
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

// Static member initialization
int Rides::totalRides = 0;

// Derived Class 2: Hierarchical Inheritance
class Stalls : public Entertainment {
public:
    Stalls(string n = "", double d = 0.0, int f = 0)
        : Entertainment(n, d, f) {}
};

// Derived Class 3: Multi-Level Inheritance
class PremiumRides : public Rides {
private:
    string additionalFeatures;

public:
    PremiumRides(string n = "", double d = 0.0, int f = 0, string features = "")
        : Rides(n, d, f), additionalFeatures(features) {}

    string getFeatures() const {
        return additionalFeatures;
    }
};

int main() {
    int numberOfRides, numberOfStalls;

    // Input for Rides
    cout << "Enter number of Rides: ";
    cin >> numberOfRides;

    if (numberOfRides <= 0) {
        cerr << "Invalid number of rides. Exiting." << endl;
        return 1;
    }

    Rides* rides = new Rides[numberOfRides];

    for (int i = 0; i < numberOfRides; i++) {
        string ride_name;
        double ride_duration;
        int ride_fare;

        cout << "Ride " << i + 1 << " Name: ";
        cin >> ride_name;
        cout << "Ride " << i + 1 << " Duration: ";
        cin >> ride_duration;
        cout << "Ride " << i + 1 << " Fare: ";
        cin >> ride_fare;

        rides[i] = Rides(ride_name, ride_duration, ride_fare);
    }

    // Input for Stalls
    cout << "Enter number of Stalls: ";
    cin >> numberOfStalls;

    if (numberOfStalls <= 0) {
        cerr << "Invalid number of stalls. Exiting." << endl;
        delete[] rides;
        return 1;
    }

    Stalls* stalls = new Stalls[numberOfStalls];

    for (int i = 0; i < numberOfStalls; i++) {
        string stall_name;
        double stall_duration;
        int stall_fare;

        cout << "Stall " << i + 1 << " Name: ";
        cin >> stall_name;
        cout << "Stall " << i + 1 << " Duration: ";
        cin >> stall_duration;
        cout << "Stall " << i + 1 << " Fare: ";
        cin >> stall_fare;

        stalls[i] = Stalls(stall_name, stall_duration, stall_fare);
    }

    // Premium Ride
    PremiumRides premiumRide("Roller Coaster", 5.0, 500, "VR Experience");

    // Display Rides
    cout << "\nRides:" << endl;
    for (int i = 0; i < numberOfRides; i++) {
        cout << "Ride Name: " << rides[i].getName() << endl;
        cout << "Ride Duration: " << rides[i].getDuration() << " minutes" << endl;
        cout << "Ride Fare: " << rides[i].getFare() << " INR" << endl;
    }

    // Display Premium Ride
    cout << "\nPremium Ride:" << endl;
    cout << "Ride Name: " << premiumRide.getName() << endl;
    cout << "Ride Duration: " << premiumRide.getDuration() << " minutes" << endl;
    cout << "Ride Fare: " << premiumRide.getFare() << " INR" << endl;
    cout << "Special Features: " << premiumRide.getFeatures() << endl;

    // Display Stalls
    cout << "\nStalls:" << endl;
    for (int i = 0; i < numberOfStalls; i++) {
        cout << "Stall Name: " << stalls[i].getName() << endl;
        cout << "Stall Duration: " << stalls[i].getDuration() << " minutes" << endl;
        cout << "Stall Fare: " << stalls[i].getFare() << " INR" << endl;
    }

    // Display Total Rides
    cout << "\nTotal Rides: " << Rides::getTotalRides() << endl;

    // Free dynamically allocated memory
    delete[] rides;
    delete[] stalls;

    return 0;
}
