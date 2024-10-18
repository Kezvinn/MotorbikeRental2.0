#ifndef MOTORBIKE_H
#define MOTORBIKE_H
#include <string>
#include "../Functions/Functions.h"

class Motorbike {
    private:
    // motorbike ID
        std::string motorbikeID;
    // motorbike information
        std::string model;
        std::string color;
        int engine_size;
        std::string transmission_mode;
        int year_made;
        std::string desctiption;
        std::string location;
    // renting information
        int rent_cost;
        std::string start_date;
        std::string end_date;
        float min_mem_rating;
    // motorbike status
        bool is_listed;
        bool is_available;
    
    public:
    
    // constructor
        Motorbike();    //default constructor
        Motorbike(std::string motorbikeID_ip, std::string model_ip, std::string color_ip, int engine_size_ip, 
        std::string transmission_mode_ip, int year_made_ip, std::string desctiption_ip, std::string location_ip, 
        int rent_cost_ip, std::string startDate_ip, std::string endDate_ip,
        float min_mem_rating_ip, bool is_listed_ip, bool is_available_ip);
    
        // getter
        std::vector<std::string> getMotorbikeinfo();    // get all motorbike information
        std::string getMotorbikeID();   // get motorbike ID

        std::string getbikeLocation();  // get bike location

        bool listed(); // check if bike is listed
        bool available();  // check if bike is available

        float getMinMemRating();  // get bike rating
        
        
        
        int bike_status();  //check for is bike is list-unlist/avalable/unavailable
        
};


#endif

