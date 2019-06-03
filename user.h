#ifndef USER_H
#define USER_H

#include "privatemessage.h"
#include <iostream>
#include <vector>

class System;

class User
{
private:
    string myName;
    System * mySystem;
    vector<PrivateMessage> mySentMessages;
    vector<PrivateMessage*> myReceivedMessages;
    vector<User*> myFriends;

public :
    User(const string & name = "", System * system = NULL);

    void sendMessage (PrivateMessage * message);
    void addMessage (const PrivateMessage & message) ;
    void addFriend (User * oneFriend) ;

    string getName() const;
    User * getFriend (unsigned i) const ;
    System * getSystem (void) const ;
    const PrivateMessage & getSentMessage(unsigned i);
    const PrivateMessage * getRecievedMessage(unsigned i);
    unsigned getNbFriends();
    unsigned getNbSentMessages();
    unsigned getNbRecievedMessages();


}; // User

#endif // USER_H
