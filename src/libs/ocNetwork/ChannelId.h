#pragma once

#include "Url.h"

#include <QHostAddress>

#include "Network.h"

class ChannelId : protected Url
{
public:
    ChannelId();
    ChannelId(const QHostAddress &host, const Network::Port port=80);

public:
    QString toString() const;

public:
    void set(const QHostAddress &host, const Network::Port port=80);
};

