//
// Created by wxrstvrsn on 16.02.2023.
//

#pragma once
#include <string>


class Student {
public:
    Student(uint age, uint month, const std::string &name, const std::string &city,
            const std::string &homeAddress);
    Student();


    void introduceYourself();

    uint getAge();

    void getMonth();


    ~Student();

private:
    uint age;
    uint month;
    std::string name;
    std::string city;
    std::string homeAddress;



};