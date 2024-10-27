#ifndef MOTORBIKE_H
#define MOTORBIKE_H

#include <bits/stdc++.h>

#include "../Functions/Functions.h"
#include "../Review/Motorbike_Review.h"

class Motorbike {
    private:
    // motorbike ID
        std::string motorbikeID;        // 0
    // motorbike information    
        std::string model;              // 1
        std::string color;              // 2
        int engine_size;                // 3
        std::string transmission_mode;  // 4
        int year_made;                  // 5
        std::string desctiption;        // 6
        std::string location;           // 7
    // renting information
        int rent_cost;                  // 8
        std::string start_date;         // 9
        std::string end_date;           // 10
        float min_mem_rating;           // 11
    // motorbike status 
        bool is_listed;                 // 12
        bool is_available;              // 13   // use this to check if the bike is available to rent or not
                                                // check for period of rent if it clash with other renter 
    // Bike Review
        std::vector<MotorbikeReview*> motorbikeReview;
        
    public:
    
    // constructor
        Motorbike();    //default constructor
        Motorbike(std::string motorbikeID_ip, std::string model_ip, std::string color_ip, int engine_size_ip, 
        std::string transmission_mode_ip, int year_made_ip, std::string desctiption_ip, std::string location_ip, 
        int rent_cost_ip, std::string startDate_ip, std::string endDate_ip,
        float min_mem_rating_ip, bool is_listed_ip, bool is_available_ip);
    
        // getter
        std::vector<std::string> getMotorbikeInfo();    // get all motorbike information
        int showMotorbikeInfo();    // show all motorbike information
        std::vector<MotorbikeReview*> &getMotorbikeReview();  // get all motorbike review
        
        
        // Getter
        std::string getMotorbikeID();   // get motorbike ID
        int getRentCost();  // get rent cost
        // std::string getbikeLocation();  // get bike location
        // bool isBikeListed(); // check if bike is listed
        // bool isBikeAvailable();  // check if bike is available
        // float getMinMemRating();  // get bike rating
        
        // setter
        int setNewMotorbikeInfo(std::vector<std::string> data);
        int setBikeStartDate(std::string date);
        int setBikeEndDate(std::string date);
        
};


#endif
