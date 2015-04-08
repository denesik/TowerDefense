TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

VERSION = 0.1.0

win32:INCLUDEPATH += $$PWD/../../libs/glew/
win32:INCLUDEPATH += $$PWD/../../libs/glfw/
win32:INCLUDEPATH += $$PWD/../../libs/glm/

unix:LIBS += -lglfw3 -lGL -lGLEW
unix:LIBS += -lm -lXrandr -lXi -lX11 -lXxf86vm -lpthread -lXinerama -lXcursor

#win32:LIBS += -L$$PWD/../../libs/lib/ -glew32

#win32:CONFIG(debug, debug|release):LIBS += -L$$PWD/../../libs/lib/ -glfw3d
#win32:CONFIG(release, debug|release):LIBS += -L$$PWD/../../libs/lib/ -glfw3


SOURCES += main.cpp \
    Game.cpp \
    Graphic/Window/KeyboardGLFW.cpp \
    Graphic/Window/WindowGL.cpp \
    Graphic/Render/BaseMesh.cpp \
    Graphic/Render/Bitmap.cpp \
    Graphic/Render/BoxMesh.cpp \
    Graphic/Render/CameraPersp.cpp \
    Graphic/Render/Color.cpp \
    Graphic/Render/Model.cpp \
    Graphic/Render/Render.cpp \
    Graphic/Render/RenderErrorChecker.cpp \
    Graphic/Render/Shader.cpp \
    Graphic/Render/ShaderBinder.cpp \
    Graphic/Render/SimpleMaterial.cpp \
    Graphic/Render/Texture.cpp \
    Graphic/Render/TextureManager.cpp \
    Graphic/Render/Vertex.cpp \
    lodepng/lodepng.cpp


HEADERS += \
    Game.h \
    Graphic/Window/ConvertKeyGlfw.h \
    Graphic/Window/IKeyboard.h \
    Graphic/Window/IWindow.h \
    Graphic/Window/KeyboardGLFW.h \
    Graphic/Window/Keys.h \
    Graphic/Window/WindowGL.h \
    Graphic/Render/BaseMesh.h \
    Graphic/Render/Bitmap.h \
    Graphic/Render/BoxMesh.h \
    Graphic/Render/CameraPersp.h \
    Graphic/Render/Color.h \
    Graphic/Render/ICamera.h \
    Graphic/Render/IMaterial.h \
    Graphic/Render/Model.h \
    Graphic/Render/Render.h \
    Graphic/Render/RenderErrorChecker.h \
    Graphic/Render/Shader.h \
    Graphic/Render/ShaderBinder.h \
    Graphic/Render/SimpleMaterial.h \
    Graphic/Render/Texture.h \
    Graphic/Render/TextureManager.h \
    Graphic/Render/Vertex.h \
    lodepng/lodepng.h

