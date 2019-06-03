#include "user.h"

User::User(const string & name, System * system) : myName(name), mySystem(system)
{
    mySentMessages.reserve(1000);
}

void User::sendMessage (PrivateMessage * message)
{
    myReceivedMessages.push_back(message);
} // sendMessage()

void User::addFriend (User * oneFriend)
{
    myFriends.push_back(oneFriend);
}

User * User::getFriend (unsigned i) const {
  return myFriends[i];
}

System * User::getSystem (void) const
{
    return mySystem;
}

void User::addMessage (const PrivateMessage & message)
{
   mySentMessages.push_back(message);
}

 string User::getName() const
 {
     return myName;
 }
const PrivateMessage & User::getSentMessage(unsigned i)
{
    return mySentMessages[i];
}

const PrivateMessage * User::getRecievedMessage(unsigned i)
{
    return myReceivedMessages[i];
}

unsigned User::getNbFriends()
{
    return myFriends.size();
}

unsigned User::getNbSentMessages()
{
    return mySentMessages.size();
}

unsigned User::getNbRecievedMessages()
{
    return myReceivedMessages.size();
}

