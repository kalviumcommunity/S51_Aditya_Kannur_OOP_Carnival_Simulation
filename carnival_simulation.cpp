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

    int ride_arr_size = sizeof(rides) / sizeof(rides[0]);
    int stall_arr_size = sizeof(stalls) / sizeof(stalls[0]);

    for (int i=0; i<ride_arr_size; i++){
        cout << "Rides " << rides[i].getName() << " -- "  << rides[i].getDuration() << " minutes " << endl;
        // cout <<  << "minutes" << endl;
    }
    for(int i=0; i<stall_arr_size; i++){
        cout << "Stalls " << stalls[i].getName() << " -- " << stalls[i].getTimer() << " minutes " << endl;
    }

   return 0; 
}