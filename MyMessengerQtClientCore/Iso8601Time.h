#ifndef ISO8601TIME_H
#define ISO8601TIME_H

#include <QJsonObject>
#include <QDateTime>
#include <QString>

class Iso8601Time
{
public:
	Iso8601Time(QString time);
	Iso8601Time(QString time, int OffsetFromUtc);

	Iso8601Time(QDateTime time);
	Iso8601Time(QDateTime time, int OffsetFromUtc);

	Iso8601Time(Iso8601Time &time);
	~Iso8601Time();

	QString ToString();
	//static Iso8601Time FromString(QString time);

	QDateTime GetQDateTime();
	int GetOffsetFromUtcSeconds();
	void SetOffsetFromUtcSeconds(int offset);
private:
	int m_OffsetFromUtcSeconds;
	QDateTime *m_inner;
};

#endif // ISO8601TIME_H
