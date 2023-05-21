set(HEADER_FILES
	Src/SkyUtility.h
	Src/SkyApp.h
	Src/GameWindow.h
	Src/WindowImplementation.h
	Src/GLFWCode/GLFWImplementation.h
	Src/Renderer.h
	Src/ImplRenderer.h
	Src/OpenGLCode/OpenGLRenderer.h
	Src/RendererTypes.h
	Src/Shader.h
	Src/ImplShader.h
	Src/OpenGLCode/OpenGLShader.h
	Src/Image.h
	Src/ImplImage.h
	Src/OpenGLCode/OpenGLImage.h
)

set(SOURCE_FILES
	Src/SkyApp.cpp
	Src/GameWindow.cpp
	Src/GLFWCode/GLFWImplementation.cpp
	Src/Shader.cpp
	Src/OpenGLCode/OpenGLShader.cpp
	Src/Renderer.cpp
	Src/OpenGLCode/OpenGLRenderer.cpp
	Src/Image.cpp
	Src/OpenGLCode/OpenGLShader.cpp
)

add_library(Sky SHARED ${HEADER_FILES} ${SOURCE_FILES})

include_directories(Src)
include_directories(../glad/include)
include_directories(../stbi)
include_directories(../glfw/include)

target_precompile_headers(Sky PRIVATE Src/pch.h)

target_link_libraries(Sky glfw glad stbi)

add_definitions(-DSKY_LIB)
add_definitions(-DSKY_GLFW)
add_definitions(-DSKY_OPENGL)
add_definitions(-DSKY_WINDOWS)
add_definitions(-DSKY_DEBUG=2)
