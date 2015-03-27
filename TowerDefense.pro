TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

VERSION = 0.1.0

unix:LIBS += -lglfw3 -lGL -lGLEW
unix:LIBS += -lm -lXrandr -lXi -lX11 -lXxf86vm -lpthread -lXinerama -lXcursor


SOURCES += main.cpp \
    Game.cpp \
    Window.cpp \
    Texture.cpp \
    Bitmap.cpp \
    lodepng/lodepng.cpp \
    Color.cpp \
    Render.cpp \
    RenderErrorChecker.cpp \
    SpriteQuad.cpp \
    TextureManager.cpp \
    BaseSprite.cpp

HEADERS += \
    Game.h \
    Window.h \
    Texture.h \
    Bitmap.h \
    lodepng/lodepng.h \
    Color.h \
    Render.h \
    RenderErrorChecker.h \
    SpriteQuad.h \
    TextureManager.h \
    Vertex.h \
    BaseSprite.h
