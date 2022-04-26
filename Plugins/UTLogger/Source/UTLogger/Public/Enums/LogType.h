#pragma once

#include "CoreMinimal.h"
#include "LogType.generated.h"

UENUM(BlueprintType)
enum class ELogType : uint8
{
	Error,
	Warning,
	Info,
	Trace
};