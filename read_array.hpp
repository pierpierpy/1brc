#pragma once
#include <fstream>
#include <string>
#include <vector>
#include <optional>
#include <algorithm>

#include "parse_array.hpp"

using namespace std;

optional<Station*> stationExists(std::vector<Station>& stations, const Station& station) {
    for (auto& _station : stations) {
        if (_station.name == station.name) {
            return &_station;
        }
    }
    return {};
}

int read_file_array(const string* filename) {
    string line;
    ifstream myfile(*filename);
    vector<Station> visited_stations;
    if (myfile.is_open())
    {
        while (getline(myfile,line) ) {
            Station station = parse_line(line);
            auto exists = stationExists(visited_stations, station);
            if (exists){
                    exists.value()->sum_temperature += station.temperature;
                    if (station.temperature>exists.value()->max_temperature) {
                        exists.value()->max_temperature = station.max_temperature;
                    }
                    if (station.temperature<exists.value()->min_temperature) {
                        exists.value()->min_temperature = station.min_temperature;
                    }
                    exists.value()->encounters+=1;
            }
            else {
                visited_stations.push_back(station);
            }
        }
        myfile.close();
    }

    else cout << "Unable to open file" ;
    sort(visited_stations.begin(), visited_stations.end(), [](const Station& a, const Station& b) {
            return a.name < b.name;
        });
    cout<<"{";
    for (const auto& _station : visited_stations) {
        cout << _station.name << " = " << _station.min_temperature << "/" << _station.max_temperature << "/" << _station
                .sum_temperature / _station.encounters <<","<< _station.encounters<<endl;
    }
    cout<<"}" <<endl;
    return 0;

}




