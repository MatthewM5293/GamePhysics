#include "ParticleTest.h"
#include "ForceTest.h"

/*
#define AREA_FORCE
#define DRAG_FORCE
#define POINT_FORCE
*/

int main(int argc, char* argv[]) 
{
    Test* test = new ForceTest();
    test->Initialize();

    while (!test->IsQuit())
    {
        test->Run();
    }
    delete test;

    return 0;
}