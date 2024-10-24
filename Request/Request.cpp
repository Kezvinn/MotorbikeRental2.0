#include "Request.h"

Request::Request(){}
Request::Request(std::string requestID_ip, std::string renterID_ip, 
                 std::string ownerID_ip, std::string motorbikeID_ip, 
                 std::string start_date_ip, std::string end_date_ip, 
                 int total_rent_cost_ip, std::string requestStatus_ip)
                :requestID(requestID_ip), renterID(renterID_ip), 
                ownerID(ownerID_ip), motorbikeID(motorbikeID_ip), 
                start_date(start_date_ip), end_date(end_date_ip), 
                total_rent_cost(total_rent_cost_ip), requestStatus(requestStatus_ip)
        {
            if (this->requestID.empty()){
                requestID = randomIDs("request");
            } else {
                this->requestID = requestID_ip;
            }
        }

std::vector<std::string> Request::getRequestInfo(){
    std::vector<std::string> data;

    data.push_back(this->requestID);
    data.push_back(this->renterID);
    data.push_back(this->ownerID);
    data.push_back(this->motorbikeID);
    data.push_back(this->start_date);
    data.push_back(this->end_date);
    data.push_back(std::to_string(this->total_rent_cost));
    
    return data;
}