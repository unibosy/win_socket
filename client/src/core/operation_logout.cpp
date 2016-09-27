#include "../operation_logout.h"
#include "log.h"

Operation_Logout::Operation_Logout()
{}
Operation_Logout::~Operation_Logout()
{}

int Operation_Logout::invoke_para(ResourceInfo* resourceinfo, void* para)
{
  LOG(INFO)<<"enter Operation_Logout";




  LOG(INFO) << "leave Operation_Logout";

  return 0;
}