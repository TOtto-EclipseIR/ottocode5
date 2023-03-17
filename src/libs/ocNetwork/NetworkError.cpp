#include "NetworkError.h"

#include <ObjectHelper.h>

NetworkError::NetworkError(const Code other) : mCode(other) {;}
NetworkError::NetworkError(const int other) : mCode(NetworkError::Code(other)) {;}

NetworkError::NetworkError(const QNetworkReply::NetworkError replyError)
{
    const int tInt = int(replyError);
    mCode = NetworkError::Code(tInt);
}

QString NetworkError::codeKey() const
{
    return codeKey(mCode);
}

NetworkError::Code NetworkError::codeValue() const
{
    return mCode;
}

bool NetworkError::isError() const
{
    return mCode != NetworkError::$null;
}

// --------------------- static ------------------------

QString NetworkError::codeKey(const Code value)
{
    return ObjectHelper::enumKey<NetworkError::Code>(value);
}

NetworkError::Code NetworkError::codeValue(const char *key)
{
    return NetworkError::Code(ObjectHelper::enumValue<NetworkError::Code>(key));
}
