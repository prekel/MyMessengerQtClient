#include "Iso8601Time.h"

Iso8601Time::Iso8601Time(QString time)
{
	auto a = QDateTime::fromString(time, Qt::DateFormat::ISODate);
	m_inner = &a;
}

Iso8601Time::Iso8601Time(Iso8601Time &time)
{

}

Iso8601Time::Iso8601Time(QDateTime time)
{

}

QString Iso8601Time::ToString()
{
	return "";
}

//Iso8601Time Iso8601Time::FromString(QString time)
//{
//	return nullptr;
//}

QDateTime Iso8601Time::GetQDateTime()
{
	return *m_inner;
}
