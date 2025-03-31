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
		void createWindow();
		void initVulkan();
		void mainLoop();
		void end();

	private:
		GLFWwindow* window;
		Vulkan vulkan;
		vk_param param;
		int a = 24;

};

#endif


