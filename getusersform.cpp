#include "getusersform.h"
#include "ui_getusersform.h"
#include "utils.h"

GetUsersForm::GetUsersForm(QWidget *parent)
    : QWidget(parent), ui(new Ui::GetUsersForm) {
  ui->setupUi(this);

  QString names;
  QVector<QVector<QString>> lines = utils::readFile(files::users);

  for (auto &line : lines) {
    for (auto &item : line) {
      names += item + '\n';
    }
  }

  ui->textBrowser->setText(names);
}

GetUsersForm::~GetUsersForm() { delete ui; }
