include_directories("${CMAKE_SOURCE_DIR}/src/logger")

target_sources(chess PRIVATE src/logger/logger.cpp)