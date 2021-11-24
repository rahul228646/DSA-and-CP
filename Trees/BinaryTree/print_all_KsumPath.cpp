

https://www.geeksforgeeks.org/print-k-sum-paths-binary-tree/

// Time : O(n*h*h) Space : O(h)

// max vector size can be h (height of tree), we visit each node n and calc. sum (max vector size h) and the print it (max vector size h) - n*h*h

void printVector(const vector<int>& v, int i)
{
	for (int j = i; j < v.size(); j++)
		cout << v[j] << " ";
	cout << endl;
}


void printKPathUtil(Node* root, vector<int>& path, int k)
{

	if (!root)
		return;

	path.push_back(root->data);

	printKPathUtil(root->left, path, k);

	printKPathUtil(root->right, path, k);


	int f = 0;
	for (int j = path.size() - 1; j >= 0; j--) {
		f += path[j];

		if (f == k)
			printVector(path, j);
	}

	path.pop_back();
}

void printKPath(Node* root, int k)
{
	vector<int> path;
	printKPathUtil(root, path, k);
}


