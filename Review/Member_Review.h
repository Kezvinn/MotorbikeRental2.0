#ifndef MEMBER_RATING_H
#define MEMBER_RATING_H
#include "Review.h"

#include "../Functions/Functions.h"

class MemberReview : public Review {
    private:
        std::string memReviewID;    // ID of the review
        std::string reviewerID;     // member who give the review
        std::string revieweeID;     // member who receive the review
        std::string memberReviewStatus; // Pending/Complete
    public:
        MemberReview();
        MemberReview(std::string memReviewID_ip, std::string reviewerID_ip, 
                    std::string revieweeID_ip, std::string memberReviewStatus_ip,
                    float rating_ip, std::string comment_ip);        
        std::vector<std::string> getMemberReviewInfo();
        float calRating();
};

#endif
