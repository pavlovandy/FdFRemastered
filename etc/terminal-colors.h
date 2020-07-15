//
// Created by Arin on 05/04/2020.
//

#ifndef FDFREMASTERED_TERMINAL_COLORS_H
#define FDFREMASTERED_TERMINAL_COLORS_H

/*
** Reset
*/

# define COLOR_OFF "\033[0m"

/*
** Regular Colors
*/

# define BLACK "\033[0;30m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define PURPLE "\033[0;35m"
# define CYAN "\033[0;36m"
# define WHITE "\033[0;37m"

/*
** Bold
*/

# define BBLACK "\033[1;30m"
# define BRED "\033[1;31m"
# define BGREEN "\033[1;32m"
# define BYELLOW "\033[1;33m"
# define BBLUE "\033[1;34m"
# define BPURPLE "\033[1;35m"
# define BCYAN "\033[1;36m"
# define BWHITE "\033[1;37m"

/*
** Underline
*/

# define UBLACK "\033[4;30m"
# define URED "\033[4;31m"
# define UGREEN "\033[4;32m"
# define UYELLOW "\033[4;33m"
# define UBLUE "\033[4;34m"
# define UPURPLE "\033[4;35m"
# define UCYAN "\033[4;36m"
# define UWHITE "\033[4;37m"

/*
** Background
*/

# define ON_BLACK "\033[40m"
# define ON_RED "\033[41m"
# define ON_GREEN "\033[42m"
# define ON_YELLOW "\033[43m"
# define ON_BLUE "\033[44m"
# define ON_PURPLE "\033[45m"
# define ON_CYAN "\033[46m"
# define ON_WHITE "\033[47m"

/*
** High Intensty
*/

# define IBLACK "\033[0;90m"
# define IRED "\033[0;91m"
# define IGREEN "\033[0;92m"
# define IYELLOW "\033[0;93m"
# define IBLUE "\033[0;94m"
# define IPURPLE "\033[0;95m"
# define ICYAN "\033[0;96m"
# define IWHITE "\033[0;97m"

/*
** Bold High Intensty
*/

# define BIBLACK "\033[1;90m"
# define BIRED "\033[1;91m"
# define BIGREEN "\033[1;92m"
# define BIYELLOW "\033[1;93m"
# define BIBLUE "\033[1;94m"
# define BIPURPLE "\033[1;95m"
# define BICYAN "\033[1;96m"
# define BIWHITE "\033[1;97m"

/*
** High Intensty backgrounds
*/

# define ON_IBLACK "\033[0;100m"
# define ON_IRED "\033[0;101m"
# define ON_IGREEN "\033[0;102m"
# define ON_IYELLOW "\033[0;103m"
# define ON_IBLUE "\033[0;104m"
# define ON_IPURPLE "\033[10;95m"
# define ON_ICYAN "\033[0;106m"
# define ON_IWHITE "\033[0;107m"

/*
** First version
*/

# define TNULL "\x1B[0m"
# define TRED  "\x1B[31m"
# define TGRE  "\x1B[32m"
# define TYEL  "\x1B[33m"
# define TBLU  "\x1B[34m"
# define TPIN  "\x1B[35m"
# define TCYN  "\x1B[36m"
# define TWHY  "\x1B[37m"

#endif //FDFREMASTERED_TERMINAL_COLORS_H
