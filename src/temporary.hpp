#pragma once
#ifndef _TEMPORARY_CPP_
#define _TEMPORARY_CPP_

#include <vk_interface/vk.hpp>


void TickFunction( const int tick_per_second, void(*fooPointer)( int a, int b ) );

void wery_hard_math_function( su::Voxel vx[], const float g );

void math_thread_function( su::Voxel voxels[], const int tick_per_second );

// ============================ НЕ ОБРАЩАЙТЕ ВНИМАНИЕ ============================
//class Voxel2 {
//	public:
//		double xyz[3] = {0, 0, 0};
//		float rotate[3] = {0, 0, 0};
//		float scale = 1.0f;
//
//		uint8_t rgb[3] = {40, 40, 40};
//		float alpha = 1.0;
//		uint8_t glow = 0;
//
//		uint16_t durability = 65000;
//		uint8_t bondability = 0;
//		bool stationary = false;
//
//		uint16_t temperature = 0;
//		uint8_t gravity = 255;
//		uint8_t mass = 1;
//		uint8_t density = 1;
//		uint8_t id = 0;
//
//		//uint16_t chunk_index = 0;
//	private:
//};
//Voxel voxel;
//std::cout << sizeof(voxel) << " : voxel\n";
//std::cout << sizeof(Voxel) << " : Voxel\n";
// ============================ НЕ ОБРАЩАЙТЕ ВНИМАНИЕ ============================


#endif
