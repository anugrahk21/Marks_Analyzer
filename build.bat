@echo off
:: Build script for GPA Analyzer
:: Usage: build.bat [debug|release|clean]

set "SOURCE=gpa_analyzer.cpp"
set "TARGET=gpa_analyzer.exe"
set "COMMON_FLAGS=-std=c++11 -Wall -Wextra"

if "%1"=="debug" (
    echo Building DEBUG version...
    g++ %COMMON_FLAGS% -g -DDEBUG -o %TARGET% %SOURCE%
    echo Debug build complete.
) else if "%1"=="release" (
    echo Building RELEASE version...
    g++ %COMMON_FLAGS% -O2 -DNDEBUG -o %TARGET% %SOURCE%
    echo Release build complete.
) else if "%1"=="clean" (
    echo Cleaning build files...
    if exist %TARGET% del %TARGET%
    if exist *.o del *.o
    echo Clean complete.
) else (
    echo Building DEFAULT version...
    g++ %COMMON_FLAGS% -O2 -o %TARGET% %SOURCE%
    if %errorlevel% equ 0 (
        echo Build successful!
        echo.
        echo Usage:
        echo   %TARGET%           - Run the program
        echo   build.bat debug    - Build debug version
        echo   build.bat release  - Build release version
        echo   build.bat clean    - Clean build files
    ) else (
        echo Build failed!
    )
)

pause
