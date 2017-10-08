#include <iostream>
#include "AstarMap.h"

int main() {
    AstarMap map("../map.txt");
    cout<<map.getWidth()<<" "<<map.getHeight();
    return 0;
}