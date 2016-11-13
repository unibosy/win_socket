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

#include "WINSOCK2.H"
#include "winsock.h"

#include <string>

#define MAXLEN 2048

#define SERVERPORT 8099
#define SERVERIP "192.168.41.109"

#define MESSAGEBUF 16384

const std::string configure_path = "./config.ini";

#define LOGNAME "COMMU"

const std::string left_brace = "\{";
const std::string right_brace = "\}";
const std::string semicolon = "\:";
const std::string left_dqm = "\"";
const std::string right_dqm = "\"";
const std::string comma = "\,";