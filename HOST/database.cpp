#include "database.h"

database::database()
{
    db = QSqlDatabase::addDatabase("QSQLITE");//使用SQLite型態的資料庫
}

bool database::connect(const QString &filename)
{
    QString filepath("./");
    filepath+=filename;
    db.setDatabaseName(filepath);

    if( !db.open() )
    {
        qDebug() << db.lastError();
        qFatal( "Failed to connect." );
        return false;
    }

    qDebug()<<"Opened Database Successfully";

    QSqlQuery query;

    if (!query.exec( "CREATE TABLE IF NOT EXISTS number ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "time VARCHAR,"
        "temperature INT,"
        "humidity INT,"
        "power REAL)")) {
        qDebug() << "Create Table Failed:" << query.lastError().databaseText();
    }

    return true;
}

bool database::insert(QString time, int t, int h, float p)
{
    QSqlQuery query;
    query.prepare("INSERT INTO number (time, temperature, humidity, power) "
                      "VALUES (:time, :temperature, :humidity, :power)");

    query.bindValue(":time",time);
    query.bindValue(":temperature",t);
    query.bindValue(":humidity",h);
    query.bindValue(":power",p);

    return query.exec();
}
