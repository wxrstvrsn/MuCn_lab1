//
// Created by wxrstvrsn on 16.02.2023.
//

#pragma once
#include <string>
#include "Database.h"



class Student {
public:
    Student(uint age, uint month, const std::string &name, const std::string &city,
            const std::string &homeAddress, const std::string &institute);
    Student();


    void introduceYourself();

    uint getDaysCount(uint month);
    uint getWorkdays(uint month);
    bool isMonth(uint month);
    uint getWeekendCost(DatabaseHandler &data);
    uint getWorkdayCost(DatabaseHandler &data);
    uint getCosts(DatabaseHandler &data);

    ~Student();

private:
    uint age;
    uint month;
    std::string name;
    std::string city;
    std::string homeAddress;
    std::string institute;
    std::string caffe;
    std::string cinema;



};