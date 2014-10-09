cmake_minimum_required(VERSION 2.8)
project(StiGameRoot)

set(STIGAME_MAJOR 0)
set(STIGAME_MINOR 0)
set(STIGAME_RELEASE 1)
set(STIGAME_BUILD 2)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -DDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O2 -DRELEASE")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

if(WIN32)
    set(SDL2_LIBS "${PROJECT_SOURCE_DIR}/lib/")
    set(SDL2_INCLUDE "include/SDL2")
elseif(UNIX)
    set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
    set(SDL2_LIBS "/usr/lib/")
    set(SDL2_INCLUDE "/usr/include/SDL2")
endif(WIN32)

if(TRAVIS_BUILD)
	#sdl2_gfx headers
	include_directories(${PROJECT_SOURCE_DIR}/SDL2_gfx-1.0.1)
endif(TRAVIS_BUILD)

include_directories(${SDL2_INCLUDE})


find_library(SDL2 NAMES "SDL2" PATHS ${SDL2_LIBS})
find_library(SDL2_image NAMES "SDL2_image" PATHS ${SDL2_LIBS})
find_library(SDL2_gfx NAMES "SDL2_gfx" PATHS ${SDL2_LIBS})
find_library(SDL2_ttf NAMES "SDL2_ttf" PATHS ${SDL2_LIBS})
find_library(SDL2_net NAMES "SDL2_net" PATHS ${SDL2_LIBS})
find_library(SDL2main NAMES "SDL2main" PATHS ${SDL2_LIBS})


set(INSTALL_DIR "${PROJECT_SOURCE_DIR}/build/${STIGAME_MAJOR}.${STIGAME_MINOR}.${STIGAME_RELEASE}.${STIGAME_BUILD}/${CMAKE_BUILD_TYPE}/")

add_subdirectory(StiGame)

include_directories(StiGame)


add_subdirectory(Sample)

add_subdirectory(GuiTest)

if(WIN32)
    #need some dll
    get_filename_component(MINGW32_ROOT ${CMAKE_CXX_COMPILER} DIRECTORY)
    install(DIRECTORY bin/ DESTINATION ${INSTALL_DIR} FILES_MATCHING PATTERN "*.dll")
    install(FILES "${MINGW32_ROOT}/libstdc++-6.dll" DESTINATION ${INSTALL_DIR})
endif(WIN32)

install(DIRECTORY assets DESTINATION ${INSTALL_DIR} CONFIGURATIONS Release FILES_MATCHING PATTERN "*.*")



