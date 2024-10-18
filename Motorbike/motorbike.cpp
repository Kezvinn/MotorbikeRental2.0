#include "Motorbike.h"

// default constructor
Motorbike::Motorbike(){}

// parameterized constructor
Motorbike::Motorbike(std::string motorbikeID_ip, std::string model_ip, std::string color_ip, 
                     int engine_size_ip, std::string transmission_mode_ip, int year_made_ip, 
                     std::string desctiption_ip, std::string location_ip, int rent_cost_ip, 
                     std::string startDate_ip, std::string endDate_ip, float min_mem_rating_ip, 
                     bool is_listed_ip, bool is_available_ip)
                    :motorbikeID(motorbikeID_ip), model(model_ip), color(color_ip), engine_size(engine_size_ip), 
                    transmission_mode(transmission_mode_ip),year_made(year_made_ip), 
                    desctiption(desctiption_ip), location(location_ip),rent_cost(rent_cost_ip), 
                    start_date(startDate_ip), end_date(endDate_ip), min_mem_rating(min_mem_rating_ip), 
                    is_listed(is_listed_ip), is_available(is_available_ip) 
                    {
                        if (!this->motorbikeID.empty()){
                            motorbikeID = randomIDs("motorbike");
                        } else {
                            this->motorbikeID = motorbikeID_ip;
                        }
                    }

std::vector<std::string> Motorbike::getMotorbikeinfo(){
    std::vector<std::string> data;
    // no BikeID
    data.push_back(model);
    data.push_back(color);
    data.push_back(std::to_string(engine_size));
    data.push_back(transmission_mode);
    data.push_back(std::to_string(year_made));
    data.push_back(desctiption);
    data.push_back(location);
    data.push_back(std::to_string(rent_cost));
    data.push_back(start_date);
    data.push_back(end_date);
    data.push_back(std::to_string(min_mem_rating));
    data.push_back(std::to_string(is_listed));
    data.push_back(std::to_string(is_available));
    return data;
}
std::string Motorbike::getMotorbikeID(){
    return motorbikeID;
}
