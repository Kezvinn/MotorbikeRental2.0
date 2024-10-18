#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>
#include <vector>
#include <fstream>

#include "../User/User.h"
#include "../User/Admin.h"
#include "../User/Member.h"

#include "../Review/Review.h"
#include "../Review/Member_review.h"
#include "../Review/Motorbike_review.h"

#include "../Motorbike/motorbike.h"

#include "../Request/request.h"

const std::string MEMBER_FILE = "../Data/Member.txt";
const std::string MOTORBIKE_FILE = "../Data/Motorbike.txt";

const std::string RENT_REQUEST_FILE = "../Data/rent_request.txt";


class System {
    private:
        // Members and Motorbike vector
        std::vector<Member> member_list;
        std::vector<Motorbike> motorbike_list;

        // Review vector
        std::vector<MemberReview> member_review_list;
        std::vector<MotorbikeReview> motorbike_review_list;     
        
        // Request vector
        std::vector<Request> request_list;

        // Pointer to current member and motorbike
        Member *current_member = nullptr;   // for the current member login in
        Motorbike *current_motorbike = nullptr; 
    public:
        System();   //default constructor

        int init();    //initialize the system
        int mainMenu();
        // Load data from txt files
        int loadMember();
        int loadMotorbike();
        int loadMemberReview();
        int loadBikeReview();
        int loadRentRequest();

        // Member Menu
        int memberLogin();
        int signup();
        int bikeSignup(Motorbike &newbike);       // add new bike to the member
        int memberMenu();       
        int viewMotorbike();    // view motorbike available to rent
        int rentMotorbike();    // send request
        int rateMotorbike();    // rate motorbike
        int rateRenter();       // rate renter
        int logout();


        // Admin Menu
        int adminLogin();
        int adminMenu();
        int adminViewMotorbike();
        int adminViewMember();

        // file handling
        int saveMember();
        int saveMotorbike();
        int saveRentRequest();


};


#endif