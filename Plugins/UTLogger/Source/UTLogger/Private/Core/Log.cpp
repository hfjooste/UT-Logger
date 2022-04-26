#include "Core/Log.h"
#include "Misc/FileHelper.h"
#include "Engine/Engine.h"

void ULog::Error(const FString Tag, const FString Text)
{
	LogToFile(ELogType::Error, Tag, Text);
	LogToScreen(FColor::Red, Tag, Text);
}

void ULog::Warning(const FString Tag, const FString Text)
{
	LogToFile(ELogType::Warning, Tag, Text);
	LogToScreen(FColor::Yellow, Tag, Text);
}

void ULog::Info(const FString Tag, const FString Text)
{
	LogToFile(ELogType::Info, Tag, Text);
	LogToScreen(FColor::Blue, Tag, Text);
}

void ULog::Trace(const FString Tag, const FString Text)
{
	LogToFile(ELogType::Trace, Tag, Text);
	LogToScreen(FColor::White, Tag, Text);
}

void ULog::LogToFile(ELogType Type, const FString Tag, const FString Text)
{
#if !PLATFORM_DESKTOP
	return;
#endif

	const FString DateText = FDateTime::Now().GetDate().ToString(TEXT("%Y%m%d"));
	
#if !WITH_EDITOR
	const FString LogFile = FString(FGenericPlatformProcess::ExecutablePath()) + "/Logs/" + DateText + ".log";
#else
	const FString LogFile = FPaths::ProjectDir() + "/Logs/" + DateText + ".log";
#endif
	
	FString LogText;
	FFileHelper::LoadFileToString(LogText, *LogFile);
	LogText += FDateTime::Now().ToString(TEXT("%Y/%m/%d %H:%M:%S")) + GetLogTypeText(Type) + "[" + Tag + "] " + Text + "\r\n";
	FFileHelper::SaveStringToFile(LogText, *LogFile);
}

void ULog::LogToScreen(const FColor Color, const FString Tag, const FString Text)
{
#if !UE_EDITOR && !WITH_EDITOR
	return;
#endif
    	
	if (!GEngine)
	{
		return;
	}

	const FString LogText = "[" + Tag + "] " + Text;
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, Color, LogText);
}

FString ULog::GetLogTypeText(const ELogType Type)
{
	switch (Type)
	{
	case ELogType::Error:
		return " [Error] ";
	case ELogType::Warning:
		return " [Warning] ";
	case ELogType::Info:
		return  " [Info] ";
	case ELogType::Trace:
		return " [Trace] ";
	default:
		return " [Unknown] ";
	}
}