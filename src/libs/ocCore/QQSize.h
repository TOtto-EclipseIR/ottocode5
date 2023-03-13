#pragma once

#include <QSize>

class QQSize : public QSize
{
public:
    QQSize() {;}
    QQSize(const QSize other) : QSize(other) {;}
    QQSize(const int width, const int height) : QSize(width, height) {;}

public:
    int area() const { return width() * height(); }

public:
    void clear() { set(0, 0); }
    void invalidate() { set(-1, -1); }
    void set(const int width, const int height);
};

