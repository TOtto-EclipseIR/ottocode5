#pragma once

#include <QObject>

#include <QMap>
#include <QString>
class QAction;

#include <Key.h>

class ActionManager : public QObject
{
    Q_OBJECT
public:
    explicit ActionManager(QObject *parent = nullptr);

public:
    bool contains(const Key &key) const;
    QAction * action(const Key &key) const;

public:
    QAction * add(const Key &key, const QString &name=QString());

signals:

private:
    QMap<Key, QAction *> mKeyActionMap;

};

