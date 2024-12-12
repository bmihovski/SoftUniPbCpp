#include "core/Engine.h"
#include "core/ControllerImpl.h"

int main(int argc, char* argv[])
{
    ControllerImpl controller;
    Engine         engine = Engine(&controller);
    engine.run();
    return 0;
}
