include ( ../base-kit.cmake )

set ( EXECUTABLE-NAME "program_v-${${PROJECT}_VERSION}" )

find_package(Vulkan REQUIRED)
find_package(glfw3 3.4 REQUIRED)

#include_directories( lib_foo )
#include_directories( just_foo )

add_executable( ${EXECUTABLE-NAME} main.cpp utils/utils.cpp )

add_library( test STATIC test.c )

add_library( vk_interface STATIC vk/run.cpp vk/createInstance.cpp vk/terminate.cpp vk/utils/vkUtils.cpp )

target_link_libraries( ${EXECUTABLE-NAME} PRIVATE Vulkan::Vulkan glfw vk_interface test )


#message( STATUS "Project version: " ${${PROJECT}_VERSION} )
message ( "\n------------------------------\n" )
message ( "PROJECT NAME: Project_Engine\nPROJECT VERISON: ${ver}\nPROJECT SUPPORTED LANGUAGES: ${supported_languages}\n" )
message ( "EXECUTABLE-NAME: ${EXECUTABLE-NAME}\nLIBS: Vulkan::Vulkan, glfw\nCUSTOM LIBS:\ntest STATIC test.c\nvk_interface STATIC vk/run.cpp vk/createInstance.cpp vk/terminate.cpp vk/utils/vkUtils.cpp\n" )
message ( "------------------------------\n" )
