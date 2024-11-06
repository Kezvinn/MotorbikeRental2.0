#include "Member_Review.h"

MemberReview::MemberReview(){}
// create new review - no rating and comment
MemberReview::MemberReview(std::string reviewerID_ip,           // 1 
                           std::string revieweeID_ip,           // 2
                           std::string memberReviewStatus_ip)   // 3
                           :reviewerID(reviewerID_ip),
                            revieweeID(revieweeID_ip), 
                            memberReviewStatus(memberReviewStatus_ip) {
                        this->memReviewID = randomIDs("memReview");     // 0
                    }
// load review from file
MemberReview::MemberReview(std::string memReviewID_ip,                  // 0
                           std::string reviewerID_ip,                   // 1
                           std::string revieweeID_ip,                   // 2
                           std::string memberReviewStatus_ip,           // 3
                           float rating_ip, std::string comment_ip)     // 4 - 5
                           :memReviewID(memReviewID_ip), 
                           reviewerID(reviewerID_ip), 
                           revieweeID(revieweeID_ip), 
                           memberReviewStatus(memberReviewStatus_ip), 
                           Review(rating_ip, comment_ip) {}

std::vector<std::string> MemberReview::getMemberReviewInfo(){
    std::vector<std::string> memberReview_info;
    
    memberReview_info.push_back(this->memReviewID);                 // 0
    memberReview_info.push_back(this->reviewerID);                  // 1
    memberReview_info.push_back(this->revieweeID);                  // 2
    memberReview_info.push_back(this->memberReviewStatus);          // 3
    memberReview_info.push_back(std::to_string(this->getRating())); // 4
    memberReview_info.push_back(this->getComment());                // 5

    return memberReview_info;
}
bool MemberReview::parseFromLine(const std::string &line){
    std::istringstream iss(line);
    std::string token;
    std::string rating_ip, comment_ip;
    try {
        std::getline(iss, memReviewID, '|');         // memReviewID
        std::getline(iss, reviewerID, '|');          // reviewerID
        std::getline(iss, revieweeID, '|');          // revieweeID
        std::getline(iss, memberReviewStatus, '|');  // memberReviewStatus
        
        std::getline(iss, rating_ip, '|');           // rating
        this->setRating(std::stof(token));
        
        std::getline(iss, token, '|');               // comment
        this->setComment(token);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return false;
    }
    return true;
}