#pragma once
#ifndef _ENGINE_HPP_
#define _ENGINE_HPP_

#include <vk_interface/vk.hpp>
#include <utils/utils.hpp>
#include "includes.hpp"

#define ENGINE_DEBUG_notifications_
#define ENGINE_DEBUG_info_
#define ENGINE_DEBUG_L1_
#define ENGINE_DEBUG_L2_
#define ENGINE_DEBUG_warnings_
#define ENGINE_DEBUG_errors_


class Engine {
	public:
		void start();
		void createWindow( const uint16_t width, const uint16_t height );
		void initVulkan();
		void mainLoop( const int tick_per_second );
		void end();

	private:
		GLFWwindow* window = nullptr;
		Vulkan vulkan;
		vk_param param;

		typedef std::chrono::milliseconds ms;

		uint16_t WIDTH = 1280;
		uint16_t HEIGHT = 720;

		bool createDirs();

};

#endif


