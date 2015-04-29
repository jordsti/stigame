cmake_minimum_required(VERSION 2.8.4)
project(StiGame)

set(SOURCE_FILES
    core/Angle.cpp
    core/BaseGameState.cpp
    core/Color.cpp
    core/ColorIndex.cpp
    core/Computer.cpp
    core/Controller.cpp
    core/Cursor.cpp
    core/Dimension.cpp
    core/DimensionF.cpp
    core/Font.cpp
    core/Logger.cpp
    core/MathTK.cpp
    core/Matrix.cpp
    core/MDimension.cpp
    core/MDimensionF.cpp
    core/MPoint.cpp
    core/MPointF.cpp
    core/MultiRect.cpp

    core/Pixel.cpp
    core/Point.cpp
    core/PointF.cpp
    core/Rectangle.cpp
    core/ResourceFile.cpp
    core/StringRenderer.cpp
    core/Surface.cpp
    core/TextLogger.cpp
    core/Texture.cpp
    core/TimeTools.cpp
    core/VarFile.cpp

    core/Vector2.cpp
    core/MVector2.cpp
    core/Vector2F.cpp
    core/MVector2F.cpp
    core/VideoConfig.cpp
    core/Viewport.cpp
    core/ViewportArea.cpp
    core/Window.cpp
    core/SGString.cpp

    bindings/ActionBind.cpp
    bindings/ActionBinding.cpp
    bindings/ActionMap.cpp
    bindings/BaseGameAction.cpp
    bindings/CompActionMap.cpp
    bindings/MouseActionMap.cpp
    bindings/OverlayGameAction.cpp
    bindings/TimedGameAction.cpp
    bindings/KeyActionMap.cpp
    bindings/KeyBind.cpp

    gui/FrameFile.cpp
    gui/Button.cpp
    gui/CheckBox.cpp
    gui/Clipboard.cpp
    gui/ComboBox.cpp
    gui/DecoratedButton.cpp
    gui/GuiState.cpp
    gui/GuiFrameState.cpp
    gui/HighlightItem.cpp
    gui/HorizontalBoxLayout.cpp
    gui/Image.cpp
    gui/ImageButton.cpp
    gui/Item.cpp
    gui/ItemContainer.cpp
    gui/ItemNode.cpp
    gui/ItemIterator.cpp
    gui/Label.cpp
    gui/Layout.cpp
    gui/List.cpp
    gui/MessageBox.cpp
    gui/MStyle.cpp
    gui/OverlayFrame.cpp
    gui/OverlayMenu.cpp
    gui/ProgressBar.cpp
    gui/RadioButton.cpp
    gui/RadioGroup.cpp
    gui/Runtime.cpp
    gui/Spacer.cpp
    gui/Style.cpp
    gui/TabItem.cpp
    gui/Table.cpp
    gui/TableCell.cpp
    gui/TableRow.cpp
    gui/TabPanel.cpp
    gui/TextBox.cpp
    gui/ValueObject.cpp
    gui/VerticalBoxLayout.cpp
    gui/ChildSupport.cpp
    gui/BaseChildSupport.cpp
    gui/ItemEquation.cpp
    gui/ItemAttribute.cpp
    gui/ItemDefinition.cpp
    gui/ItemCreatorChain.cpp
    gui/StartingCreator.cpp

    gui/effects/ItemEffect.cpp
    gui/effects/MovingItem.cpp
    gui/effects/ExpandItem.cpp

    events/CheckEventArgs.cpp
    events/CheckEventListener.cpp
    events/CheckEventThrower.cpp
    events/ControllerAxisEventArgs.cpp
    events/ControllerAxisEventListener.cpp
    events/ControllerAxisEventThrower.cpp
    events/ControllerButtonEventArgs.cpp
    events/ControllerButtonEventListener.cpp
    events/ControllerButtonEventThrower.cpp
    events/ControllerDeviceEventArgs.cpp
    events/ControllerDeviceEventListener.cpp
    events/ControllerDeviceEventThrower.cpp
    events/EventArgs.cpp
    events/EventListener.cpp
    events/EventThrower.cpp
    events/KeyEventArgs.cpp
    events/KeyEventListener.cpp
    events/KeyEventThrower.cpp
    events/MouseButtonEventArgs.cpp
    events/MouseButtonEventListener.cpp
    events/MouseButtonEventThrower.cpp
    events/MouseMotionEventArgs.cpp
    events/MouseMotionEventListener.cpp
    events/MouseMotionEventThrower.cpp
    events/MouseWheelEventArgs.cpp
    events/MouseWheelEventListener.cpp
    events/MouseWheelEventThrower.cpp
    events/SelectionEventArgs.cpp
    events/SelectionEventListener.cpp
    events/SelectionEventThrower.cpp
    events/WindowEventArgs.cpp
    events/WindowEventListener.cpp
    events/WindowEventThrower.cpp

    files/Entry.cpp
    files/Directory.cpp
    files/File.cpp
    files/FileSystem.cpp

    sprites/ClonedDirectionSprite.cpp
    sprites/ClonedSprite.cpp
    sprites/DirectionSprite.cpp
    sprites/DirectionSpriteLibrary.cpp
    sprites/DirectionSpriteFile.cpp
    sprites/DirectionSpriteFileCreator.cpp
    sprites/IDirectionSprite.cpp
    sprites/ISprite.cpp
    sprites/Sprite.cpp
    sprites/SpriteFile.cpp
    sprites/SpriteFileCreator.cpp
    sprites/SpriteLibrary.cpp

    network/PacketBuffer.cpp
    network/TcpSocket.cpp
    network/UdpSocket.cpp

    primitives/PCircle.cpp
    primitives/PEllipse.cpp
    primitives/PLine.cpp
    primitives/PRect.cpp
    primitives/Primitive.cpp

    GamePath.cpp
    StiGameVersion.cpp
)

include_directories(".")
include_directories(core)
include_directories(bindings)
include_directories(events)
include_directories(files)
include_directories(gui)
include_directories(events)
include_directories(primitives)
include_directories(network)
include_directories(sprites)

if(NOT STIGAME_STATIC)
    if(WIN32)
        set(CMAKE_SHARED_LINKER_FLAGS "-Wl,--export-all-symbols")
    endif(WIN32)
endif(NOT STIGAME_STATIC)

configure_file(StiGameVersion.cpp.in ${PROJECT_SOURCE_DIR}/StiGameVersion.cpp)

if(STIGAME_STATIC)
    add_library(StiGame STATIC ${SOURCE_FILES})
else(STIGAME_STATIC)
    add_library(StiGame SHARED ${SOURCE_FILES})
endif(STIGAME_STATIC)

target_link_libraries(StiGame ${SDL2} ${SDL2_image} ${SDL2_ttf} ${SDL2_net} ${SDL2_gfx})

install(TARGETS StiGame LIBRARY DESTINATION ${INSTALL_DIR} RUNTIME DESTINATION ${INSTALL_DIR} ARCHIVE DESTINATION ${INSTALL_DIR} COMPONENT library)
install(DIRECTORY "${PROJECT_SOURCE_DIR}/" DESTINATION "${INSTALL_DIR}/include" FILES_MATCHING PATTERN "*.h")

