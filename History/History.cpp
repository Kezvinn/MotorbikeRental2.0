#include "History.h"

History::History(){}
History::History(std::string historyID_ip, 
                 std::string memberID_ip, std::string motorbikeID_ip, 
                 std::string startDate_ip, std::string endDate_ip)
                :historyID(historyID_ip), 
                 renterID(memberID_ip), motorbikeID(motorbikeID_ip),
                 startDate(startDate_ip), endDate(endDate_ip) {}
// Setter
int History::setMemID(std::string memID){ this->renterID = memID; return 0; }
int History::setBikeID(std::string bikeID){ this->motorbikeID = bikeID; return 0; }
int History::setStartDate(std::string startDate){ this->startDate = startDate; return 0; }
int History::setEndDate(std::string endDate){ this->endDate = endDate; return 0; }

// Getter
std::string History::getMemID(){ return this->renterID; }
std::string History::getBikeID(){ return this->motorbikeID; }
std::string History::getStartDate(){ return this->startDate; }
std::string History::getEndDate(){ return this->endDate; }
std::vector<std::string> History::getHistoryInfo(){
    std::vector<std::string> data;
    data.push_back(this->historyID);     // 0
    data.push_back(this->renterID);      // 1
    data.push_back(this->motorbikeID);   // 2
    data.push_back(this->startDate);     // 3
    data.push_back(this->endDate);       // 4
    return data;
}
