@echo off
echo =========================================
echo          GPA ANALYZER COMPILER         
echo =========================================
echo.

:: Check if g++ is available
where g++ >nul 2>&1
if %errorlevel% neq 0 (
    echo Error: g++ compiler not found!
    echo Please install MinGW or use Visual Studio Developer Command Prompt
    pause
    exit /b 1
)

:: Compile the program
echo Compiling GPA Analyzer...
g++ -std=c++11 -Wall -Wextra -O2 -o gpa_analyzer_temp.exe gpa_analyzer.cpp

:: Check if compilation was successful
if %errorlevel% neq 0 (
    echo.
    echo Compilation failed!
    pause
    exit /b 1
)

:: Replace the old executable if it exists
if exist gpa_analyzer.exe del gpa_analyzer.exe
ren gpa_analyzer_temp.exe gpa_analyzer.exe

echo.
echo Compilation successful!
echo.
echo Starting GPA Analyzer...
echo.

:: Run the program
gpa_analyzer.exe

echo.
echo Program finished.
pause
