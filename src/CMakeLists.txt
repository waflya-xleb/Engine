include ( ../base-kit.cmake )

set ( EXECUTABLE-NAME "program_v-${PROJECT_VERSION}" )

#include_directories( ../lib )
include_directories( ../../../ )

add_executable( ${EXECUTABLE-NAME} main.cpp engine/engine.cpp engine/window/createWindow.cpp temporary.cpp )

add_library( test SHARED test.c )

target_link_libraries( ${EXECUTABLE-NAME} PRIVATE vk::vk_interface test )


#message( STATUS "Project version: " ${${PROJECT}_VERSION} )
message ( "\n------------------------------\n" )
message ( "PROJECT NAME: ${PROJECT_NAME}\nPROJECT VERSION: ${PROJECT_VERSION}\nPROJECT DESCRIPTION: ${PROJECT_DESCRIPTION}\nPROJECT SUPPORTED LANGUAGES: ${supported_languages}\n" )
message ( "EXECUTABLE-NAME: ${EXECUTABLE-NAME}\nLIBS: vk::vk_interface\nSUB LIBS:\ntest SHARED test.c\n" )
message ( "------------------------------\n" )
