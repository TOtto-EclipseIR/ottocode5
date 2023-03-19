#include "ChannelMachine.h"

#include "Channel.h"

ChannelMachine::ChannelMachine(Channel *parent)
    : QStateMachine(parent)
{
    Q_CHECK_PTR(parent);
    setObjectName("ChannelMachine:" + parent->toString());
}
