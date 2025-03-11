#pragma once
#ifndef _COLORS_
#define _COLORS_

/* FOREGROUND */

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGNETA "\033[35m"
#define CYAN "\033[36m"

#define RST  "\x1B[0m"

#define KRED  "\x1B[31m"

#define KGRN  "\x1B[32m"

#define KYEL  "\x1B[33m"

#define KBLU  "\x1B[34m"

#define KMAG  "\x1B[35m"

#define KCYN  "\x1B[36m"

#define KWHT  "\x1B[37m"


#define FRED(x) KRED x RST/* RED */

#define FGRN(x) KGRN x RST/* GREEN */

#define FYEL(x) KYEL x RST/* YELLOW */

#define FBLU(x) KBLU x RST/* BLUE */

#define FMAG(x) KMAG x RST/* MAGNETA */

#define FCYN(x) KCYN x RST/* CYAN */

#define FWHT(x) KWHT x RST/* WHITE */


#define BOLD(x) "\x1B[1m" x RST

#define UNDL(x) "\x1B[4m" x RST


#endif
