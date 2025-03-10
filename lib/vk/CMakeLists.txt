cmake_minimum_required ( VERSION 3.31.6 )

message ( "Starting compiling vk_interface..." )

set ( CMAKE_CXX_STANDARD 23 )

project( vk_interface
	VERSION 0.0.1
	LANGUAGES CXX )

find_package(Vulkan REQUIRED)
find_package(glfw3 3.4 REQUIRED)

include_directories( ../../lib )

add_library( ${PROJECT_NAME} SHARED run.cpp createInstance.cpp terminate.cpp vkUtils/vkUtils.cpp )
add_library( vk::vk_interface ALIAS ${PROJECT_NAME} )
target_link_libraries( ${PROJECT_NAME} PRIVATE Vulkan::Vulkan )
target_link_libraries( ${PROJECT_NAME} PUBLIC glfw utils::utils )
