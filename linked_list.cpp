class Node {
public:
    int row, col, val;
    Node* next;
    Node(int r, int c, int v)
    {
        row = r;
        col = c;
        val = v;
        next = nullptr;
    }
};

class SparseMatrix {
private:
    int rows, cols, non_zero;
    Node* head;

public:
    SparseMatrix(int r, int c, int nz)
    {
        rows = r;
        cols = c;
        non_zero = nz;
        head = new Node(-1, -1, -1);
    }

    void insert(int r, int c, int v)
    {
        Node* temp = new Node(r, c, v);
        temp->next = head->next;
        head->next = temp;
    }

    void display()
    {
        Node* temp = head->next;
        while (temp != nullptr) {
            cout << "(" << temp->row << ", " << temp->col << ") " << temp->val << endl;
            temp = temp->next;
        }
    }
};
