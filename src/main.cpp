#include "Kernel.h"

int main(void) {

    Kernel kernel;
    bool initSuccess = kernel.init(640,640,"SIMPLE_OPENGL");
    if(initSuccess){
    	kernel.run();
    	kernel.teardown();
    }
    else{
    	std::cout<<"Failure."<<std::endl;
    }
}