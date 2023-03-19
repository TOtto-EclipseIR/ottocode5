#include "Url.h"

Url::Url(const QUrl &url) : data(new UrlData)
{
    set(url);
}

// --------------------- QSharedData implemenation -----------------------

Url::Url() : data(new UrlData)
{

}

Url::Url(const Url &rhs)
    : data{rhs.data}
{

}

Url &Url::operator=(const Url &rhs)
{
    if (this != &rhs)
        data.operator=(rhs.data);
    return *this;
}

Url::~Url()
{

}
