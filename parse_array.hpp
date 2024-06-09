#pragma once
#include <string>
using namespace std;

struct Station {
    string name;
    float sum_temperature;
    float temperature;
    float max_temperature;
    float min_temperature;
    int encounters;
    Station(string name, double temperature)
        : name(name), temperature(temperature), max_temperature(temperature), min_temperature(temperature),sum_temperature(temperature), encounters(1) {}
};


Station parse_line(string line) {
    size_t pos = line.find(';');
    string stationName = line.substr(0, pos);
    string temperatureStr = line.substr(pos+1, pos+1);
    double temperature = std::stod(temperatureStr);
    //created a little initializer to initialize the values directly based on temperature and set the value of ecnounters to 1
    return Station(stationName, temperature);
}