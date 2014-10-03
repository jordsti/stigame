cmake_minimum_required(VERSION 2.8)
project(StiGameRoot)

set(STIGAME_VERSION "0.0.1")
set(BUILD_NUMBER 28)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -DDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O2 -DRELEASE")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

include_directories(include/SDL2)

if(WIN32)
find_library(SDL2 NAMES "SDL2" PATHS ${PROJECT_SOURCE_DIR}/lib/)
find_library(SDL2_image NAMES "SDL2_image" PATHS ${PROJECT_SOURCE_DIR}/lib/)
find_library(SDL2_gfx NAMES "SDL2_gfx" PATHS ${PROJECT_SOURCE_DIR}/lib/)
find_library(SDL2_ttf NAMES "SDL2_ttf" PATHS ${PROJECT_SOURCE_DIR}/lib/)
find_library(SDL2_net NAMES "SDL2_net" PATHS ${PROJECT_SOURCE_DIR}/lib/)
find_library(SDL2main NAMES "SDL2main" PATHS ${PROJECT_SOURCE_DIR}/lib/)
endif(WIN32)

set(INSTALL_DIR "${PROJECT_SOURCE_DIR}/build/${STIGAME_VERSION}-${BUILD_NUMBER}/${CMAKE_BUILD_TYPE}/")

add_subdirectory(StiGame)

include_directories(StiGame)


add_subdirectory(Sample)

add_subdirectory(GuiTest)

if(WIN32)
    get_filename_component(MINGW32_ROOT ${CMAKE_CXX_COMPILER} DIRECTORY)
    install(DIRECTORY bin/ DESTINATION ${INSTALL_DIR} FILES_MATCHING PATTERN "*.dll")
    install(FILES "${MINGW32_ROOT}/libstdc++-6.dll" DESTINATION ${INSTALL_DIR})
endif(WIN32)

install(DIRECTORY assets DESTINATION ${INSTALL_DIR} CONFIGURATIONS Release FILES_MATCHING PATTERN "*.*")



