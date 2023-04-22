//
// Created by Piotr Szczypior on 03/04/2023.
//

#include "RedBlackTree.h"
#include <iostream>

using namespace std;

RedBlackTree::RedBlackTree() {
    // initialize pointer
    _root = nullptr;
}

void RedBlackTree::rotate_right(Node *node_to_rotate) {
    Node *left_node = node_to_rotate->left_child;

    node_to_rotate->left_child = left_node->right_child;
    if (node_to_rotate->left_child != nullptr) {
        // assign parent if new left child is not nullptr
        node_to_rotate->left_child->parent = node_to_rotate;
    }
    // assign new parent
    left_node->parent = node_to_rotate->parent;
    if (node_to_rotate->parent == nullptr) {
        // case rotating node is root. Assign new root
        _root = left_node;
    } else if (node_to_rotate == node_to_rotate->parent->left_child) {
        // assign new left child of parent to rotate
        node_to_rotate->parent->left_child = left_node;
    } else {
        // assign new right child of parent to rotate
        node_to_rotate->parent->right_child = left_node;
    }
    // new right child and parenthood of
    // previous left child of node to rotate
    left_node->right_child = node_to_rotate;
    node_to_rotate->parent = left_node;
}

void RedBlackTree::rotate_left(Node *node_to_rotate) {
    Node *right_child = node_to_rotate->right_child;

    node_to_rotate->right_child = right_child->left_child;
    if (node_to_rotate->right_child != nullptr) {
        // assign parent if new right child is not nullptr
        node_to_rotate->right_child->parent = node_to_rotate;
    }
    // assign parenthood
    right_child->parent = node_to_rotate->parent;
    if (node_to_rotate->parent == nullptr) {
        // new root
        _root = right_child;
    } else if (node_to_rotate == node_to_rotate->parent->left_child) {
        // assign new left child of parent to rotate
        node_to_rotate->parent->left_child = right_child;
    } else {
        // assign new right child of parent to rotate
        node_to_rotate->parent->right_child = right_child;
    }
    // new left child and parenthood of
    // previous right child of node to rotate
    right_child->left_child = node_to_rotate;
    node_to_rotate->parent = right_child;
}

void RedBlackTree::fix_insert(Node *node) {
    Node *parent = node->parent;

    if (parent == nullptr) {
        return;
    }

    if (is_black(parent)) {
        return;
    }

    Node *grandparent = parent->parent;

    // case when parent is _root
    if (grandparent == nullptr) {
        setColor(parent, Color::BLACK);
        return;
    }
    // get uncle
    auto uncle = this->get_uncle(node);

    // If uncle exists and it is red, change the colors of parent,
    // grandparent and uncle and fix once more on grandparent
    if (uncle != nullptr && getColor(uncle) == Color::RED) {

        setColor(parent, Color::BLACK);
        setColor(grandparent, Color::RED);
        setColor(uncle, Color::BLACK);
        fix_insert(grandparent);

        // If current node is on the right of parent and
        // parent is on the left of grandparent, perform
        // a left rotation on parent
        // and then a right rotation on grandparent.
        // Change colors of parent and grandparent
    } else if (parent == grandparent->left_child) {
        if (node == parent->right_child) {
            rotate_left(parent);
            parent = node;
        }
        rotate_right(grandparent);
        setColor(parent, Color::BLACK);
        setColor(grandparent, Color::RED);

        // If current node is on the left of parent and
        // parent is on the right of grandparent,
        // perform a right rotation on parent
        // and then a left rotation on grandparent.
        // Change colors of parent and grandparent
    } else {
        if (node == parent->left_child) {
            rotate_right(parent);
            parent = node;
        }
        rotate_left(grandparent);
        setColor(parent, Color::BLACK);
        setColor(grandparent, Color::RED);
    }
}

void RedBlackTree::push_back(int value) {
    // create new node
    Node *new_node = new Node(value);

    Node *node = _root;
    Node *previous_to_node = nullptr;

    // find place by traversing
    while (node != nullptr) {
        previous_to_node = node;
        if (value < node->value) {
            node = node->left_child;
        } else {
            node = node->right_child;
        }
    }

    // previous is null means tree is empty
    // new node will be root
    if (previous_to_node == nullptr) {
        _root = new_node;
        _root->color = Color::BLACK;
        return;
    }

    // Insert the new node as a child of the previous node based on the value
    if (value < previous_to_node->value) {
        previous_to_node->left_child = new_node;
    } else {
        previous_to_node->right_child = new_node;
    }
    // maintain hierarchy
    new_node->parent = previous_to_node;

    // case if parent of parent is
    // null no fix is furthermore required
    if (new_node->parent->parent == nullptr) {
        return;
    }

    // fix tree
    this->fix_insert(new_node);
    // set root as black
    setColor(_root, Color::BLACK);
}

Node *RedBlackTree::get_uncle(Node *node) {
    // return correct uncle of node
    auto grandparent = node->parent->parent;

    if (grandparent->left_child == node->parent) {
        return grandparent->right_child;
    }
    return grandparent->left_child;
}

Node *RedBlackTree::delete_node(Node *node) {
    if (node->left_child != nullptr) {
        // Replace the node with its left child
        replace_child(node, node->left_child);
        return node->left_child;

    } else if (node->right_child != nullptr) {
        // Replace the node with its right child
        replace_child(node, node->right_child);
        return node->right_child;
    }

    // Create a new child node with color BLACK
    // if the node to be deleted is also BLACK,
    // otherwise set to null
    auto new_child = is_black(node) ? new Node() : nullptr;
    // Replace the node with the new child
    replace_child(node, new_child);
    return new_child;
}

void RedBlackTree::remove_element(int value) {
    Node *node_to_delete = _root;

    // traverse and find node to delete
    while (node_to_delete != nullptr) {
        if (node_to_delete->value > value) {
            node_to_delete = node_to_delete->left_child;
        } else if (node_to_delete->value < value) {
            node_to_delete = node_to_delete->right_child;
        } else {
            break;
        }
    }

    // if not found then return
    if (node_to_delete == nullptr) {
        cout << "Value has not been found" << endl;
        return;
    }
    Node *moved_node;
    Color color;

    // If the node to be deleted has at most one child
    if (node_to_delete->left_child == nullptr ||
        node_to_delete->right_child == nullptr) {
        color = node_to_delete->color;
        moved_node = delete_node(node_to_delete);
    } else {
        // find the minimum successor of the node to be deleted,
        // copy its value to the node to be deleted,
        // delete the minimum successor,
        auto minimum_successor = find_minimum(node_to_delete);
        node_to_delete->value = minimum_successor->value;
        moved_node = delete_node(minimum_successor);
        color = minimum_successor->color;
    }

    // Fix the tree if the moved node is d_black if it is a double black node
    // double black is when node and node's parent are black
    // and this way this hierarchy is violating RBtree properties
    Color tColor = Color::BLACK;
    if (getColor(moved_node) == Color::d_black) {
        setColor(moved_node, Color::RED);
        tColor = Color::d_black;
    }

    if (color == Color::BLACK) {
        // fix tree
        fix_delete(moved_node);
        if (tColor == Color::d_black) {
            // if color was double black replace child with null
            replace_child(moved_node, nullptr);
        }
    }
}

void RedBlackTree::replace_child(Node *old_child, Node *new_child) {
    auto parent = old_child->parent;

    // If the old child node is the root of
    // the tree, set the new child node as the new root
    if (parent == nullptr) {
        _root = new_child;
    }
        // replace the old child node
        // with the new child node as a child of its parent node
    else if (parent->left_child == old_child) {
        parent->left_child = new_child;
    } else if (parent->right_child == old_child) {
        parent->right_child = new_child;
    }

    // If the new child node is not null,
    // set its parent to the old child node's parent
    if (new_child != nullptr) {
        new_child->parent = parent;
    }
}

Node *RedBlackTree::find_minimum(Node *node) {
    // traverse throughout tree and find minimum node
    while (node->left_child != nullptr) {
        node = node->left_child;
    }
    return node;
}

void RedBlackTree::fix_delete(Node *node) {
    // no need for further fix
    if (node == _root) {
        return;
    }

    auto *sibling = get_sibling(node);

    // If the sibling is red
    // recolor and rotate to make it black
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

    // If the sibling and its children are black
    // recolor and fix the parent
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
        // if sibling's right child is black and node is left
        if (is_left_child && is_black(sibling->right_child)) {
            setColor(sibling->left_child, Color::BLACK);
            setColor(sibling, Color::RED);
            rotate_right(sibling);
            sibling = node->parent->right_child;
            // if node is right and left child of sibling is black
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
    // traverse throughout tree and find searched for value
    while (temporary_node != nullptr) {
        if (temporary_node->value < value) {
            temporary_node = temporary_node->right_child;
        } else if (temporary_node->value > value) {
            temporary_node = temporary_node->left_child;
        } else {
            return true;
        }
    }
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



