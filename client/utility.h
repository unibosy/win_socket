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

#include <string>
#include <list>

typedef std::list<std::string> StrList;

/*
 * Common functions
 *
*/
class  Utility
{
public:
  Utility();
  ~Utility();
  static Utility* instance();

  //get local ip
  StrList getLocalIP();

protected:
  ////get local ip
  //std::string getLocalIP();
private:
  static Utility* m_instance;
  StrList m_strlist;
};
