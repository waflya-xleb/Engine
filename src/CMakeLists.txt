include ( ../base-kit.cmake )

set ( EXECUTABLE-NAME "program_v-${PROJECT_VERSION}" )

include_directories( ../lib )

add_executable( ${EXECUTABLE-NAME} main.cpp )

add_library( test SHARED test.c )

target_link_libraries( ${EXECUTABLE-NAME} PRIVATE vk::vkFramework test )


#message( STATUS "Project version: " ${${PROJECT}_VERSION} )
message ( "\n------------------------------\n" )
message ( "PROJECT NAME: ${PROJECT_NAME}\nPROJECT VERSION: ${PROJECT_VERSION}\nPROJECT DESCRIPTION: ${PROJECT_DESCRIPTION}\nPROJECT SUPPORTED LANGUAGES: ${supported_languages}\n" )
message ( "EXECUTABLE-NAME: ${EXECUTABLE-NAME}\nLIBS: vk::vkFramework\nSUB LIBS:\ntest SHARED test.c\n" )
message ( "------------------------------\n" )
