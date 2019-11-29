cls
rmdir /s /q build
mkdir build
cd build
conan install .. --profile ProfileWin32MT
cmake -DCMAKE_BUILD_TYPE=Release ..
cmake --build . --config Release
pause