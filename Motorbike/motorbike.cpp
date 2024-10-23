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

int Motorbike::getRentCost(){
    return rent_cost;
}
std::vector<std::string> Motorbike::getMotorbikeInfo(){
    std::vector<std::string> data;

    data.push_back(motorbikeID); // 0
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
    data.push_back(std::to_string(is_available));   // 13
    
    return data;
}
std::string Motorbike::getMotorbikeID(){
    return motorbikeID;
}

int Motorbike::setNewMotorbikeInfo(std::vector<std::string> data){
    if (data.size() != 13){
        return 1;
    }
    this->motorbikeID = data[0];
    this->model = data[1];
    this->color = data[2];
    this->engine_size = std::stoi(data[3]);
    this->transmission_mode = data[4];
    this->year_made = std::stoi(data[5]);
    this->desctiption = data[6];
    this->location = data[7];
    this->rent_cost = std::stoi(data[8]);
    this->start_date = data[9];
    this->end_date = data[10];
    this->min_mem_rating = std::stof(data[11]);
    this->is_listed = std::stoi(data[12]);
    this->is_available = std::stoi(data[13]);
    return 0;
}