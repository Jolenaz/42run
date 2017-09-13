cmake_minimum_required(VERSION 3.5)
project(42run)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++14")

find_package(OpenGL REQUIRED)
find_package(SDL2 REQUIRED)

include_directories(third-party/glad/include)
include_directories(${SDL2_INCLUDE_DIRS})
include_directories(${OPENGL_INCLUDE_DIR})
include_directories(Classes)
include_directories(Classes/Math)
include_directories(Classes/Render)
include_directories(include)

SET(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

set(SOURCE_FILES
	src/main.cpp
	Classes/Math/Vec2.class.cpp
	Classes/Math/Vec3.class.cpp
	Classes/Math/Vec4.class.cpp
	Classes/Math/Mat2.class.cpp
	Classes/Math/Mat3.class.cpp
	Classes/Math/Mat4.class.cpp
	Classes/Render/Camera.class.cpp
	Classes/Transform.class.cpp
	)

add_executable(42run ${SOURCE_FILES})

target_link_libraries(42run ${CMAKE_DL_LIBS})
target_link_libraries(42run ${SDL2_LIBRARIES})
target_link_libraries(42run ${OPENGL_LIBRARIES})
