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
    #end
)