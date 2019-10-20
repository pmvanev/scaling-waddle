# add_subdirectory(controller)
add_subdirectory(logger)
add_subdirectory(model)
add_subdirectory(observer)
add_subdirectory(view)

include_directories(logger model observer view)