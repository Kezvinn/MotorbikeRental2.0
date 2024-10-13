#include "motorbike.h"

Motorbike::Motorbike(std::string model_ip, std::string color_ip, int engine_size_ip, 
        std::string transmission_mode_ip, int year_made_ip, std::string desctiption_ip, 
        int rent_cost_ip, std::string start_date_ip, std::string end_date_ip)
        :model(model_ip), color(color_ip), engine_size(engine_size_ip),
        transmission_mode(transmission_mode_ip), year_made(year_made_ip), desctiption(desctiption_ip), 
        rent_cost(rent_cost_ip), start_date(start_date_ip), end_date(end_date_ip){};
