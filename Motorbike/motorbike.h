#ifndef MOTORBIKE_H
#define MOTORBIKE_H

#include <string>
using namespace std;

class Motorbike {
    private:

    public:
    // motorbike information
        string model;
        string color;
        int engine_size;
        string transmission_mode;
        int year_made;
        string desctiption;

    // renting information
        int rent_cost;
        string start_date;
        string end_date;
    // constructor
        Motorbike(string model_ip, string color_ip, int engine_size_ip, 
        string transmission_mode_ip, int year_made_ip, string desctiption_ip, 
        int rent_cost_ip, string start_date_ip, string end_date_ip);
};


#endif