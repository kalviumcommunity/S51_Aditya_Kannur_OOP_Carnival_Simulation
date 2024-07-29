#include <iostream>
using namespace std;

// Class Rides
class Rides {

// Member Variables
private:
    string ride_name;
    double ride_duration;
    int ride_fare;

public:
    // Constructor 
    Rides(string name, double duration, int fare) {
        this->ride_name = name;
        this->ride_duration = duration;
        this->ride_fare = fare;
    }
        // : ride_name(name), ride_duration(duration), ride_fare(fare) {}
        
    string getName() const {
        return ride_name;
    }

    double getDuration() const {
        return ride_duration;
    }
};

class Stalls {
private:
    string stall_name;
    double stall_timer;
    int stall_fare;

public:
    Stalls(string name, double timer, int fare) {
        this->stall_name = name;
        this->stall_timer = timer;
        this->stall_fare = fare;
    }
        // : stall_name(name), stall_timer(timer), stall_fare(fare) {}

    string getName() const {
        return stall_name;
    }

    double getTimer() const {
        return stall_timer;
    }
};

void print_rides(const Rides rides[], int size) {
    cout << "Rides " << endl;
    for (int i = 0; i < size; i++) {
        cout << "Ride name: " << rides[i].getName() << endl;
        cout << "Ride duration: " << rides[i].getDuration() << " minutes" << endl;
    }
}

void print_stalls(const Stalls stalls[], int size) {
    cout << "Stalls " << endl;
    for (int i = 0; i < size; i++) {
        cout << "Stall name: " << stalls[i].getName() << endl; 
        cout << "Stall duration: " << stalls[i].getTimer() << " minutes" << endl; 
    }
}

int main() {
    Rides rides[] = {
        Rides("roller-coaster", 3.0, 300),
        Rides("bumper-cars", 5.0, 200),
        Rides("ferris-wheel", 4.0, 400)
    };

    Stalls stalls[] = {
        Stalls("shooting", 2.0, 200),
        Stalls("ring-toss", 5.0, 100),
        Stalls("basket-ball-shoot", 5.0, 100)
    };

    print_rides(rides, 3);
    print_stalls(stalls, 3);

    return 0;
}
