#pragma once
#ifndef _ENGINE_HPP_
#define _ENGINE_HPP_

#include <vk_interface/vk.hpp>
#include "includes.hpp"

#define ENGINE_DEBUG_notifications_
#define ENGINE_DEBUG_info_
#define ENGINE_DEBUG_L1_
#define ENGINE_DEBUG_L2_


class Engine {
	public:
		void start();
		void createWindow( const uint16_t width, const uint16_t height );
		void initVulkan();
		void mainLoop();
		void end();

	private:
		GLFWwindow* window = nullptr;
		Vulkan vulkan;
		vk_param param;
		uint16_t WIDTH = 1280;
		uint16_t HEIGHT = 720;

};

#endif


