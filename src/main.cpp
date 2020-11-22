#include "Kernel.h"

int main(void) {

    Kernel kernel;
    kernel.init(640,640,"SIMPLE_OPENGL");
    kernel.run();
    kernel.teardown();
}