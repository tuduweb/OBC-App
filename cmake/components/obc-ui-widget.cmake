set(OBC_WIDGETS_UI_BASEDIR ${CMAKE_SOURCE_DIR}/src/ui/widgets)
add_definitions(-DQAPPLICATION_CLASS=QApplication)

set(_OBC_UI_FORMS
    #
    ${OBC_WIDGETS_UI_BASEDIR}/windows/w_MainWindow.ui
)

set(_OBC_UI_SOURCES
    ${OBC_WIDGETS_UI_BASEDIR}/windows/w_MainWindow.hpp
    ${OBC_WIDGETS_UI_BASEDIR}/windows/w_MainWindow.cpp
)

set(OBC_UI_WIDGET_SOURCES ${_OBC_UI_FORMS} ${_OBC_UI_SOURCES})
