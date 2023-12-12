#include "adduserform.h"

AddUserForm::AddUserForm(QWidget *parent)
    : QWidget(parent), ui(new Ui::AddUserForm) {
  ui->setupUi(this);
}

AddUserForm::~AddUserForm() { delete ui; }

void AddUserForm::on_confirmButton_clicked() {
  QString line = ui->lineEdit->text();
  utils::writeFile(files::users, line);
  this->close();
}
