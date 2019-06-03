#ifndef PUBLICMESSAGE_H
#define PUBLICMESSAGE_H
#include <string>
#include "message.h"

using namespace std;

class PublicMessage : public Message
{
private:
    unsigned myNbLikers;
public:
    PublicMessage(const string& content);
    unsigned getNbLikers();

    void add();
};

#endif // PUBLICMESSAGE_H
