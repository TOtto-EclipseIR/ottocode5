#include "AbstractPageWidget.h"

#include <QtDebug>
#include <QMetaEnum>
#include <QMetaObject>
#include <QString>

AbstractPageWidget::AbstractPageWidget(const PageType ptype, QWidget *parent)
    : QWidget{parent}
    , mPageType(ptype)
{
    qDebug() << Q_FUNC_INFO;

}

QString AbstractPageWidget::name() const
{
    const QMetaObject * const pMetaObject = metaObject();
    const int tPageTypeEnumIndex = pMetaObject->indexOfEnumerator("PageType");
    const QMetaEnum tMetaEnum = pMetaObject->enumerator(tPageTypeEnumIndex);
    const QString result = tMetaEnum.key(mPageType);
    qDebug() << Q_FUNC_INFO << result;
    return result;
}
