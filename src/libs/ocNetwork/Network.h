#pragma once
#include "ocNetwork.h"

#include <QDateTime>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>

#include <ObjectHelper.h>

#include "NetworkError.h"

class OCNETWORK_EXPORT Network : public QNetworkAccessManager
{
    Q_OBJECT
public:
    enum Scheme
    {
        $null = 0,
        http,
        ftp,
        https,
        ftps,
        git,
        $end
    };
    typedef quint16 Port;

public:
    explicit Network(QObject *parent = nullptr);

public slots:
    void initialize();

public:
    QNetworkReply * requestGet(QNetworkRequest * request);


signals:
    void initialized(const bool ok);
    void requestStarted(QNetworkRequest * request);
    void requestTimeout(QNetworkRequest * request);
    void requestError(const NetworkError ne, QNetworkRequest * request);
    void requestProgress(const int count, const int limit, QNetworkRequest * request);
    void replyError(const NetworkError, QNetworkReply * reply, QNetworkRequest * request);
    void replyProgress(const int count, const int limit, QNetworkRequest * request);
    void replyFinished(QNetworkReply * reply, QNetworkRequest * request);


private slots:
    void handleReply(QNetworkReply * reply);

protected:
    virtual void timerEvent(QTimerEvent *event) override;

private:
    QNetworkRequest * mpCurrentRequest=nullptr;
    QNetworkReply * mpCurrentReply=nullptr;
    int mPeriodTimerId=0;
    int mRequestTimerId=0;
    quint64 mRequestStartMsec;

// -------------------- properties -------------------
private:
    int mPeriodTimerMsec=1000;
    int mRequestTimerMsec=60000;
    Q_PROPERTY(int PeriodTimerMsec READ PeriodTimerMsec WRITE PeriodTimerMsec NOTIFY PeriodTimerMsecChanged)
    Q_PROPERTY(int RequestTimerMsec READ RequestTimerMsec WRITE RequestTimerMsec NOTIFY RequestTimerMsecChanged)
signals:
    void PeriodTimerMsecChanged(int PeriodTimerMsec);
    void RequestTimerMsecChanged(int RequestTimerMsec);
public:
    int PeriodTimerMsec() const;
    void PeriodTimerMsec(int newPeriodTimerMsec);
    int RequestTimerMsec() const;
    void RequestTimerMsec(int newRequestTimerMsec);
};

