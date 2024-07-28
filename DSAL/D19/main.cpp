#include <iostream>
using namespace std;

struct node
{
    int word;
    string mean;
    node *right;
    node *left;
    int hei;
};

class avlt
{
public:
    node *Root;

    avlt()
    {
        Root = NULL;
    }

    int max(int x, int y)
    {
        if (x > y)
        {
            return x;
        }
        else
        {
            return y;
        }
    }

    node *insert(node *t, int w, string m)
    {
        if (t == NULL)
        {
            t = new node;
            t->word = w;
            t->mean = m;
            t->left = NULL;
            t->right = NULL;
            t->hei = 0;
        }

        else if (t->word != w)
        {
            if (t->word > w)
            {
                t->left = insert(t->left, w, m);
            }
            else
            {
                t->right = insert(t->right, w, m);
            }
        }

        else
        {
            cout << "repeated key " << endl;
        }

        t->hei = max(height(t->left), height(t->right)) + 1;

        if (bfactor(t) == 2)
        {
            if (t->left->word > w)
            {
                t = RR(t);
            }
            else
            {
                t = LR(t);
            }
        }

        if (bfactor(t) == -2)
        {
            if (t->right->word > w)
            {
                t = RL(t);
            }
            else
            {
                t = LL(t);
            }
        }

        return t;
    }

    node *Delete(node *t, int w)
    {
        if (t == NULL)
        {
            return t;
            cout << "word is not found " << endl;
        }

        else if (t->word > w)
        {
            t->left = Delete(t->left, w);
        }
        else if (t->word < w)
        {
            t->right = Delete(t->right, w);
        }
        else if (t->left == NULL || t->right == NULL)
        {
            t = t->left ? t->left : t->right;
            cout << "The word is deleted " << endl;
        }
        else
        {
            node *temp = t->right;
            while (temp->left)
            {
                temp = temp->left;
            }
            t->word = temp->word;
            t->right = Delete(t->right, temp->word);
        }

        if (t == NULL)
        {
            return t;
        }

        t->hei = max(height(t->left), height(t->right)) + 1;

        if (bfactor(t) == 2)
        {
            if (bfactor(t->left) >= 0)
            {
                t = RR(t);
            }
            else
            {
                t = LR(t);
            }
        }

        if (bfactor(t) == -2)
        {
            if (bfactor(t->right) <= 0)
            {
                t = LL(t);
            }
            else
            {
                t = RL(t);
            }
        }

        return t;
    }

    int height(node *t)
    {
        if (t == NULL)
        {
            return -1;
        }

        else
        {
            return t->hei;
        }
    }

    int bfactor(node *t)
    {
        int lh = 0;
        int rh = 0;
        if (t == NULL)
        {
            return 0;
        }
        else
        {
            return height(t->left) - height(t->right);
        }
    }

    node *RR(node *t)
    {
        node *temp = t->left;
        t->left = temp->right;
        temp->right = t;
        t->hei = max(height(t->left), height(t->right)) + 1;
        temp->hei = max(height(t->left), height(t->right)) + 1;
        return temp;
    }

    node *LL(node *t)
    {
        node *temp = t->right;
        t->right = temp->left;
        temp->left = t;
        t->hei = max(height(t->left), height(t->right)) + 1;
        temp->hei = max(height(t->left), height(t->right)) + 1;
        return temp;
    }

    node *RL(node *t)
    {
        t->right = RR(t->right);
        return LL(t);
    }

    node *LR(node *t)
    {
        t->left = LL(t->left);
        return RR(t);
    }

    void inorder(node *t)
    {
        if (t != NULL)
        {
            inorder(t->left);
            cout << t->word << " " << t->mean << endl;
            inorder(t->right);
        }
    }
    void preorder(node *t)
    {
        if (t != NULL)
        {
            
            cout << t->word << " " << t->mean << endl;
            preorder(t->left);
            preorder(t->right);
        }
    }
};

int main()
{
    avlt a;
    a.Root = a.insert(a.Root, 10, "t");
    a.Root = a.insert(a.Root, 20, "t1");
    a.Root = a.insert(a.Root, 15, "t2");
    a.Root = a.insert(a.Root, 12, "t3");
    a.Root = a.insert(a.Root, 25, "t4");
    a.Root = a.insert(a.Root, 30, "t5");
    a.Root = a.insert(a.Root, 14, "t6");
    a.Root = a.insert(a.Root, 22, "t7");
    a.Root = a.insert(a.Root, 35, "t8");
    a.Root = a.insert(a.Root, 40, "t9");

    a.inorder(a.Root);

    a.Delete(a.Root, 15);
    a.inorder(a.Root);
    cout<<"\n\n"<<endl;
    a.preorder(a.Root);

    return 0;
}
