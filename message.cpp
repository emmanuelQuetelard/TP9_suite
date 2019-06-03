#include "message.h"
#include <iostream>

Message::Message(const string& content) : myContent(content)
{

}
void Message::displayContent() const
{
    cout << myContent;
}

Date Message::getDate()
{
    return myDate;
}
