#ifndef DESCRIBTION_H   //специальные макросы. создаются автоматически. вникать не надо
#define DESCRIBTION_H

#include <iostream>

namespace Tree    // дерево в своё пространстве имён
{
    typedef int Data; // мы работаем с какими-то данными а не с интом. поэтому условно int заменяем на Data (даём ему второе имя)

    struct Node						// Структура для описания узла дерева. В качестве полей имеет поле для хранения информации а так же указатели на левый и правый элементы. Т.к. Это БИНАРНОЕ дерево, то максимальное кол-во дочерних узлов - 2, потому что это блять логично.
    {
        Data  information;			// Поле информации
        Node *left;					// Указатель на левый элемент
        Node *right;				// Указатель на правый элемент
    };

    class BinaryTree
    {
    public:                     // публичные поля. доступны для пользователя. содержат методы
        BinaryTree(const Data &inf);											    // Инициализация only корневого элемента.
        BinaryTree() {Root = nullptr;}
        BinaryTree(const Data *arr, int count_of_elements);							// Инициализация дерева путём передачи в конструктор массива (может быть неотсортирован) и его размера.
        BinaryTree(const BinaryTree &bt);											// Инициализация дерева через другое дерево (полное его копирование через конструктор копирования).
        BinaryTree(const BinaryTree *bt) { if(bt == nullptr){ Root = nullptr; return; } Root = bt->Root; }

        bool AddTree(const BinaryTree &bt);											// Метод добавления поддерева (другого дерева) в структуру. При благоприятном исходе возвращает true, иначе false.
        bool Add(const Data &);             // добавление элемента
        bool Remove(const Data &);          // удаление элемента

        bool Search(const Data &inf) const;                                         // Метод поиска элемента внутри дерева. При благоприятном исходе возвращает true, иначе false (!!! МОЖЕТ ИЗМЕНИТЬСЯ В ПРОЦЕССЕ !!!).
        const Node* get_Root() const {return Root;} // метод возврата указателя на корень дерева. т.к. подразумевается что мы не будем менять значение по корню, то указатель константный.

        ~BinaryTree();																// Деструктор класса. При выходе из блока операторов уничтожает объект этого класса, который находился в нём. Поочерёдно удаляет все связи и узлы, начиная с "листьев", дабы не было утечки памяти (memory leak).
    private:        // приватные поля. содержат указатель на корень дерева и функции, вызываемые ТОЛЬКО из методов, но не могут быть вызваны пользователем класса

        Node *Root;						// Указатель на корневой элемент структуры. Т.к. между всеми родительскими и дочерними узлами существует связь в виде указателей, то можно ограничиться только адресом корневого элемента, ведь добраться до других не составит особо труда епт

        void copy_node(Node *destination, const Node *source)   // функция копирования узлов (рекурсивная, используется в методе копирования дерева в поддерево другого дерева). принимает первым аргументом пункт назначения копирования, второй - откуда копируем. поэтому он const т.к. не будет изменяться
        {
            if (source == nullptr)          // если источник ничего не имеет
            {
                destination = nullptr;  // ничего не копируем
                return; // выходим из функции
            }

            destination = new Node; // выделяем память для нового узла
            destination->information = source->information; // копируем ин-цию туда из источника

            copy_node(destination->left,  source->left); // рекурсивно вызываем для левого поддерева и правого (строчка снизу)
            copy_node(destination->right, source->right);
        }

        void remove_node(Node *node) // удаление узлов (рекурсивная, используется в деструкторе класса)
        {
            if (node == nullptr) // если удалять нечего
                return; //выходим

            remove_node(node->left); //доходим до листьев в левом поддереве и в правом (строка ниже)
            remove_node(node->right);

            delete node; // удаляем элемент, если у него нет потомков (удаляем листья). после удаления узел выше по иерархии так же лишится потомка, поэтому в последствии так же может быть удалён
            return;   // выходим после удаления по рекурсии выше.
        }

        // дальше при работе с узлами используется ** (указатель на указатель). при передаче просто по указателю создаётся его локальная копия с параметром от передаваемого. если мы передаём указатель на указатель, то будет изменяться сам передаваемый указатель

        int fix_bf(Node **root = nullptr) // функция балансировки. в качестве аргумента указатель на указатель корня
        {
            if (*root == nullptr) // в узле пусто, то выходим
                return 0;

            int left_subt_height  = fix_bf(&(*root)->left); // переменная баланса левого поддерева узла. рекурсивно вызывается fix_bf с передачей адреса указателя на левый узел от текущего (левое поддерево)
            int right_subt_height = fix_bf(&(*root)->right); // переменная баланса правого поддерева узла. рекурсивно вызывается fix_bf с передачей адреса указателя на правый узел от текущего (правое поддерево)

            if (left_subt_height == 2) // если в левом поддереве баланс равен 2 (разбаланс имеется)
            {
                if (left_subt_height - right_subt_height <= 1) // если между правым и левым поддеревьями разница в 1 узел, то возвращаем 1 вверх по рекурсии, т.к. это допустимо
                    return 1;

                if ((*root)->left->left != nullptr)             //иначе
                    LL_Rotation(root, (*root)->left->left);
                else
                    LR_Rotation(root, (*root)->left->right);
                return 1;
            }
            else if (right_subt_height == 2)
            {
                if (right_subt_height - left_subt_height <= 1)
                    return 1;

                if ((*root)->right->right != nullptr)
                    RR_Rotation(root, (*root)->right->right);
                else
                    RL_Rotation(root, (*root)->right->left);

                return 1;
            }

            if (left_subt_height == right_subt_height)
                return 1;

            else if (right_subt_height > left_subt_height)
                return right_subt_height + 1;

            else if (left_subt_height > right_subt_height)
                return left_subt_height + 1;
        }

        void LL_Rotation(Node **parent, Node *child) // поворот при случае расбалансировки "лево-лево" относительно проверяемого узла
        {
            Node *temp = *parent;
            *parent = (*parent)->left;
            (*parent)->right = temp;
            temp->left = nullptr;
        }

        void LR_Rotation(Node **parent, Node *child) // поворот при случае расбалансировки "лево-право" относительно проверяемого узла
        {
            Node *temp = *parent;
            *parent = child;
            temp->left->right = nullptr;
            (*parent)->right = temp;
            (*parent)->left = temp->left;
            temp->left = nullptr;
        }

        void RL_Rotation(Node **parent, Node *child) // поворот при случае расбалансировки "право-лево" относительно проверяемого узла
        {
            Node *temp = *parent;
            *parent = child;
            temp->right->left = nullptr;
            (*parent)->left = temp;
            (*parent)->right = temp->right;
            temp->right = nullptr;
        }

        void RR_Rotation(Node **parent, Node *child) // поворот при случае расбалансировки "право-право" относительно проверяемого узла
        {
            Node *temp = *parent;       // временный указатель
            *parent = (*parent)->right;
            (*parent)->left = temp;
            temp->right = nullptr;
        }
/*
        void BigL_Rotation(Node **parent, Node *child)
        {
            Node *temp = *parent;
            *parent = child;
            temp->right = (*parent)->left;
            (*parent)->left = temp;
        }

        void BigR_Rotation(Node **parent, Node *child)
        {
             Node *temp = *parent;
             *parent = child;
             temp->left = (*parent)->right;
             (*parent)->right = temp;
        } */
    };

}

#endif DESCRIBTION_H // специальный макрос. создаётся автоматтиески
