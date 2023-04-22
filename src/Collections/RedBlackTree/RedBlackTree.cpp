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
    if (node_to_rotate->left_child != nullptr) {
        node_to_rotate->left_child->parent = node_to_rotate;
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


//void RBTree::fixInsertRBTree(Node *&ptr) {
//    Node *parent = nullptr;
//    Node *grandparent = nullptr;
//    while (ptr != root && getColor(ptr) == RED && getColor(ptr->parent) == RED) {
//        parent = ptr->parent;
//        grandparent = parent->parent;
//        if (parent == grandparent->left) {
//            Node *uncle = grandparent->right;
//            if (getColor(uncle) == RED) {
//                setColor(uncle, BLACK);
//                setColor(parent, BLACK);
//                setColor(grandparent, RED);
//                ptr = grandparent;
//            } else {
//                if (ptr == parent->right) {
//                    rotateLeft(parent);
//                    ptr = parent;
//                    parent = ptr->parent;
//                }
//                rotateRight(grandparent);
//                swap(parent->color, grandparent->color);
//                ptr = parent;
//            }
//        } else {
//            Node *uncle = grandparent->left;
//            if (getColor(uncle) == RED) {
//                setColor(uncle, BLACK);
//                setColor(parent, BLACK);
//                setColor(grandparent, RED);
//                ptr = grandparent;
//            } else {
//                if (ptr == parent->left) {
//                    rotateRight(parent);
//                    ptr = parent;
//                    parent = ptr->parent;
//                }
//                rotateLeft(grandparent);
//                swap(parent->color, grandparent->color);
//                ptr = parent;
//            }
//        }
//    }
//    setColor(root, BLACK);
//}

void RedBlackTree::rotate_left(Node *node_to_rotate) {
    Node *right_child = node_to_rotate->right_child;

    node_to_rotate->right_child = right_child->left_child;
    if (node_to_rotate->right_child != nullptr) {
        node_to_rotate->right_child->parent = node_to_rotate;
    }

    right_child->parent = node_to_rotate->parent;
    if (node_to_rotate->parent == nullptr) {
        _root = right_child;
    } else if (node_to_rotate == node_to_rotate->parent->left_child) {
        node_to_rotate->parent->left_child = right_child;
    } else {
        node_to_rotate->parent->right_child = right_child;
    }

    right_child->left_child = node_to_rotate;
    node_to_rotate->parent = right_child;
}

void RedBlackTree::fix_insert(Node *node) {
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
        fix_insert(grandparent);
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
    }

    if (value < previous_to_node->value) {
        previous_to_node->left_child = new_node;
    } else {
        previous_to_node->right_child = new_node;
    }
    new_node->parent = previous_to_node;

    if (new_node->parent->parent == nullptr) {
        return;
    }

    this->fix_insert(new_node);
    setColor(_root, Color::BLACK);
}

Node *RedBlackTree::get_uncle(Node *node) {
    auto grand_parent = node->parent->parent;

    if (grand_parent->left_child == node->parent) {
        return grand_parent->right_child;
    }
    return grand_parent->left_child;
}

Node *RedBlackTree::delete_node(Node *node) {
    if (node->left_child != nullptr) {
        replace_child(node, node->left_child);
        return node->left_child;

    } else if (node->right_child != nullptr) {
        replace_child(node, node->right_child);
        return node->right_child;
    }
    auto new_child = node->color == Color::BLACK ? new Node() : nullptr;
    replace_child(node, new_child);
    return new_child;
}

void RedBlackTree::remove_element(int value) {
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

    Color tColor = Color::BLACK;
    if (getColor(moved_node) == Color::d_black) {
        setColor(moved_node, Color::RED);
        tColor = Color::d_black;
    }

    if (color == Color::BLACK) {
        fix_delete(moved_node);
        if (tColor == Color::d_black) {
            replace_child(moved_node, nullptr);
        }
    }
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

    auto *sibling = get_sibling(node);

    if (getColor(sibling) == Color::RED) {
        setColor(sibling, Color::BLACK);
        setColor(sibling, Color::BLACK);
        setColor(node->parent, Color::RED);

        if (node == node->parent->left_child) {
            rotate_left(node->parent);
        } else {
            rotate_right(node->parent);
        }

        sibling = get_sibling(node);
    }

    if (is_black(sibling->left_child) &&
        is_black(sibling->right_child)) {
        setColor(sibling, Color::RED);

        if (getColor(node->parent) == Color::RED) {
            setColor(node->parent, Color::BLACK);
        } else {
            fix_delete(node->parent);
        }
    } else {
        bool is_left_child = node == node->parent->left_child;

        if (is_left_child && is_black(sibling->right_child)) {
            setColor(sibling->left_child, Color::BLACK);
            setColor(sibling, Color::RED);
            rotate_right(sibling);
            sibling = node->parent->right_child;
        } else if (!is_left_child && is_black(sibling->left_child)) {
            setColor(sibling->right_child, Color::BLACK);
            setColor(sibling, Color::RED);
            rotate_left(sibling);
            sibling = node->parent->left_child;
        }

        setColor(sibling, node->parent->color);
        setColor(node->parent, Color::BLACK);
        if (is_left_child) {
            setColor(sibling->right_child, Color::BLACK);
            rotate_left(node->parent);
        } else {
            setColor(sibling->left_child, Color::BLACK);
            rotate_right(node->parent);
        }
    }
    setColor(_root, Color::BLACK);
}

Node *RedBlackTree::get_sibling(Node *node) {
    auto parent = node->parent;
    if (parent->left_child == node) {
        return parent->right_child;
    }
    return parent->left_child;
}

bool RedBlackTree::is_black(Node *node) {
    return node == nullptr || node->color == Color::BLACK;
}

void RedBlackTree::print() {
    if (_root != nullptr) {
        print_helper(this->_root, "", true, true);
        return;
    }
    cout << "Tree is empty!" << endl;
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

bool RedBlackTree::find(int value) {
    auto temporary_node = _root;

    while (temporary_node != nullptr) {
        if (temporary_node->value < value) {
            temporary_node = temporary_node->right_child;
        } else if (temporary_node->value > value) {
            temporary_node = temporary_node->left_child;
        } else {
            return true;
        }
    }
    cout << "value: " << value << " has not been found! Returning -1" << endl;
    return false;
}

string RedBlackTree::get_name() {
    return "RedBlackTree";
}

Color RedBlackTree::getColor(Node *node) {
    if (node == nullptr)
        return Color::BLACK;
    return node->color;
}

void RedBlackTree::setColor(Node *node, Color color) {
    if (node == nullptr)
        return;
    node->color = color;
}



