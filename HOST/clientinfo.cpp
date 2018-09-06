#include "clientinfo.h"

clientInfo::clientInfo(QString IP,QString name,QString function, bool active):
IP(IP),name(name),function(function),active(active)
{

}

QString clientInfo::getIP() const
{
    return this->IP;
}

QString clientInfo::getName() const
{
    return this->name;
}

QString clientInfo::getFunction() const
{
    return this->function;
}

bool clientInfo::getActive() const
{
    return this->active;
}

bool clientInfo::operator==(const clientInfo& rhs)
{
    return !(this->getIP().compare(rhs.getIP()));
}

