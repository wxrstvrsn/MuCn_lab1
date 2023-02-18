//
// Created by wxrstvrsn on 16.02.2023.
//
#include <iostream>
#include <fstream>
#include <sstream>
#include "Database.h"


DatabaseHandler::DatabaseHandler() {
    std::cout << "Вы не задали расположение файлов для инициализации БД \n"
                 "возможна некорректная работа" << std::endl;
}

DatabaseHandler::DatabaseHandler(std::string &fileName) {
    this->fileName = fileName;
}

DatabaseHandler::~DatabaseHandler() {

}

void DatabaseHandler::readData() {
    std::ifstream fs;
    fs.open(this->fileName, std::fstream::in);
    if (!fs.is_open()) {
        return;
    }
    std::string line;
    std::getline(fs, line);
    std::stringstream  lineStream(line);
    while (getline(lineStream, line, ',')) {
        headersOfTable[columns] = line;
        columns++;
    }

    while (std::getline(fs, line)) {
        std::stringstream lineStream(line);
        uint tempCount = 0;
        while (std::getline(lineStream, line, ',')) {
            data[rows][tempCount++];
        }
        rows++;
    }
}

int DatabaseHandler::headerNameToIndex(const std::string &headerName) {
    for (int ind = 0; ind < columns; ind++) {
        if (headersOfTable[ind] == headerName) {
            return ind;
        }
    }
    return -1;
}

std::string DatabaseHandler::getCell(int column, int row) {
    return data[column][row];

}




uint DatabaseHandler::getOtherMontlyCosts(uint month, const std::string &city, uint age) {
    return 0;
}

uint DatabaseHandler::getHomeFoodCost(const std::string &city) {
    return 0;
}

uint DatabaseHandler::getCinemaCost(const std::string &city, const std::string &cinema) {
    return 0;
}

uint DatabaseHandler::getCoffeeCost(const std::string &city, const std::string &coffee) {
    return 0;
}

uint DatabaseHandler::getInstituteDinnerCost(const std::string &city, const std::string &institute) {
    return 0;
}

uint DatabaseHandler::getTransportCost(const std::string &city, const std::string &homeAddress,
                                       const std::string &institute) {
    return 0;
}

std::string DatabaseHandler::getCell(const std::string &columnMarker, const std::string &rowMarker) {

}









