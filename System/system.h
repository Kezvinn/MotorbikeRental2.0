#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>
#include <vector>
#include <fstream>

#include "../user/User.h"
#include "../user/Admin.h"
#include "../user/Member.h"

#include "../Review/Review.h"
#include "../Review/Member_review.h"
#include "../Review/Motorbike_review.h"

#include "../Motorbike/motorbike.h"

#include "../Request/request.h"

const std::string MEMBER_FILE = "../Data/Member.txt";
const std::string MOTORBIKE_FILE = "../Data/Motorbike.txt";

class System {
    private:
        // Members and Motorbike vector pointer
        std::vector<Member*> member_list;
        std::vector<Motorbike*> motorbike_list;

        // Admin
        Admin *admin = nullptr;
        
        // Pointer to current member and motorbike
        Member *current_member = nullptr;   
        Motorbike *current_motorbike = nullptr; 
    
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

