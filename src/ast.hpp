#ifndef AST_HPP
#define AST_HPP

#include <vector>

class Visitor;

enum Operator
{
    PLUS,
    MINUS,
    STAR,
    SLASH,
};

enum NodeType
{
    COMPOUND_NODE,
    ROOT_NODE,
    LITERAL_NODE,
    UNARY_EXPR_NODE,
    BINARY_EXPR_NODE

};

class Node 
{
public:
    NodeType type;

    Node(NodeType type) : type(type) {}

    virtual void accept(Visitor* v) = 0;
};

class CompoundNode : public Node
{
public:
    std::vector<Node*> node_list;

    CompoundNode() : Node(COMPOUND_NODE) {}

    void accept(Visitor* v) override;
    Node* add_node(Node* node);
};

class RootNode : public Node 
{
public:
    Node* child;

    RootNode(Node* child) : Node(ROOT_NODE), child(child) {}
    void accept(Visitor* v) override;
};

class LiteralNode : public Node
{
public:
    int value;

    LiteralNode(int value) : Node(LITERAL_NODE), value(value) {}
    void accept(Visitor* v) override;
};

class UnaryNode : public Node
{
public:
    Operator op;
    Node* expr;

    UnaryNode(Operator op, Node* expr) : Node(UNARY_EXPR_NODE), op(op), expr(expr) {}
    void accept(Visitor* v) override;
};

class BinaryNode : public Node
{
public:
    Node* left;
    Operator op;
    Node* right;

    BinaryNode(Node* left, Operator op, Node* right) : Node(BINARY_EXPR_NODE), left(left), op(op), right(right) {}
    void accept(Visitor* v) override;
};


// VISITORS


class Visitor
{
public:
    virtual void visit(CompoundNode* node) = 0;
    virtual void visit(RootNode* node) = 0;
    virtual void visit(LiteralNode* node) = 0;
    virtual void visit(UnaryNode* node) = 0;
    virtual void visit(BinaryNode* node) = 0;
};

class PrintVisitor : public Visitor 
{
public:

    void visit(CompoundNode* node) override;
    void visit(RootNode* node) override;
    void visit(LiteralNode* node) override;
    void visit(UnaryNode* node) override;
    void visit(BinaryNode* node) override;
};



#endif