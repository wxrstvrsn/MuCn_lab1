//
// Created by wxrstvrsn on 16.02.2023.
//
#include <iostream>
#include <fstream>
#include <sstream>
#include "Database.h"


DatabaseHandler::DatabaseHandler() {
    costsPath = "C:\\Users\\79157\\CLionProjects\\MISP\\1stLAB\\Database\\Costs.csv";
    transportPath = "C:\\Users\\79157\\CLionProjects\\MISP\\1stLAB\\Database\\Transport.csv";
    institutePath = "C:\\Users\\79157\\CLionProjects\\MISP\\1stLAB\\Database\\Institute.csv";
    restPath = "C:\\Users\\79157\\CLionProjects\\MISP\\1stLAB\\Database\\Caffe-and-cinema.csv";
    std::cout << "NOTICE: The paths to the data files were set by default" << std::endl;
}

DatabaseHandler::DatabaseHandler(const std::string &costs, const std::string &transport,
                                 const std::string &institute, const std::string &rest) :
        costsPath(costs), transportPath(transport), institutePath(institute), restPath(rest) {
    std::cout << "NOTICE: The paths to the data files were set based on user data" << std::endl;
};

int DatabaseHandler::getOtherMontlyCosts(const std::string &city, const uint &age) const {
    std::fstream fs;
    fs.open(this->costsPath, std::fstream::in);
    if (!fs.is_open()) {
        std::cout << "\nWARNING: Error " << costsPath << " reading\n" << std::endl;
        exit(-1);

    }

    std::string line;
    char delimiter = ',';
    getline(fs, line);
    while (getline(fs, line)) {
        std::stringstream stream(line);

        std::string _city, _age, _foodCostPerMonth, _otherCosts;
        getline(stream, _city, delimiter);
        getline(stream, _age, delimiter);
        getline(stream, _foodCostPerMonth, delimiter);
        getline(stream, _otherCosts, delimiter);

        if (age == std::stoi(_age) && city == _city) {
            return stoi(_otherCosts);
        }
    }
    return -1;

}

int DatabaseHandler::getHomeFoodCost(const std::string &city, const uint &age) const {
    std::fstream fs;
    fs.open(this->costsPath, std::fstream::in);
    if (!fs.is_open()) {
        std::cout << "\nWARNING: Error " << costsPath << " reading\n" << std::endl;
        return 0;
    }

    std::string line;
    char delimiter = ',';
    getline(fs, line);
    while (getline(fs, line)) {
        std::stringstream stream(line);

        std::string _city, _age, _otherCosts, _foodCostPerMonth;
        getline(stream, _city, delimiter);
        getline(stream, _age, delimiter);
        getline(stream, _foodCostPerMonth, delimiter);
        getline(stream, _otherCosts, delimiter);

        if (age == std::stoi(_age) && city == _city) {
            return stoi(_foodCostPerMonth);
        }

    }
    return -1;
}

int DatabaseHandler::getCinemaCost(const std::string &city, const std::string &cinema) const {
    std::fstream fs;
    fs.open(this->restPath, std::fstream::in);
    if (!fs.is_open()) {
        std::cout << "\nWARNING: Error " << restPath << " reading\n" << std::endl;
        return 0;
    }


    std::string line;
    char delimiter = ',';
    getline(fs, line);
    while (getline(fs, line)) {
        std::stringstream stream(line);

        std::string _city, _address, _caffe, _avCaffeCost, _cinema, _cinemaCost;
        getline(stream, _city, delimiter);
        getline(stream, _address, delimiter);
        getline(stream, _caffe, delimiter);
        getline(stream, _avCaffeCost, delimiter);
        getline(stream, _cinema, delimiter);
        getline(stream, _cinemaCost, delimiter);

        if (_city == city && _cinema == cinema) {
            return stoi(_cinemaCost);
        }

    }
    return -1;
}

int DatabaseHandler::getCoffeeCost(const std::string &city, const std::string &coffee) const {
    std::fstream fs;
    fs.open(this->restPath, std::fstream::in);
    if (!fs.is_open()) {
        std::cout << "\nWARNING: Error " << restPath << " reading\n" << std::endl;
        return 0;
    }


    std::string line;
    char delimiter = ',';
    getline(fs, line);
    while (getline(fs, line)) {
        std::stringstream stream(line);

        std::string _city, _address, _caffe, _cinema, _cinemaCost, _avCaffeCost;
        getline(stream, _city, delimiter);
        getline(stream, _address, delimiter);
        getline(stream, _caffe, delimiter);
        getline(stream, _avCaffeCost, delimiter);
        getline(stream, _cinema, delimiter);
        getline(stream, _cinemaCost, delimiter);

        if (_city == city && _caffe == coffee) {
            return stoi(_avCaffeCost);

        }

    }
    return -1;
}

int DatabaseHandler::getInstituteDinnerCost(const std::string &city, const std::string &institute) const {
    std::fstream fs;
    fs.open(this->institutePath, std::fstream::in);
    if (!fs.is_open()) {
        std::cout << "\nWARNING: Error " << institutePath << " reading\n" << std::endl;
        return 0;
    }


    std::string line;
    char delimiter = ',';
    getline(fs, line);
    while (getline(fs, line)) {
        std::stringstream stream(line);

        std::string _city, _institute, _dinnerCost;
        getline(stream, _city, delimiter);
        getline(stream, _institute, delimiter);
        getline(stream, _dinnerCost, delimiter);

        if (_city == city && _institute == institute) {
            return stoi(_dinnerCost);
        }

    }
    return -1;
}

int DatabaseHandler::getTransportCost(const std::string &city, const std::string &homeAddress,
                                      const std::string &institute) const {
    std::fstream fs;
    fs.open(this->transportPath, std::fstream::in);
    if (!fs.is_open()) {
        std::cout << "\nWARNING: Error " << transportPath << " reading\n" << std::endl;
        return -2;
    }


    std::string line;
    char delimiter = ',';
    getline(fs, line);
    while (getline(fs, line)) {
        std::stringstream stream(line);

        std::string _city, _homeAddress, _institute, _transportCost;
        getline(stream, _city, delimiter);
        getline(stream, _homeAddress, delimiter);
        getline(stream, _institute, delimiter);
        getline(stream, _transportCost, delimiter);

        if (_city == city && _homeAddress == homeAddress && _institute == institute) {
            return stoi(_transportCost);
        }

    }

    return -1;
}






