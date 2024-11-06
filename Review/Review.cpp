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

int Review::setRating(float rating_i){
    this->rating = rating_i;
    return 0;
}
int Review::setComment(std::string comment_i){
    this->comment = comment_i;
    return 0;
}

int Review::getReview(){
    std::cout << "Rating: " << rating << std::endl;
    std::cout << "Comment: " << comment << std::endl;
    return 0;
}