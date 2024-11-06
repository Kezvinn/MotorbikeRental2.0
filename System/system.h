#ifndef SYSTEM_H
#define SYSTEM_H

#include <bits/stdc++.h>

#include "../User/User.h"
#include "../User/Member.h"
#include "../User/Admin.h"

#include "../Review/Review.h"
#include "../Review/Member_review.h"
#include "../Review/Motorbike_review.h"

#include "../Motorbike/motorbike.h"

#include "../Request/request.h"

#define TODAY_DATE "07/11/2024"

#define MEMBER_FILE "Data/Member.txt"
#define MOTORBIKE_FILE "Data/Motorbike.txt"

class Admin;

class System {
    private:
        // Admin
        Admin* admin;
        // Members and Motorbike vector pointer
        std::vector<Member*> member_list;
        std::vector<Motorbike*> motorbike_list;
        // Pointer to current member and motorbike
        Member *current_member;
        Motorbike *current_motorbike; 
    public:
    // Default Constructor
        System();
    // Destructor
        ~System();
    // Init function - update Info of request and rent status
        int init();

    // Getter to serve the Admin class
        std::vector<Member*> &getMemberList();
        std::vector<Motorbike*> &getMotorbikeList();
    
    // Main Menu
        int mainMenu();
    // Admin Menu
        int adminLogin();
        int adminMenu();    
    // Non-Member
        int viewAllMotorbike();
        int signup();
        
    // Member Menu
        int memberLogin();
        Motorbike* bikeSignup();
        int memberMenu();       // have all the function for member (in Member class)
        int rentMotorbikeMenu();
    
    // File handling
        // Load data from txt files
        int loadMember();
        int loadMotorbike();
        // Save data to txt files 
        int saveMember();
        int saveMotorbike();
    // logout
        int logout();
};
#endif

