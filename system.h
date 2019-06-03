#ifndef SYSTEM_H
#define SYSTEM_H

#include "user.h"
#include "publicmessage.h"

class System
{
private:
    unsigned myNbUsers;
    vector<User> myUsers;
    unsigned myNbMessages;
    vector<PublicMessage> myPublicMessages;

public:
    System() : myNbUsers(0), myNbMessages(0)
    {
        myUsers.reserve (1000);
        myPublicMessages.reserve (1000);
        // création des Users
        addUser ("Alfred");
        addUser ("Alain");
        addUser ("Sophie");
        addUser ("Emmanuel");
        addUser ("Christian");
        addUser ("Petru");
        addUser ("Marc");
        /* verification des Users */
        cout << myUsers.size () << endl;
        for (const User & user : myUsers)
        {
            cout << user.getName () << endl;
        }


        /* création de leurs amis * /
                  for (unsigned i (0); i < myUsers.size (); ++i)
                      for (unsigned j (0); j < myUsers.size () / 2; ++j)
                          myUsers [i].addFriend (&myUsers [(i + ((j * 2) + 1)) % myUsers.size ()]);

                  /*  verification des amis  * /
                  for (unsigned i (0); i < myUsers.size (); ++i)
                  {
                      User user = myUsers [i];
                      cout << user.getName () << " a " << user.getNbFriends() << " amis : " << endl;
                      for (unsigned j (0); j < user.getNbFriends (); ++j)
                          cout << (user.getFriend (j))->getName () << endl;
                  }
                  /*  création et envoi des messages privés  * /
                  for (User & user : myUsers)
                  {
                      for (unsigned j (0); j < user.getNbFriends (); ++j)
                      {
                          string content (string ("salut") + ' ' + (user.getFriend (j))->getName ());
                          PrivateMessage message (content, & user);
                          user.addMessage (message);
                          (user.getFriend (j))->sendMessage (&(user.getSentMessage (user.getNbSentMessages () - 1)));
                      }
                  }
                  /*  vérifications des messages envoyés  * /
                  for (unsigned i (0); i < myUsers.size (); ++i)
                  {
                      User user = myUsers [i];
                      cout << user.getName () << " a envoyé " << user.getNbSentMessages() << " messages : " << endl;
                      for (unsigned j (0); j < user.getNbSentMessages (); ++j)
                      {
                          (user.getSentMessage (j)).displayContent();
                          cout << endl;
                      }

                  }
                  /*  vérifications des messages reçus  * /
                  for (unsigned i (0); i < myUsers.size (); ++i)
                  {
                      User user = myUsers [i];
                      cout << user.getName () << " a reçu " << user.getNbRecievedMessages() << " messages : " << endl;
                      for (unsigned j (0); j < user.getNbRecievedMessages (); ++j)
                      {
                          cout << "de " << (user.getRecievedMessage (j))->getSender ()->getName () << " : ";
                          (user.getRecievedMessage (j))->displayContent();
                          cout << endl;
                      }

                  }
                  /* création et envoie des messages publiques  * /
                  string oneMessage ("a");
                  for (const User & user : myUsers)
                      for (unsigned i (0); i < 5; ++i)
                      {
                          oneMessage += 'a';
                          (user.getSystem ())->addPublicMessage (oneMessage);
                      }
                  /* test de la création des messages * /
                  for (const PublicMessage & message : myPublicMessages)
                  {
                      message.displayContent ();
                      cout << endl;
                  }
                  /*  création des like  * /
                  for (User & user : myUsers)
                      for (unsigned i (0); i < myNbMessages; ++i)
                          (user.getSystem ())->getPublicMessage (i).add ();

                  /*  test des likes * /
                  for (const PublicMessage & message : myPublicMessages)
                  {
                      message.displayContent ();
                      cout << " a " << message.getNbLikers () << " likers" << endl;
                  }*/
    }

    User & getUser(unsigned i) {return myUsers[i];}
    PublicMessage & getPublicMessage(unsigned i) {return myPublicMessages[i];}

    void addUser (const string & name)
    {
        myUsers.push_back(User(name, this));
        ++myNbUsers;
    }

    void addPublicMessage(const string & message)
    {
        myPublicMessages.push_back(message);
        ++myNbMessages;
    }


};

#endif // SYSTEM_H
