#pragma once
#ifndef _TEMPORARY_CPP_
#define _TEMPORARY_CPP_

#include <vk_interface/vk.hpp>
extern "C" {
#include "test.h"
}


//void TickFunction( const int tick_per_second, int(*fooPointer)( int a, int b ) );

//void wery_hard_math_function( su::Voxel vx[], const float g );

//void math_thread_function( su::Voxel voxels[], const int tick_per_second );

bool if_sum( const int a, const int b, int &return_value, su::warning_struct &warning_list );



//throw su::custom_exception( "just error", "the custom exception.", 25 );
//throw std::runtime_error("the error.");

//su::Voxel voxel[2] = { { 10, 10, 10 }, { -10, -10, -10 } };
//std::thread th_math( math_thread_function, std::ref(voxel), 40 );
//std::thread th_test([&]() { TickFunction(2, sum); });
//	th_math.join();
//	th_test.join();


		//int sum_result = 0;
		//if ( !if_sum( 30, 13, sum_result, warning_list ) ) {
		//	std::cout << sum_result << " <---sum_result\n";
		//} else {
		//	warning_list.warning.push_back( "function 'sum' in 'test' library failure. --- main.cpp" );
		//	std::cout << YELLOW << "warning: " << warning_list.warning.back() << "\n";
		//}
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
//	class Voxel {
//		public:
//			double xyz[3] = {0, 0, 0};
//		private:
//	};
//Voxel voxel;
//std::cout << sizeof(voxel) << " : voxel\n";
//std::cout << sizeof(Voxel) << " : Voxel\n";
// ============================ НЕ ОБРАЩАЙТЕ ВНИМАНИЕ ============================


#endif
