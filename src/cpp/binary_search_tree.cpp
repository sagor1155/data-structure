#include <iostream>
#include <queue>

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int data, Node* left, Node* right){
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

struct Node* insert(Node* node, int data){
    if(node==NULL){
        node = new Node(data, NULL, NULL);
    }else{
        if(data < node->data){
            node->left = insert(node->left, data);
        }else{
            node->right = insert(node->right, data);
        }
    }
    return node;
}

void preorder(Node* node){
    if(node==NULL) return;
    std::cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
}

void inorder(Node* node){
    if(node==NULL) return;
    inorder(node->left);
    std::cout << node->data << " ";
    inorder(node->right);
}

void postorder(Node* node){
    if(node==NULL) return;
    postorder(node->left);
    postorder(node->right);
    std::cout << node->data << " ";
}

void levelorder(Node* node){
    if(node==NULL) return;
    std::queue<Node*> q;
    q.push(node);

    while(!q.empty()){
        Node* current = q.front();
        std::cout << current->data << " ";
        if(current->left != NULL) q.push(current->left);
        if(current->right != NULL) q.push(current->right);
        q.pop();
    }
    std::cout << std::endl;
}

Node* search(Node* node, int data){
    if(node==NULL || node->data == data){
        return node;
    } 

    if(data < node->data){
        return search(node->left, data);
    }else{
        return search(node->right, data);
    }
}

Node* findMin(Node* node){
    Node* curr = node;
    while(curr != NULL && curr->left != NULL){
        curr = curr->left;
    }
    return curr;
}

Node* remove(Node* node, int data){
    if(node==NULL) return node;

    if(data < node->data) 
        node->left = remove(node->left, data);
    else if(data > node->data) 
        node->right = remove(node->right, data);
    else{
        // node to be removes - is a leaf node
        if(node->left==NULL && node->right==NULL){
            delete node;
            node = NULL;
        }

        // node to be removes - has only left node
        else if(node->right==NULL){
            Node *temp = node;
            node = node->left;
            delete temp;
        }

        // node to be removes - has only right node
        else if(node->left==NULL){
            Node* temp = node;
            node = node->right;
            delete temp;
        }

        // node to be removes - has both left & right node
        else{
            Node* temp = findMin(node->right);
            node->data = temp->data;
            node->right = remove(node->right, temp->data);
        }
    }

    return node;
}

int findHeight(Node* node){
    if(node==NULL) return -1;
    int h_left = findHeight(node->left);
    int h_right = findHeight(node->right);
    return std::max(h_left, h_right)+1;
}

int main(int argc, char** argv){

    Node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    std::cout << "Height: " << findHeight(root) << std::endl;

    std::cout << "Preorder traverse: " << std::endl;
    preorder(root);
    std::cout << std::endl;

    std::cout << "Inorder traverse: " << std::endl;
    inorder(root);
    std::cout << std::endl;

    std::cout << "Postorder traverse: " << std::endl;
    postorder(root);
    std::cout << std::endl;

    std::cout << "Levelorder traverse: " << std::endl;
    levelorder(root);
    std::cout << std::endl;

    Node* node_query = search(root, 80);
    if(node_query)
        std::cout << "Node found: " << node_query->data << std::endl;
    else
        std::cout << "Node Not found!" << std::endl;

    remove(root, 30);
    std::cout << "Inorder traverse: " << std::endl;
    inorder(root);
    std::cout << std::endl;

    std::cout << "Height: " << findHeight(root) << std::endl;
    return 0;
}


