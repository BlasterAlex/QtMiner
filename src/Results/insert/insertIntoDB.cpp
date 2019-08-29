#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>

#include "../connection/connectDB.hpp"
#include "insertIntoDB.hpp"

void addToTable(int width, int height, int mines, Result newOne) {

  QSqlDatabase db = connectDB("src/db/config");

  if (db.open()) {

    QSqlQuery query;

    query.prepare("INSERT INTO public.results(date, width, height, mines, totalTime)"
                  " VALUES (:d, :w, :h, :m, :t)");
    query.bindValue(":d", newOne.date);
    query.bindValue(":w", width);
    query.bindValue(":h", height);
    query.bindValue(":m", mines);
    query.bindValue(":t", newOne.totalTime);

    query.exec();

  } else {
    qDebug() << "Ошибка соединения с бд";
  }
}