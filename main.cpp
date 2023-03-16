//
// Created by wxrstvrsn on 16.02.2023.
//


#include <iostream>
#include "Database.h"
#include "Student.h"
#include "supportFuncs.h"

int main() {

    DatabaseHandler db;

    std::cout << "\x1b[32;1m Do you want to set custom file paths for database initialization? (Y/N) \x1b[0m"
              << std::endl;
    char choose;
    std::cin >> choose;
    if (choose == 'Y') {
        db = createDbWCustomPaths();
    }


    std::cout << "\n\n------Checking work on a defaulted student------\n\n" << std::endl;
    Student st;

    uint ans = st.getCosts(db, 1, "Pizza", "Almaz");
    st.introduceYourself();
    std::cout << "Total Cost is " << ans << std::endl;

    /*std::cout << "\n\n\n" << "Now you can set the parameters of custom student" << std::endl;

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
        return 0;
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
    std::cout << "Month for calculations: ";
    std::cin >> sMonth;
    try {
        month = std::stoi(sMonth);
    } catch (std::invalid_argument) {
        std::cout << "Invalid Month" << std::endl;
        return 0;
    }

    Student customStudent(age, month, name, city, homeAddress, institute, caffe, cinema);
    customStudent.introduceYourself();

    int ansForCustomData = customStudent.getCosts(dt);

    std::cout << "\x1b[32;1m RESULT: Total cost for custom data: \x1b[0m" << ansForCustomData << std::endl;

*/
    return 0;
}
