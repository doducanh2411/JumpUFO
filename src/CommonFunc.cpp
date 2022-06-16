#include "CommonFunc.h"

int getBestPoint()
{
    std::ifstream myFile("yourbestscore.txt");
    if(myFile.is_open())
    {
        int tempPoint;
        myFile >> tempPoint;
        return tempPoint;
    }
    else std::cout << "Can't open file at getBestPoint()" << std::endl;
}

void fixBestPoint(int newPoint)
{
    std::ofstream myFile("yourbestscore.txt");
    if(myFile.is_open())
    {
        myFile << newPoint;
    }
    else std::cout << "Can't open file at getBestPoint()" << std::endl;
}
int get_random(int a, int b){
    return rand() % (a - b + 1) + b;
}
