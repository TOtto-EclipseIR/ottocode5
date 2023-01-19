#include "ViewPage.h"

#include <QtDebug>

ViewPage::ViewPage(const QString pageName, QWidget *parent)
    : AbstractPageWidget(ViewBase, parent)
    , mPageName(pageName)
{
    qDebug() << Q_FUNC_INFO << pageName;

}

QString ViewPage::name() const
{
    return "View: " + mPageName;
}
