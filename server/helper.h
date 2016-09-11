/*
Copyright (c) 2016 by unibosy@gmail.com
This file is part of the unibosy library. https://github.com/unibosy
This software is distributed under a license. The full license
agreement can be found in the file LICENSE in this distribution.
This software may not be copied, modified, sold or distributed
other than expressed in the named license agreement.
This software is distributed without any warranty.
*/

#pragma once

//provide some little functions
class Helper
{
public:
  Helper() { ; }
  ~Helper() { ; }
  static Helper* getInstance();

  //print detail error infomessage after GetLastError()
  void showLastErrMessage();
protected:
  
private:
  static Helper* m_instance;

};