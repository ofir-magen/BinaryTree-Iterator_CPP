#pragma once

#include <iostream>
#include <list>
#include <memory>
#include <sstream>
#include <stdexcept>
#include <stdlib.h>
#include <fstream>
#include <stack>
#include <string>

namespace ariel
{
    template <class T>
    class BinaryTree
    {
        enum class Travel_line
        {
            PREORDER,
            POSTORDER,
            INORDER
        };
        struct Node
        {
            T parameter;
            Node *left = nullptr;
            Node *right = nullptr;

            Node(T d) : parameter(d) {}
        };
        Node *root = nullptr;

        class Iterator_class
        {
        private:
            Node *node;
            Travel_line travel_way;
            std::stack<Node *> nodes_stack;
            std::list<Node *> post_List;

        public:
            Iterator_class(Travel_line t = Travel_line::INORDER, Node *ptr = nullptr)
                : travel_way(t), node(ptr)
            {
                if (node != nullptr)
                {
                    if (travel_way == Travel_line::PREORDER)
                    {
                        if (ptr != nullptr)
                        {
                            nodes_stack.push(ptr);
                            node = nodes_stack.top();
                        }
                        else
                        {
                            node = nullptr;
                        }
                    }
                    if (travel_way == Travel_line::INORDER)
                    {
                        while (node != nullptr)
                        {
                            nodes_stack.push(node);
                            node = node->left;
                        }

                        node = nodes_stack.top();
                        nodes_stack.pop();
                    }
                    if (travel_way == Travel_line::POSTORDER)
                    {
                        while (node != nullptr || !nodes_stack.empty())
                        {
                            if (node != nullptr)
                            {
                                nodes_stack.push(node);
                                node = node->left;
                            }
                            else
                            {
                                Node *temp = nodes_stack.top()->right;
                                if (temp == nullptr)
                                {
                                    temp = nodes_stack.top();
                                    nodes_stack.pop();
                                    post_List.push_back(temp);
                                    while (!nodes_stack.empty() && temp == nodes_stack.top()->right)
                                    {
                                        temp = nodes_stack.top();
                                        nodes_stack.pop();
                                        post_List.push_back(temp);
                                    }
                                }
                                else
                                {
                                    node = temp;
                                }
                            }
                        }
                        node = post_List.front();
                        post_List.pop_front();
                    }
                }
            }
            T &operator*() /* parameter can be changed */
            {
                return node->parameter;
            }
            const T &operator*() const
            {
                return node->parameter;
            }
            T *operator->() const
            {
                return &(node->parameter);
            }
            Iterator_class &operator++()
            {
                if (travel_way == Travel_line::PREORDER)
                {
                    if (!nodes_stack.empty())
                    {
                        Node *temp = node;
                        nodes_stack.pop();
                        if (temp->right != nullptr)
                        {
                            nodes_stack.push(temp->right);
                        }
                        if (temp->left != nullptr)
                        {
                            nodes_stack.push(temp->left);
                        }
                        if (nodes_stack.empty())
                        {
                            node = nullptr;
                        }
                        else
                        {
                            node = nodes_stack.top();
                        }
                    }
                    else
                    {
                        node = nullptr;
                    }
                }

                if (travel_way == Travel_line::INORDER)
                {
                    if (!nodes_stack.empty() || node->right != nullptr)
                    {
                        node = node->right;

                        while (node != nullptr)
                        {
                            nodes_stack.push(node);
                            node = node->left;
                        }
                        node = nodes_stack.top();
                        nodes_stack.pop();
                    }
                    else
                    {
                        node = nullptr;
                    }
                }

                if (travel_way == Travel_line::POSTORDER)
                {
                    if (post_List.size() != 0)
                    {
                        node = post_List.front();
                        post_List.pop_front();
                    }
                    else
                    {
                        node = nullptr;
                    }
                }
                return *this;
            }

            Iterator_class operator++(int)
            {
                Iterator_class befor_add = *this;
                ++(*this);
                return befor_add;
            }

            bool operator==(const Iterator_class &other) const
            {
                return node == other.node;
            }

            bool operator!=(const Iterator_class &other) const
            {
                return node != other.node;
            }

        }; // End - Iterator_class

    public:
        // Constructors
        BinaryTree<T>()
        {
        }
        ~BinaryTree<T>()
        {
            if (root != nullptr)
            {
                delete root;
            }
        }

        void copyRoot(Node *&main_root, Node *&add_from)
        {
            if (add_from == NULL)
            {
                main_root = NULL;
            }
            else
            {
                main_root = new Node(add_from->parameter);
                copyRoot(main_root->left, add_from->left);
                copyRoot(main_root->right, add_from->right);
            }
        }

        // Copy Constractor
        BinaryTree<T>(BinaryTree<T> &other)
        {
            if (other.root == nullptr)
            {
                this->root = nullptr;
            }
            else
            {
                copyRoot(this->root, other.root);
            }
        }

        // Move constractor
        BinaryTree<T>(BinaryTree<T> &&other) noexcept
        {
            this->root = other.root;
            other.root = nullptr;
        }

        BinaryTree<T> &operator=(BinaryTree<T> other)
        {
            if (this == &other)
            {
                return *this;
            }
            if (root != nullptr)
            {
                delete root;
            }
            copyRoot(this->root, other.root);
            return *this;
        }

        BinaryTree<T> &operator=(BinaryTree<T> &&other) noexcept
        {
            this->root = other.root;
            other.root = nullptr;
            return *this;
        }

        BinaryTree<T> &addTo(const T &add_in, const T &the_add, int side)
        {
            if (this->root == nullptr)
            {
                throw std::invalid_argument{"BinaryTree not exist"};
            }
            std::stack<Node *> nodes;
            Node *curent = root;
            while (curent != nullptr || !nodes.empty())
            {
                while (curent != nullptr)
                {
                    nodes.push(curent);
                    curent = curent->left;
                }
                curent = nodes.top();
                nodes.pop();
                if (curent->parameter == add_in)
                {
                    if (side == 0) // Add Left
                    {
                        if (curent->left == nullptr)
                        {
                            curent->left = new Node(the_add);
                        }
                        else
                        {
                            curent->left->parameter = the_add;
                        }
                    }
                    else // Add right
                    {
                        if (curent->right == nullptr)
                        {
                            curent->right = new Node(the_add);
                        }
                        else
                        {
                            curent->right->parameter = the_add;
                        }
                    }
                    return *this;
                }
                curent = curent->right;
            }
            throw std::invalid_argument{"the Node is not exist in the BinaryTree"};
        }

        BinaryTree &add_root(const T &a)
        {
            if (root == nullptr)
            {
                this->root = new Node(a);
            }
            else
            {
                this->root->parameter = a;
            }
            return *this;
        }

        BinaryTree<T> &add_left(const T &add_in, const T &the_add)
        {
            if (root == nullptr)
            {
                throw std::invalid_argument{"BinaryTree not exist"};
            }
            return this->addTo(add_in, the_add, 0);
        }

        BinaryTree<T> &add_right(const T &add_in, const T &the_add)
        {
            if (root == nullptr)
            {
                throw std::invalid_argument{"BinaryTree not exist"};
            }

            return this->addTo(add_in, the_add, 1);
        }

        Iterator_class begin_preorder()
        {
            return Iterator_class(Travel_line::PREORDER, root);
        }

        Iterator_class end_preorder()
        {
            return Iterator_class(Travel_line::PREORDER, nullptr);
        }

        Iterator_class begin_inorder()
        {
            return Iterator_class(Travel_line::INORDER, root);
        }

        Iterator_class end_inorder()
        {
            return Iterator_class(Travel_line::INORDER, nullptr);
        }

        Iterator_class begin_postorder()
        {
            return Iterator_class(Travel_line::POSTORDER, root);
        }

        Iterator_class end_postorder()
        {
            return Iterator_class(Travel_line::POSTORDER, nullptr);
        }

        Iterator_class begin()
        {
            return this->begin_inorder();
        }

        Iterator_class end()
        {
            return this->end_inorder();
        }

        friend std::ostream &operator<<(std::ostream &os, const BinaryTree<T> &bt)
        {
            return os;
        }
    };
}