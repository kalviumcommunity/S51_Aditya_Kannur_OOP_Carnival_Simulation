#include <iostream>
using namespace std;


class Rides{
    private:
    std::string ride_name;
    double ride_duration;
    int fare;

    public:
    void setName(std::string name){
        ride_name = name;
    }
    void setDuration(double duration){
        ride_duration = duration;
    }
    std::string getName(){
        return ride_name;
    }
    double getDuration(){
        return ride_duration;
    }
};

class Stalls{
    private:
    std::string stall_name;
    double stall_timer;
    int fare;

    public:
    void setName(std::string name){
        stall_name = name;
    }
    void setTimer(double timer){
        stall_timer = timer;
    }
    std::string getName(){
        return stall_name;
    }
    double getTimer(){
        return stall_timer;
    }
};

int main(){
    Rides roller_coster;
    Stalls game_stall;

    std::string ride_name = "roller_coster";
    double ride_duration = 2; // in minutes
    std::string stall_name = "shooting_game";
    double stall_timer = 3; // in minutes

    roller_coster.setName(ride_name);
    roller_coster.setDuration(ride_duration);
    game_stall.setName(stall_name);
    game_stall.setTimer(stall_timer);

    std::cout << "Ride name:" << " " << roller_coster.getName() << " " << endl;
    std::cout << "Ride duration: " << " " << roller_coster.getDuration() << " " << endl;
    std::cout << "stall name: " << " " << game_stall.getName() << " " << endl;
    std::cout << "stall duration: " << " " << game_stall.getTimer();

   return 0; 
}