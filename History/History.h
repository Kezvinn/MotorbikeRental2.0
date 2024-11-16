#ifndef HISTORY_H
#define HISTORY_H
#include "../Functions/Functions.h"

class History {
    private:
        std::string historyID;          // 0 history ID
        std::string renterID;           // 1 renter ID
        std::string motorbikeID;        // 2 motorbike ID
        std::string startDate;          // 3 start date
        std::string endDate;            // 4 end date
    public:
        History();
        // Use for loading history from file
        History(std::string historyID_ip,
                std::string renterID_ip, std::string motorbikeID_ip, 
                std::string startDate_ip, std::string endDate_ip);
        // Use for creating new history
        History(std::string renterID_ip, std::string motorbikeID_ip, 
                std::string startDate_ip, std::string endDate_ip);
        // Setter
        int setMemID(std::string memID);
        int setBikeID(std::string bikeID);
        int setStartDate(std::string startDate);
        int setEndDate(std::string endDate);
        // Getter
        std::string getMemID();
        std::string getBikeID();
        std::string getStartDate();
        std::string getEndDate();
        std::vector<std::string> getHistoryInfo();
};
#endif