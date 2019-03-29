#include "Iso8601Time.h"

Iso8601Time Iso8601Time()
{
}

Iso8601Time::Iso8601Time(Iso8601Time &time)
{
	m_inner = new QDateTime(*time.m_inner);
	m_OffsetFromUtcSeconds = time.m_OffsetFromUtcSeconds;
}

Iso8601Time Iso8601Time::FromString(QString time)
{
	Iso8601Time t;
	t.m_inner = QDateTime::fromString(time, Qt::DateFormat::ISODate);
	t.m_OffsetFromUtcSeconds = QDateTime::currentDateTime().offsetFromUtc();
	return t;
}

Iso8601Time Iso8601Time::FromString(QString time, int OffsetFromUtc)
{
	Iso8601Time t;
	t.m_inner = QDateTime::fromString(time, Qt::DateFormat::ISODate);
	t.m_OffsetFromUtcSeconds = OffsetFromUtc;
	return t;
}

Iso8601Time Iso8601Time::FromQDateTime(QDateTime time)
{
	Iso8601Time t;
	t.m_inner = time;
	t.m_OffsetFromUtcSeconds = QDateTime::currentDateTime().offsetFromUtc();
	return t;
}

Iso8601Time Iso8601Time::FromQDateTime(QDateTime time, int OffsetFromUtc)
{
	Iso8601Time t;
	t.m_inner = time;
	t.m_OffsetFromUtcSeconds = OffsetFromUtc;
	return t;
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

QString Iso8601Time::ToString(int OffsetFromUtcSeconds)
{
	return m_inner->toOffsetFromUtc(OffsetFromUtcSeconds).toString(Qt::ISODateWithMs);
	//return m_inner->toString(Qt::ISODateWithMs);
}

//Iso8601Time Iso8601Time::FromString(QString time)
//{
//	return nullptr;
//}

Iso8601Time Iso8601Time::FromQDateTime(QDateTime time)
{
	Iso8601Time a(time);
	return a;
}

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
