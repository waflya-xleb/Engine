include ( ../base-kit.cmake )

set ( EXECUTABLE-NAME "program_v-${PROJECT_VERSION}" )

set ( vk_lib_path ../lib/vk )

find_package(Vulkan REQUIRED)
find_package(glfw3 3.4 REQUIRED)

include_directories( ../lib )
include_directories( ../src )
#include_directories( just_foo )

add_executable( ${EXECUTABLE-NAME} main.cpp utils/utils.cpp )

add_library( test SHARED test.c )

add_library( vk_interface SHARED ${vk_lib_path}/run.cpp ${vk_lib_path}/createInstance.cpp ${vk_lib_path}/terminate.cpp ${vk_lib_path}/utils/vkUtils.cpp )
add_library( vk::vk_interface ALIAS vk_interface )
target_link_libraries( vk_interface PRIVATE Vulkan::Vulkan )
target_link_libraries( vk_interface PUBLIC glfw )

target_link_libraries( ${EXECUTABLE-NAME} PRIVATE vk::vk_interface test )


#message( STATUS "Project version: " ${${PROJECT}_VERSION} )
message ( "\n------------------------------\n" )
message ( "PROJECT NAME: ${PROJECT_NAME}\nPROJECT VERSION: ${PROJECT_VERSION}\nPROJECT DESCRIPTION: ${PROJECT_DESCRIPTION}\nPROJECT SUPPORTED LANGUAGES: ${supported_languages}\n" )
message ( "EXECUTABLE-NAME: ${EXECUTABLE-NAME}\nLIBS: Vulkan::Vulkan, glfw\nCUSTOM LIBS:\ntest SHARED test.c\nvk::vk_interface SHARED vk/run.cpp vk/createInstance.cpp vk/terminate.cpp vk/utils/vkUtils.cpp\n" )
message ( "------------------------------\n" )
