#include "SettingsPage.h"

#include <QtDebug>

SettingsPage::SettingsPage(QWidget *parent)
    : AbstractPageWidget(Settings, parent)
{
    qDebug() << Q_FUNC_INFO;

}
