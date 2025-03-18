#pragma once
#ifndef _SU_TERMINAL_
#define _SU_TERMINAL_

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>
#include <chrono>
#include <ctime>
#include <thread>

#define UNDERLINE "\033[4m"// подчёркивание
#define DOUBLE_UNDERLINE "\033[21m"// двойное подчёркивание
#define LINE_THROUGH "\033[9m"// перечёркнутый
#define ITALIC "\033[3m"// курсив

#define RESET "\033[0m"// сбросить цвет
#define GRAY "\033[2m"// серый текст
#define BLACK "\033[30m"// чёрный текст
#define RED "\033[31m"// красный текст
#define GREEN "\033[32m"// зелёный текст
#define YELLOW "\033[33m"// желтый текст
#define BLUE "\033[34m"// голубой текст
#define MAGNETA "\033[35m"// фиолетовый текст
#define CYAN "\033[36m"// светло-голубой текст

#define BLACK_BG "\033[40m"// чёрный фон текста
#define RED_BG "\033[41m"// красный фон текста
#define GREEN_BG "\033[42m"// зелёный фон текста
#define YELLOW_BG "\033[43m"// желтый фон текста
#define BLUE_BG "\033[44m"// голубой фон текста
#define MAGNETA_BG "\033[45m"// фиолетовый фон текста
#define CYAN_BG "\033[46m"// светло-голубой фон текста
#define WHITE_BG "\033[47m"// белый фон текста
#define WHITE_BG2 "\033[7m"// точно такой-же белый фон текста

namespace su {
	void terminal();
}


#endif
