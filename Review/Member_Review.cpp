#include "Member_Review.h"

MemberReview::MemberReview(){}
MemberReview::MemberReview(std::string memReviewID_ip, std::string reviewerID_ip, 
                    std::string revieweeID_ip, std::string memberReviewStatus_ip, 
                    float rating_ip, std::string comment_ip)
                    :memReviewID(memReviewID_ip), reviewerID(reviewerID_ip), 
                    revieweeID(revieweeID_ip), memberReviewStatus(memberReviewStatus_ip), 
                    Review(rating_ip, comment_ip){
                        if (this->memReviewID.empty()){
                            this->memReviewID = randomIDs("memReview");
                        }
                    }

std::vector<std::string> MemberReview::getMemberReviewInfo(){
    std::vector<std::string> memberReview_info;
    memberReview_info.push_back(this->memReviewID);
    memberReview_info.push_back(this->reviewerID);
    memberReview_info.push_back(this->revieweeID);
    memberReview_info.push_back(this->memberReviewStatus);
    memberReview_info.push_back(std::to_string(this->getRating()));
    memberReview_info.push_back(this->getComment());

    return memberReview_info;
}

float MemberReview::calRating(){
    float total = 0;
    
}