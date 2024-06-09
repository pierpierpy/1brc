#include <iostream>
#include <chrono>

#include "read_array.hpp"
using namespace std;




int main() {
    chrono::duration<double> timetable(0);
    int trials = 1;
    string filename = "measurements_10k.txt";
    for(int i= 1; i<=trials; i++) {
        auto start = std::chrono::high_resolution_clock::now();
        read_file_array(&filename);
        //parse_file_vector("measurements_10k.txt");
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> duration = end - start;
        timetable+=duration;
    }
    chrono::duration<double> mean_time = timetable/trials;
    cout << mean_time.count();
}
