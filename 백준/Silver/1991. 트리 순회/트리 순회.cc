#include <iostream>
#include <unordered_map>

struct TreeNode
{
    char left;
    char right;
};

std::unordered_map<char, TreeNode> tree;

void preorder(char node)
{
    if (node == '.')
        return;
    std::cout << node;
    preorder(tree[node].left);
    preorder(tree[node].right);
}

void inorder(char node)
{
    if (node == '.')
        return;
    inorder(tree[node].left);
    std::cout << node;
    inorder(tree[node].right);
}

void postorder(char node)
{
    if (node == '.')
        return;
    postorder(tree[node].left);
    postorder(tree[node].right);
    std::cout << node;
}

int main()
{
    int N;
    std::cin >> N;

    for (int i = 0; i < N; ++i)
    {
        char root, left, right;
        std::cin >> root >> left >> right;
        tree[root] = {left, right};
    }

    preorder('A');
    std::cout << std::endl;
    inorder('A');
    std::cout << std::endl;
    postorder('A');
    std::cout << std::endl;

    return 0;
}
