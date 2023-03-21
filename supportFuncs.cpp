//
// Created by wxrstvrsn on 16.03.2023.
//

#include "supportFuncs.h"

#define YEAR 2023


uint getWorkdays(const uint month) {
    uint workingDays = 0;
    uint daysInMonth = getDaysCount(month);
    for (int day = 1; day <= daysInMonth; ++day) {
        int weekday = (day + 5) % 7; // вычисление дня недели для каждого числа
        if (weekday >= 1 && weekday <= 5) { // подсчет рабочих дней: если между понедельником и пятницей
            ++workingDays; // инкрементируем счетчик
        }
    }
    return workingDays;
}

uint getDaysCount(const uint month) {
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

bool menu() {
    std::cout << "\x1b[32;1mContinue to calculate for other student? (Y/N)\x1b[0m" << std::endl;
    char choose = ' ';
    std::cin >> choose;
    return choose == 'Y' ? true : false;

}

bool isMonth(uint month) {
    return month >= 1 and month <= 12;
}


/*void calculateForCustom(const DatabaseHandler &db) {
    int age = 0;
    std::string sAge;
    int month = 0;
    std::string sMonth;
    std::string name;
    std::string city;
    std::string homeAddress;
    std::string institute;
    std::string caffe;
    std::string cinema;

    std::cout << "Name: ";
    std::cin >> name;
    std::cout << "Age: ";
    std::cin >> sAge;
    try {
        age = std::stoi(sAge);
    } catch (std::invalid_argument) {
        std::cout << "Invalid Age" << std::endl;
        exit(1);
    }
    std::cout << "City: ";
    std::cin >> city;
    std::cout << "home Address: ";
    std::cin >> homeAddress;
    std::cout << "Institute: ";
    std::cin >> institute;
    std::cout << "Caffe: ";
    std::cin >> caffe;
    std::cout << "Cinema: ";
    std::cin >> cinema;
    while (!isMonth(month)) {
        std::cout << "Month for calculations: " << std::endl;
        std::cin >> sMonth;
        try {
            month = std::stoi(sMonth);

        } catch (std::invalid_argument) {
            std::cout << "Invalid Month" << std::endl;
            exit(1);
        }
    }

    Student tempStudent(age, name, city, homeAddress, institute);

    std::cout << "\x1b[32;1mTotal cost is: " << tempStudent.getCosts(db, month, caffe, cinema) << "\x1b[0m"
              << std::endl;
}*/
