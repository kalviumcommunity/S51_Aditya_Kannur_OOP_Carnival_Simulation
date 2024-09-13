#include <iostream>
#include <string> 
using namespace std;

// Class Rides
class Rides {

// Member Variables
private:
    string ride_name;
    double ride_duration;
    int ride_fare;

    int static totalRides;

public:
    Rides(string name = "", double duration = 0.0, int fare = 0) 
        : ride_name(name), ride_duration(duration), ride_fare(fare) {
            if (fare != 0){
            totalRides ++;
            }
        }

    string getName() const {
        return ride_name;
    }

    double getDuration() const {
        return ride_duration;
    }

    static int getTotalRides() {
        return totalRides;
    }
};

class Stalls {
private:
    string stall_name;
    double stall_timer;
    int stall_fare;

public:
    Stalls(string name, double timer, int fare) 
        : stall_name(name), stall_timer(timer), stall_fare(fare) {}

    string getName() const {
        return stall_name;
    }

    double getTimer() const {
        return stall_timer;
    }

};

class Visitors {
private:
    string name;
    int age;
    double height;

    static int totalVisitors;

public:
    Visitors(string n = "", int a = 0, double h = 0.0) 
        : name(n), age(a), height(h) {
            if (a != 0){
                totalVisitors++;
            }
    }

    // Accessor (getter) methods
    string getName() const {
        return name;
    }

    int getAge() const {
        return age;
    }

    double getHeight() const {
        return height;
    }

    static int getTotalVisitors() {
        return totalVisitors;
    }

    // Mutator (setter) methods
    void setName(string n) {
        name = n;
    }

    void setAge(int a) {
        age = a;
        totalVisitors++;
    }

    void setHeight(double h) {
        height = h;
    }
};

void print_stalls(const Stalls stalls[], int size) {
    cout << "Stalls " << endl;
    for (int i = 0; i < size; i++) {
        cout << "Stall name: " << stalls[i].getName() << endl; 
        cout << "Stall duration: " << stalls[i].getTimer() << " minutes" << endl; 
    }
}

int Visitors::totalVisitors = 0;
int Rides::totalRides = 0;

int main() {
    int numberOfRides, numberOfVisitors;

    cout << "Enter number of Rides: ";
    cin >> numberOfRides;

    // Error handling
    if (numberOfRides <= 0) {
        cerr << "Invalid number of rides. Exiting." << endl;
        return 1;
    }

    cout << "Enter number of Visitors: ";
    cin >> numberOfVisitors;

    // Error Handling
    if (numberOfVisitors <= 0) {
        cerr << "Invalid number of visitors. Exiting." << endl;
        return 1;
    }

    Rides* rides = new Rides[numberOfRides];
    Visitors* visitors = new Visitors[numberOfVisitors];

    Stalls stalls[] = {
        Stalls("shooting", 2.0, 200),
        Stalls("ring-toss", 5.0, 100)
    };

    for (int i = 0; i < numberOfRides; i++) {
        string ride_name;
        double ride_duration;
        int ride_fare;

        cout << "Ride" << i+1 << " Name :";
        cin >> ride_name;
        cout << "Ride" << i+1 << " Duration :";
        cin >> ride_duration;
        cout << "Ride" << i+1 << " Fare :";
        cin >> ride_fare;

        rides[i] = Rides(ride_name, ride_duration, ride_fare);
    }

       for (int i = 0; i < numberOfVisitors; i++) {
        string name;
        int age;
        double height;

        cout << "Visitor" << i+1 << " Name :";
        cin >> name;
        cout << "Visitor" << i+1 << " Age :";
        cin >> age;
        cout << "Visitor" << i+1 << " Height :";
        cin >> height;

        // Using mutators
        visitors[i].setName(name);
        visitors[i].setAge(age);
        visitors[i].setHeight(height);
    }


    cout << endl;

    cout << "Visitors" << endl;
    for (int i = 0; i < numberOfVisitors; i++) {
        cout << "Visitor's Name: " << visitors[i].getName() << endl;
        cout << "Visitor's Age: " << visitors[i].getAge() << endl;
        cout << "Visitor's Height: " << visitors[i].getHeight() << endl;
    }

    cout << endl;

    cout << "Rides " << endl;
    for (int i = 0; i < numberOfRides; i++) {
        cout << "Ride name: " << rides[i].getName() << endl;
        cout << "Ride duration: " << rides[i].getDuration() << " minutes" << endl;
    }

    print_stalls(stalls, 2);
    
    cout << Visitors::getTotalVisitors()<<endl;
    cout << Rides::getTotalRides()<<endl;


    // Deallocate dynamic memory
    delete[] rides;
    delete[] visitors;

    return 0;
}
