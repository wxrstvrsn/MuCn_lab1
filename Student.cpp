//
// Created by wxrstvrsn on 16.02.2023.
//

#include "Student.h"
#include <iostream>


Student::Student(uint age, uint month, const std::string &name, const std::string &city,
                 const std::string &homeAddress) {
    this->name = name;
    this->age = age;
    this->homeAddress = homeAddress;
    this->city = city;

}

Student::Student() {
    this->name = "Default Name";
    this->age = 0;
    this->homeAddress = "Default Address";
    this->city = "Default City";

    std::cout << "Вы не задали параметры для студента, поэтому поля инициализированы значениями по умолчанию" << std::endl;
}

void Student::introduceYourself(){
    std::cout << "-------------------------------------------" << std::endl;
    std::cout << "Hello! My name is " << name << ". I am " << age << " year(s) old" << std::endl;
    std::cout << "My city is " << city << "; my homeAddress is " << homeAddress << std::endl;
    std::cout << "-------------------------------------------" << std::endl;
}

Student::~Student() {
    std::cout << "See you next time, goodbye! [" << this << "]" << std::endl;

}