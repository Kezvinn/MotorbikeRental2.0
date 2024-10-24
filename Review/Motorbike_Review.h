#ifndef MOTORBIKE_REVIEW_H
#define MOTORBIKE_REVIEW_H

#include "Review.h"
#include "../Functions/Functions.h"
class MotorbikeReview: public Review {
    private:
        std::string motorbikeReviewID;          // 0 ID of the review
        std::string renterID;                   // 1 member who give the review about the motorbike
        std::string rentedMotorbikeID;          // 2 motorbike that is being reviewed
        std::string motorbikeReviewStatus;      // 3 pending/completed
    public:
        MotorbikeReview();
        MotorbikeReview(std::string motorbikeReviewID_ip, std::string renterID_ip, 
                        std::string rentedMotorbikeID_ip, std::string motorbikeReviewStatus_ip, 
                        float rating_ip, std::string comment_ip);
        std::vector<std::string> getMotorbikeReviewInfo();

        float calMotorbikeRating();
        
};

#endif


