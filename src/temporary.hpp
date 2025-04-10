#pragma once
#ifndef _TEMPORARY_CPP_
#define _TEMPORARY_CPP_

#include "engine/engine.hpp"
extern "C" {
#include "test.h"
}


//void TickFunction( const int tick_per_second, int(*fooPointer)( int a, int b ) );

//void wery_hard_math_function( su::Voxel vx[], const float g );

//void math_thread_function( su::Voxel voxels[], const int tick_per_second );

bool if_sum( const int a, const int b, int &return_value, su::warning_struct &warning_list );

//void print_foo( const std::string str );

//su::Voxel voxel[2] = { { 10, 10, 10 }, { -10, -10, -10 } };
//std::thread th_math( math_thread_function, std::ref(voxel), 40 );
//std::thread th_test([&]() { TickFunction(2, sum); });
//	th_math.join();
//	th_test.join();

// ============================ НЕ ОБРАЩАЙТЕ ВНИМАНИЕ ============================
//class Voxel2 {
//	public:
//		int xyz[3] = {0, 0, 0};
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
//class Voxel {
//	public:
//		int xyz[3] = {0, 0, 0};
//		float scale = 1.0f;
//
//		uint8_t rgb[3] = {40, 40, 40};
//		float alpha = 1.0;
//		uint8_t glow = 0;
//
//		int material_index = 0;
//		//uint16_t chunk_index = 0;
//	private:
//};
//struct Material_Water {
//	uint16_t durability = 65000;
//	uint8_t bondability = 40;
//	bool stationary = false;
//
//	uint16_t temperature = 20;
//	uint8_t gravity = 0;
//	uint8_t mass = 1;
//	uint8_t density = 1;
//};
//struct Material_List {
//	Material_Water water;
//};
// ============================ НЕ ОБРАЩАЙТЕ ВНИМАНИЕ ============================


#endif
