#ifndef ISO8601TIME_H
#define ISO8601TIME_H

#include <QJsonObject>
#include <QDateTime>
#include <QString>

class Iso8601Time
{
public:
	Iso8601Time();
	Iso8601Time(Iso8601Time &time);
	~Iso8601Time();

	QString ToString();
	QString ToString(int OffsetFromUtcSeconds);

	QDateTime GetQDateTime();
	int GetOffsetFromUtcSeconds();
	void SetOffsetFromUtcSeconds(int offset);

	static Iso8601Time FromString(QString time);
	static Iso8601Time FromString(QString time, int OffsetFromUtc);
	static Iso8601Time FromQDateTime(QDateTime time);
	static Iso8601Time FromQDateTime(QDateTime time, int OffsetFromUtc);
private:
	int m_OffsetFromUtcSeconds;
	QDateTime *m_inner;
};

#endif // ISO8601TIME_H
