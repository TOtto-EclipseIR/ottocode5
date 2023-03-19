#pragma once

#include <QStateMachine>

class Channel;

class ChannelMachine : public QStateMachine
{
    Q_OBJECT
public:
    ChannelMachine(Channel * parent);

private:

};

