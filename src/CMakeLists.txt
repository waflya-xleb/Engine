set ( "${PROJECT}_VERSION_GENERATION" 0 )
set ( "${PROJECT}_VERSION_BRANCH" 0 )
set ( "${PROJECT}_VERSION_RELEASE" 0 )
set ( "${PROJECT}_VERSION_BETA" 1 )
set ( "${PROJECT}_VERSION" ${${PROJECT}_VERSION_GENERATION}.${${PROJECT}_VERSION_BRANCH}.${${PROJECT}_VERSION_RELEASE}.${${PROJECT}_VERSION_BETA} )

message( STATUS "Project version: " ${${PROJECT}_VERSION} )

set ( EXECUTABLE-NAME "program_v-${${PROJECT}_VERSION}" )

find_package(Vulkan REQUIRED)
find_package(glfw3 3.4 REQUIRED)

#include_directories( lib_foo )
#include_directories( just_foo )

add_executable( ${EXECUTABLE-NAME} main.cpp utils/utils.cpp )

add_library( vk_interface STATIC vk/run.cpp vk/createInstance.cpp vk/terminate.cpp vk/utils/vkUtils.cpp )

target_link_libraries( ${EXECUTABLE-NAME} PRIVATE Vulkan::Vulkan glfw vk_interface )
