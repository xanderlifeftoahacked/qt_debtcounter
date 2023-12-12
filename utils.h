#pragma once
#include "constants.h"
#include <QFile>
#include <QTextStream>
#include <QVector>
#include <algorithm>

enum files { users, data };

namespace utils {
bool writeFile(files, QString);
QVector<QVector<QString>> readFile(files);
QString calculateDebts();
} // namespace utils
