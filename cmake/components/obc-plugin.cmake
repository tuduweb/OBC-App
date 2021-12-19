set(OBC_PLUGINDIR ${CMAKE_SOURCE_DIR}/src/plugin)

set(OBC_PLUGIN_SOURCES
    ${OBC_PLUGINDIR}/PluginBase.hpp
    ${OBC_PLUGINDIR}/PluginProcessor.hpp
    ${OBC_PLUGINDIR}/PluginInterface.hpp
    ${OBC_PLUGINDIR}/PluginInterface.cpp
    ${OBC_PLUGINDIR}/GUIPluginInterface.hpp


    # mock examples linkin
    ${OBC_PLUGINDIR}/examples/mock/MockKernel.hpp
    ${OBC_PLUGINDIR}/examples/mock/MockKernel.cpp

    ${OBC_PLUGINDIR}/examples/mock/MockPlugin.hpp
    ${OBC_PLUGINDIR}/examples/mock/MockPlugin.cpp

    ${OBC_PLUGINDIR}/examples/mock/MockGUI.hpp
    ${OBC_PLUGINDIR}/examples/mock/MockGUI.cpp
)