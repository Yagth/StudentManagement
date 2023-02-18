#include "dataStructures.h"
#include "CourseFunctions.cpp"
#include "StudentFunctions.cpp"

#ifdef _WIN32
#include <conio.h> // for _getch()
#else
#include <unistd.h>  // for STDIN_FILENO
#include <termios.h> // for tcgetattr(), tcsetattr(), struct termios
#endif

void clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void waitForUser()
{
#ifdef _WIN32
    _getch();
#else
    struct termios old_termios, new_termios;
    tcgetattr(STDIN_FILENO, &old_termios);
    new_termios = old_termios;
    new_termios.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_termios);
    getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &old_termios);
#endif
}

void registerStudentToCourse()
{
    clearScreen();
}