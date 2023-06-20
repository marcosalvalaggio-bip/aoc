@echo off

set BUILD_DIR=build

REM Check if the build directory exists
if exist "%BUILD_DIR%" (
    REM If it exists, remove the build directory
    rmdir /s /q "%BUILD_DIR%"
)

REM Create a new build directory
mkdir "%BUILD_DIR%"
cd "%BUILD_DIR%"

REM Generate build files using CMake
cmake -G "MinGW Makefiles" ..

REM Build the project
mingw32-make

REM Execute the compiled program
main.exe

