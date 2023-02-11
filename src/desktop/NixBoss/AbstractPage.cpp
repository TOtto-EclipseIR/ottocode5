#include "AbstractPage.h"

AbstractPage::AbstractPage(const QString title, QWidget *parent)
    : QWidget{parent}
    , mTitle(title)
{

}

const QString &AbstractPage::title() const
{
    return mTitle;
}

void AbstractPage::title(const QString &newTitle)
{
    mTitle = newTitle;
    emit titleChanged(mTitle);
}

const QIcon &AbstractPage::icon() const
{
    return mIcon;
}

void AbstractPage::icon(const QIcon &newIcon)
{
    mIcon = newIcon;
    emit iconChanged(mIcon);
}

const QStringList &AbstractPage::rawText() const
{
    return mRawText;
}

void AbstractPage::rawText(const QStringList &newRawText)
{
    mRawText = newRawText;
    emit rawTextChanged(mRawText);
}
