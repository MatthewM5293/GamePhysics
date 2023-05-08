#include "ParticleTest.h"

int main(int argc, char* argv[]) 
{
    Test* test = new ParticleTest();
    test->Initialize();

    while (!test->IsQuit())
    {
        test->Run();
    }
    delete test;

    return 0;
}