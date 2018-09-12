#ifndef DATABASE_H
#define DATABASE_H
#include <QtSql>
#include <QString>


class database
{
private:
    QSqlDatabase db;
    std::string filename;

public:
    database();
    bool connect(const QString &);
};

#endif // DATABASE_H
