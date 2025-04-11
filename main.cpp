#include <iostream>
#include <vector>
#include <string>
#include "photo.hpp"
#define SPATH "C:\\Users\\Admin\\misha\\PW\\PTI proj\\resources\\"
#define DPATH "C:\\Users\\Admin\\misha\\PW\\PTI proj\\destination\\"


int main(int argc, char* argv[]) {
    /* if (argc < 2) {
        cerr << "Usage: program.exe <path to photo>" << endl;
        return 1;
    } */


    string input = "new1.jpeg";
    //string output = "new2.png";

    Photo image(SPATH + input);
    //image.show("Original image");
    
    Photo nr(image.getNR());

    image.set_path("orig");
    nr.set_path("nr");

    cout << image.countNoise() << '\t' << nr.countNoise() << endl;




    waitKey(0);
    return 0;
}