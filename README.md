# Logger Plugin
The Logger Plugin for Unreal Engine allows you to easily log info to file and via on-screen messages. This plugin supports the following log types
1. Errors
2. Warnings
3. Info
4. Trace

## Installation
1. Download the latest release from GitHub
2. Navigate to `C:\Program Files\Epic Games\UE_{VERSION}\Engine\Plugins\`
3. Create a `Marketplace` folder if needed
4. Extract the release and copy to the `Marketplace` folder
5. Open Unreal Engine
6. Click on `Edit > Plugins`
7. Enable the plugin under the `Installed > Unreal Toolbox` category
8. Restart Unreal Engine

## Logging Methods
There is 2 different logging methods. Both of these are used each time you log anything:
1. `On-screen messages` - These messages will appear on-screen for 5 seconds (only used when running through the editor)
2. `File` - Everything you log is also written to a file. The file name is the current date and a new file is created each day the game is played. All log files are stored in the root of the project under the `Logs` director

## Required Input
You need to provide the following info regardless of if you're logging info through Blueprints or C++:
1. `Tag` - This is usually the function or class name. It allows you to find out exactly where this is being logged
2. `Text` - The actual text that should be logged out

## Blueprint Usage
You can easily log info in Blueprints by added one of the following nodes
1. `Unreal Toolbox > Logger > Error`
2. `Unreal Toolbox > Logger > Warning`
3. `Unreal Toolbox > Logger > Info`
4. `Unreal Toolbox > Logger > Trace`

## C++ Usage
The logging is handled through a static class/functions. You can log info by using the following functions:
1. `ULog::Error(const FString Tag, const FString Text)`
2. `ULog::Warning(const FString Tag, const FString Text)`
3. `ULog::Info(const FString Tag, const FString Text)`
4. `ULog::Trace(const FString Tag, const FString Text)`
