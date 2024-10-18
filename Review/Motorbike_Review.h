#ifndef MOTORBIKE_REVIEW_H
#define MOTORBIKE_REVIEW_H

#include "Review.h"
class MotorbikeReview: public Review {
    private:
        bool review_status;
        int reviewCount;    // number of review
    public:
        MotorbikeReview();
        float calRating();
        
};

#endif

