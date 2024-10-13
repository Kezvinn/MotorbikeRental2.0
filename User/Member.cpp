#include "Member.h"
Member::Member(){}
Member::Member(std::string username_ip, std::string password_ip, std::string fullname_ip, 
    std::string phonenumber_ip, bool id_type_ip, std::string id_number_ip, 
    std::string drv_license_ip, std::string exp_date_ip, int credit_ip)
    :User(username_ip, password_ip), fullname(fullname_ip), 
    phonenumber(phonenumber_ip), id_type(id_type_ip), id_number(id_number_ip),
    drv_license(drv_license_ip), exp_date(exp_date_ip), credit(credit_ip){};
Member::~Member(){
    delete this->ownedbike;
    delete this->rentedbike;
}
int Member::addCredit(){
    char ans;
    int credit_ip;
    std::cout << "--------------------------------------------" << std::endl; 
    do {    
        std::cout << "Enter the amount of credit you want to add (> 0): ";
        std::cin >> credit_ip;
        if (std::cin.fail()){
            std::cin.clear();
            std::cin.ignore();
        }
    } while (credit_ip <= 0);

    std::cout << "--------------------------------------------" << std::endl; 
    do {
        std::cout << "Credit add: " << credit_ip << " credits" <<  std::endl;
        std::cout << "Confirmation (Y/N): ";
        std::cin >> ans;
        if (std::cin.fail()){
            std::cin.clear();
            std::cin.ignore();
        }
    } while (tolower(ans) != 'y' && tolower(ans) != 'n');

    std::cout << "--------------------------------------------" << std::endl; 
    if ((ans == 'Y' || ans == 'y') && credit_ip > 0){
        this->credit += credit_ip;
        std::cout << "You had add " << credit_ip << " credits"<< std::endl;
        std::cout << "Your current balance: " << this->credit << "credits" << std::endl;
    }
    return 0;
}


int Member::signup(){
    std::string username, password, fullname, phonenumber;
    int id_type;   // 0 = Citizen ID, 1 = Passport
    std::string id_number, drv_license, exp_date;
    int credit = 20;    // default credit

    std::cin.ignore();
    std::cout << "--------------------------------------------" << std::endl; 
    do {
        std::cout << "Enter your username: ";
        std::getline(std::cin, username, '\n');
    } while (!isUsername(username));

    std::cout << "--------------------------------------------" << std::endl; 
    do {
        std::cout << "Enter your password: ";
        std::getline(std::cin, password, '\n');
    } while (!isPassword(password));
    
    std::cout << "--------------------------------------------" << std::endl; 
    do {
        std::cout << "Enter your fullname: ";
        std::getline(std::cin, fullname,'\n');
    } while (!isLetter(fullname));

    std::cout << "--------------------------------------------" << std::endl; 
    do {
        std::cout << "Enter your phone number: ";
        std::getline(std::cin, phonenumber,'\n');
    } while (!isNumber(phonenumber));    

    std::cout << "--------------------------------------------" << std::endl; 
    do {
        std::cout << "ID type (0 = Citizen ID, 1 = Passport): ";
        std::cin >> id_type;
        if (std::cin.fail()){
            std::cin.clear();
            std::cin.ignore();
        }
    } while (id_type != 0 && id_type != 1);
    
    std::cin.ignore();
    std::cout << "--------------------------------------------" << std::endl; 
    do {
        std::cout << "Enter your ID number: ";
        std::getline(std::cin, id_number,'\n');
    } while (!isNumber(id_number));

    std::cout << "--------------------------------------------" << std::endl; 
    do {
        std::cout << "Enter your driver license: ";
        std::getline(std::cin, drv_license, '\n');
    } while (!isNumber(drv_license));

    std::cout << "--------------------------------------------" << std::endl; 
    do {
        std::cout << "Enter your driver license expiration date (DD/MM/YYYY): ";
        std::getline(std::cin, exp_date, '\n');
    } while (!isDateValid(exp_date));

    std::cout << "--------------------------------------------" << std::endl; 
    char ans;
    do {
        std::cout << "Add new bike (Y/N)? ";
        std::cin >> ans; 
    }  while (tolower(ans) != 'y' && tolower(ans) != 'n');
    
    if (ans == 'Y' || ans == 'y'){
        // add new bike
    } else if (ans == 'N' || ans == 'n'){
        std::cout << "Sign up successfully!" << std::endl;
    }

    // create new member and add to to the list 
    return 0;
    
}