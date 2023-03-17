#include "ActionManager.h"

#include <QtDebug>
#include <QAction>

ActionManager::ActionManager(QObject *parent)
    : QObject{parent}
{
    setObjectName("ActionManager");
}

bool ActionManager::contains(const Key &key) const
{
    return mKeyActionMap.contains(key);
}

QAction *ActionManager::action(const Key &key) const
{
    Q_ASSERT(contains(key));
    return mKeyActionMap.value(key);
}

QAction *ActionManager::add(const Key &key, const QString &name)
{
    qDebug() << Q_FUNC_INFO << key() << name;
    QAction * result = new QAction(name.isEmpty() ? key.last().toQString() : name);
    mKeyActionMap.insert(key, result);
    return result;
}
