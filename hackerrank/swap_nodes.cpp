#include <iostream>
#include <vector>
using namespace std;

/*
 * Complete the swapNodes function below.
 */

typedef struct treeNode {
    treeNode* left;
    treeNode* right;
    int val;
    treeNode(int value) {
        left = nullptr;
        right = nullptr;
        val = value;
    }
} treeNode;

void DFS(treeNode* root, int k, int height = 1) {
    if (!root) return;
    cout << root->val << endl;
    cout << root->left << endl;
    cout << root->right << endl;
    if (k == height) {
        treeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        return;
    } 
    DFS(root->right, k, height+1);
    DFS(root->left, k, height+1);
}

void inOrderTraversal(treeNode* root, vector<int> &results) {
    if (root) {
        inOrderTraversal(root->left, results);
        results.push_back(root->val);
        inOrderTraversal(root->right, results);
    }
}

vector<vector<int>> swapNodes(vector<vector<int>> indexes, vector<int> queries) {
    // Beginning coding journey... 
    treeNode* ptr[indexes.size()];
    for (int i = 0; i < indexes.size(); i++) {
        ptr[i] = new treeNode(i);
    }
    
    for (int i = 0; i < indexes.size(); i++) {
        if (indexes[i][0] != -1) ptr[i]->left = ptr[indexes[i][0]];
        if (indexes[i][1] != -1) ptr[i]->right= ptr[indexes[i][1]];
    }
    
    cout << "Past first" << endl;
    
    vector<vector<int>> result_array; 
    for (int i = 0; i < queries.size(); i++) {
        DFS(ptr[0], queries[i]);
        vector<int> result;
        inOrderTraversal(ptr[0], result);
        result_array.push_back(result);
    }
    return result_array;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> indexes(n);
    for (int indexes_row_itr = 0; indexes_row_itr < n; indexes_row_itr++) {
        indexes[indexes_row_itr].resize(2);

        for (int indexes_column_itr = 0; indexes_column_itr < 2; indexes_column_itr++) {
            cin >> indexes[indexes_row_itr][indexes_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int queries_count;
    cin >> queries_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> queries(queries_count);

    for (int queries_itr = 0; queries_itr < queries_count; queries_itr++) {
        int queries_item;
        cin >> queries_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        queries[queries_itr] = queries_item;
    }

    vector<vector<int>> result = swapNodes(indexes, queries);

    for (int result_row_itr = 0; result_row_itr < result.size(); result_row_itr++) {
        for (int result_column_itr = 0; result_column_itr < result[result_row_itr].size(); result_column_itr++) {
            fout << result[result_row_itr][result_column_itr];

            if (result_column_itr != result[result_row_itr].size() - 1) {
                fout << " ";
            }
        }

        if (result_row_itr != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

