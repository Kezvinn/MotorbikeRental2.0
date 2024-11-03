#include "Member_Review.h"

MemberReview::MemberReview(){}
// create new review
MemberReview::MemberReview(std::string memReviewID_ip, std::string reviewerID_ip, 
                    std::string revieweeID_ip, std::string memberReviewStatus_ip)
                    :memReviewID(memReviewID_ip), reviewerID(reviewerID_ip),
                    revieweeID(revieweeID_ip), memberReviewStatus(memberReviewStatus_ip){
                        this->memReviewID = randomIDs("memReview");
                    }
// load review from file
MemberReview::MemberReview(std::string memReviewID_ip, std::string reviewerID_ip, 
                    std::string revieweeID_ip, std::string memberReviewStatus_ip, 
                    float rating_ip, std::string comment_ip)
                    :memReviewID(memReviewID_ip), reviewerID(reviewerID_ip), 
                    revieweeID(revieweeID_ip), memberReviewStatus(memberReviewStatus_ip), 
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