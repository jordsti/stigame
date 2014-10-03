project(Sample)
cmake_minimum_required(VERSION 2.8)

set(SOURCE_FILES main.cpp
                 SampleState.cpp
)


add_executable(${PROJECT_NAME} ${SOURCE_FILES})


target_link_libraries(${PROJECT_NAME} mingw32 ${SDL2main} ${SDL2} ${SDL2_image} ${SDL2_ttf} ${SDL2_net} ${SDL2_gfx} StiGame)


install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION ${INSTALL_DIR})
