#ifndef ISO8601TIME_H
#define ISO8601TIME_H

#include <QDateTime>
#include <QString>

class Iso8601Time
{
public:
	Iso8601Time(QString time);
	Iso8601Time(Iso8601Time &time);
	Iso8601Time(QDateTime time);
	QString ToString();
	//static Iso8601Time FromString(QString time);
	QDateTime GetQDateTime();
private:
	QDateTime *m_inner;
};

#endif // ISO8601TIME_H
