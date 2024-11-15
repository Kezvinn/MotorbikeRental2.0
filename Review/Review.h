#ifndef REVIEW_H
#define REVIEW_H

#include <bits/stdc++.h>

class Review {
    private:
        float rating;               // 1-10
        std::string comment;        // comment of the review
    public:
        Review();
        Review(float rating_i, std::string comment_i);

        // Getter 
        float getRating();
        std::string getComment();
        // Setter
        int setRating(float rating_i);
        int setComment(std::string comment_i);

        int getReview();    //print out rating and comment
        
};
#endif