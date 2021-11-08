#include <iostream>
#include "listclasses.h"
using namespace std;

ostream& operator << (ostream& stream, Node*& element)
{
	stream << element->GetNumber();
	return stream;
}

ostream& operator << (ostream& stream, UnorderedList& formular)
{
	if (ifPointerEmpty(formular.GetHead()))
	{
		cout << "List is empty!" << endl;
	}
	else
	{
		Node* node = formular.GetHead();
		while (!(ifPointerEmpty(node)))
		{
			cout << node << " -> ";
			node = node->GetNext();
		}
		cout << endl << endl;
	}
	return stream;
}


int main()
{
	int x = 0;
	setlocale(LC_ALL, "Russian");

	UnorderedList Spisok;

	//Spisok.push_back(56);

	cout << Spisok << endl;

	int options = 0;
	int Number = 0;
	int index = 0;

	cout << endl;

	while (options != 12)
	{
		cout << "Options:\n1) Push back\n2) Push front\n3) Pop back\n4) Pop front\n5) Insert element\n6) Get Element\n";
		cout << "7) Remove Element\n8) Get Size\n9) Clear all\n10) Change Value\n11) Swap elements\n12) Exit\n";

		cout << "Enter option:\n";

		//cin.clear();
		cin >> options;
		try
		{
			switch (options)
			{
			case 1: //Push back
				cout << "Enter number to push back\n";
				cin >> Number;
				Spisok.push_back(Number);
				break;
			case 2: //Push front
				cout << "Enter number to push front\n";
				cin >> Number;
				Spisok.push_front(Number);
				break;
			case 3: //Pop back
				Spisok.pop_back();
				break;
			case 4: //Pop front
				Spisok.pop_front();
				break;
			case 5: //Insert element
				cout << "Enter number to insert:\n";
				cin >> Number;

				cout << "Enter index:\n";
				cin >> index;

				Spisok.insert(Number, index);
				break;
			case 6: //Get element
				cout << "Enter index\n";
				cin >> index;
				cout << Spisok.GetElem(index) << endl;;
				break;
			case 7: //Remove element
				cout << "Enter index\n";
				cin >> index;
				Spisok.remove(index);
				break;
			case 8: //Get size
				cout << "Size is:\n";
				cout << Spisok.get_size() << endl;
				break;
			case 9: //Clear all
				cout << "Clearing...\n";
				Spisok.clear();
				break;
			case 10: //Change value
				cout << "Enter number\n";
				cin >> Number;
				cout << "Enter index\n";
				cin >> index;
				Spisok.set(index, Number);
				break;
			case 11: //Swap elements
				cout << "Enter first index\n";
				cin >> index;

				cout << "Enter second index\n";
				cin >> Number;

				Spisok.swap(index, Number);
				break;
			default:
				cout << "Wrong option, please enter new ...\n";
			}
		}
		catch (invalid_argument& ErrorMessage)
		{
			cout << ErrorMessage.what() << endl;
		}
		catch (out_of_range& ErrorMessage)
		{
			cout << ErrorMessage.what() << endl;
		}

		cout << "\List:\n" << Spisok << endl;
	}
	return 0;
}