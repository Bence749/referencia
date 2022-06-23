#include <iostream>

struct Node
{
    int val;
    Node* left, *right;

    Node( int v )
    {
        val = v;
        left = right = 0;
    }
};

void print( const Node* n )
{
    if( n )
    {
        print( n->left );
        std::cout << n->val << ' ';
        print( n->right );
    }
}

void insert( Node*& n, int v )
{
    if( n )
    {
        insert( v <= n-> val ? n->left : n->right, v );
    }
    else
    {
        n = new Node(v);
    }
}

void dealloc( Node* n )
{
    if( n )
    {
        dealloc( n->left );
        dealloc( n->right );
        delete n;
    }
}

int main()
{
    int i;
    Node* root = 0;
    while( std::cin >> i )
    {
        insert( root, i );
    }
    print( root );
    std::endl( std::cout );

    dealloc( root );
}