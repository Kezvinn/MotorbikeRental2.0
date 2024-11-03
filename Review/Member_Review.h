#ifndef MEMBER_RATING_H
#define MEMBER_RATING_H
#include "Review.h"

#include "../Functions/Functions.h"

class MemberReview : public Review {
    private:
        std::string memReviewID;            // 0 ID of the review
        std::string reviewerID;             // 1 member who give the review
        std::string revieweeID;             // 2 member who receive the review
        std::string memberReviewStatus;     // 3 Pending/Complete
    public:
        MemberReview();
        // parameterized constructor use for creating new review
        MemberReview(std::string memReviewID_ip, std::string reviewerID_ip, 
                     std::string revieweeID_ip, std::string memberReviewStatus_ip);
        //  parameterized constructor - use for loading review from file
        MemberReview(std::string memReviewID_ip, std::string reviewerID_ip, 
                     std::string revieweeID_ip, std::string memberReviewStatus_ip,
                     float rating_ip, std::string comment_ip);        
        std::vector<std::string> getMemberReviewInfo();
        
};

#endif
