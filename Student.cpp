//
// Created by wxrstvrsn on 16.02.2023.
//

#include "Student.h"
#include "Database.h"
#include "supportFuncs.h"
#include <iostream>

Student::Student(const uint &age, const uint &month, const std::string &name, const std::string &city,
                 const std::string &homeAddress, const std::string &institute) {
    this->name = name;
    this->age = age;
    this->homeAddress = homeAddress;
    this->city = city;
    this->institute = institute;

}

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
    /* По выходным дням расходы складываются из стоимости:
     - похода в кино (пешком)
     - похода  в кафе (пешком)
     - завтрака и обеда дома */

    return static_cast<uint>(0.66 * data.getHomeFoodCost(this->city, this->age) / getDaysCount(month) +
                             data.getCinemaCost(this->city, cinema)
                             + data.getCoffeeCost(this->city, caffe) + 0.5);
}

int Student::getWorkdayCost(const DatabaseHandler &data, const uint &month) {
    return static_cast<uint>(2 * data.getTransportCost(this->city, this->homeAddress, this->institute) +
                             data.getInstituteDinnerCost(this->city, this->institute)
                             + 0.66 * data.getHomeFoodCost(this->city, this->age) / getDaysCount(month) + 0.5);
}

int Student::getCosts(const DatabaseHandler &data, const uint &month,
                      const std::string caffe, const std::string &cinema) {
    /* Расходы:
     - по рабочим дням
     - по выходным дням
     - прочие расходы */
    if (!isMonth(month)) {
        return 0;
    }
    const uint daysCount = getDaysCount(month);
    const uint workDays = getWorkdays(month);
    const uint weekends = daysCount - workDays;

    return workDays * getWorkdayCost(data, month) +
           weekends * getWeekendCost(data, month, caffe, cinema) +
           data.getOtherMontlyCosts(this->city, this->age);
}
