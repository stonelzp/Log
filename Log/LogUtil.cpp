// Fill out your copyright notice in the Description page of Project Settings.

#include "LogUtil.h"

LogUtil::LogUtil()
{
}

LogUtil::~LogUtil()
{
}


Record & Record::operator<<(int data)
{
	return *this << FString::FromInt(data);
}

Record & Record::operator<<(float data)
{
	return *this << FString::SanitizeFloat(data);
}

Record & Record::operator<<(double data)
{
	return *this << FString::SanitizeFloat(data);
}

Record & Record::operator<<(bool data)
{
	return *this << (data ? TEXT("true") : TEXT("false"));
}

Record & Record::operator<<(FVector data)
{
	return *this << data.ToString();
}

Record & Record::operator<<(FVector2D data)
{
	return *this << data.ToString();
}

Record & Record::operator<<(FRotator data)
{
	return *this << data.ToString();
}

Record & Record::operator<<(FLinearColor data)
{
	return *this << data.ToString();
}

Record & Record::operator<<(const char * data)
{
	data = data ? data : "null";
	return *this << FString(data);
}

Record & Record::operator<<(char data)
{
	char str[] = { data,0 };
	return *this << str;
}

#ifdef UNICODE
Record & Record::operator<<(const wchar_t * data)
{
	data = data ? data : L"null";
	return *this << FString(data);
}
Record & Record::operator<<(wchar_t data)
{
	wchar_t str[] = { data,0 };
	return *this << str;
}
#endif

Record & Record::operator<<(FString data)
{
	m_message += data;
	return *this;
}
