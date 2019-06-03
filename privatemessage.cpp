#include "privatemessage.h"
#include "user.h"

PrivateMessage::PrivateMessage(const string & content, User * sender) : Message(content), mySender(sender)
{

}
User * PrivateMessage::getSender()
{
    return mySender;
}
