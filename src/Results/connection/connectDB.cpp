#include "connectDB.hpp"
#include <QDebug>
#include <QFile>
#include <QSqlDatabase>
#include <QString>

QString readLineFromFile(QFile &file) {
  QString str = file.readLine();
  QStringList list = str.split(QRegExp("\\s+"), QString::SkipEmptyParts);
  list.pop_front();
  return list.join(" ");
}

QSqlDatabase connectDB(QString PATH) {

  QSqlDatabase db;
  if (QSqlDatabase::contains(QSqlDatabase::defaultConnection)) {
    db = QSqlDatabase::database();
  } else {
    db = QSqlDatabase::addDatabase("QPSQL");

    QFile file(PATH);
    if ((file.exists()) && (file.open(QIODevice::ReadOnly))) {

      db.setHostName(readLineFromFile(file));
      db.setDatabaseName(readLineFromFile(file));
      db.setUserName(readLineFromFile(file));
      db.setPassword(readLineFromFile(file));

      file.close();
    } else
      qDebug() << "Ошибка чтения config файла!";
  }
  return db;
}