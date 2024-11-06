#include "Request.h"
// Default constructor
Request::Request(){}
// Parameterized constructor - use this for creating new request
Request::Request(std::string renterID_ip, 
                 std::string ownerID_ip, std::string motorbikeID_ip, 
                 std::string start_date_ip, std::string end_date_ip, 
                 int total_rent_cost_ip, std::string requestStatus_ip)
                :renterID(renterID_ip), 
                ownerID(ownerID_ip), motorbikeID(motorbikeID_ip), 
                start_date(start_date_ip), end_date(end_date_ip), 
                total_rent_cost(total_rent_cost_ip), requestStatus(requestStatus_ip) {
            this->requestID = randomIDs("request");
        }
// Parameterized constructor - use this to load request from file
Request::Request(std::string requestID_ip, std::string renterID_ip, 
                 std::string ownerID_ip, std::string motorbikeID_ip, 
                 std::string start_date_ip, std::string end_date_ip, 
                 int total_rent_cost_ip, std::string requestStatus_ip)
                :requestID(requestID_ip), renterID(renterID_ip), 
                ownerID(ownerID_ip), motorbikeID(motorbikeID_ip), 
                start_date(start_date_ip), end_date(end_date_ip), 
                total_rent_cost(total_rent_cost_ip), requestStatus(requestStatus_ip){}

std::vector<std::string> Request::getRequestInfo(){
    std::vector<std::string> data;

    data.push_back(this->requestID);                            // 0
    data.push_back(this->renterID);                             // 1
    data.push_back(this->ownerID);                              // 2
    data.push_back(this->motorbikeID);                          // 3
    data.push_back(this->start_date);                           // 4
    data.push_back(this->end_date);                             // 5
    data.push_back(std::to_string(this->total_rent_cost));      // 6
    data.push_back(this->requestStatus);                        // 7
    
    return data;
}
int Request::showRequestInfo(){
    std::cout << std::left;
    std::cout << std::setw(18) << "Request ID: " << this->requestID << std::endl;
    std::cout << std::setw(18) << "Renter ID: " << this->renterID << std::endl;
    std::cout << std::setw(18) << "Owner ID: " << this->ownerID << std::endl;
    std::cout << std::setw(18) << "Motorbike ID: " << this->motorbikeID << std::endl;
    std::cout << std::setw(18) << "Start Date: " << this->start_date << std::endl;
    std::cout << std::setw(18) << "End Date: " << this->end_date << std::endl;
    std::cout << std::setw(18) << "Total Rent Cost: " << this->total_rent_cost << " credits" << std::endl;
    std::cout << std::setw(18) << "Request Status: " << this->requestStatus << std::endl;
    return 0;
}

bool Request::parseFromLine(const std::string &line){
    std::istringstream iss(line);
    std::string token;
    try {
        std::getline(iss, requestID, '|');         // requestID
        std::getline(iss, renterID, '|');          // renterID
        std::getline(iss, ownerID, '|');           // ownerID
        std::getline(iss, motorbikeID, '|');       // motorbikeID
        std::getline(iss, start_date, '|');        // start_date
        std::getline(iss, end_date, '|');          // end_date
        
        std::getline(iss, token, '|');             // total_rent_cost
        total_rent_cost = std::stoi(token);
        
        std::getline(iss, requestStatus, '|');     // requestStatus
        return true;
    }
    catch (const std::exception& e){
        std::cerr << "Error parsing line: " << line << "\nException: " << e.what() << std::endl;
        return false;
    }

}