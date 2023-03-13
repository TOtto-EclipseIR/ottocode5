#pragma once

#include <QWidget>

#include <QIcon>
#include <QString>
#include <QStringList>
class QVBoxLayout;
class QTextEdit;

class AbstractPage : public QWidget
{
    Q_OBJECT
public:
    explicit AbstractPage(const QString title, QWidget *parent = nullptr);

public slots:
    virtual void initialize() = 0;
    virtual void parse() = 0;
    virtual void setup() = 0;

signals:
    void constructed();
    void initialized();
    void parsed();
    void setupd();

public:


private:
    QVBoxLayout * mpMainLayout=nullptr;
    QTextEdit * mRawTextWidget=nullptr;
    QWidget * mParsedWidget=nullptr;

private:
    QString mTitle;
    QIcon mIcon;
    QStringList mRawText;
    // ============== generated ==============
public:
    const QString &title() const;
    void title(const QString &newTitle);
    const QIcon &icon() const;
    void icon(const QIcon &newIcon);
    const QStringList &rawText() const;
    void rawText(const QStringList &newRawText);
signals:
    void titleChanged(const QString &Title);
    void iconChanged(const QIcon &Icon);
    void rawTextChanged(const QStringList &RawText);
private:
    Q_PROPERTY(QString mTitle READ title WRITE title NOTIFY titleChanged)
    Q_PROPERTY(QIcon mIcon READ icon WRITE icon NOTIFY iconChanged)
    Q_PROPERTY(QStringList mRawText READ rawText WRITE rawText NOTIFY rawTextChanged)
};

