#ifndef REQUEST_H
#define REQUEST_H

#include "../Functions/Functions.h"

class Request {
    private:
    // Request ID
        std::string requestID;      // auto create                  // 0
    // Request information 
        std::string renterID;       // member ID                    // 1
        std::string ownerID;        // owner ID                     // 2
        std::string motorbikeID;    // motorbike ID                 // 3
        std::string start_date;     // start date                   // 4 
        std::string end_date;       // end date                     // 5
        int total_rent_cost;        // total rent cost              // 6
    // Request Status
        std::string requestStatus;  // Pending/Approved/Rejected    // 7
    public:
        Request();
        // Parameterized constructor
        Request(std::string requestID_ip, std::string renterID_ip, 
                std::string ownerID_ip, std::string motorbikeID_ip, 
                std::string start_date_ip, std::string end_date_ip, 
                int total_rent_cost_ip, std::string requestStatus_ip);

        std::vector<std::string> getRequestInfo();
        int showRequestInfo();
        bool parseFromLine(const std::string& line);

        std::string getRqstStt();
        int setRqstStt(std::string rqstStt);
        bool operator== (const Request &rqst) const;
};


#endif
