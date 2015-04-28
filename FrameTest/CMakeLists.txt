project(FrameTest)
cmake_minimum_required(VERSION 2.8)

set(SOURCE_FILES main.cpp
        Frame.cpp
        CustomItem.cpp
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

if(WIN32)
    target_link_libraries(${PROJECT_NAME} mingw32 ${SDL2main} ${SDL2} ${SDL2_image} ${SDL2_ttf} ${SDL2_net} ${SDL2_gfx} StiGame)
elseif(UNIX)
    target_link_libraries(${PROJECT_NAME} ${SDL2main} ${SDL2} ${SDL2_image} ${SDL2_ttf} ${SDL2_net} ${SDL2_gfx} StiGame)
endif(WIN32)

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION ${INSTALL_DIR})
