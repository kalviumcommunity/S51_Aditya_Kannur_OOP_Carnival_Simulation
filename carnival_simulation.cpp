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
        this-> ride_duration = duration;
        this-> ride_fare = fare;
    };

    // void setName(string name){
    //     this->ride_name = name;
    // }
    // void setDuration(double duration){
    //     this->ride_duration = duration;
    // }
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
        this-> stall_name = stall_name;
        this-> stall_timer = stall_timer;
        this-> stall_fare = stall_fare;
    };


    // void setName(string name){
    //     this->stall_name = name;
    // }
    // void setTimer(double timer){
    //     this->stall_timer = timer;
    // }
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

    // string ride_name = "roller_coster";
    // double ride_duration = 2; // in minutes
    // string stall_name = "shooting_game";
    // double stall_timer = 3; // in minutes

    // roller_coster.setName(ride_name);
    // roller_coster.setDuration(ride_duration);
    // game_stall.setName(stall_name);
    // game_stall.setTimer(stall_timer);

    cout << "Ride name:" << " " << roller_coster.getName() << " " << endl;
    cout << "Ride duration: " << " " << roller_coster.getDuration() << " " << endl;
    cout << "stall name: " << " " << game_stall.getName() << " " << endl;
    cout << "stall duration: " << " " << game_stall.getTimer();

   return 0; 
}