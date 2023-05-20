set(HEADER_FILES
	Src/SkyUtility.h
	Src/SkyApp.h
	Src/GameWindow.h
	Src/WindowImplementation.h
	Src/GLFWCode/GLFWImplementation.h
)

set(SOURCE_FILES
	Src/SkyApp.cpp
	Src/GameWindow.cpp
	Src/GLFWCode/GLFWImplementation.cpp
)

add_library(Sky SHARED ${HEADER_FILES} ${SOURCE_FILES})

include_directories(Src)

target_precompile_headers(Sky PRIVATE Src/pch.h)

target_link_libraries(Sky glfw)

add_definitions(-DSKY_LIB)
add_definitions(-DSKY_GLFW)
