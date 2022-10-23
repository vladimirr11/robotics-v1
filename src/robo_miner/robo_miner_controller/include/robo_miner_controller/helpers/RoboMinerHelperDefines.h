#ifndef USERAUTHENTICATEHELPER_H
#define USERAUTHENTICATEHELPER_H

// C++ System headers
#include <functional>

// Own components headers
#include "robo_common/defines/RoboCommonDefines.h"

using InitiateUserAuthenticateCb = std::function<void(const UserData&)>;

#endif  // !USERAUTHENTICATEHELPER_H
