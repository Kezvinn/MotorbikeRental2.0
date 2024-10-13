#include <iostream>
#include "./Functions/my_func.h"
#include "./System/system.h"
#include "./User/Member.h"
#include "./User/Admin.h"

using namespace std;
int main(){
    cout << "----------------------------" << endl;
    cout << "MOTORBIKE RENTAL APPLICATION" << endl;
    cout << "Created by: Nhat Nguyen" << endl;
    cout << "----------------------------" << endl;
    cout << "1. Log in" << endl;
    cout << "2. Sign up" << endl;
    cout << "3. View motorbikes" << endl;
    cout << "4. Exit" << endl;
    Admin admin;
    Member member;


    while (1){
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
    
        switch (choice) {
            case 1:
                cout << "case 1" <<endl;
                break;
            case 2:
                cout << "case 2" <<endl;
                // member.signup();
                member.addCredit();
                cout << "Completed case 2" << endl;
            
                break;
            case 3:
                cout << "case 3" <<endl;
            
                break;
            case 4:
                cout << "case 4" <<endl;

                return 0;
        }
    }

    return 0;
}