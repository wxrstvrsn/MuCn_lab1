//
// Created by wxrstvrsn on 16.02.2023.
//


#include <iostream>
#include <fstream>
#include <sstream>
#include "Student.h"
#include "Database.h"


int main() {
//    DatabaseHandler dat;
//    uint age = 0;
//    std::string name = "";
//    std::string city = "";
//    std::string hAd = "";
//
//    std::cin >> age;
//    std::cin >> name;
//    std::cin >> city;
//    std::cin >> hAd;

    std::string filename = "C:\\Users\\79157\\CLionProjects\\MISP\\1stLAB\\Database\\Costs.csv";
    std::ifstream work_file(filename);

    std::string line;
    char delimiter = ',';
    getline(work_file, line);

    while (getline(work_file, line)){
        std::stringstream stream(line);

        std::string city, age, foodCostPerMonth, otherCosts;
        getline(stream, city, delimiter);
        getline(stream, age, delimiter);
        getline(stream, foodCostPerMonth, delimiter);
        getline(stream, otherCosts, delimiter);

        std::cout << "==================" << std::endl;
        std::cout << "City: " << city << std::endl;
        std::cout << "Age: " << age << std::endl;
        std::cout << "foodCostPerMonth: " << foodCostPerMonth << std::endl;
        std::cout << "otherCosts: " << otherCosts << std::endl;

    }
    work_file.close();


    return 0;
}
