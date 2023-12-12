#pragma once

#include <QDir>
#include <QString>

namespace constants {
const inline QString projectPath = "/home/xander/Code/qt/debtCounter/";
const inline QString pathToDataFile = projectPath + "data.csv";
const inline QString dataFileHead = "purpose;lender;debtor;amount";
const inline QString pathToUsersFile = projectPath + "users.csv";
const inline QString usersFileHead = "name;";
} // namespace constants
