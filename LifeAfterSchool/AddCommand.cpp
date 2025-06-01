#include "AddComand.h"

AddCommand::AddCommand(ServiceAM* _globalServ, ServiceUM* _userServ, Event _newEvent, WhichService _whichServ):
	Command(_globalServ, _userServ), newEvent(_newEvent), whichServ(_whichServ){ }

void AddCommand::Execute() {
	whichServ == AdminService ? globalServ->AddEvent(newEvent) : userServ->AddUserEvent(globalServ->FindEvent(newEvent));
}
void AddCommand::Undo() {
	whichServ == AdminService ? globalServ->RemoveEvent(newEvent.title) : userServ->RemoveUserEvent(newEvent.title);
}