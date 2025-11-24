#include <bits/stdc++.h>
using namespace std;

struct MinHeapNode
{
    // one of the input characters
    char data;

    // freq of character
    unsigned freq;

    // left and right child
    MinHeapNode *left, *right;

    MinHeapNode(char data, unsigned freq)
    {
        left = right = NULL;
        this->data = data;
        this->freq = freq;
    }
};

struct compare
{
    bool operator()(MinHeapNode *l, MinHeapNode *r)
    {
        return (l->freq > r->freq);
    }
};

void printCodes(struct MinHeapNode *root, string str)
{
    if (!root)
        return;
    if (root->data != '$')
        cout << root->data << ": " << str << "\n";

    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}

void HuffmanCodes(char data[], int freq[], int size)
{
    struct MinHeapNode *left, *right, *top;

    // create a min heap & insert all characters of data[]
    priority_queue<MinHeapNode *, vector<MinHeapNode *>, compare>
        minHeap;

    for (int i = 0; i < size; ++i)
        minHeap.push(new MinHeapNode(data[i], freq[i]));

    // iterate while size of heap doesnt become 1
    while (minHeap.size() != 1)
    {

        // extract the 2 mini. freq items from min heap
        left = minHeap.top();
        minHeap.pop();

        right = minHeap.top();
        minHeap.pop();

        top = new MinHeapNode('$', left->freq + right->freq);

        top->left = left;
        top->right = right;

        minHeap.push(top);
    }
    // print huffman codes using the huffman tree built above
    printCodes(minHeap.top(), " ");
}
int main()
{
    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};

    int size = sizeof(arr) / sizeof(arr[0]);

    HuffmanCodes(arr, freq, size);
    return 0;
}