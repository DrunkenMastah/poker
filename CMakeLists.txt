cmake_minimum_required(VERSION 3.16.3)
project(poker VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_AUTORCC ON)
add_compile_options(-fdiagnostics-color=always)
find_package(Qt5 COMPONENTS Quick Widgets REQUIRED)
find_package(cpr  REQUIRED)
find_package(Threads)
add_executable(poker 
    src/main.cpp
    src/cards_helper.cpp
    src/connector.cpp
    Resources/resources.qrc
    )
target_include_directories(poker PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(poker
    PRIVATE 
    Qt5::Widgets
    Qt5::Quick
    cpr::cpr
    Threads::Threads
)

add_custom_target(run
    COMMAND ./poker
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)

#pip install conan
#conan install . -if build -s compiler=gcc -s compiler.libcxx=libstdc++11 --build=missing
#cmake -B build -GNinja -DCMAKE_TOOLCHAIN_FILE=build/conan_paths.cmake
