#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  if (!utils::writeFile(files::data, QString("")))
    qDebug() << "data.csv error" << '\n';
  if (!utils::writeFile(files::users, QString("")))
    qDebug() << "users.csv error" << '\n';

  updateCbox();
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::updateCbox() {
  QVector<QVector<QString>> lines = utils::readFile(files::users);

  ui->chooseUserCbox->clear();
  for (auto &line : lines) {
    for (auto &item : line) {
      ui->chooseUserCbox->addItem(item);
    }
  }
}

void MainWindow::on_getUsersListButton_clicked() {
  GetUsersForm *form = new GetUsersForm();
  form->show();
}

void MainWindow::on_addUserButton_clicked() {
  AddUserForm *form = new AddUserForm;
  form->show();
  connect(form->ui->confirmButton, &QPushButton::clicked, this,
          &MainWindow::updateCbox);
}

void MainWindow::on_chooseDebtorsButton_clicked() {
  if (debtorsform == nullptr)
    debtorsform = new AddDebtorsForm(utils::readFile(files::users));
  debtorsform->show();
}

void MainWindow::on_confirmButton_clicked() {
  QVector<QString> debtors;

  if (debtorsform != nullptr)
    debtors = debtorsform->debtors;
  if (!debtors.size() || !ui->moneySpentLineEdit->text().size())
    return;

  for (auto &name : debtors) {
    QString strSum;
    QString moneyspent = ui->moneySpentLineEdit->text();
    strSum = QString::number(moneyspent.toInt() / debtors.size());

    QString csvline = ui->purposeLineEdit->text() + ';' +
                      ui->chooseUserCbox->currentText() + ';' + name + ';' +
                      strSum;
    utils::writeFile(files::data, csvline);
  }

  DebtorsAddedForm *form = new DebtorsAddedForm;
  form->show();
}

void MainWindow::on_moneySpentLineEdit_textChanged(const QString &arg1) {
  ui->moneySpentLineEdit->setText(arg1);
}

void MainWindow::on_purposeLineEdit_textChanged(const QString &arg1) {
  ui->purposeLineEdit->setText(arg1);
}

void MainWindow::on_getResultButton_clicked() {
  ResultForm *form = new ResultForm(utils::calculateDebts());
  form->show();
}
