// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "LogUtil.h"
#include "Paths.h"
// #include "Engine.h"
// #include "Runtime/Core/Public/Windows/WIndowsPlatformProcess.h"

class NonCopyable
{
protected:
	NonCopyable(){}

private:
	NonCopyable(const NonCopyable&);
	NonCopyable& operator=(const NonCopyable&);
};

template<class T>
class Singleton :NonCopyable
{
public:
	Singleton()
	{
		if (m_instance == NULL)
		{
			m_instance = static_cast<T*>(this);
		}
	}

	~Singleton()
	{
		if (m_instance != NULL)
		{
			m_instance = 0;
		}
	}

	static T* getInstance()
	{
		return m_instance;
	}

private:
	static T* m_instance;
};

template<class T>
T* Singleton<T>::m_instance = NULL;

class Logger : public Singleton<Logger>
{
private:
	static Logger logger;

private:
	Logger();
	Logger(const Logger&);
	~Logger() {};

public:
	void operator+=(const Record& record);
};
