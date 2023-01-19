#include "BookListPage.h"

#include <QtDebug>

BookListPage::BookListPage(QWidget *parent)
    : AbstractPageWidget(BookList, parent)
{
    qDebug() << Q_FUNC_INFO;

}
