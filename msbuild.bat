@echo off
rem Detect if VC devenv is activated by checking if cl is available
where cl
if %ERRORLEVEL% NEQ 0 (
    echo Error: You need to enable VC developer console. Press the windows key and type 'x64 Native Tools Command Prompt for VS'
    echo        and run the command again.
    exit /b 1
)

where cmake
if %ERRORLEVEL% NEQ 0 (
    echo Error: You need cmake.    
    exit /b
)

set target=Release

md bin
cd bin
cmake -DCMAKE_BUILD_TYPE=%target% .. && msbuild tophat.sln /property:Configuration=%target%
cd ..
copy bin\%target%\tophat.exe tophat.exe

