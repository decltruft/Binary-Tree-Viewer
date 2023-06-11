#include "describtion.h"

namespace Tree
{
    bool BinaryTree::Add(const Data &inf)
    {
        if (Root == nullptr)
        {
            Root = new Node;
            Root->information = inf;
            Root->left = nullptr;
            Root->right = nullptr;

            return true;
        }

        Node *temp = Root;
        while (1)
        {
            if (inf >= temp->information)
            {
                if (temp->right == nullptr)
                {
                    temp->right = new Node;
                    temp = temp->right;
                    temp->information = inf;

                    temp->left = nullptr;
                    temp->right = nullptr;
                    break;
                }
                else
                {
                    temp = temp->right;
                    continue;
                }
            }
            else if (inf < temp->information)
            {
                if (temp->left == nullptr)
                {
                    temp->left = new Node;
                    temp = temp->left;
                    temp->information = inf;

                    temp->left = nullptr;
                    temp->right = nullptr;
                    break;
                }
                else
                {
                    temp = temp->left;
                    continue;
                }
            }
        }
        fix_bf(&Root);
        return true;
    }

    bool BinaryTree::Remove(const Data &inf)
    {
        if (Root == nullptr)
                    return false;
                if (Root->information == inf)
                {
                    if ((Root->left == nullptr) && (Root->right == nullptr))
                    {
                        Node *temp = Root;
                        Root = nullptr;
                        delete temp;
                        return true;
                    }
                    else if ((Root->left != nullptr) && (Root->right == nullptr))
                    {
                        Node *temp = Root;
                        Root = Root->left;

                        delete temp;
                        return true;
                    }
                    else if ((Root->left == nullptr) && (Root->right != nullptr))
                    {
                        Node *temp = Root;
                        Root = Root->right;

                        delete temp;
                        return true;
                    }
                    else if ((Root->left != nullptr) && (Root->right != nullptr))
                    {
                        Node *temp = Root;
                        Node *root_after_removing = Root->right;
                        Node *root_parent = root_after_removing;

                        while (root_after_removing->left != nullptr)
                        {
                            root_parent = root_after_removing;
                            root_after_removing = root_after_removing->left;
                        }

                        if (root_after_removing == root_parent)
                        {
                            Root = Root->right;
                            Root->left = temp->left;

                            delete temp;
                            return true;
                        }

                        Root = root_after_removing;

                        root_parent->left = root_after_removing->right;
                        root_after_removing->left = temp->left;
                        root_after_removing->right = temp->right;

                        delete temp;

                        fix_bf(&Root);
                        return true;
                    }
                }

                Node *temp_child = Root;
                Node *temp_parent = Root;
                bool turn = true;

                while (temp_child->information != inf)
                {
                    if (inf >= temp_child->information)
                    {
                        if (temp_child->right == nullptr)
                            return false;
                        temp_parent = temp_child;
                        temp_child = temp_child->right;
                        turn = true;
                        continue;
                    }
                    else if (inf < temp_child->information)
                    {
                        if (temp_child->left == nullptr)
                            return false;
                        temp_parent = temp_child;
                        temp_child = temp_child->left;
                        turn = false;
                        continue;
                    }
                }

                if ((temp_child->left == nullptr) && (temp_child->right == nullptr))
                {
                    if (turn)
                        temp_parent->right = nullptr;
                    else
                        temp_parent->left = nullptr;

                    delete temp_child;

                    fix_bf(&Root);
                    return true;
                }
                else if ((temp_child->left != nullptr) && (temp_child->right == nullptr))
                {
                    if (turn)
                        temp_parent->right = temp_child->left;
                    else
                        temp_parent->left = temp_child->left;

                    delete temp_child;

                    fix_bf(&Root);
                    return true;
                }
                else if ((temp_child->left == nullptr) && (temp_child->right != nullptr))
                {
                    if (turn)
                        temp_parent->right = temp_child->right;
                    else
                        temp_parent->left = temp_child->right;

                    delete temp_child;

                    fix_bf(&Root);
                    return true;
                }
                else if ((temp_child->left != nullptr) && (temp_child->right != nullptr))
                {
                    Node *temp = temp_child->right;
                    Node *temp2_parent = temp_parent;

                    while (temp->left != nullptr)
                    {
                        temp2_parent = temp;
                        temp = temp->left;
                    }

                    if (temp2_parent != temp_parent)
                    {
                        temp2_parent->left = nullptr;
                        temp->right = temp2_parent;
                    }

                    temp->left = temp_child->left;

                    if (temp_parent != temp_child)
                    {
                        if (turn)
                            temp_parent->right = temp;
                        else
                            temp_parent->left = temp;
                    }
                    delete temp_child;

                    fix_bf(&Root);
                    return true;
            }
    }

    BinaryTree::BinaryTree(const Data &inf)
    {
        Root = new Node;
        Root->left = nullptr;
        Root->right = nullptr;
        Root->information = inf;
    }

    BinaryTree::BinaryTree(const Data *arr = nullptr, int count_of_elements = 0)
    {
        if (arr == nullptr)
        {
            Root = nullptr;
            return;
        }
        for (int i(0); i < count_of_elements; ++i)
            this + arr[i];
    }

    BinaryTree::BinaryTree(const BinaryTree &bt)
    {
        if (bt.Root == nullptr)
        {
            Root = nullptr;
            return;
        }

        Root = new Node;
        Root->information = bt.Root->information;

        copy_node(Root->left, bt.Root->left);
        copy_node(Root->right, bt.Root->right);
    }

    bool BinaryTree::AddTree(const BinaryTree &bt)
    {
        if (bt.Root == nullptr)
            return false;

        if (Root == nullptr)
        {
            Root = new Node;
            Root->information = bt.Root->information;

            copy_node(Root->left, bt.Root->left);
            copy_node(Root->right, bt.Root->right);

            return true;
        }

        const Node *source = bt.Root;
        Node *destination = Root;

        while (destination != nullptr)
        {
            if (destination->information >= source->information)
            {
                destination = destination->right;
                continue;
            }
            else if (destination->information < source->information)
            {
                destination = destination->left;
                continue;
            }
        }

        destination = new Node;
        copy_node(destination->left, source->left);
        copy_node(destination->right, source->right);

        return true;
    }

    bool BinaryTree::Search(const Data &inf) const
    {
        if(Root == nullptr)
            return false;
        Node *temp = Root;  
        while (temp != nullptr)
        {
            if (inf == temp->information)
            {
                return true;
            }
            else if (inf > temp->information)
            {
                temp = temp->right;
                continue;
            }
            else if (inf < temp->information)
            {
                temp = temp->left;
                continue;
            }
        }
        return false;
    }

    BinaryTree::~BinaryTree()
    {
        if (Root == nullptr)
            return;

        remove_node(Root->left);
        remove_node(Root->right);

        delete Root;
    }
}
