add_executable(prj01
        main.cpp
        element.cpp
        pipe.h
        pipe.cpp
        local.h
        local.cpp
        json.h
        json.cpp
)

target_include_directories(prj01 PRIVATE
        ${PROJECT_BINARY_DIR}
)
target_link_libraries(prj01
        fmt::fmt
        nlohmann_json::nlohmann_json)