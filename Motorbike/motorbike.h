#ifndef MOTORBIKE_H
#define MOTORBIKE_H
#include <string>

class Motorbike {
    private:
    // motorbike information
        std::string model;
        std::string color;
        int engine_size;
        std::string transmission_mode;
        int year_made;
        std::string desctiption;

    // renting information
        int rent_cost;
        std::string start_date;
        std::string end_date;
    public:
    
    // constructor
        Motorbike(std::string model_ip, std::string color_ip, int engine_size_ip, 
        std::string transmission_mode_ip, int year_made_ip, std::string desctiption_ip, 
        int rent_cost_ip, std::string start_date_ip, std::string end_date_ip);

        int bike_status();  //check for is bike is list/unlist/avalable/unaviaable
        
};


#endif