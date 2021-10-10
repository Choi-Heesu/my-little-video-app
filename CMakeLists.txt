cmake_minimum_required(VERSION 3.14)
project(my-little-video-app C CXX)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_BUILD_TYPE Debug)

add_subdirectory(lib/glfw)
add_subdirectory(lib/ffmpeg)

add_definitions(-DGL_SILENCE_DEPRECATION)

if(APPLE)
  list(APPEND EXTRA_LIBS
    "-framework OpenGL"
  )
elseif(WIN32)
  list(APPEND EXTRA_LIBS
    "-lglu32 -lopengl32"    
  )
  set(CMAKE_EXE_LINKER_FLAGS "-std=gnu99 -static -static-libgcc -static-liibstdc++ -mwindows")
else()
  list(APPEND EXTRA_LIBS
    "-lGL -lGLU -lX11"    
  )
endif()

list(APPEND SOURCES
  src/main.cpp
  src/load_frame.cpp
)

add_executable(my-little-video-app ${SOURCES})
target_link_libraries(my-little-video-app FFmpeg glfw ${EXTRA_LIBS})