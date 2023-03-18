//
// Created by wxrstvrsn on 16.02.2023.
//


#include <iostream>
#include "Database.h"
#include "supportFuncs.h"

int main() {

    DatabaseHandler db;
    std::cout << "\x1b[32;1m Do you want to set custom file paths for database initialization? (Y/N) \x1b[0m"
              << std::endl;
    char choose;
    std::cin >> choose;
    if (choose == 'Y') {
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
        db = tempDataBase;
    }
    do {
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
    } while (menu());


    return 0;
}
