#include "Network.h"

#include <QtDebug>
#include <QTimerEvent>


Network::Network(QObject *parent)
    : QNetworkAccessManager(parent)
{
    setObjectName("Network");
}

void Network::initialize()
{
    qDebug() << Q_FUNC_INFO;
    // TODO What?
    emit initialized(true);
}

QNetworkReply * Network::requestGet(QNetworkRequest *request)
{
    Q_CHECK_PTR(request);
    qDebug() << Q_FUNC_INFO << request->url();
    QNetworkReply * result = nullptr;
    if (nullptr == mpCurrentRequest)
    {
        mpCurrentRequest = request;
        result = get(*mpCurrentRequest);
        if (result)
        {
            mpCurrentReply = result;
            mRequestStartMsec = QDateTime::currentMSecsSinceEpoch();
            mRequestTimerId = startTimer(RequestTimerMsec());
        }
    }
    return result;
}

void Network::handleReply(QNetworkReply *reply)
{
    Q_CHECK_PTR(reply);
    qDebug() << Q_FUNC_INFO << reply->url().toString();
    Q_ASSERT(mpCurrentReply == reply);
    mpCurrentRequest = nullptr;
    emit replyFinished(mpCurrentReply, mpCurrentRequest);
}

void Network::timerEvent(QTimerEvent *event)
{
    if (event->timerId() == mRequestTimerId)
    {
        emit requestTimeout(mpCurrentRequest);
        mpCurrentRequest = nullptr;
        event->accept();
    }
    else if (event->timerId() == mPeriodTimerId)
    {
        quint64 tCurrentMsecs
            = QDateTime::currentMSecsSinceEpoch() - mRequestStartMsec;
        emit requestProgress(tCurrentMsecs, mRequestTimerMsec, mpCurrentRequest);
        event->accept();
    }
    else
    {
        event->ignore();
    }
}

// ----------------------- properties ---------------------------

int Network::PeriodTimerMsec() const
{
    return mPeriodTimerMsec;
}

void Network::PeriodTimerMsec(int newPeriodTimerMsec)
{
    if (mPeriodTimerMsec == newPeriodTimerMsec)
        return;
    mPeriodTimerMsec = newPeriodTimerMsec;
    emit PeriodTimerMsecChanged(mPeriodTimerMsec);
}

int Network::RequestTimerMsec() const
{
    return mRequestTimerMsec;
}

void Network::RequestTimerMsec(int newRequestTimerMsec)
{
    if (mRequestTimerMsec == newRequestTimerMsec)
        return;
    mRequestTimerMsec = newRequestTimerMsec;
    emit RequestTimerMsecChanged(mRequestTimerMsec);
}

