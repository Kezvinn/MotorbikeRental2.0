#include "my_func.h"

std::string randomIDs (std::string type){ 
    srand(time(0));
    std::string id;
    if (type == "member"){
        id = "M" + std::to_string(rand() % 1000);
    }
    else if (type == "motorbike"){
        id = "B" + std::to_string(rand() % 1000);
    }
    return id;
}
// Fucntion to check if the input is only number
bool isNumber(std::string phone){
    std::regex number_regex("^[0-9]+$");
    if (std::regex_match(phone, number_regex)){
        return true;
    }
    return false;
}
// Function to check if a year is a leap year
bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
// Function to check if the date is valid
bool isValidDate(int day, int month, int year) {
    // Array with the maximum days per month
    int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    // Check if year is a leap year and set February to 29 days
    if (month == 2 && isLeapYear(year)) {
        daysInMonth[1] = 29;
    }

    // Check if month is valid and day is within the valid range for that month
    if (month < 1 || month > 12) return false;
    if (day < 1 || day > daysInMonth[month - 1]) return false;

    return true;
}
// Function to validate date format and logical correctness
bool isDateValid(const std::string& input) {
    // Regex for DD/MM/YYYY format with only digits and / symbol
    std::regex dateRegex("^([0-3][0-9])/([0-1][0-9])/([0-9]{4})$");
    std::smatch match;

    if (std::regex_match(input, match, dateRegex)) {
        // Extract day, month, and year from the input
        int day, month, year;
        std::stringstream(match[1]) >> day;   // Day
        std::stringstream(match[2]) >> month; // Month
        std::stringstream(match[3]) >> year;  // Year

        // Check if the date is logically valid
        return isValidDate(day, month, year);
    }

    return false;  // If the format is incorrect
}
// Function to check if the input is a letter
bool isLetter(std::string input){
    std::regex validRegex("^[A-Za-z ]+$");
     if (std::regex_match(input, validRegex)){
        return true;
    }
    return false;
}

bool isUsername(std::string username){
    std::regex validRegex("^[A-Za-z0-9]+$");
    if (std::regex_match(username, validRegex)){
        return true;
    }
    return false;
}
bool isPassword(std::string password){
    std::regex validRegex("^[A-Za-z0-9!@#$%^&*()_+\\-=\\[\\]{};:,<.>?]+$");
    if (std::regex_match(password, validRegex)){
        return true;
    }
    return false;
}
