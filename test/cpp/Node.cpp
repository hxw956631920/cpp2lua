
#include "Node.h"

Node::Node()
:_position(0, 0),_scaleX(1),_scaleY(1)
{

}

Node::~Node()
{
    vector<Node *>::iterator it = _children.begin();
    for (; it != _children.end(); it++)
    {
        Node *child = *it;
        child->remove();
    }
}

void Node::setPosition(float x, float y)
{
    _position._x = x;
    _position._y = y;
}

Vec2 Node::getPosition()
{
    return _position;
}

void Node::remove()
{
    this->release();
    delete this;
}