//
// Created by wxrstvrsn on 16.02.2023.
//

#include <string>


#pragma once



class DatabaseHandler {
private:
    std::string costsPath;
    std::string transportPath;
    std::string institutePath;
    std::string restPath;

public:
    // по дефолту задаем свои пути, если был вызван стандартный конструктор
    DatabaseHandler();
    DatabaseHandler(const std::string &costs, const std::string &transport,
                    const std::string institute, const std::string &rest);

    ~DatabaseHandler();


    uint getOtherMontlyCosts(const std::string& city, uint age);
    uint getHomeFoodCost(const std::string &city, uint age);
    uint getCinemaCost(const std::string& city, const std::string& cinema);
    uint getCoffeeCost(const std::string& city, const std::string& coffee);
    uint getInstituteDinnerCost(const std::string& city, const std::string& institute);
    uint getTransportCost(const std::string& city, const std::string& homeAddress,
                          const std::string& institute);






};