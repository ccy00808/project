#include "command.h"
#include <iostream>

void LightCommand::Execute(int pos)
{
    receiver->Action(pos);
}

void LightsCommand::RegisterCommand(int pos, Command::CommandPtr ptr)
{
    if (onCommands.find(pos) != onCommands.end() || offCommands.find(pos) != offCommands.end()) {
        std::cout << "current pos " << pos << " has busy\n";
        return ;
    }

    onCommands.insert(std::pair<int, Command::CommandPtr>(pos, ptr));
    return ;
}

void LightsCommand::Execute(int pos)
{
    if (pos == 0) {
        for (auto iter : offCommands) {
            iter.second->Execute(pos);
        }
    } else if (pos == 1) {
        for (auto iter : onCommands) {
            iter.second->Execute(pos);
        }
    }
    
}