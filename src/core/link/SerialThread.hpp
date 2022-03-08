#pragma once
#include <QObject>
#include <QThread>

#include <QByteArray>

class SerialThread : public QThread
{
    Q_OBJECT
public:
    explicit SerialThread(QObject *parent = nullptr);
protected:
    void run() override;
signals:
    void NewDataArrived(const QByteArray& data);
};