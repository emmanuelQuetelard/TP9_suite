#include <iostream>
#include "date.h"
#include "message.h"
#include "publicmessage.h"
#include "privatemessage.h"
#include "user.h"

using namespace std;

void displayDate (const Date & date)
{
    cout << date.getDay () << ' ' << date.getMonth () << ' ' << date.getYear ();

} // displayDate()

void displayHour (const Date & date)
{
    cout << date.getHour () << "h " << date.getMinute ()
         << "mn et " <<date.getSecond()<<" sec ";
}

void testMessage (void)
{
    Message message ("salut");
    message.displayContent ();
    cout << " posté le : ";
    displayDate (message.getDate ());
    cout << " à ";
    displayHour (message.getDate ());
    cout << endl;

} // testMessage()}

void testPublicMessage (void)
{
    PublicMessage message ("salut");
    message.displayContent ();
    cout << " posté le : ";
    displayDate (message.getDate ());
    cout << " à ";
    displayHour (message.getDate ());
    cout << endl;
    for (unsigned i(0); i < 5; ++i)
        message.add ();
    cout << "Nb de likers : " << message.getNbLikers ()<< endl;

} // testPublicMessage()

void testPrivateMessage (void)
{
    User user;
    PrivateMessage message ("salut", & user);
    message.displayContent ();
    cout << " posté le : ";
    displayDate (message.getDate ());
    cout << " à ";
    displayHour (message.getDate ());
    cout << endl;
    message.getSender ()->getFriend (5);

} // testPrivateMessage()

void testUser (void)
   {
       //System oneSystem;
       User alfred    ("Alfred", NULL);
       User alain     ("Alain", NULL);
       User sophie    ("Sophie", NULL);
       User emmanuel  ("Emmanuel", NULL);
       User christian ("Christian", NULL);
       User petru     ("Petru", NULL);
       User marc      ("Marc", NULL);
       PrivateMessage message ("salut", & alfred);
       message.displayContent ();
       cout << endl;

       alain.addFriend (&sophie);
       alain.addFriend (&emmanuel);
       alain.addFriend (&christian);
       alain.addFriend (&petru);
       alain.addFriend (&marc);

       cout << "Alain a " << alain.getNbFriends () << " amis" << endl;
       cout << "Le troisième ami d'Alain est : " << (alain.getFriend (2))->getName () << endl;

       alfred.addMessage (message);
       alain.sendMessage (&message);
       cout << "Nombre de message envoyés par Alfred : " << alfred.getNbSentMessages ()   << endl;
       cout << "Nombre de message reçus par Alfred : " << alfred.getNbRecievedMessages () << endl;
       cout << "Nombre de message envoyés par Alain : " << alain.getNbSentMessages ()   << endl;
       cout << "Nombre de message reçus par Alain : " << alain.getNbRecievedMessages () << endl;
       alain.getRecievedMessage (0)->displayContent ();
       cout << endl;
       alfred.getSentMessage (0).displayContent ();
       cout << endl;

   } // testUser()

int main()
{
    //testMessage();
    //testPublicMessage();
    //testPrivateMessage();
    testUser();
    return 0;
}

