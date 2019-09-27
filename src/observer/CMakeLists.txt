include_directories("${CMAKE_SOURCE_DIR}/src/observer")

target_sources(chess PRIVATE src/observer/observable.cpp)