#include <iostream>
using namespace std;

class Rides{
    private:
    string ride_name;
    double ride_duration;
    int ride_fare;

    public:

    Rides(string name, double duration, int fare){
        this->ride_name = name;
        this->ride_duration = duration;
        this->ride_fare = fare;
    };

    string getName(){
        return this->ride_name;
    }
    double getDuration(){
        return this->ride_duration;
    }
};

class Stalls{
    private:
    string stall_name;
    double stall_timer;
    int stall_fare;

    public:

    Stalls(string stall_name, double stall_timer, int stall_fare){
        this->stall_name = stall_name;
        this->stall_timer = stall_timer;
        this->stall_fare = stall_fare;
    };

    string getName(){
        return this->stall_name;
    }
    double getTimer(){
        return this->stall_timer;
    }
};

int main(){
    Rides roller_coster("roller-coster", 3, 300);
    Stalls game_stall("shooting", 2, 200);

    cout << "Ride name:" << " " << roller_coster.getName() << " " << endl;
    cout << "Ride duration: " << " " << roller_coster.getDuration() << " " << endl;
    cout << "stall name: " << " " << game_stall.getName() << " " << endl;
    cout << "stall duration: " << " " << game_stall.getTimer();

   return 0; 
}