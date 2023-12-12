#include "utils.h"

bool utils::writeFile(files filetype, QString string) {
  QString path;

  if (filetype == files::data)
    path = constants::pathToDataFile;
  else if (filetype == files::users)
    path = constants::pathToUsersFile;

  QFile file(path);
  if (!file.open(QIODevice::WriteOnly | QIODevice::Append))
    return false;

  QTextStream out(&file);

  if (!file.size()) {
    if (filetype == files::data)
      out << constants::dataFileHead << '\n';
    else if (filetype == files::users)
      out << constants::usersFileHead << '\n';
  }

  if (!string.isEmpty())
    out << string << '\n';

  file.close();
  return true;
}

QVector<QVector<QString>> utils::readFile(files filetype) {
  QString path;
  QVector<QVector<QString>> rows;

  if (filetype == files::data)
    path = constants::pathToDataFile;
  else if (filetype == files::users)
    path = constants::pathToUsersFile;

  QFile file(path);
  if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    return rows;

  QTextStream in(&file);

  QString firstline = in.readLine();
  if (firstline.isEmpty()) {
    file.close();
    return rows;
  }

  while (!in.atEnd()) {
    QString line = in.readLine();
    QVector<QString> items;
    for (QString &item : line.split(';')) {
      items.push_back(item);
    }
    rows.push_back(items);
  }

  file.close();
  return rows;
}

QString utils::calculateDebts() {
  QString retString;
  QMap<QString, QPair<int, int>> operations;
  QVector<QPair<QString, QPair<int, int>>> operationsSortedbySpended;
  QVector<QPair<QString, QPair<int, int>>> operationsSortedbyLended;
  QVector<QVector<QString>> names = readFile(files::users);
  QVector<QVector<QString>> data = readFile(files::data);

  for (auto &line : names) {
    for (auto &name : line) {
      operations[name] = QPair<int, int>(0, 0);
    }
  }

  for (auto &line : data) {
    operations[line[1]].first += line[3].toInt();
    operations[line[2]].second += line[3].toInt();
  }

  for (auto &key : operations.keys()) {
    operationsSortedbySpended.push_back(QPair(key, operations.value(key)));
    operationsSortedbyLended.push_back(QPair(key, operations.value(key)));
  }

  for (auto &key : operations.keys()) {
    qDebug() << key << operations[key].first << operations[key].second;
  }

  std::sort(operationsSortedbySpended.begin(), operationsSortedbySpended.end(),
            [](const QPair<QString, QPair<int, int>> &lhs,
               const QPair<QString, QPair<int, int>> &rhs) {
              return lhs.second.first > rhs.second.first;
            });

  std::sort(operationsSortedbyLended.begin(), operationsSortedbyLended.end(),
            [](const QPair<QString, QPair<int, int>> &lhs,
               const QPair<QString, QPair<int, int>> &rhs) {
              return lhs.second.second > rhs.second.second;
            });

  int i = 0;
  int j = 0;
  while (i < operations.size() && j < operations.size()) {
    int transited;
    QString nameCreditor = operationsSortedbySpended[i].first;
    QString nameDebtor = operationsSortedbyLended[j].first;
    QPair<int, int> *elemCreditor =
        &operations[operationsSortedbySpended[i].first];
    QPair<int, int> *elemDebtor =
        &operations[operationsSortedbyLended[j].first];

    if (elemCreditor->first > elemDebtor->second) {
      transited = elemDebtor->second;
      j++;
    } else if (elemCreditor->first < elemDebtor->second) {
      transited = elemCreditor->first;
      i++;
    } else if (elemCreditor->first == elemDebtor->second) {
      transited = elemCreditor->first;
      j++;
      i++;
    }
    elemCreditor->first -= transited;
    elemDebtor->second -= transited;
    if (transited && nameCreditor != nameDebtor)
      retString += QString(nameDebtor + "->" + nameCreditor + ": " +
                           QString::number(transited) + '\n');
  }

  qDebug() << retString;

  return retString;
}
