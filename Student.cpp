//
// Created by wxrstvrsn on 16.02.2023.
//

#include "Student.h"
#include <iostream>
#define YEAR 2023


Student::Student(uint age, uint month, const std::string &name, const std::string &city,
                 const std::string &homeAddress, const std::string &institute) {
    this->name = name;
    this->age = age;
    this->homeAddress = homeAddress;
    this->city = city;
    this->institute = institute;

}

Student::Student() {
    this->name = "Bjarne";
    this->age = 72;
    this->homeAddress = "Wall Street";
    this->city = "New York";
    this->institute = "Morgan Stanley";

    std::cout << "You didn't set the parameters for the student, so the fields are initialized with default values" << std::endl;
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

uint Student::getCosts(uint month, const std::string& city, const std::string& homeAddress,
              const std::string& institute, const std::string& cinema,
              const std::string& coffee, uint age) {
    /* Расходы:
     - по рабочим дням
     - по выходным дням
     - прочие расходы */

    const uint daysCount = getDaysCount(month);
    const uint workDays = getWorkdays(month);
    const uint weekends = daysCount - workDays;

    return workDays * getWorkdayCost(city, homeAddress, institute) +
           weekends * getWeekandCost(city, cinema, coffee) +
           getOtherMontlyCosts(month, city, age);
}
bool Student::isMonth(int month) {
    // может ли введенное число являться номером месяца
    return month >= 1 and month <= 12;
}
uint Student::getWeekandCost(const std::string& city, const std::string& cinema,
                    const std::string& coffee, uint age) {
    /* По выходным дням расходы складываются из стоимости:
     - похода в кино (пешком)
     - похода  в кафе (пешком)
     - завтрака и обеда дома */

    return static_cast<uint>(0.66 * getHomeFoodCost(city, age) +
                             getCinemaCost(city, cinema) + getCoffeeCost(city, coffee) + 0.5);
}


uint Student::getDaysCount(uint month) {
        // Вычисляем количество дней в месяце

        if (isMonth(month)) {
            uint daysInMonth = 31 - (month == 2) - ((month - 1) % 7 % 2);
            return daysInMonth;
        }

        return 0;
    }


uint Student::getWorkdays(uint month) {
    // Получаем число рабочих дней данном в месяце

    const int daysInMonth = getDaysCount(month);

    uint workDays = 0;

    //Конгруэнтность Целлера
    for (int i = 1; i <= daysInMonth; i++) {
        int dayOfWeek = (i + 2 * month + 3 * (month + 1) / 5 + YEAR + YEAR / 4 - YEAR / 100 + YEAR / 400) % 7; // определение дня недели

        if (dayOfWeek != 0 && dayOfWeek != 6) { // если не воскресенье и не суббота, то считаем день рабочим
            workDays++;
        }
    }
    return workDays;

}
