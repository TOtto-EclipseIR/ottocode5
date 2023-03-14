#pragma once

#include "ErrorInfo.h"


template <typename T, typename E=ErrorInfo> class ErrorReturn
{
public:
    ErrorReturn() {;}
    ErrorReturn(const T &t) : mT(t) {;}
    ErrorReturn(const T &t, const E &e) : mT(t), mE(e) {;}

public:
    bool isNull() const { return mT == T(); }
    bool isError() const { return mE == E(); }
    T value() const { return mT; }
    E error() const { return mE; }

public:
    void clear() { t = T(), e = e(); }
    void set(const T &t) { mT = t; }
    void set(const E &e) { mE = e; }
    void set(const T &t, const E &e) { mT = t, mE = e; }

private:
    T mT;
    E mE;
}
