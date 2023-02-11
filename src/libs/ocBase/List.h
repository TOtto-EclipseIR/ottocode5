#pragma once

#include <QList>

#include "Types.h"

template <typename T> class List
{
public:
    List() {;}
    List(const Size size) : mList(size) {;}
    List(const Size size, const T &t) : mList(size, t) {;}

public:
    bool isValidIndex(const Index ix) const { return ix >= 0 && ix < mList.count(); }
    T at(const Index ix) const { return isValidIndex(ix) ? mList.at(ix) : T(); }
    T & at(const Index ix) { if ( ! isValidIndex(ix)) mList.resize(1 + ix); return mList[ix]; }
    QList<T> toQList() const { return mList; }
    operator QList<T> () const { return toQList(); }

private:
    QList<T> mList;
};
