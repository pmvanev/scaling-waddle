include_directories("${CMAKE_SOURCE_DIR}/src/model")

target_sources(chess PRIVATE src/model/board.cpp)
target_sources(chess PRIVATE src/model/piece.cpp)
target_sources(chess PRIVATE src/model/space.cpp)

