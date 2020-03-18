// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Logger.h"
#include "CoreMinimal.h"

/**
 * 
 */
class Log
{
public:
	Log();
	~Log();
};

//////////////////////////////////////////////////////
// Main logging macros for C++
#define IF_LOG(logSeverity)             if(Logger::getInstance() != NULL)
#define LOG(logSeverity)                IF_LOG(logSeverity) (*Logger::getInstance()) += Record(logSeverity, __FUNCTION__, __LINE__).ref()

#define LOG_FATAL                       LOG(LogSeverity::fatal)
#define LOG_ERROR                       LOG(LogSeverity::error)
#define LOG_WARNING                     LOG(LogSeverity::warning)
#define LOG_INFO                        LOG(LogSeverity::info)
#define LOG_DEBUG                       LOG(LogSeverity::debug)
#define LOG_VERBOSE                     LOG(LogSeverity::verbose)

#define LOGF                            LOG_FATAL
#define LOGE                            LOG_ERROR
#define LOGW                            LOG_WARNING
#define LOGI                            LOG_INFO
#define LOGD                            LOG_DEBUG
#define LOGV                            LOG_VERBOSE




//////////////////////////////////////////////////////
// Main logging macros for Blurprint (Only for developer)
#define LOG_BP(logSeverity, func, text)       IF_LOG(logSeverity) (*Logger::getInstance()) += Record(logSeverity, func, 0, text).ref()

#define LOGF_BP(func, text)                   LOG_BP(LogSeverity::fatal, func, text)
#define LOGE_BP(func, text)                   LOG_BP(LogSeverity::error, func, text)
#define LOGW_BP(func, text)                   LOG_BP(LogSeverity::warning, func, text)
#define LOGI_BP(func, text)                   LOG_BP(LogSeverity::info, func, text)
#define LOGD_BP(func, text)                   LOG_BP(LogSeverity::debug, func, text);
#define LOGV_BP(func, text)                   LOG_BP(LogSeverity::verbose, func, text)
