#ifndef RATINGS_H
#define RATINGS_H

#include <string>
using namespace std;

class Rating{
    private:
        float rating;   // 1-10
        string comment;
    public:
        Rating(float rating_i, string comment_i);
};


#endif