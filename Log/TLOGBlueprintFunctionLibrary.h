// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Paths.h"
#include "Logger.h"
// for delete
#include "Log.h"
#include "TLOGBlueprintFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class UTLOGBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

		UTLOGBlueprintFunctionLibrary();


public:
	    /*
		UFUNCTION(BlueprintCallable, Category = "LogCollection")
		    static void initLogger();
		*/
		
		/* Version 1 
		// we have to add "self ref" to the method that we called
		// so that we can get the blueprint name
		UFUNCTION(BlueprintCallable, Category = "LogCollection")
			static void LogFatal(FString context, UObject* obj);

		UFUNCTION(BlueprintCallable, Category = "LogCollection")
			static void LogDebug(FString context, UObject* obj);

		UFUNCTION(BlueprintCallable, Category = "LogCollection")
			static void LogInfo(FString context, UObject* obj);

		UFUNCTION(BlueprintCallable, Category = "LogCollection")
			static void LogWarning(FString context, UObject* obj);

		UFUNCTION(BlueprintCallable, Category = "LogCollection")
			static void LogError(FString context, UObject* obj);

		UFUNCTION(BlueprintCallable, Category = "LogCollection")
			static void LogVerbose(FString context, UObject* obj);
		*/

		// Version 2
		// The version that we can get blueprint name we called
		// without self reference.
		UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject", CallableWithoutWorldContext, Keywords = "logf"), Category = "LogCollection")
			static void LogFatal(UObject* WorldContextObject, FString context);

		UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject", CallableWithoutWorldContext, Keywords = "logd"), Category = "LogCollection")
			static void LogDebug(UObject* WorldContextObject, FString context);

		UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject", CallableWithoutWorldContext, Keywords = "logi"), Category = "LogCollection")
			static void LogInfo(UObject* WorldContextObject, FString context);

		UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject", CallableWithoutWorldContext, Keywords = "logw"), Category = "LogCollection")
			static void LogWarning(UObject* WorldContextObject, FString context);

		UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject", CallableWithoutWorldContext, Keywords = "loge"), Category = "LogCollection")
			static void LogError(UObject* WorldContextObject, FString context);

		UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject", CallableWithoutWorldContext, Keywords = "logv"), Category = "LogCollection")
			static void LogVerbose(UObject* WorldContextObject, FString context);


		/*
		UFUNCTION(BlueprintCallable, Category = "LogCollection")
		    static void testLogger();
		*/
private:
	static Logger * getlogger();
	
};
