//#include "JsonConvert.h"

//template <class T>
//QString JsonConvert::SerializeObject(T *value)
//{
//	return value->ToJsonString();
//}

//template <>
//QString JsonConvert::SerializeObject(IJsonSerializable *value)
//{
//	return value->ToJsonString();
//}

//template <class T>
//T JsonConvert::DeserializeObject(QString s)
//{
//	T a;
//	QJsonDocument doc = QJsonDocument::fromJson(s.toUtf8());
//	a.read(doc.object());
//	return a;
//}

//template <>
//IJsonSerializable JsonConvert::DeserializeObject(QString s)
//{
//	IJsonSerializable *a;
//	QJsonDocument doc = QJsonDocument::fromJson(s.toUtf8());
//	a->read(doc.object());
//	return a;
//}
