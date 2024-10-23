#ifndef MEMBER_H
#define MEMBER_H

#include <iostream>
#include <fstream>

#include "User.h"

#include "../Motorbike/Motorbike.h"
#include "../Functions/Functions.h"
#include "../Request/Request.h"
#include "../Review/Member_review.h"

const std::string MEMBER_REVIEW_FILE = "Data/MemberReview.txt";
const std::string MEMBER_REQUEST_FILE = "Data/MemberRequest.txt";

class Member: public User{
    private:
    // Member ID
        std::string memberID;           // 0
    
    // Member information
        std::string fullname;           // 1
        std::string phonenumber;        // 2
        bool id_type;   // 0 = Citizen ID, 1 = Passport     // 3
        std::string id_number;                              // 4
        std::string drv_license;                            // 5
        std::string exp_date;                               // 6
        int credit = 20;    // default credit               // 7 

    // pointer to bike own and rent
        Motorbike *ownedbike;   // pointer to the motorbike that the member is own
        Motorbike *rentedbike;  // pointer to the motorbike that the member is renting
    
    // Motorbike ID -- owned and rented
        std::string ownedbikeID;
        std::string rentedbikeID;
    
    // Rating
        float memberRating;

    // Request and Reivew
        std::vector<Request*> rentRequest;
        std::vector<MemberReview*> memberReview;
        
    // Pointer to Request and Review of the members
        Request *current_request;
        MemberReview *current_review;
        

    public:
        // Constructor
        Member(); //default constructor
        Member(std::string memberID_ip, std::string username_ip, std::string password_ip, std::string fullname_ip, 
        std::string phonenumber_ip, bool id_type_ip, std::string id_number_ip, 
        std::string drv_license_ip, std::string exp_date_ip, int credit_ip, 
        std::string ownedbikeID_ip, std::string rentedbikeID_ip,
        float memberRating_ip);
        
        // Destructor
        ~Member();

        // Getter
        std::vector<std::string> getMemberInfo();    // get all member information
        void showMemberInfo();  // show all member information
        std::string getMemberID();   // get member ID
        float getMemberRating();    // get member rating
        std::string getOwnedMotorbikeID();  // get owned motorbike ID
        std::string getRentedMotorbikeID(); // get rented motorbike ID
        
        // show member info (done)
        // show motorbike info (owned bike info)
        // show renting request (belong to member bike)
        // rate rented motorbike
        // rate renter
        // rent motorbike
        int addCredits();

        // Logout
        int logout();

        // File handling functions
        // Load request and review from File (based on Current Member ID)
        int loadRequest();
        int loadMemberReview();
        // Save Requests and Review back to file (based on Current Member ID)
        int saveRequest();
        int saveMemberReview();
};


#endif 
