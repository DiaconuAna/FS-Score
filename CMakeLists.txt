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
        main.cpp GUI/mainGUI.cpp GUI/mainGUI.h Ladies/LadiesSPWindow.cpp Ladies/LadiesSPWindow.h Ladies/LadiesFSWindow.cpp Ladies/LadiesFSWindow.h Model/Score.cpp Model/Score.h Service/ScoreService.cpp Service/ScoreService.h Model/Element.h Model/Singles/Jumps.cpp Model/Singles/Jumps.h Model/Singles/Spins.cpp Model/Singles/Spins.h Model/Singles/StepSequence.cpp Model/Singles/StepSequence.h Model/Singles/ChoreoSequence.cpp Model/Singles/ChoreoSequence.h Model/Element.cpp Repository/ElementsRepo.cpp Repository/ElementsRepo.h)

if (NOT CMAKE_PREFIX_PATH)
    message(WARNING "CMAKE_PREFIX_PATH is not defined, you may need to set it "
            "(-DCMAKE_PREFIX_PATH=\"path/to/Qt/lib/cmake\" or -DCMAKE_PREFIX_PATH=/usr/include/{host}/qt{version}/ on Ubuntu)")
endif ()

find_package(Qt6 COMPONENTS Widgets)
find_package(Qt6 COMPONENTS Widgets REQUIRED)
target_link_libraries(FS_Score_v2 PRIVATE Qt6::Widgets)

