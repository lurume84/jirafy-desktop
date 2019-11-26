cmake_minimum_required(VERSION 3.2)
project(DesktopProject)

include_external_msproject(DesktopCore ${CMAKE_SOURCE_DIR}/src/DesktopCore/DesktopCore.vcxproj PLATFORM Win32)
include_external_msproject(DesktopApp ${CMAKE_SOURCE_DIR}/src/DesktopApp/DesktopApp.vcxproj PLATFORM Win32)
include_external_msproject(DesktopInstaller ${CMAKE_SOURCE_DIR}/src/DesktopInstaller/DesktopInstaller.vbproj PLATFORM Win32)

add_dependencies(DesktopApp DesktopCore)
add_dependencies(DesktopInstaller DesktopApp)