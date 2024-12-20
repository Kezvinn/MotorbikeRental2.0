#include "Functions.h"

std::string randomIDs (std::string type){ 
    srand(time(0));
    std::string id;
    std::ostringstream oss;
    
    int randomNum = rand() % 1000;
    oss <<std::setw(3) << std::setfill('0') << randomNum;
    
    if (type == "member"){ id = "M" + oss.str(); }
    else if (type == "motorbike"){ id = "B" + oss.str(); }
    else if (type == "request"){ id = "RQ" + oss.str(); }
    else if (type == "memReview"){ id = "MR" + oss.str(); }
    else if (type == "bikeReview"){ id = "BR" + oss.str();
    } else if (type == "history"){ id = "H" + oss.str(); }
    return id;
}
// Fucntion to check if the input is only number
bool isNumber(std::string &input){
    std::regex number_regex("^[0-9]+$");
    if (std::regex_match(input, number_regex)){
        return true;
    }
    return false;
}
// check for number and allow float number
bool isFloatNumber(std::string &input){  
    std::regex validRegex("^[0-9]*\\.?[0-9]+$");
    if (std::regex_match(input, validRegex)){
        return true;
    }
    return false;
}
// Function to check if a year is a leap year
bool isLeapYear(int &year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
// Function to check if the date is valid - need to check for today date
bool isValidDate(int &day, int &month, int &year) {
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
bool isDateValid(const std::string &input) {
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
bool isLetter(std::string &input){
    std::regex validRegex("^[A-Za-z\\s-]+$");
     if (std::regex_match(input, validRegex)){
        return true;
    }
    return false;
}

bool isUsername(std::string &username){
    std::regex validRegex("^[A-Za-z0-9]+$");
    if (std::regex_match(username, validRegex)){
        return true;
    }
    return false;
}

bool isPassword(std::string &password){
    std::regex validRegex("^[A-Za-z0-9!@#$%^&*()_+\\-=\\[\\]{};:,<.>?]+$");
    if (std::regex_match(password, validRegex)){
        return true;
    }
    return false;
}

bool isPassport(std::string &passport){
    std::regex pattern("^[A-Za-z][0-9]{8}$");
    if (std::regex_match( passport, pattern)){
        return true;
    }
    return false;

}
// get real time date of today
std::string todayDate(){
    auto now = std::chrono::system_clock::now();
    std::time_t currentTime = std::chrono::system_clock::to_time_t(now);
    std::tm localTime = *std::localtime(&currentTime);

    std::ostringstream oss;
    oss << std::put_time(&localTime, "%d/%m/%Y");
    std::string date = oss.str();
    
    return date;
}

std::vector<std::string> splitString(std::string &str, char delimiter){
    std::vector <std::string> data_result;
    std::istringstream is(str);
    std::string item;
    while (std::getline(is, item, delimiter)){
        data_result.push_back(item);
    }
    return data_result;
}

int choiceInRange(int min, int max){
    int choice;
    do {
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        if (std::cin.fail()){
            std::cin.clear();
            std::cin.ignore();
        }
    } while (choice < min || choice > max);
    return choice;
}

char returnYesNo(){ 
    char c; 
    do {
        std::cout << "Enter your answer (Y/N): ";
        std::cin >> c;
        if (std::cin.fail()){
            std::cin.clear();
            std::cin.ignore();
        }
    } while (tolower(c) != 'y' && tolower(c) != 'n');
    
    return c;
}
char returnYes(){ // only accept Y
    char c; 
    do {
        std::cout << "Enter your answer (Y/N): ";
        std::cin >> c;
        if (std::cin.fail()){
            std::cin.clear();
            std::cin.ignore();
        }
    } while (tolower(c) != 'y');
    c = tolower(c);
    return c;
}

// Functions to calculate the duration by the different of date
tm parseDate(const std::string & dateStr){
    struct tm date = {0};
    std::istringstream dateStream(dateStr);
    std::string day, month, year;

    // Parse the date string
    std::getline(dateStream, day, '/');
    std::getline(dateStream, month, '/');
    std::getline(dateStream, year);

    // Set the tm structure
    date.tm_mday = std::stoi(day);
    date.tm_mon = std::stoi(month) - 1;  // Months are 0-based in tm
    date.tm_year = std::stoi(year) - 1900;  // Years since 1900

    return date;
}
int rentDuration(const std::string &startDateStr, const std::string &endDateStr){
     // Parse the input date strings
    tm startDate = parseDate(startDateStr);
    tm endDate = parseDate(endDateStr);

    // Convert tm structure to time_t
    time_t start = mktime(&startDate);
    time_t end = mktime(&endDate);

    // Calculate the difference in seconds and convert to days
    double secondsDifference = difftime(end, start);
    int daysDifference = secondsDifference / (60 * 60 * 24);

    return daysDifference;
}

bool isFileEmpty(const std::string &filename){
    std::ifstream file(filename, std::ios::ate); // Open file in "at end" mode
    if (!file.is_open()) {
        std::cerr << "Error: Could not open the file.\n";
        return true; // Assume empty if unable to open
    }
    return file.tellg() == 0; // Check if the position is at the start (file is empty)
}
// std::vector<std::string> readFile(const std::string &filename){
//     std::ifstream file;
//     file.open(filename, std::ios::in);
//     if (!file.is_open()){
//         std::cerr << "Error opening file " << filename << std::endl;
        
//     }
//     std::vector<std::string> data;
//     std::vector<std::string> matrix;
//     std::string line;
    
//     int cols = 8;
//     int rows = 0;
//     while (std::getline(file, line)){
//         data = splitString(line, '|');
//         matrix.insert(matrix.end(), data.begin(), data.end());
//         rows++;
//     }
//     // std::cout << "rows = " << rows << std::endl;
//     // for (int row = 0; row < rows; ++row){
//     //     for (int col = 0; col < cols; ++col){
//     //         std::cout << matrix[row * cols + col] << " ";
//     //     }
//     //     std::cout << std::endl;
//     // }
//     // std::cout << "DOne" << std::endl;

//     return matrix;
// }