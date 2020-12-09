
#ifndef __BV_NODE_H_
#define __BV_NODE_H_

#include "Ref.h"
#include "Vec2.h"
#include <vector>

class Node : public Ref
{
protected:
    Vec2 _position;
    float _scaleX;
    float _scaleY;
    Node *parent;
    vector<Node *> _children;
public:
    Node();
    ~Node();
    void setPosition(float x, float y);
    Vec2 getPosition();
    void remove();
};

#endif