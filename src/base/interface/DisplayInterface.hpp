#pragma once

#include <QWidget>

#include <QDateTime>
#include <QVector>
class FPSCounter
{
public:
	void refreshFPS() {
		qint64 currentTime = QDateTime::currentDateTime().toMSecsSinceEpoch();
		m_frames.push_back(currentTime);

		while (m_frames[0] < (currentTime - 1000)) {
			m_frames.pop_front();
		}

		int currentCount = m_frames.length();
		m_value = (currentCount + m_cacheCount) / 2;

		if (currentCount != m_cacheCount) {
			//emit valueChanged(m_value);
		}

		m_cacheCount = currentCount;
	};
	int m_value = -1;
	int m_cacheCount = 0;
	QVector<qint64> m_frames;
};


class DisplayInterface : public QWidget
{
    Q_OBJECT

public:
    DisplayInterface() {};
    ~DisplayInterface() {};


signals:
    void SendEvent(const QJsonObject& obj);
public://slots
    virtual void HandleEvent(const QJsonObject& obj) {};
    virtual void OnReceivedFrame(const QImage& frame) {};
};