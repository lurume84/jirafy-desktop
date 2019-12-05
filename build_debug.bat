cls
REM rmdir /s /q build
REM mkdir build_debug
cd build_debug
conan install .. --profile ProfileWin32MT_Debug
cmake -DCMAKE_BUILD_TYPE=Debug ..
cmake --build . --config Debug
pause