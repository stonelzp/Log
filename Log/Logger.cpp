// Fill out your copyright notice in the Description page of Project Settings.
#include "Logger.h"
#include "ILogCollector.h"

Logger::Logger()
{
}

Logger Logger::logger = Logger();

void Logger::operator+=(const Record & record)
{
	ILogCollector::Get().LogRecord(
		int(record.getSeverity()), 
		record.getFunc(), 
		record.getMessage(), 
		record.getLine()
	);
}
