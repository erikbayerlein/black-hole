cmake_minimum_required(VERSION 3.10)
project(BlackHoleSimulator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(APPLE)
  set(CMAKE_OSX_ARCHITECTURES "arm64")
endif()

set(EIGEN3_INCLUDE_DIR "/opt/homebrew/include/eigen3")

find_package(glfw3 CONFIG REQUIRED)

add_executable(BlackHoleSimulator
  src/main.cpp
  src/engine/engine.cpp
  src/elements/ray/ray.cpp
)

target_include_directories(BlackHoleSimulator PRIVATE
  ${EIGEN3_INCLUDE_DIR}
  /opt/homebrew/include/GLFW
  /opt/homebrew/include/glm
)

if(APPLE)
  target_compile_definitions(BlackHoleSimulator PRIVATE GL_SILENCE_DEPRECATION)

  target_link_libraries(BlackHoleSimulator PRIVATE
    glfw
    "-framework OpenGL"
    "-framework Cocoa"
    "-framework IOKit"
    "-framework CoreVideo"
  )
else()
  find_package(OpenGL REQUIRED)
  target_link_libraries(BlackHoleSimulator PRIVATE glfw OpenGL::GL)
endif()
