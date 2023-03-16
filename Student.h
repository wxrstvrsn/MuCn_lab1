//
// Created by wxrstvrsn on 16.02.2023.
//

#pragma once

#include <string>
#include "Database.h"


class Student {
public:
    Student(const uint &age, const uint &month, const std::string &name, const std::string &city,
            const std::string &homeAddress, const std::string &institute);

    Student();


    void introduceYourself();

    int getWeekendCost(const DatabaseHandler &data, const uint &month,
                       const std::string &caffe, const std::string &cinema);

    int getWorkdayCost(const DatabaseHandler &data, const uint &month);

    int getCosts(const DatabaseHandler &data, const uint &month,
                 const std::string caffe, const std::string &cinema);

private:
    uint age;
    std::string name;
    std::string city;
    std::string homeAddress;
    std::string institute;
};