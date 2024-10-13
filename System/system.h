#ifndef SYSTEM_H
#define SYSTEM_H
#include <string>
#include <vector>
#include <fstream>

#include "../User/Admin.h"
#include "../User/Member.h"

#include "../Motorbike/motorbike.h"

class System{
    private:
        std::vector<Member> member_list;
        std::vector<Motorbike> motorbike_list;

        Member *current_member;
        Motorbike *current_motorbike;
    public:
        System();   //default constructor
        int init();    //initialize the system
        int loadMember();
        int loadMotorbike();
        int login();
        int signup();

        int saveMember();
        int saveMotorbike();

};


#endif