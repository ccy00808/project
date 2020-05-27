#incude "command.h"

LightCommand::LightCommand(Command::ReceiverPtr p, int pos)
{
    if (p == nullptr) {
        return ;
    }
    lights.push_back(1, p);
}

void LightCommand::RegisterLight(int pos, Command::ReceiverPtr p)
{
    if (lights.find(p) != lights.end()) {
        return ;
    }

    lights.push_back(pos, p);
}


void LightCommand::UnRegisterLight(int id)
{

}

void LightCommand::ExecuteAll()
{
    for(auto iter : lights) {
        iter.second->Action();
    }
}

void LightCommand::UndoAll()
{
    for(auto iter : lights) {
        iter.second->UnAction();
    }
}

void LightCommand::Execute(void *context)
{
    int pos = *(reinterpret_cast<int *>context);
    if (pos == 0) {
        ExecuteAll();
        return;
    }

    if (lights.find(pos) != lights.end()) {
        lights[pos]->Action();
    }
}

void LightCommand::Undo(void *context)
{
    int pos = *(reinterpret_cast<int *>context);
    if (pos == 0) {
        UnDoAll();
        return;
    }

    if (lights.find(pos) != lights.end()) {
        lights[pos]->UnAction();
    }
}

void TVCommand::Execute(void *context)
{
    if (ptr != nullptr) {
        ptr->Action();
    }
}