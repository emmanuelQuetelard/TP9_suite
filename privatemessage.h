#ifndef PRIVATEMESSAGE_H
#define PRIVATEMESSAGE_H

#include "message.h"
class User;

class PrivateMessage : public Message
{
    private:
    User * mySender;

public:
    PrivateMessage(const string & content, User * sender);
    User * getSender();
};

#endif // PRIVATEMESSAGE_H
