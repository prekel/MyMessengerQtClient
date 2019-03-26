#ifndef ISO8601TIMETESTS_H
#define ISO8601TIMETESTS_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include <Iso8601Time.h>

using namespace testing;

TEST(Iso8601TimeTests, FromString)
{
	auto t = new Iso8601Time("2019-03-16T16:13:44.543048+08:00", 7 * 60 * 60);
	auto a = t->GetQDateTime();
	EXPECT_EQ(2019, a.date().year());
	EXPECT_EQ(3, a.date().month());
	EXPECT_EQ(16, a.date().day());
	EXPECT_EQ(16, a.time().hour());
	EXPECT_EQ(13, a.time().minute());
	EXPECT_EQ(44, a.time().second());
	EXPECT_EQ(543, a.time().msec());
	EXPECT_EQ(8 * 60 * 60, a.offsetFromUtc());

	auto s = t->ToString();
	EXPECT_EQ("2019-03-16T15:13:44.543+07:00", s.toStdString());

	delete t;
}

TEST(Iso8601TimeTests, FromQDateTimeToString)
{
	auto a = QDateTime::fromSecsSinceEpoch(1553610607);
	//a.setTimeSpec(Qt::TimeSpec::OffsetFromUTC);

	auto b = new Iso8601Time(a, 7 * 60 * 60);
	auto s = b->ToString();
	EXPECT_EQ("2019-03-26T21:30:07.000+07:00", s.toStdString());

	delete b;
}

TEST(Iso8601TimeTests, FromStringToString1)
{
	auto t = new Iso8601Time("2019-03-16T16:13:44.543048+00:00", 7 * 60 * 60);

	auto s = t->ToString();
	EXPECT_EQ("2019-03-16T23:13:44.543+07:00", s.toStdString());

	delete t;
}

TEST(Iso8601TimeTests, FromStringToString2)
{
	auto t = new Iso8601Time("2019-03-16T16:13:44.543048Z", 7 * 60 * 60);

	auto s = t->ToString();
	EXPECT_EQ("2019-03-16T23:13:44.543+07:00", s.toStdString());

	delete t;
}

TEST(Iso8601TimeTests, FromStringToString3)
{
	auto t = new Iso8601Time("2019-03-16T16:13:44.543048+07:00", 7 * 60 * 60);

	auto s = t->ToString();
	EXPECT_EQ("2019-03-16T16:13:44.543+07:00", s.toStdString());

	delete t;
}

TEST(Iso8601TimeTests, CurrentTimeCtor)
{
	auto t = new Iso8601Time("2019-03-16T16:13:44.543048+07:00");

	auto offset = QDateTime::currentDateTime().offsetFromUtc();

	EXPECT_EQ(offset, t->GetQDateTime().offsetFromUtc());

	if (offset == 7 * 60 * 60)
	{
		auto s = t->ToString();
		EXPECT_EQ("2019-03-16T16:13:44.543+07:00", s.toStdString());
	}

	delete t;
}

TEST(Iso8601TimeTests, SetOffset)
{
	auto t = new Iso8601Time("2019-03-16T16:13:44.543048+07:00");

	auto offset = QDateTime::currentDateTime().offsetFromUtc();

	EXPECT_EQ(offset, t->GetQDateTime().offsetFromUtc());

	t->SetOffsetFromUtcSeconds(7 * 60 * 60);
	auto s1 = t->ToString();
	EXPECT_EQ("2019-03-16T16:13:44.543+07:00", s1.toStdString());

	t->SetOffsetFromUtcSeconds(8 * 60 * 60);
	auto s2 = t->ToString();
	EXPECT_EQ("2019-03-16T17:13:44.543+08:00", s2.toStdString());

	delete t;
}

#endif // ISO8601TIMETESTS_H
