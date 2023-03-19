#pragma once

#include <QObject>

#include "ChannelId.h"
class ChannelMachine;

class Channel : public QObject
{
    Q_OBJECT
public:
    explicit Channel(QObject *parent = nullptr);
    explicit Channel(const ChannelId &id, QObject *parent = nullptr);
    ChannelMachine * machine();

public:
    ChannelId id() const;
    QString toString() const;

public:

public slots:

signals:

private:
    const ChannelId cmId;
    ChannelMachine * mpMachine=nullptr;
};

