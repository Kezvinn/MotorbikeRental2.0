#ifndef SYSTEM_H
#define SYSTEM_H

// #include <string>
// #include <vector>
// #include <fstream>
#include <bits/stdc++.h>

#include "../User/User.h"
#include "../User/Member.h"
#include "../User/Admin.h"

#include "../Review/Review.h"
#include "../Review/Member_review.h"
#include "../Review/Motorbike_review.h"

#include "../Motorbike/motorbike.h"

#include "../Request/request.h"

#define TODAY_DATE "24/10/2024"

#define MEMBER_FILE "Data/Member.txt"
#define MOTORBIKE_FILE "Data/Motorbike.txt"

class Admin;

class System {
    private:
        // Members and Motorbike vector pointer
        std::vector<Member*> member_list;
        std::vector<Motorbike*> motorbike_list;

        // Admin
        Admin* admin;
        
        // Pointer to current member and motorbike
        Member *current_member;
        Motorbike *current_motorbike; 
    public:
    // Default Constructor
        System();
        
    // Destructor
        ~System();

    // Getter
        std::vector<Member*> &getMemberList();
        std::vector<Motorbike*> &getMotorbikeList();
        
    // Main Menu
        int mainMenu();
        
    // Non-Member
        int viewAllMotorbike(); 
        int signup();
        
    // Member Menu
        int memberLogin();
        int bikeSignup(Motorbike &newbike);
        int memberMenu();     
        int logout();
        int rentMotorbikeMenu();
    // Admin Menu
        int adminLogin();
        int adminMenu();
    
    // file handling
        // Load data from txt files
        int loadMember();
        int loadMotorbike();
        // Save data to txt files 
        int saveMember();
        int saveMotorbike();
    
};
#endif
