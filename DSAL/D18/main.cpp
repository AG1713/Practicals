#include <iostream>
using namespace std;

class node
{
public:
    int key;
    double prob;
    node *left;
    node *right;

    node(int k, double p)
    {
        key = k;
        prob = p;
        left = right = NULL;
    }
};

node *buildoptimalbst(int keys[], double prob[], int start, int end)
{
    if (start > end)
    {
        return NULL;
    }

    int minindex = start;
    double mincost = prob[start];
    for (int i = start + 1; i <= end; ++i)
    {
        if (prob[i] < mincost)
        {
            mincost = prob[i];
            minindex = i;
        }
    }

    node *Root = new node(keys[minindex], prob[minindex]);

    Root->left = buildoptimalbst(keys, prob, start, minindex - 1);
    Root->right = buildoptimalbst(keys, prob, minindex + 1, end);

    return Root;
}

void inorder(node *t)
{
    if (t == NULL)
    {
        return;
    }

    inorder(t->left);
    cout << "(" << t->key << "," << t->prob << " )";
    inorder(t->right);
}

void preorder(node *t)
{
    if (t == NULL)
    {
        return;
    }

    preorder(t->left);
    preorder(t->right);
    cout << "(" << t->key << "," << t->prob << " )";
}

int main()
{
    int n;
    cout << "Enter the number of nodes " << endl;
    cin >> n;

    int keys[n];
    double prob[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter the node " << i + 1 << ":" << endl;
        cin >> keys[i];

        cout << "Enter the probability of " << i + 1 << ":" << endl;
        cin >> prob[i];
    }

    node *Root;
    Root = buildoptimalbst(keys, prob, 0, n - 1);

    cout << "The inorder traversal " << endl;
    inorder(Root);
    cout<<endl;
    preorder(Root);

    return 0;
}
