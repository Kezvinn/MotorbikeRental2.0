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
        std::string memberID;                               // 0
    // Member information                                   // 1-2 = username, password
        std::string fullname;                               // 3
        std::string phonenumber;                            // 4    10 digits
        bool id_type;   // 0 = Citizen ID, 1 = Passport     // 5    
        std::string id_number;                              // 6    12 digit for citizen ID, passport 1 initial letter +8 numbers
        std::string drv_license;                            // 7    12 digits
        std::string exp_date;                               // 8    
        int credit = 20;    // default credit               // 9 
    // pointer to bike own and rent
        Motorbike *ownedbike;   // pointer to the motorbike that the member is own
        Motorbike *rentedbike;  // pointer to the motorbike that the member is renting
    // Motorbike ID -- owned and rented
        std::string ownedbikeID;                            // 10
        std::string rentingbikeID;                          // 11
    // Rating
        float memberRating;                                 // 12
    
    // Request and Reivew
        std::vector<Request*> rentRequest;
        std::vector<MemberReview*> memberReview; 

        std::vector<std::string> rentedBikeHistory; // store rented bike ID that had not been rate
    public:
        // Default constructor
        Member(); 
        // Parameterized constructor - use this to create new member
        Member(std::string username_ip, std::string password_ip,
               std::string fullname_ip, std::string phonenumber_ip, 
               bool id_type_ip, std::string id_number_ip, 
               std::string drv_license_ip, std::string exp_date_ip, 
               int credit_ip, 
               std::string ownedbikeID_ip, std::string rentedbikeID_ip,
               float memberRating_ip);
        // Parameterized constructor - use this to load member from file    
        Member(std::string memberID_ip, std::string username_ip, std::string password_ip,
               std::string fullname_ip, std::string phonenumber_ip, 
               bool id_type_ip, std::string id_number_ip, 
               std::string drv_license_ip, std::string exp_date_ip, 
               int credit_ip, 
               std::string ownedbikeID_ip, std::string rentedbikeID_ip,
               float memberRating_ip);
        // Destructor
        ~Member();

        int memberLogin(std::string &username_ip, std::string &pwd_ip);                      // Member login
        
        Motorbike* getOwnedBike() const;                                                          // Get owned bike
        Motorbike* getRentedBike() const;                                                         // Get rented bike
        // Setter
        int setOwnedBike(Motorbike *ownedbike_ip);        // Set owned bike ptr
        int setRentedBike(Motorbike *rentedbike_ip);      // Set rented bike ptr
        int setOwnbikeID(std::string bikeID);             // Set owned bike ID
        int setRentBikeID(std::string bikeID);            // Set rented bike ID

        // Getter
        std::vector<std::string> getMemberInfo();       // get all member information
        std::string getOwnbikeID();                     // get owned bike ID
        std::string getRentBikeID();                    // get rented bike ID
        std::string getMemberID();                      // get member ID
        int addRentRequest(Request *newRequest);         // add new rent request
        int addMemberReview(MemberReview *newReview);    // add new member review
        
        // Member Menu Methods
        // Show Member Info
        void showMemberInfo();      // 1
        // Show renting request
        int rentRequestMenu();      // 3
        // Rate rented motorbike
        int rateMotorbikeMenu();    // 4
        // Rate renter 
        int rateRenterMenu();       // 5
        // add credit
        int addCredits();           // 7
        // Logout
        int logout();               // 8

        // File handling functions
        // Load request and review from File (based on Current Member ID)
        int loadRequest();
        int loadMemberReview();
        // Save Requests and Review back to file (based on Current Member ID)
        int saveRequest();
        int saveMemberReview();


        // check for member owned bike and renting bike if have

        
};

#endif