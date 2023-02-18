//
// Created by wxrstvrsn on 16.02.2023.
//

#include <string>
#include "Student.h"

#pragma once



class DatabaseHandler {
private:
    std::string fileName;
    std::string data[20][20];
    std::string headersOfTable[20];
    int columns = 0;
    int rows = 0;

public:
    DatabaseHandler();
    DatabaseHandler(std::string &fileName);

    ~DatabaseHandler();

    void readData();
    int headerNameToIndex(const std::string &headerName);
    std::string getCell(int column, int row);
    std::string getCell(const std::string &columnMarker,
                                         const std::string &rowMarker);

    uint getOtherMontlyCosts(uint month, const std::string& city,
                             uint age);
    uint getHomeFoodCost(const std::string& city);
    uint getCinemaCost(const std::string& city, const std::string& cinema);
    uint getCoffeeCost(const std::string& city, const std::string& coffee);
    uint getInstituteDinnerCost(const std::string& city, const std::string& institute);
    uint getTransportCost(const std::string& city, const std::string& homeAddress,
                          const std::string& institute);





};