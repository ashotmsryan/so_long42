#ifndef KEYS_H
#define KEYS_H

# ifdef __linux__
#  define ESC 65307
#  define LEFT 65361
#  define RIGHT 65363
#  define DOWN 65364
#  define UP 65362
#  define LEFT1 97
#  define RIGHT1 100
#  define UP1 119
#  define DOWN1 115
#  define ENTER 65293
#  define SPACE 32
# else
#  define ESC 53
#  define LEFT 123
#  define RIGHT 124
#  define DOWN 125
#  define UP 126
#  define LEFT1 0
#  define RIGHT1 2
#  define UP1 13
#  define DOWN1 1
#  define ENTER 36
#  define SPACE 49
# endif

#endif