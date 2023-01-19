#include <QCoreApplication>

#include <cstdio>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    printf("Hello ConsApp");
    return a.exec();
}
