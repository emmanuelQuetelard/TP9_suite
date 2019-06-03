#include "publicmessage.h"

PublicMessage::PublicMessage(const string& content) : Message(content), myNbLikers(0)
{

}
unsigned PublicMessage::getNbLikers()
{
    return myNbLikers;
}

void PublicMessage::add()
{
    ++myNbLikers;
}
