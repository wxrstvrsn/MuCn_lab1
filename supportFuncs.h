//
// Created by wxrstvrsn on 14.03.2023.
//

#pragma once

#include "Student.h"
#include "Database.h"

uint getWorkdays(const uint month);

uint getDaysCount(const uint month);

bool isMonth(uint month);

DatabaseHandler createDbWCustomPaths();