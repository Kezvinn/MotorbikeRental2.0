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
                        if (this->motorbikeID.empty()){
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

    data.push_back(motorbikeID);                    // 0
    data.push_back(model);                          // 1
    data.push_back(color);                          // 2                          
    data.push_back(std::to_string(engine_size));    // 3
    data.push_back(transmission_mode);              // 4
    data.push_back(std::to_string(year_made));      // 5
    data.push_back(desctiption);                    // 6
    data.push_back(location);                       // 7
    data.push_back(std::to_string(rent_cost));      // 8
    data.push_back(start_date);                     // 9     
    data.push_back(end_date);                       // 10
    data.push_back(std::to_string(min_mem_rating)); // 11
    data.push_back(std::to_string(is_listed));      // 12
    data.push_back(std::to_string(is_available));   // 13
    
    return data;
}
int Motorbike::showMotorbikeInfo(){
    std::cout << std::left;
    std::cout << std::string(40, '-') << std::endl;

    std::cout << std::setw(23) << "Motorbike ID: "      << this->motorbikeID << std::endl;
    std::cout << std::setw(23) << "Model: "             << this->model << std::endl;
    std::cout << std::setw(23) << "Color: "             << this->color << std::endl;
    std::cout << std::setw(23) << "Engine Size: "       << this->engine_size << std::endl;
    std::cout << std::setw(23) << "Transmission Mode: " << this->transmission_mode << std::endl;
    std::cout << std::setw(23) << "Year Made: "         << this->year_made << std::endl;
    std::cout << std::setw(23) << "Description: "       << this->desctiption << std::endl;
    std::cout << std::setw(23) << "Location: "          << this->location << std::endl;
    std::cout << std::setw(23) << "Rent Cost: "         << this->rent_cost << "credits" << std::endl;
    std::cout << std::setw(23) << "Start Date: "        << this->start_date << std::endl;
    std::cout << std::setw(23) << "End Date: "          << this->end_date  << std::endl;
    std::cout << std::setw(23) << "Minimum Member Rating: " << std::fixed << std::setprecision(2) << this->min_mem_rating << std::endl;
    std::cout << std::setw(23) << "Listed: "            << (this->is_listed ? "Listed":"Unlisted") << std::endl;
    std::cout << std::setw(23) << "Availability: "      << (this->is_available? "Available":"Unavailable") << std::endl;
    std::cout << std::string(40, '-') << std::endl;

    return 0;
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
// get review of the motorbike that align with the member rented bike
std::vector<MotorbikeReview*> &Motorbike::getMotorbikeReview(){
    std::vector<MotorbikeReview*> ownBikeReview;
    for (auto rev: this->motorbikeReview){
        if (rev->getMotorbikeReviewInfo()[2] == this->motorbikeID){
            ownBikeReview.push_back(rev);
        }
    }
    return ownBikeReview;
}