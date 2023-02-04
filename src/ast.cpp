#include "ast.hpp"
#include <cstdio>


/* HELPER FUNCTION */
void print_operator_enum(Operator op)
{
    switch (op)
    {
        case PLUS: printf("+"); break;
        case MINUS: printf("-"); break;
        case STAR: printf("*"); break;
        case SLASH: printf("/"); break;
    }
}

void CompoundNode::accept(Visitor* v) 
{
    v->visit(this);
}

Node* CompoundNode::add_node(Node* node)
{
    node_list.push_back(node);
    return node;
}

void RootNode::accept(Visitor* v)
{
    v->visit(this);
}

void LiteralNode::accept(Visitor* v)
{
    v->visit(this);
}

void UnaryNode::accept(Visitor* v)
{
    v->visit(this);
}


void BinaryNode::accept(Visitor* v)
{
    v->visit(this);
}


// VISITORS

void PrintVisitor::visit(CompoundNode* node)
{
    for (Node* element: node->node_list)
    {
        printf("Statement -> ");
        element->accept(this);
        printf("\n");
    }
}



void PrintVisitor::visit(RootNode *node)
{
    node->child->accept(this);
}


void PrintVisitor::visit(LiteralNode *node)
{
    printf("%d", node->value);
}

void PrintVisitor::visit(UnaryNode *node)
{
    printf("( ");
    print_operator_enum(node->op);
    node->expr->accept(this);
    printf(" )");
}

void PrintVisitor::visit(BinaryNode* node)
{
    printf("( ");
    node->left->accept(this);
    print_operator_enum(node->op);
    node->right->accept(this);
    printf(" )");
}