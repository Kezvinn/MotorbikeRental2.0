#ifndef REVIEW_H
#define REVIEW_H

// #include <string>
// #include <iostream> //testing
#include <bits/stdc++.h>


class Review {
    private:
        float rating;   // 1-10
        std::string comment;
    public:
        Review();
        Review(float rating_i, std::string comment_i);
        
        int getReview();    //getter to get rating and comment
        
        float getRating();
        std::string getComment();
};


#endif

