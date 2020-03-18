// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <sstream>

enum LogSeverity
{
	none = 0,
	fatal = 1,
	error = 2,
	warning = 3,
	info = 4,
	debug = 5,
	verbose = 6
};

class LogUtil
{
public:
	LogUtil();
	~LogUtil();
};

class Record
{
public:
	Record(LogSeverity severity, const char* func, size_t line, FString msg = "")
		: m_severity(severity), m_func(func), m_line(line), m_message(msg)
	{
	}

	Record& ref()
	{
		return *this;
	}

	Record& operator<<(int data);
	Record& operator<<(float data);
	Record& operator<<(double data);
	Record& operator<<(bool data);
	Record& operator<<(FVector data);
	Record& operator<<(FVector2D data);
	Record& operator<<(FRotator data);
	Record& operator<<(FLinearColor data);
	Record& operator<<(const char* data);
	Record& operator<<(char data);

#ifdef UNICODE
	Record& operator<<(const wchar_t* data);
	Record& operator<<(wchar_t data);
#endif

	Record& operator<<(FString data);


	const char* getFunc () const {
		return m_func;
	}
	size_t getLine() const {
		return m_line;
	}
	const TCHAR* getMessage() const {
		return *m_message;
	}
	LogSeverity getSeverity() const {
		return m_severity;
	}

private:
	const LogSeverity    m_severity;
	const char* const    m_func;
	const size_t         m_line;
	FString              m_message;
};
