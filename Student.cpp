//
// Created by wxrstvrsn on 16.02.2023.
//

#include "Student.h"
#include "Database.h"
#include "supportFuncs.h"
#include <iostream>

Student::Student(const uint &_age, const std::string &_name, const std::string &_city,
                 const std::string &_homeAddress, const std::string &_institute) :
        age(_age), name(_name), city(_city), homeAddress(_homeAddress),
        institute(_institute) {};

Student::Student() {
    this->name = "Bjarne";
    this->age = 18;
    this->homeAddress = "Izmailovo";
    this->city = "Moscow";
    this->institute = "MIREA";

    std::cout << "NOTICE: You didn't set the parameters for the student, \n"
                 "so the fields are initialized with default values" << std::endl;
}

void Student::introduceYourself() {
    std::cout << "-------------------------------------------" << std::endl;
    std::cout << "Hello! My name is " << name << ". I am " << age << " year old" << std::endl;
    std::cout << "My city is " << city << "; my homeAddress is " << homeAddress << std::endl;
    std::cout << "My institute: " << institute << std::endl;
}

int Student::getWeekendCost(const DatabaseHandler &data, const uint &month,
                            const std::string &caffe, const std::string &cinema) {
    int food = data.getHomeFoodCost(this->city, this->age);
    int movie = data.getCinemaCost(this->city, cinema);
    int coffe = data.getCoffeeCost(this->city, caffe);
    if (food < 0) {
        std::cout << "Home food cost not found" << std::endl;
        food = 0;
    }
    if (movie < 0) {
        std::cout << "Cinema cost not found" << std::endl;
        movie = 0;
    }
    if (coffe < 0) {
        std::cout << "Coffe cost not found" << std::endl;
        coffe = 0;
    }
    std::cout << food << " " << movie << " " << coffe << std::endl;

    return static_cast<uint>(0.66 * food / getDaysCount(month) + movie + coffe + 0.5);
}

int Student::getWorkdayCost(const DatabaseHandler &data, const uint &month) {
    int transp = data.getTransportCost(this->city, this->homeAddress, this->institute);
    if (transp < 0) {
        std::cout << "Transport cost not found" << std::endl;
        transp = 0;
    }
    int instDinner = data.getInstituteDinnerCost(this->city, this->institute);
    if (instDinner < 0) {
        std::cout << "Institute dinner cost not found" << std::endl;
        instDinner = 0;
    }
    int food = data.getHomeFoodCost(this->city, this->age);
    if (food < 0) {
        std::cout << "Home food cost not found" << std::endl;
        food = 0;
    }
    return static_cast<uint>(2 * transp + instDinner + 0.66 * food / getDaysCount(month) + 0.5);
}

int Student::getCosts(const DatabaseHandler &data, const uint &month,
                      const std::string caffe, const std::string &cinema) {
    const uint daysCount = getDaysCount(month);
    const uint workDays = getWorkdays(month);
    const uint weekends = daysCount - workDays;
    int otherCost = data.getOtherMontlyCosts(this->city, this->age);
    if (otherCost < 0) {
        std::cout << "Other monthly cost not found" << std::endl;
        otherCost = 0;
    }
    return workDays * getWorkdayCost(data, month) +
           weekends * getWeekendCost(data, month,caffe, cinema) + otherCost;
}
