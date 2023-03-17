#pragma once

#include <QMetaObject>
#include <QNetworkReply>

class NetworkError
{
    Q_GADGET
public:
    enum Code
    {
        $null = 0,
        ConnectionRefusedError = QNetworkReply::ConnectionRefusedError,
        RemoteHostClosedError = QNetworkReply::RemoteHostClosedError,
        HostNotFoundError = QNetworkReply::HostNotFoundError,
        TimeoutError = QNetworkReply::TimeoutError,
        SslHandshakeFailedError = QNetworkReply::SslHandshakeFailedError,
        TemporaryNetworkFailureError = QNetworkReply::TemporaryNetworkFailureError,
        NetworkSessionFailedError = QNetworkReply::NetworkSessionFailedError,
        BackgroundRequestNotAllowedError = QNetworkReply::BackgroundRequestNotAllowedError,
        TooManyRedirectsError = QNetworkReply::TooManyRedirectsError,
        InsecureRedirectError = QNetworkReply::InsecureRedirectError,
        ProxyConnectionRefusedError = QNetworkReply::ProxyConnectionRefusedError,
        ProxyConnectionClosedError = QNetworkReply::ProxyConnectionClosedError,
        ProxyNotFoundError = QNetworkReply::ProxyNotFoundError,
        ProxyTimeoutError = QNetworkReply::ProxyTimeoutError,
        ProxyAuthenticationRequiredError = QNetworkReply::ProxyAuthenticationRequiredError,
        ContentAccessDenied = QNetworkReply::ContentAccessDenied,
        ContentOperationNotPermittedError = QNetworkReply::ContentOperationNotPermittedError,
        ContentNotFoundError = QNetworkReply::ContentNotFoundError,
        AuthenticationRequiredError = QNetworkReply::AuthenticationRequiredError,
        ContentReSendError = QNetworkReply::ContentReSendError,
        ContentConflictError = QNetworkReply::ContentConflictError,
        ContentGoneError = QNetworkReply::ContentGoneError,
        InternalServerError = QNetworkReply::InternalServerError,
        OperationNotImplementedError = QNetworkReply::OperationNotImplementedError,
        ServiceUnavailableError = QNetworkReply::ServiceUnavailableError,
        ProtocolUnknownError = QNetworkReply::ProtocolUnknownError,
        ProtocolInvalidOperationError = QNetworkReply::ProtocolInvalidOperationError,
        UnknownNetworkError = QNetworkReply::UnknownNetworkError,
        UnknownProxyError = QNetworkReply::UnknownProxyError,
        UnknownContentError = QNetworkReply::UnknownContentError,
        ProtocolFailure = QNetworkReply::ProtocolFailure,
        UnknownServerError = QNetworkReply::UnknownServerError,
    };
    Q_ENUM(Code)

public:
    NetworkError(const Code other);
    NetworkError(const int other);
    NetworkError(const QNetworkReply::NetworkError other);

public:
    QString codeKey() const;
    Code codeValue() const;
    bool isError() const;
    operator bool () const { return isError(); }

public:
    static QString codeKey(const Code value);
    static Code codeValue(const char * name);

private:
    Code mCode=$null;
};

