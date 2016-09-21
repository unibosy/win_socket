#include "../operationmanager_imp.h"


OperationManager_Imp* OperationManager_Imp::m_instance = nullptr;

OperationManager_Imp::OperationManager_Imp()
{}
OperationManager_Imp::~OperationManager_Imp()
{}

//todo: get the single instance
OperationManager_Imp* OperationManager_Imp::instance()
{
  return nullptr;
}
//a virtual function must be implemented
int OperationManager_Imp::invoke(ResourceInfo* resourceinfo, OPERATIONTYPE type, void* para)
{
  return 0;
}