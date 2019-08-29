#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>

#include "../connection/connectDB.hpp"
#include "selectFromDB.hpp"

QVector<Result> getTable(int width, int height, int mines) {

  QSqlDatabase db = connectDB("src/Results/connection/config");
  QVector<Result> results;

  {
    if (db.open()) {

      QSqlQuery query;

      query.prepare("SELECT TO_CHAR(date, 'dd.MM.yy'),totalTime FROM public.results "
                    "WHERE (width=:w AND height=:h AND mines=:m) ORDER BY totalTime");
      query.bindValue(":w", width);
      query.bindValue(":h", height);
      query.bindValue(":m", mines);
      query.exec();

      while (query.next()) {
        Result res;
        res.date = query.value(0).toString();
        res.totalTime = query.value(1).toString();
        results.push_back(res);
      }

    } else {
      qDebug() << "Ошибка соединения с бд";
    }
  }

  return results;
}