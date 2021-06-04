cmake_minimum_required(VERSION 3.16)
project(novelty C)
set(CMAKE_C_STANDARD 11)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Build)

include_directories(${CMAKE_SOURCE_DIR}/Headers)

if(APPLE)
    link_directories(/usr/local/Cellar/raylib/3.5.0/lib)
endif()

add_executable(novelty Sources/main.c Sources/Launcher/launcher.c Sources/Launcher/parse_settings.c)

#add_custom_command(
#        TARGET novelty PRE_BUILD
#        COMMAND ${CMAKE_COMMAND} -E copy_directory
#        ${CMAKE_SOURCE_DIR}/Resources/ $<TARGET_FILE_DIR:novelty>/Resources
#)

if (WIN32)
    target_link_libraries(
            novelty ${CMAKE_SOURCE_DIR}/Libraries/libraylib.a
    )
    target_link_libraries(novelty winmm.lib)
endif (WIN32)

if(APPLE)
    target_link_libraries(novelty raylib)
endif()