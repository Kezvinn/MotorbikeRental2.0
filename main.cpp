#include <iostream>
#include "./Functions/Functions.h"
#include "./System/system.h"
#include "./User/Member.h"
#include "./User/Admin.h"

using namespace std;

int main(){
    System *system = new System();

    system->init();
    while (1){
        system->mainMenu();
    }
    return 0;
}
