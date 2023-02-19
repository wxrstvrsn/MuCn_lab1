//
// Created by wxrstvrsn on 16.02.2023.
//


#include <iostream>
#include <fstream>
#include <sstream>
#include "Database.h"
#include "Student.h"


/*public class StudentService {
private final Database database;

public Student getStudentByName(String name) {
        Row row = database.getRowByName(name);

        return createStudentFromRow(row);
    }
}*/


int main() {

/*
//    DatabaseHandler dat;
//    uint age = 0;
//    std::string name = "";
//    std::string city = "";
//    std::string hAd = "";
//
//    std::cin >> age;
//    std::cin >> name;
//    std::cin >> city;
//    std::cin >> hAd;

    std::string filename = "C:\\Users\\79157\\CLionProjects\\MISP\\1stLAB\\Database\\Costs1.csv";
    std::ifstream work_file(filename);

    std::string line;
    char delimiter = ',';
    getline(work_file, line);

    while (getline(work_file, line)){
        std::stringstream stream(line);

        std::string city, age, foodCostPerMonth, otherCosts;
        getline(stream, city, delimiter);
        getline(stream, age, delimiter);
        getline(stream, foodCostPerMonth, delimiter);
        getline(stream, otherCosts, delimiter);

        std::cout << "==================" << std::endl;
        std::cout << "City: " << city << std::endl;
        std::cout << "Age: " << age << std::endl;
        std::cout << "foodCostPerMonth: " << foodCostPerMonth << std::endl;
        std::cout << "otherCosts: " << otherCosts << std::endl;

    }
    work_file.close();
    DatabaseHandler dt;
    Student st;
*/
    DatabaseHandler dt;
    Student st;
//    st.introduceYourself();

//    std::cout << dt.getHomeFoodCost("Moscow", 30) << std::endl;
    std::cout << dt.getOtherMontlyCosts("Moscow", 30) << std::endl;
    std::cout << dt.getHomeFoodCost("Moscow", 30) << std::endl;
    std::cout << dt.getCinemaCost("Moscow", "Pobeda") << std::endl;
    std::cout << dt.getCoffeeCost("Moscow", "SuperCOffe") << std::endl;
    std::cout << dt.getInstituteDinnerCost("Moscow", "MEI") << std::endl;
    std::cout << dt.getTransportCost("Moscow", "Zamoskvorechje", "MIREA") << std::endl;








    return 0;
}
