include_directories("${CMAKE_SOURCE_DIR}/src/view")

target_sources(chess PRIVATE src/view/terminal_view.cpp)