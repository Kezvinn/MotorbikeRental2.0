#ifndef MEMBER_H
#define MEMBER_H

#include "User.h"

#include "../Functions/Functions.h"
#include "../Motorbike/Motorbike.h"
#include "../Request/Request.h"
#include "../Review/Member_review.h"

#define MEMBER_REVIEW_FILE "Data/MemberReview.txt"
#define MEMBER_REQUEST_FILE "Data/MemberRequest.txt"

class Member: public User{
    private:
    // Member ID
        std::string memberID;                               // 0
    // Member information                                   // 1-2 = username, password
        std::string fullname;                               // 3
        std::string phonenumber;                            // 4    10 digits
        bool id_type;                                       // 5    0 = Citizen ID, 1 = Passport    
        std::string id_number;                              // 6    12 digit for citizen ID, passport 1 initial letter +8 numbers
        std::string drv_license;                            // 7    12 digits
        std::string exp_date;                               // 8    
        int credit = 20;    // default credit               // 9 
    // pointer to bike own and rent
        Motorbike *ownedbike;   
        Motorbike *rentedbike;
    // Motorbike ID -- owned and rented
        std::string ownedbikeID;                            // 10
        std::string rentingbikeID;                          // 11
    // Rating
        float memberRating;                                 // 12
    // Request and Reivew
        std::vector<Request*> rentRequest;
        std::vector<MemberReview*> memberReview; 
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
        // Member Login
        bool memberLogin(std::string &username_ip, std::string &pwd_ip);
        
        // Getter
        Motorbike* getOwnedBike() const;                // Get owned bike ptr
        Motorbike* getRentedBike() const;               // Get rented bike ptr
        std::string getOwnbikeID();                     // Get owned bike ID
        std::string getRentBikeID();                    // Get rented bike ID
        std::string getMemberID();                      // Get member ID
        std::vector<std::string> getMemberInfo();       // Get all member information into vector of string
        
        // Setter
        int setOwnedBike(Motorbike *ownedbike_ip);        // Set owned bike ptr
        int setRentedBike(Motorbike *rentedbike_ip);      // Set rented bike ptr
        int setOwnbikeID(std::string bikeID);             // Set owned bike ID
        int setRentBikeID(std::string bikeID);            // Set rented bike ID

        // Function to add request and review into private vector
        int addRentRequest(Request *newRequest);         // Add new rent request
        int addMemberReview(MemberReview *newReview);    // Add new member review
        
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
        // Load request and review from File
        int loadRequest();
        int loadMemberReview();
        // Save Requests and Review back to file
        int saveRequest();
        int saveMemberReview();

        // calculate member rating
        float calcMemberRating(); 
};

#endif