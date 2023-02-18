//
// Created by wxrstvrsn on 16.02.2023.
//

#pragma once
#include <string>


class Student {
public:
    Student(uint age, uint month, const std::string &name, const std::string &city,
            const std::string &homeAddress, const std::string &institute);
    Student();


    void introduceYourself();

    uint getCosts(uint month, const std::string& city, const std::string& homeAddress,
                  const std::string& institute, const std::string& cinema,
                  const std::string& coffee, uint age);
    uint getDaysCount(uint month);
    uint getWorkdays(uint month);
    bool isMonth(int month);
    uint getWeekandCost(const std::string& city, const std::string& cinema,
                        const std::string& coffee, uint age);


    uint getAge();

    void getMonth();


    ~Student();

private:
    uint age;
    uint month;
    std::string name;
    std::string city;
    std::string homeAddress;
    std::string institute;



};