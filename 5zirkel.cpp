#include <iostream>
int main() {
    unsigned char ton = 'e';
    int mode = 2;//0 = dur, 1 = dorisch, 2 = phrygisch, 3 = lydisch, 4=mixolydisch, 5=moll, 6=lokrisch
    int sharp = 1;
    int flat = 0;
    //int a = (unsigned char)ton;
    int wurst = 2 * ((ton - 1) % 7);
    wurst -= (int)(wurst > 4);
    wurst += sharp - flat - (2 * mode);
    wurst += (int)(mode > 2);
    wurst += 12 * (int)(wurst < 0);
    wurst = (wurst + 6 * (int)(wurst % 2 != 0))%12;
    std::cout << "kreuz: " << wurst << " b: " << (12 - wurst) << std::endl;
    return 0;
}
