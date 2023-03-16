//
// Created by wxrstvrsn on 16.03.2023.
//

#include "supportFuncs.h"
#include <iostream>

#define YEAR 2023


uint getWorkdays(const uint month) {
    uint working_days = 0;
    uint daysInMonth = getDaysCount(month);
    for (int day = 1; day <= daysInMonth; ++day) {
        int weekday = (day + 5) % 7; // вычисление дня недели для каждого числа
        if (weekday >= 1 && weekday <= 5) { // подсчет рабочих дней: если между понедельником и пятницей
            ++working_days; // инкрементируем счетчик
        }
    }
    return working_days;

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

bool isMonth(uint month) {
    return month >= 1 and month <= 12;
}

DatabaseHandler createDbWCustomPaths() {
    std::string costs, transport, inst, rest;

    std::cout << "Path to the Cost:";
    std::cin >> costs;
    std::cout << "Path to the Transport:";
    std::cin >> transport;
    std::cout << "Path to the Institute:";
    std::cin >> inst;
    std::cout << "Path to the Caffe-and-cinema:";
    std::cin >> rest;
    DatabaseHandler tempDataBase(costs, transport, inst, rest);
    return tempDataBase;
}
