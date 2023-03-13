#pragma once

#include <QList>

#include "TypeDefs.h"

template <typename T> class List
{
public:
    List() {;}
    List(const Count count) : mList(count) {;}
    List(const Count count, const T &t) : mList(count, t) {;}

public:
    bool isValidIndex(const Index ix) const { return ix >= 0 && ix < mList.count(); }
    T at(const Index ix) const { return isValidIndex(ix) ? mList.at(ix) : T(); }
    T & at(const Index ix) { if ( ! isValidIndex(ix)) mList.resize(1 + ix); return mList[ix]; }
    QList<T> toQList() const { return mList; }
    operator QList<T> () const { return toQList(); }

private:
    QList<T> mList;
};
