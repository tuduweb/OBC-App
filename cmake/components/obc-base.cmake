set(OBC_BASEDIR_COMPONENTS ${CMAKE_SOURCE_DIR}/src/components)
set(OBC_BASEDIR_CORE ${CMAKE_SOURCE_DIR}/src/core)
set(OBC_BASEDIR_BASE ${CMAKE_SOURCE_DIR}/src/base)

set(OBC_BASE_SOURCES
    #
    #${CMAKE_SOURCE_DIR}/src/utils/OBCHelpers.cpp
    #${CMAKE_SOURCE_DIR}/src/utils/OBCHelpers.hpp

    ${OBC_BASEDIR_BASE}/OBCBaseHeader.hpp

    ${CMAKE_SOURCE_DIR}/src/base/models/OBCSafeType.hpp
    ${CMAKE_SOURCE_DIR}/src/base/models/OBCIdentifier.hpp
    
    ${OBC_BASEDIR_CORE}/handler/ConfigHandler.cpp
    ${OBC_BASEDIR_CORE}/handler/ConfigHandler.hpp

    #plugin
    ${CMAKE_SOURCE_DIR}/src/plugin/PluginBase.hpp
    ${CMAKE_SOURCE_DIR}/src/plugin/PluginInterface.hpp
    ${CMAKE_SOURCE_DIR}/src/plugin/PluginInterface.cpp
    ${CMAKE_SOURCE_DIR}/src/plugin/PluginProcessor.hpp
    #plugin examples
    ${CMAKE_SOURCE_DIR}/src/plugin/examples/mock/kernel.hpp
    ${CMAKE_SOURCE_DIR}/src/plugin/examples/mock/kernel.cpp



    ## Links
    ${OBC_BASEDIR_CORE}/link/LinkInterface.cpp
    ${OBC_BASEDIR_CORE}/link/LinkInterface.hpp

    ${OBC_BASEDIR_CORE}/link/SerialLink.hpp
    ${OBC_BASEDIR_CORE}/link/SerialLink.hpp


    #end
)