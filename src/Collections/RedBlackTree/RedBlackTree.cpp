//
// Created by Piotr Szczypior on 03/04/2023.
//

#include "RedBlackTree.h"
#include <iostream>

using namespace std;

RedBlackTree::RedBlackTree() {
    _root = nullptr;
}

void RedBlackTree::rotate_right(Node *node_to_rotate) {
    Node *new_node = node_to_rotate->left_child;

    node_to_rotate->left_child = new_node->right_child;
    if (new_node->right_child != nullptr) {
        new_node->right_child->parent = node_to_rotate;
    }

    new_node->parent = node_to_rotate->parent;
    if (node_to_rotate->parent == nullptr) {
        _root = new_node;
    } else if (node_to_rotate == node_to_rotate->parent->left_child) {
        node_to_rotate->parent->left_child = new_node;
    } else {
        node_to_rotate->parent->right_child = new_node;
    }

    new_node->right_child = node_to_rotate;
    node_to_rotate->parent = new_node;
}

void RedBlackTree::rotate_left(Node *node_to_rotate) {
    Node *new_node = node_to_rotate->right_child;

    node_to_rotate->right_child = new_node->left_child;
    if (new_node->left_child != nullptr) {
        new_node->left_child->parent = node_to_rotate;
    }

    new_node->parent = node_to_rotate->parent;
    if (node_to_rotate->parent == nullptr) {
        _root = new_node;
    } else if (node_to_rotate == node_to_rotate->parent->left_child) {
        node_to_rotate->parent->left_child = new_node;
    } else {
        node_to_rotate->parent->right_child = new_node;
    }

    new_node->left_child = node_to_rotate;
    node_to_rotate->parent = new_node;
}

void RedBlackTree::balance_tree(Node *node) {
    Node *parent = node->parent;

    if (parent == nullptr) {
        return;
    }

    if (parent->color == Color::BLACK) {
        return;
    }

    Node *grandparent = parent->parent;

    if (grandparent == nullptr) {
        parent->color = Color::BLACK;
        return;
    }

    auto uncle = this->get_uncle(node);
    if (uncle != nullptr && uncle->color == Color::RED) {
        parent->color = Color::BLACK;
        grandparent->color = Color::RED;
        uncle->color = Color::BLACK;
        balance_tree(grandparent);
    } else if (parent == grandparent->left_child) {
        if (node == parent->right_child) {
            rotate_left(parent);

            parent = node;
        }
        rotate_right(grandparent);

        parent->color = Color::BLACK;
        grandparent->color = Color::RED;
    } else {
        if (node == parent->left_child) {
            rotate_right(parent);
            parent = node;
        }
        rotate_left(grandparent);

        parent->color = Color::BLACK;
        grandparent->color = Color::RED;
    }
}

void RedBlackTree::push_back(int value) {
    Node *new_node = new Node(value);

    Node *node = _root;
    Node *previous_to_node = nullptr;

    while (node != nullptr) {
        previous_to_node = node;
        if (value < node->value) {
            node = node->left_child;
        } else {
            node = node->right_child;
        }
    }

    if (previous_to_node == nullptr) {
        _root = new_node;
        _root->color = Color::BLACK;
        return;
    } else if (value < previous_to_node->value) {
        previous_to_node->left_child = new_node;
    } else {
        previous_to_node->right_child = new_node;
    }
    new_node->parent = previous_to_node;

    if (new_node->parent->parent == nullptr) {
        return;
    }

    this->balance_tree(new_node);
}

Node *RedBlackTree::get_uncle(Node *node) {
    auto grand_parent = node->parent->parent;

    if (grand_parent->left_child == node->parent) {
        return grand_parent->right_child;
    }
    return grand_parent->left_child;
}

void RedBlackTree::remove(int value) {
    Node *node_to_delete = _root;

    while (node_to_delete != nullptr) {
        if (node_to_delete->value > value) {
            node_to_delete = node_to_delete->left_child;
        } else if (node_to_delete->value < value) {
            node_to_delete = node_to_delete->right_child;
        } else {
            break;
        }
    }

    if (node_to_delete == nullptr) {
        cout << "Value has not been found" << endl;
        return;
    }
    Node *moved_node;
    Color color;

    if (node_to_delete->left_child == nullptr ||
        node_to_delete->right_child == nullptr) {
        color = node_to_delete->color;
        moved_node = delete_node(node_to_delete);
    } else {
        auto minimum_successor = find_minimum(node_to_delete);
        node_to_delete->value = minimum_successor->value;
        moved_node = delete_node(minimum_successor);
        color = minimum_successor->color;
    }

    if (color == Color::BLACK) {
        fix_delete(moved_node);

        if (moved_node->value == -1) {
            replace_child(moved_node, nullptr);
        }
    }
}

Node *RedBlackTree::delete_node(Node *node) {

    if (node->left_child != nullptr) {
        replace_child(node, node->left_child);
        return node->left_child;

    } else if (node->right_child != nullptr) {
        replace_child(node, node->right_child);
        return node->right_child;
    }
    auto new_child = node->color == Color::BLACK ? new Node(-1) : nullptr;
    replace_child(node, new_child);
    return new_child;
}

void RedBlackTree::replace_child(Node *old_child, Node *new_child) {
    auto parent = old_child->parent;

    if (parent == nullptr) {
        _root = new_child;
    } else if (parent->left_child == old_child) {
        parent->left_child = new_child;
    } else if (parent->right_child == old_child) {
        parent->right_child = new_child;
    }

    if (new_child != nullptr) {
        new_child->parent = parent;
    }
}

Node *RedBlackTree::find_minimum(Node *node) {
    while (node->left_child != nullptr) {
        node = node->left_child;
    }
    return node;
}

void RedBlackTree::fix_delete(Node *node) {
    if (node == _root) {
        return;
    }

    Node *sibling = get_sibling(node);

    if (sibling->color == Color::RED) {
        sibling->color = Color::BLACK;
        node->parent->color = Color::RED;

        if (node == node->parent->left_child) {
            rotate_left(node->parent);
        } else {
            rotate_right(node->parent);
        }

        sibling = get_sibling(node);
    }

    if (is_black(sibling->left_child) && is_black(sibling->right_child)) {
        sibling->color = Color::RED;

        if (node->parent->color == Color::RED) {
            node->parent->color = Color::BLACK;
        } else {
            fix_delete(node->parent);
        }
    } else {
        bool node_is_left_child = node == node->parent->left_child;

        if (node_is_left_child && is_black(sibling->right_child)) {
            sibling->left_child->color = Color::RED;
            sibling->color = Color::RED;
            rotate_right(sibling);
            sibling = node->parent->right_child;
        } else if (!node_is_left_child && is_black(sibling->left_child)) {
            sibling->right_child->color = Color::BLACK;
            sibling->color = Color::RED;
            rotate_left(sibling);
            sibling = node->parent->left_child;
        }

        sibling->color = node->parent->color;
        node->parent->color = Color::BLACK;
        if (node_is_left_child) {
            sibling->right_child->color = Color::BLACK;
            rotate_left(node->parent);
        } else {
            sibling->left_child->color = Color::BLACK;
            rotate_right(node->parent);
        }
    }
}

Node *RedBlackTree::get_sibling(Node *node) {
    auto parent = node->parent;
    if (parent->left_child == node) {
        return parent->right_child;
    }
    return nullptr;
}

bool RedBlackTree::is_black(Node *node) {
    return node == nullptr || node->color == Color::BLACK;
}

void RedBlackTree::print() {
    if (_root) {
        print_helper(this->_root, "", true, true);
    }
}

void RedBlackTree::print_helper(Node *node, std::string indent, bool isLast, bool isFirst) {

    if (node != nullptr) {
        cout << indent;
        if (isFirst) {
            cout << endl << endl;
            cout << "O----";
            indent += "   ";
        } else {
            if (isLast) {
                cout << "R----";
                indent += "   ";
            } else {
                cout << "L----";
                indent += "|  ";
            }
        }
        string sColor = node->color == Color::RED ? "RED" : "BLACK";
        cout << node->value << "(" << sColor << ")" << endl;
        print_helper(node->right_child, indent, true, false);
        print_helper(node->left_child, indent, false, false);
    }
}

int RedBlackTree::find(int value) {
    auto temporary_node = _root;

    while(temporary_node != nullptr) {
        if(temporary_node->value < value) {
            temporary_node = temporary_node->right_child;
        } else if (temporary_node->value > value) {
            temporary_node = temporary_node->left_child;
        } else {
            return temporary_node->value;
        }
    }
    cout << "value: " << value << " has not been found! Returning -1" << endl;
    return -1;
}

RedBlackTree::~RedBlackTree() = default;

