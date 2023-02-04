#include <cstdio>
#include "ast.hpp"

int main()
{   
    /* 
    Test Tree:
    

    ROOT:
        0:
            -(5 + 15) 

    */

    CompoundNode* compound = new CompoundNode;
    RootNode* root = new RootNode(compound);


    LiteralNode* literal1 = new LiteralNode(5);
    LiteralNode* literal2 = new LiteralNode(15);

    BinaryNode* binary = new BinaryNode(literal1, Operator::PLUS, literal2);

    UnaryNode* unary = new UnaryNode(Operator::MINUS, binary);

    compound->add_node(unary);


    PrintVisitor* visitor = new PrintVisitor;


    visitor->visit(root);


    
}