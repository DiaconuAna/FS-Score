cmake_minimum_required(VERSION 3.17)
project(FS_Score_v2)

set(CMAKE_CXX_STANDARD 14)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")
set(CMAKE_PREFIX_PATH "D:\\qt\\6.2.3\\mingw_64")

set(QT_VERSION 6)
set(REQUIRED_LIBS Core Gui Widgets Charts)
set(REQUIRED_LIBS_QUALIFIED Qt6::Core Qt6::Gui Qt6::Widgets Qt6::Charts)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

include_directories(.)

add_executable(FS_Score_v2
        main.cpp mainGUI.cpp mainGUI.h LadiesSPWindow.cpp LadiesSPWindow.h LadiesFSWindow.cpp LadiesFSWindow.h Score.cpp Score.h ScoreRepository.cpp ScoreRepository.h ScoreService.cpp ScoreService.h)

if (NOT CMAKE_PREFIX_PATH)
    message(WARNING "CMAKE_PREFIX_PATH is not defined, you may need to set it "
            "(-DCMAKE_PREFIX_PATH=\"path/to/Qt/lib/cmake\" or -DCMAKE_PREFIX_PATH=/usr/include/{host}/qt{version}/ on Ubuntu)")
endif ()

find_package(Qt6 COMPONENTS Widgets)
find_package(Qt6 COMPONENTS Widgets REQUIRED)
target_link_libraries(FS_Score_v2 PRIVATE Qt6::Widgets)

