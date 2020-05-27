#include "command.h"
#include "receiver.h"
#include "invoker.h"
#include <memory>

int main()
{
    std::shared_ptr<Receiver> light1 = std::make_shared<Light>(1);
    std::shared_ptr<Command> cmd1 = std::make_shared<LightCommand>(light1);
    Invoker *invoker = new Person("chenchuanying", cmd1);
    invoker->response(1);

    std::shared_ptr<Receiver> light2 = std::make_shared<Light>(2);
    std::shared_ptr<Command> cmd2 = std::make_shared<LightCommand>(light2);
    std::shared_ptr<Receiver> light3 = std::make_shared<Light>(3);
    std::shared_ptr<Command> cmd3 = std::make_shared<LightCommand>(light3);
    std::shared_ptr<LightsCommand> cmds = std::make_shared<LightsCommand>();
    cmds->RegisterCommand(1, cmd1);
    cmds->RegisterCommand(2, cmd2);
    cmds->RegisterCommand(3, cmd3);

    Invoker *invokerT = new Person("teacher", cmds);
    invokerT->response(1);

    delete(invoker);
    delete(invokerT);

    //test comm command
    Light *ligt = new Light(100);
    std::shared_ptr<CommCommand<Light>> commcmd = std::make_shared<CommCommand<Light>>(ligt, &Light::Action);
    Invoker *invokerTt = new Person("yeqingxiu", commcmd);
    invokerTt->response(1);
}