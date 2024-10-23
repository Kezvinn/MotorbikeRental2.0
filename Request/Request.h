#ifndef REQUEST_H
#define REQUEST_H
#include "../Functions/Functions.h"
class Request {
    private:
        std::string requestID;      // auto create
        std::string renterID;       // member ID
        std::string ownerID;        // owner ID
        std::string motorbikeID;    // motorbike ID
        std::string start_date;     // start date
        std::string end_date;       // end date
        int total_rent_cost;        // total rent cost
    public:
        Request();
        Request(std::string requestID_ip, std::string renterID_ip, 
                std::string ownerID_ip, std::string motorbikeID_ip, 
                std::string start_date_ip, std::string end_date_ip, 
                int total_rent_cost_ip);
        std::vector<std::string> getRequestInfo();
        

};


#endif