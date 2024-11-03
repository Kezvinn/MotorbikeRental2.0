#include "Review.h"
// Constructor
Review::Review(){};
Review::Review(float rating_i, std::string comment_i):rating(rating_i), comment(comment_i){};

float Review::getRating(){
    return rating;
}
std::string Review::getComment(){
    return comment;
}

int Review::getReview(){
    std::cout << "Rating: " << rating << std::endl;
    std::cout << "Comment: " << comment << std::endl;
    return 0;
}