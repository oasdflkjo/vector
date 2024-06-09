@echo off
echo Rebuilding the project...

REM Check if the build directory exists
IF EXIST build (
    REM Remove the build directory
    echo Removing old build directory...
    rmdir /s /q build
)

REM Create a new build directory
echo Creating new build directory...
mkdir build

REM Change to the build directory
cd build

REM Run CMake and Ninja
echo Running CMake and Ninja...
cmake -G Ninja ..
ninja

REM Go to the folder and run Ninja
echo Navigating to the build folder and running Ninja...
cd ..
cd build
ninja

REM Change back to the root directory
cd ..

echo Build completed.
