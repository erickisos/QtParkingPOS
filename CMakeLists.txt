cmake_minimum_required(VERSION 3.2)

include("cmake/HunterGate.cmake")
huntergate(URL "https://github.com/cpp-pm/hunter/archive/v0.23.321.tar.gz" SHA1
           "5e53cbb0429037ea8e2592bfd92704b8ff3ab492")

project(
  QtParkingPOS
  VERSION 0.2.0
  LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
  set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

if(APPLE AND EXISTS /usr/local/opt/qt6)
  # Homebrew installs Qt6 (up to at least 5.9.1) in /usr/local/qt6, ensure it
  # can be found by CMake since it is not in the default /usr/local prefix.
  # source:
  # https://github.com/Homebrew/homebrew-core/issues/8392#issuecomment-325226494
  list(APPEND CMAKE_PREFIX_PATH "/usr/local/opt/qt6")
  set(CMAKE_MACOSX_RPATH 1)
elseif(APPLE AND EXISTS /opt/homebrew/opt/qt@5)
  list(APPEND CMAKE_PREFIX_PATH "/opt/homebrew/opt/qt@5")
  set(CMAKE_MACOSX_RPATH 1)
endif()

find_package(Qt6 QUIET)

if(NOT Qt6_FOUND)
  hunter_add_package(Qt6)
endif()

find_package(
  Qt6
  COMPONENTS Core Widgets Concurrent Sql
  REQUIRED)

set(QT_LINK_LIBRARIES Qt6::Core Qt6::Widgets Qt6::Concurrent Qt6::Sql)

set(QT_PARKINGPOS_SRC
    src/main.cpp
    src/QDatabaseManager.cpp
    src/QRegisterDialog.cpp
    src/QAboutDialog.cpp
    src/QLoginDialog.cpp
    src/QParkingPOS.cpp
    src/QCheckInWindow.cpp
    src/QCheckOutWindow.cpp
    src/QParkingSplashscreen.cpp
    src/QAdministratorWindow.cpp
    src/QRegisterDialog.ui
    src/QAboutDialog.ui
    src/QLoginDialog.ui
    src/QCheckInWindow.ui
    src/QCheckOutWindow.ui
    src/QParkingSplashscreen.ui
    src/QAdministratorWindow.ui
    resources/parking_pos.qrc
    resources/images.qrc)
add_executable(qtparkingpos ${QT_PARKINGPOS_SRC})
include_directories(includes/)

target_link_libraries(qtparkingpos ${QT_LINK_LIBRARIES})
