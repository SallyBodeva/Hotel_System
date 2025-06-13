#pragma once
#include "User.h"
#include "MyString.h"
#include "MyVector.hpp"


class ActionLog {
public:
    ActionLog() = default;
    ActionLog(const MyString& username, const MyString& action);

    const MyString& getUsername() const;
    const MyString& getAction() const;

private:
    MyString username;
    MyString action;

};