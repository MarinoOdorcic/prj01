cmake_minimum_required(VERSION 3.5)

project(prj01 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(fmt
        GIT_REPOSITORY https://github.com/fmtlib/fmt
        GIT_TAG origin/master) # or whatever tag you want

FetchContent_Declare(json
        GIT_REPOSITORY https://github.com/nlohmann/json
        GIT_TAG v3.11.3)

FetchContent_GetProperties(fmt)
if(NOT fmt_POPULATED)
    FetchContent_Populate(fmt)
    add_subdirectory(${fmt_SOURCE_DIR} ${fmt_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()

FetchContent_GetProperties(json)
if(NOT json_POPULATED)
    FetchContent_Populate(json)
    add_subdirectory(${json_SOURCE_DIR} ${json_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()

#FetchContent_MakeAvailable(fmt)
#FetchContent_MakeAvailable(json)

add_executable(prj01
        main.cpp
        elementBaseClass/element.cpp
        elementSubClass/pipe.h
        elementSubClass/pipe.cpp
        seriesBaseClass/series.h
        seriesBaseClass/series.cpp
        elementSubClass/local.h
        elementSubClass/local.cpp
        elementSubClass/inlet.h
        elementSubClass/inlet.cpp
        localSubClass/contraction.h
        localSubClass/contraction.cpp
        localSubClass/expansion.h
        localSubClass/expansion.cpp
        localSubClass/elbow.h
        localSubClass/elbow.cpp
)

target_link_libraries(prj01
        fmt::fmt
        nlohmann_json::nlohmann_json)
