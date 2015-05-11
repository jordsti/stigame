cmake_minimum_required(VERSION 2.8)
project(StiGameRoot)

set(STIGAME_MAJOR 0)
set(STIGAME_MINOR 0)
set(STIGAME_RELEASE 3)

if(NOT STIGAME_BUILD)
    set(STIGAME_BUILD 0)
endif(NOT STIGAME_BUILD)

set(STIGAME_NAME "")

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -DDEBUG -DFUTURE")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O2 -DRELEASE")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

if(NOT SDL2_LIBS)
	if(WIN32)
		set(SDL2_LIBS "${PROJECT_SOURCE_DIR}/lib/")
	elseif(UNIX)
		set(SDL2_LIBS "/usr/lib/")
	endif(WIN32)
endif(NOT SDL2_LIBS)

if(NOT SDL2_INCLUDE)
	if(WIN32)
		set(SDL2_INCLUDE "include/SDL2")
	elseif(UNIX)
		set(SDL2_INCLUDE "/usr/include/SDL2")
	endif(WIN32)
endif(NOT SDL2_INCLUDE)

if(TRAVIS_BUILD)
	#sdl2_gfx headers
	include_directories(${PROJECT_SOURCE_DIR}/SDL2_gfx-1.0.1)
endif(TRAVIS_BUILD)

if(SDL2_GFX_PATH)
	include_directories(${SDL2_GFX_PATH})
endif(SDL2_GFX_PATH)

include_directories(${SDL2_INCLUDE})


find_library(SDL2 NAMES "SDL2" PATHS ${SDL2_LIBS})
find_library(SDL2_image NAMES "SDL2_image" PATHS ${SDL2_LIBS})
find_library(SDL2_gfx NAMES "SDL2_gfx" PATHS ${SDL2_LIBS})
find_library(SDL2_ttf NAMES "SDL2_ttf" PATHS ${SDL2_LIBS})
find_library(SDL2_net NAMES "SDL2_net" PATHS ${SDL2_LIBS})
find_library(SDL2main NAMES "SDL2main" PATHS ${SDL2_LIBS})

if("${STIGAME_NAME}" STREQUAL "")
    set(INSTALL_DIR "${PROJECT_SOURCE_DIR}/build/${CMAKE_BUILD_TYPE}/${STIGAME_MAJOR}.${STIGAME_MINOR}.${STIGAME_RELEASE}.${STIGAME_BUILD}")
else("${STIGAME_NAME}" STREQUAL "")
    set(INSTALL_DIR "${PROJECT_SOURCE_DIR}/build/${CMAKE_BUILD_TYPE}/${STIGAME_MAJOR}.${STIGAME_MINOR}.${STIGAME_RELEASE}.${STIGAME_BUILD}-${STIGAME_NAME}")
endif("${STIGAME_NAME}" STREQUAL "")

add_subdirectory(StiGame)

include_directories(StiGame)

include_directories(StiGame/core)
include_directories(StiGame/bindings)
include_directories(StiGame/events)
include_directories(StiGame/gui)
include_directories(StiGame/gui/effects)
include_directories(StiGame/events)
include_directories(StiGame/files)
include_directories(StiGame/primitives)
include_directories(StiGame/network)
include_directories(StiGame/sprites)

add_subdirectory(Sample)

add_subdirectory(GuiTest)

add_subdirectory(FrameTest)

add_subdirectory(sgrc)

add_subdirectory(NetMessage)

add_subdirectory(TableTest)

if(WIN32)
    #need some dll
    get_filename_component(MINGW32_ROOT ${CMAKE_CXX_COMPILER} DIRECTORY)
    install(DIRECTORY "${PROJECT_SOURCE_DIR}/bin/" DESTINATION ${INSTALL_DIR} FILES_MATCHING PATTERN "*.dll")
    install(DIRECTORY "${MINGW32_ROOT}/" DESTINATION ${INSTALL_DIR} FILES_MATCHING PATTERN "libgcc*.dll")
    install(DIRECTORY "${MINGW32_ROOT}/" DESTINATION ${INSTALL_DIR} FILES_MATCHING PATTERN "libwinpthread*.dll")
    install(FILES "${MINGW32_ROOT}/libstdc++-6.dll" DESTINATION ${INSTALL_DIR})
endif(WIN32)

install(DIRECTORY assets DESTINATION ${INSTALL_DIR} CONFIGURATIONS Release FILES_MATCHING PATTERN "*.*")



