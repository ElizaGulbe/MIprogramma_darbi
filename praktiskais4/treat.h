/** ifndef, define, endif nelauj failam tikt kopetam failos, kur rakstits #include <Treat.h>**/
#ifndef TREAT_H
#define TREAT_H

struct Treat {
    char name[50];
    double price;
    int curCount = 0;
    int soldCount = 0;
};

#endif