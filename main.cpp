#include <iostream>
#include <vector>
#include "photo.hpp"

int main() {
    
    Photo image("C:/Users/Admin/misha/PW/PTI proj/resources/104493390011.JPG");
    image.show("Original image");
    image.showHist();
    image.showHE();
    image.showCLAHE();
    image.showGC();
    
    waitKey(0);
    return 0;
}