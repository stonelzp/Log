// Fill out your copyright notice in the Description page of Project Settings.

#include "TLOGBlueprintFunctionLibrary.h"

UTLOGBlueprintFunctionLibrary::UTLOGBlueprintFunctionLibrary()
{
	
}

/*
void UTLOGBlueprintFunctionLibrary::initLogger()
{
	FString dll_path = FPaths::Combine(*FPaths::ProjectPluginsDir(), TEXT("LogCollection/"), TEXT("LogSystemDLL.dll"));
	// Init Logger.
	LogSeverity maxSeverity = verbose;
	const char* filepath = "c:\\logs\\log.txt";
	uint32 maxFileSize = 100000;
	int maxFile = 10;
	getlogger()->initLogPlugin(dll_path, maxSeverity, filepath, maxFileSize, maxFile);
}
*/

/* 
// Version 1
void UTLOGBlueprintFunctionLibrary::LogFatal(FString context, UObject* obj)
{
	if (obj != NULL)
	{
		const char* funcName = TCHAR_TO_ANSI(*(obj->GetClass()->GetName()));
		LOGF_BP(funcName, context);
	}
	else
	{
		LOGF_BP("Unknow_BPFunction", context);
	}
}

void UTLOGBlueprintFunctionLibrary::LogDebug(FString context, UObject* obj)
{
	if (obj != NULL)
	{
		const char * funcName = TCHAR_TO_ANSI(*(obj->GetClass()->GetName()));
		LOGD_BP(funcName, context);
	}
	else
	{
		LOGD_BP("Unknow_BPFunction", context);
	}
}

void UTLOGBlueprintFunctionLibrary::LogInfo(FString context, UObject* obj)
{
	if (obj != NULL)
	{
		const char * funcName = TCHAR_TO_ANSI(*(obj->GetClass()->GetName()));
		LOGI_BP(funcName, context);
	}
	else
	{
		LOGI_BP("Unknow_BPFunction", context);
	}
}

void UTLOGBlueprintFunctionLibrary::LogWarning(FString context, UObject* obj)
{
	if (obj != NULL)
	{
		const char * funcName = TCHAR_TO_ANSI(*(obj->GetClass()->GetName()));
		LOGW_BP(funcName, context);
	}
	else
	{
		LOGW_BP("Unknow_BPFunction", context);
	}
}

void UTLOGBlueprintFunctionLibrary::LogError(FString context, UObject* obj)
{
	if (obj != NULL)
	{
		const char * funcName = TCHAR_TO_ANSI(*(obj->GetClass()->GetName()));
		LOGE_BP(funcName, context);
	}
	else
	{
		LOGE_BP("Unknow_BPFunction", context);
	}
}

void UTLOGBlueprintFunctionLibrary::LogVerbose(FString context, UObject* obj)
{
	if (obj != NULL)
	{
		const char * funcName = TCHAR_TO_ANSI(*(obj->GetClass()->GetName()));
		LOGV_BP(funcName, context);
	}
	else
	{
		LOGV_BP("Unknow_BPFunction", context);
	}
}
*/

// Version 2
void UTLOGBlueprintFunctionLibrary::LogFatal(UObject* WorldContextObject,FString context)
{
	if (WorldContextObject)
	{
		const char* funcName = TCHAR_TO_ANSI(*GetNameSafe(WorldContextObject));
		LOGF_BP(funcName, context);
	}
	else
	{
		LOGF_BP("Unknow_BPFunction", context);
	}
}

void UTLOGBlueprintFunctionLibrary::LogDebug(UObject* WorldContextObject, FString context)
{
	if (WorldContextObject)
	{
		const char* funcName = TCHAR_TO_ANSI(*GetNameSafe(WorldContextObject));
		LOGD_BP(funcName, context);
	}
	else
	{
		LOGD_BP("Unknow_BPFunction", context);
	}
}

void UTLOGBlueprintFunctionLibrary::LogInfo(UObject* WorldContextObject, FString context)
{
	if (WorldContextObject)
	{
		const char* funcName = TCHAR_TO_ANSI(*GetNameSafe(WorldContextObject));
		LOGI_BP(funcName, context);
	}
	else
	{
		LOGI_BP("Unknow_BPFunction", context);
	}
}

void UTLOGBlueprintFunctionLibrary::LogWarning(UObject* WorldContextObject, FString context)
{
	if (WorldContextObject)
	{
		const char* funcName = TCHAR_TO_ANSI(*GetNameSafe(WorldContextObject));
		LOGW_BP(funcName, context);
	}
	else
	{
		LOGW_BP("Unknow_BPFunction", context);
	}
}

void UTLOGBlueprintFunctionLibrary::LogError(UObject* WorldContextObject, FString context)
{
	if (WorldContextObject)
	{
		const char* funcName = TCHAR_TO_ANSI(*GetNameSafe(WorldContextObject));
		LOGE_BP(funcName, context);
	}
	else
	{
		LOGE_BP("Unknow_BPFunction", context);
	}
}

void UTLOGBlueprintFunctionLibrary::LogVerbose(UObject* WorldContextObject, FString context)
{
	if (WorldContextObject)
	{
		const char* funcName = TCHAR_TO_ANSI(*GetNameSafe(WorldContextObject));
		LOGV_BP(funcName, context);
	}
	else
	{
		LOGV_BP("Unknow_BPFunction", context);
	}
}

Logger * UTLOGBlueprintFunctionLibrary::getlogger()
{
	return Logger::getInstance();
}

/*
void UTLOGBlueprintFunctionLibrary::testLogger()
{
	// FString test = getlogger()->getPluginPath();
	// FString testFuncName = getlogger()->DllFuncName.LogInitProc;
	// UE_LOG(LogTemp, Log, TEXT("test the logger %s"), *test);
	// const char* fname = __FUNCTION__;
	// FString a = fname;
	FString n = "私";
	//const TCHAR* h = *n;
	// FString k = "111qqwqweqwe";
	//UE_LOG(LogTemp, Log, TEXT("fileaaaaa name %s"), *k);

	////////////////////////////////////////
	// LOG TEST CASE
	int t_int = 20;
	float t_float = 20.1112f;
	double t_double = 3.1415;
	bool t_bool = false;
	FVector t_FVector = FVector(1.0, 2.0, 3.0);
	FVector2D t_FVector2D = FVector2D(4.0, 5.0);
	char* t_char = "test char type.";
	char t_cha = ':';
	wchar_t *t_wchar = L"test wchar.";
	wchar_t t_wcha = ';';
	FString t_FString = FString("FString test");

	// test int
	LOGD << t_int;
	LOGD << 30;
	LOGD << 20 + 30;

	// test float
	LOGD << t_float;
	LOGD << 3.1415926f;  // 精度若干低い　 3.141593

	// test double
	LOGD << t_double;
	LOGD << 3.141592697;   // 3.141593

	// test bool
	LOGD << t_bool;
	LOGD << true;

	// test FVector
	LOGD << t_FVector;

	// test FVector2D
	LOGD << t_FVector2D;

	// test char*
	LOGD << t_char;
	LOGD << "test const char*";
	LOGD << "test const char* 日本語文字";      // 漢字の部分は表示できない

	// test char
	LOGD << t_cha;

	// test wchar_t*
	LOGD << t_wchar;
	LOGD << L"test const wchar_t";
	LOGD << L"test const wchar_t*　日本語文字";
	LOGD << TEXT("日本語文字TEXT_test");

	// test wchar_t
	LOGD << t_wcha;

	// test FString
	LOGD << t_FString;

}
*/
