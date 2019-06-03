#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>
#include "date.h"

using namespace std;

class Message
{
private:
    string myContent;
    Date myDate;

public:
    Message(const string& content);
    void displayContent() const;

    Date getDate();
};

#endif // MESSAGE_H
