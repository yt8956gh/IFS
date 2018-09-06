#ifndef CLIENTINFO_H
#define CLIENTINFO_H

#include <QString>

class clientInfo
{

public:
    clientInfo(QString ,QString ,QString, bool);
    QString getIP() const;
    QString getName() const;
    QString getFunction() const;
    bool getActive() const;
    bool operator==(const clientInfo& rhs);

private:
    QString IP,name,function;
    bool active;

};



#endif // CLIENTINFO_H
