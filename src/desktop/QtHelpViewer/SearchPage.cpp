#include "SearchPage.h"

#include <QtDebug>

SearchPage::SearchPage(QWidget *parent)
    : AbstractPageWidget(Search, parent)
{
    qDebug() << Q_FUNC_INFO;

}
