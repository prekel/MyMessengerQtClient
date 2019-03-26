#include "Iso8601Time.h"

Iso8601Time::Iso8601Time(QString time, int OffsetFromUtc)
{
	QDateTime a = QDateTime::fromString(time, Qt::DateFormat::ISODate);
	m_inner = new QDateTime(a);
	m_OffsetFromUtcSeconds = OffsetFromUtc;
}

Iso8601Time::Iso8601Time(Iso8601Time &time)
{
	m_inner = new QDateTime(*time.m_inner);
	m_OffsetFromUtcSeconds = time.m_OffsetFromUtcSeconds;
}

Iso8601Time::Iso8601Time(QDateTime time, int OffsetFromUtc)
{
	m_inner = new QDateTime(time);
	m_OffsetFromUtcSeconds = OffsetFromUtc;
}

Iso8601Time::Iso8601Time(QString time) : Iso8601Time(time, QDateTime::currentDateTime().offsetFromUtc())
{
}

Iso8601Time::Iso8601Time(QDateTime time) : Iso8601Time(time, QDateTime::currentDateTime().offsetFromUtc())
{
}

Iso8601Time::~Iso8601Time()
{
	delete m_inner;
}

QString Iso8601Time::ToString()
{
	return m_inner->toOffsetFromUtc(m_OffsetFromUtcSeconds).toString(Qt::ISODateWithMs);
	//return m_inner->toString(Qt::ISODateWithMs);
}

//Iso8601Time Iso8601Time::FromString(QString time)
//{
//	return nullptr;
//}

QDateTime Iso8601Time::GetQDateTime()
{
	return *m_inner;
}

int Iso8601Time::GetOffsetFromUtcSeconds()
{
	return m_OffsetFromUtcSeconds;
}

void Iso8601Time::SetOffsetFromUtcSeconds(int offset)
{
	m_OffsetFromUtcSeconds = offset;
}
