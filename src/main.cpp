#include "core/Engine.h"
#include "core/ControllerImpl.h"

int main(int argc, char* argv[])
{
    ControllerImpl controller;
    auto           engine = Engine(&controller);
    engine.Run();
    return 0;
}
