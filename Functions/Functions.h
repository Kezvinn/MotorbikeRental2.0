#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
#include <string>
#include <random>
#include <time.h>
#include <regex>
#include <sstream>

// generate random ID for member and motorbike
std::string randomIDs (std::string type);

// funtions to check for each input from user
bool isNumber(std::string phone);
bool isLeapYear(int year);
bool isValidDate(int day, int month, int year);
bool isDateValid(const std::string& input);
bool isLetter(std::string input);
bool isUsername(std::string input);
bool isPassword(std::string input);

int choiceInRange(int min, int max);

// string manipulation functions
std::vector<std::string> splitString (std::string &str, char delimiter);
#endif