cmake_minimum_required(VERSION 3.2)
project(DesktopProject)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

include_external_msproject(DesktopCore ${CMAKE_SOURCE_DIR}/src/Desktop.sln)

include_external_msproject(DesktopCore ${CMAKE_SOURCE_DIR}/src/DesktopCore/DesktopCore.vcxproj PLATFORM Win32 )
include_external_msproject(DesktopApp ${CMAKE_SOURCE_DIR}/src/DesktopApp/DesktopApp.vcxproj PLATFORM Win32 DesktopCore)
include_external_msproject(DesktopInstaller ${CMAKE_SOURCE_DIR}/src/DesktopInstaller/DesktopInstaller.vbproj PLATFORM Win32 DesktopApp)

include_directories(${CMAKE_SOURCE_DIR}/include)
link_libraries(${CMAKE_SOURCE_DIR}/lib)

add_dependencies(DesktopApp DesktopCore)
add_dependencies(DesktopInstaller DesktopApp)