#ifndef MOTORBIKE_H
#define MOTORBIKE_H

#include "../Functions/Functions.h"
#include "../Review/Motorbike_Review.h"

#define MOTORBIKE_REVIEW_FILE "Data/Motorbike_Review.txt"

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
        bool is_available;              // 13   // check for bike currently rented or not 
    // Renter(Member)ID
        std::string renterID;           // 14
    // Bike Review
        std::vector<MotorbikeReview*> motorbikeReview;
    public:
        // Default constructor
        Motorbike();
        
        // Parameterized constructor - use this for sign up new bike    
        Motorbike(std::string model_ip, std::string color_ip, int engine_size_ip, 
        std::string transmission_mode_ip, int year_made_ip, std::string desctiption_ip, std::string location_ip, 
        int rent_cost_ip, std::string startDate_ip, std::string endDate_ip,
        float min_mem_rating_ip, bool is_listed_ip, bool is_available_ip,std::string renterID_ip);
    
        // Parameterized constructor - use this to load motorbike from file
        Motorbike(std::string motorbikeID_ip, std::string model_ip, std::string color_ip, int engine_size_ip, 
        std::string transmission_mode_ip, int year_made_ip, std::string desctiption_ip, std::string location_ip, 
        int rent_cost_ip, std::string startDate_ip, std::string endDate_ip,
        float min_mem_rating_ip, bool is_listed_ip, bool is_available_ip,std::string renterID_ip);
    
        // Getter
        // Display all motorbike information
        int showMotorbikeInfo();

        std::vector<MotorbikeReview*> &getMotorbikeReview();  // get all motorbike review
        
        // Getter
        std::vector<std::string> getMotorbikeInfo();
        std::string getMotorbikeID();   // get motorbike ID
        int getRentCost();  // get rent cost
        std::string getStartdate(); // get start date
        std::string getEnddate();   // get end date
        std::string getRenterID();   // get renter ID
        
        // Setter
        int setNewMotorbikeInfo(std::vector<std::string> data);
        int setBikeStartDate(std::string date);
        int setBikeEndDate(std::string date);
        int setBikeAvailability(bool status);
        int setRenterID(std::string renterID);
        
        // add review into vector
        int addBikeReview(MotorbikeReview *review);  // add bike review

        // Files handling methods
        int loadMotorbikeReview();
        int saveMotorbikeReview();

        int logout();

        // calculate motorbike rating
        float calcMotorbikeRating();  
};


#endif
