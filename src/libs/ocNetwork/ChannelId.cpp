#include "ChannelId.h"


ChannelId::ChannelId()
{
    set(QHostAddress(), 0);
}

ChannelId::ChannelId(const QHostAddress &host, const Network::Port port)
{
    set(host, port);
}

QString ChannelId::toString() const
{
    return QString("%1:%2").arg(d()->dHostAddress.toString()).arg(d()->dPort);
}

void ChannelId::set(const QHostAddress &host, const Network::Port port)
{
    d()->dHostAddress = host, d()->dPort = port;
}
