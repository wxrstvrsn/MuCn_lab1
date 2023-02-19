//
// Created by wxrstvrsn on 16.02.2023.
//

#include "Student.h"
#include "Database.h"
#include <iostream>
#define YEAR 2023


Student::Student(uint age, uint month, const std::string &name, const std::string &city,
                 const std::string &homeAddress, const std::string &institute) {
    this->name = name;
    this->month = month;
    this->age = age;
    this->homeAddress = homeAddress;
    this->city = city;
    this->institute = institute;

}

Student::Student() {
    this->name = "Bjarne";
    this->age = 18;
    this->month = 1;
    this->homeAddress = "Metrogorodok";
    this->city = "Moscow";
    this->institute = "MIREA";
    this->caffe = "Coffemania";
    this->cinema = "SuperCinema";

    std::cout << "You didn't set the parameters for the student, so the fields are initialized with default values" << std::endl;
}

void Student::introduceYourself(){
    std::cout << "-------------------------------------------" << std::endl;
    std::cout << "Hello! My name is " << name << ". I am " << age << " year(s) old" << std::endl;
    std::cout << "My city is " << city << "; my homeAddress is " << homeAddress << std::endl;
    std::cout << "My institute: " << institute << std::endl;
    std::cout << "I like " << caffe << " and" << cinema << std::endl;
    std::cout << "month: " << month << std::endl;
}

Student::~Student() {
    std::cout << "See you next time, goodbye! [" << this << "]" << std::endl;

}

uint Student::getDaysCount(uint month) {

    if (isMonth(month)) {
        switch (month) {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                return 31;
            case 4:
            case 6:
            case 9:
            case 11:
                return 30;
            case 2:
                return 28 + int(((YEAR % 4 == 0) && (YEAR % 100 != 0)) || (YEAR % 400 == 0));
        }
    }
}

uint Student::getWorkdays(uint month) {

    uint working_days = 0;
    uint daysInMonth = getDaysCount(month);
    for (int day = 1; day <= daysInMonth; ++day) {
        int weekday = (day + 5) % 7; // вычисление дня недели для каждого число
        if (weekday >= 1 && weekday <= 5) { // подсчет рабочих дней: если между понедельником и пятницей
            ++working_days; // инкрементируем счетчик
        }
    }
    return working_days;

}



bool Student::isMonth(uint month) {
    return month >= 1 and month <= 12;
}

uint Student::getWeekendCost(DatabaseHandler &data) {
    /* По выходным дням расходы складываются из стоимости:
     - похода в кино (пешком)
     - похода  в кафе (пешком)
     - завтрака и обеда дома */

    return static_cast<uint>(0.66 * data.getHomeFoodCost(this->city, this->age) +
                             data.getCinemaCost(this->city, this->cinema)
                             + data.getCoffeeCost(this->city, this->caffe) + 0.5);
}

uint Student::getWorkdayCost(DatabaseHandler &data) {
    return static_cast<uint>(2 * data.getTransportCost(this->city, this->homeAddress,                                                       this->institute) +
                             data.getInstituteDinnerCost(this->city, this->institute) + 0.66 * data.getHomeFoodCost(this->city, this->age) + 0.5);
}

uint Student::getCosts(DatabaseHandler &data) {
    /* Расходы:
     - по рабочим дням
     - по выходным дням
     - прочие расходы */

    const uint daysCount = getDaysCount(month);
    const uint workDays = getWorkdays(month);
    const uint weekends = daysCount - workDays;

    return workDays * getWorkdayCost(data) +
           weekends * getWeekendCost(data) +
           data.getOtherMontlyCosts(this->city, this->age);
}

bool isMonth(int month) {
    // может ли введенное число являться номером месяца
    return month >= 1 and month <= 12;
}



/*
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
*/

