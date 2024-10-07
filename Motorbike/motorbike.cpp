#include "Motorbike.h"

Motorbike::Motorbike(string model_ip, string color_ip, int engine_size_ip, 
        string transmission_mode_ip, int year_made_ip, string desctiption_ip, 
        int rent_cost_ip, string start_date_ip, string end_date_ip)
        :model(model_ip), color(color_ip), engine_size(engine_size_ip),
        transmission_mode(transmission_mode_ip), year_made(year_made_ip), desctiption(desctiption_ip), 
        rent_cost(rent_cost_ip), start_date(start_date_ip), end_date(end_date_ip){};

