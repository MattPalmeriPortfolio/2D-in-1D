#include <iostream>
int* create2DArray(const int rows, const int columns)
{
	int* new2DArray = new int[rows * columns];
	return new2DArray;//new int[rows * columns];
}
void set(int* arr, const int rows, const int columns, const int desiredRow, const int desiredColumn, const int val)
{
	if (desiredRow > rows || desiredColumn > columns)
		std::cout << "Input out of range, exiting.\n";
	else
	{
		arr[desiredRow + desiredColumn - 1] = val;
		std::cout << "Value successfully set.\n";
	}
	return;
}
int get(const int* arr, const int rows, const int columns, const int desiredRow, const int desiredColumn)
{
	if (desiredRow > rows || desiredColumn > columns)
		std::cout << "Input out of range, returning 0.\n";
	else
		return arr[desiredRow + desiredColumn - 1];
	return 0;
}
bool promptContinue()
{
	char next;
	std::cout << "Would you like to continue? y/n: ";
	std::cin >> next;
	if (next == 'y' || next == 'Y')
		return true;
	else
		return false;
}

//main
int main()
{
	using namespace std;
	int* matrix, value, desiredRow, desiredColumn;
	const int ROWS = 3, COLUMNS = 4;
	char getSet;
	matrix = create2DArray(ROWS, COLUMNS);
	do {
		cout << "G to get, S to set\n";
		cin >> getSet;
		if (getSet == 's' || getSet == 'S')
		{
			cout << "Enter the desired value, row, and column, each separated by a space.\n";
			cin >> value >> desiredRow >> desiredColumn;
			set(matrix, ROWS, COLUMNS, desiredRow, desiredColumn, value);
		}
		else if (getSet == 'g' || getSet == 'G')
		{
			cout << "Enter the desired row and column, each separated by a space.\n";
			cin >> desiredRow >> desiredColumn;
			value = get(matrix, ROWS, COLUMNS, desiredRow, desiredColumn);
			cout << "Value: " << value << endl;
		}
		else
			cout << "Bad input.\n";
	} while (promptContinue());
	delete[] matrix;
	return 0;
}