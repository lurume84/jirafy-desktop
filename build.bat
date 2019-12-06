cls
REM rmdir /s /q build
REM mkdir build
cd build
conan install .. --profile ../profiles/ProfileWin32MT
cmake -DCMAKE_BUILD_TYPE=Release ..
cmake --build . --config Release