// Question 1
#include <iostream>
using namespace std;

int moveDisks(int n, char source, char auxiliary, char destination) {
    //Type your code here
    static int moves = 0;
    if(n == 0){
        return 0;
    }
    
    moveDisks(n-1, source, destination, auxiliary);
    cout << "move disk " << n << " from rod " << source << " to rod " << destination << endl;
    moves++;
    moveDisks(n-1, auxiliary, source, destination);
    
    return moves;
}

int main() {
    int n;
    cin >> n;
    
    int totalMoves = moveDisks(n, '1', '2', '3');
    
    cout << totalMoves << endl;
    
    return 0;
}


// Question 2
// You are using GCC
#include <iostream>
#include<stdlib.h>

using namespace std;

struct tnode
{
    int data;
    struct tnode *right;
    struct tnode *left;
};

struct tnode *CreateBST(struct tnode *, int);
void Inorder(struct tnode *);
void Preorder(struct tnode *);
void Postorder(struct tnode *);

int main()
{
    struct tnode *root = NULL;
    int choice, item, n, i;
    do
    {
        cin>>choice;
        switch(choice)
        {
        case 1:
            root = NULL;
            cin>>n;
            for(i = 1; i <= n; i++)
            {
                cin>>item;
                root = CreateBST(root,item);
            }
            break;
        case 2:
            cout<<"Inorder: ";
            Inorder(root);
            cout<<"\n";
            break;
        case 3:
            cout<<"Preorder: ";
            Preorder(root);
            cout<<"\n";
            break;
        case 4:
            cout<<"Postorder: ";
            Postorder(root);
            cout<<"\n";
            break;
        case 5:
            exit(0);
            break;
        default:
            break;
        }
    } while(1);
    return 0;
}

struct tnode *CreateBST(struct tnode *root, int item) {
    //Type your code here
    
    
    if(root == NULL){
        tnode* newNode = new tnode();
        newNode->data = item;
        newNode->left = nullptr;
        newNode->right = nullptr;
        root = newNode;
    }else if(root->data < item){
        root->right = CreateBST(root->right, item);
    }else{
        root->left = CreateBST(root->left, item);
    }
    
    return root;
}

void Inorder(struct tnode *root) {
    //Type your code here
    if(!root){
        return;
    }
    
    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
    
}

void Preorder(struct tnode *root) {
    //Type your code here
    if(!root){
        return;
    }
    
    cout << root->data << " ";
    Preorder(root->left);
    Preorder(root->right);
    
}

void Postorder(struct tnode *root) {
    //Type your code here
    if(!root){
        return;
    }
    
    
    Postorder(root->left);
    Postorder(root->right);
    cout << root->data << " ";
    
}

// Question 3
// You are using GCC
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node* insert(Node* root, int data) {
    if (root == NULL)
        return newNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

void inOrderTraversal(Node* root) {
    if (root) {
        inOrderTraversal(root->left);
        cout << root->data << " ";
        inOrderTraversal(root->right);
    }
}

int sumNodes(Node* root) {
    //Type your code here
    if(root == NULL){
        return 0;
    }
    
    return root->data + sumNodes(root->left) + sumNodes(root->right);
    
}

int countNodes(Node* root) {
    //Type your code here
    if(root == NULL){
        return 0;
    }
    
    return 1 + countNodes(root->left) + countNodes(root->right);
    
}

void deleteGreaterThanAverage(Node** root, int avg) {
    //Type your code here
    if(*root == NULL){
        return;
    }
    
    deleteGreaterThanAverage(&(*root)->left, avg);
    deleteGreaterThanAverage(&(*root)->right, avg);
    
    if((*root)->data > avg){
        Node* temp = *root;
        *root = (*root)->left;
        delete temp;
    }
    
}

int main() {
    Node* root = NULL;
    int n, data;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> data;
        root = insert(root, data);
    }

    int sum = sumNodes(root);
    int count = countNodes(root);
    int avg = count ? sum / count : 0;
    deleteGreaterThanAverage(&root, avg);
    inOrderTraversal(root);
    return 0;
}


// Question 4

// You are using GCC
#include <iostream>
using namespace std;

int rec = 0;

void conquer(int arr[], int l, int m, int r, int size) {
    //Type your code here
    int n1 = m-l+1;
    int n2 = r-m;
    
    int arr1[n1], arr2[n2];
    
    for(int i=0; i<n1; i++){
        arr1[i] = arr[l + i];
    }
    
    for(int j=0; j<n2; j++){
        arr2[j] = arr[m + j + 1];
    }
    
    int i=0, j=0, k=l;
    
    while(i<n1 && j<n2){
        if(arr1[i] <= arr2[j]){
            arr[k++] = arr1[i++];
        }else{
            arr[k++] = arr2[j++];
        }
    }
    
    while(i<n1){
        arr[k++] = arr1[i++];
    }
    while(j<n2){
        arr[k++] = arr2[j++];
    }
    rec++;
    cout << "After iteration " << rec << endl;
    for(int i=0; i<size; i++){
        cout << arr[i] << " ";
    }
    
    cout << endl;
    
}

void divide(int arr[], int l, int r, int size) {
    //Type your code here
    if(l < r){
        int m = l + (r-l)/2;
        divide(arr, l, m, size);
        divide(arr, m+1, r, size);
        conquer(arr, l, m, r, size);
    }
    
    
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Given Array" << endl;
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
    divide(arr, 0, n - 1, n);
    cout << "\nSorted Array" << endl;
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    return 0;
}

// Question 5

// You are using GCC
#include <iostream>
#include <string>

using namespace std;

int partition(char arr[], int low, int high) {
    //Type your code here
    char pivot = arr[high];
    int i= low-1;
    
    for(int j = low; j<high;j++){
        if(arr[j] <= pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    
    swap(arr[i+1], arr[high]);
    return i+1;
    
}

void quickSort(char arr[], int low, int high) {
    //Type your code here
    if(low < high){
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot-1);
        quickSort(arr, pivot+1, high);
    }
    
}

int main() {
    int n;
    cin >> n;

    char characters[n];

    for (int i = 0; i < n; ++i) {
        cin >> characters[i];
    }

    quickSort(characters, 0, n - 1);

    for (int i = 0; i < n; ++i) {
        cout << characters[i] << " ";
    }

    return 0;
}