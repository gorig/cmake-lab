#include <stdio.h>

static const double PI = 3.14159265358979323846;

#ifdef USE_MY_MATH
    #include <my-math.h>
    const char *MATH_LIBRARY = "my-math";
#else
    #include <math.h>
    #define fsin sin
    const char *MATH_LIBRARY = "system";
#endif

int main() {
    printf("Used math library: %s\n", MATH_LIBRARY);

    printf("sin(0)=%f\n", fsin(0));
    printf("sin(PI/2)=%f\n", fsin(PI/2));
    printf("sin(2*PI/3)=%f\n", fsin(2*PI/3));
    printf("sin(3*PI/2)=%f\n", fsin(3*PI/2));
    printf("sin(PI)=%f\n", fsin(PI));

    return 0;
}