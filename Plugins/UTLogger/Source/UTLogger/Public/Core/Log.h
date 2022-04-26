#pragma once

#include "CoreMinimal.h"
#include "Enums/LogType.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Log.generated.h"

UCLASS()
class UTLOGGER_API ULog final : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "Unreal Toolbox|Logger")
	static void Error(const FString Tag, const FString Text);

	UFUNCTION(BlueprintCallable, Category = "Unreal Toolbox|Logger")
	static void Warning(const FString Tag, const FString Text);

	UFUNCTION(BlueprintCallable, Category = "Unreal Toolbox|Logger")
	static void Info(const FString Tag, const FString Text);

	UFUNCTION(BlueprintCallable, Category = "Unreal Toolbox|Logger")
	static void Trace(const FString Tag, const FString Text);

private:
	static void LogToFile(ELogType LogType, const FString Tag, const FString Text);
	static void LogToScreen(const FColor Color, const FString Tag, const FString Text);
	static FString GetLogTypeText(ELogType LogType);
};