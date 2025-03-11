#pragma once
#ifndef _SU_TERMINAL_
#define _SU_TERMINAL_

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include<unistd.h>

#include "colors.hpp"
#include "integrated_cxx_libs.hpp"

namespace su {
	enum command_list {
		ls,
		clear,
		cd,
		_mkdir,
		_rmdir,
		userName,
		_exit_cli,
		unknown
	};
	command_list switch_str (std::string const& input_string);
	void terminal();
}


#endif
