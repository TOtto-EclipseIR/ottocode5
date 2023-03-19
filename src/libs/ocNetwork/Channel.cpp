#include "Channel.h"

Channel::Channel(QObject *parent)
    : QObject{parent}
{
    setObjectName("Channel");
}

Channel::Channel(const ChannelId &id, QObject *parent)
    : QObject{parent}
    , cmId(id)
{
    setObjectName("Channel:" + cmId.toString());

}

ChannelMachine *Channel::machine()
{
    Q_CHECK_PTR(mpMachine);
    return mpMachine;
}

ChannelId Channel::id() const
{
    return cmId;
}

QString Channel::toString() const
{
    return id().toString();
}
