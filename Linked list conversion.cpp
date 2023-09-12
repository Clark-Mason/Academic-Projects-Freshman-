////Mason Clark(MXC220017)
//#include <iostream>
//#include <iomanip>
//#include <fstream>
//#include <string>
//#include <map>
//using namespace std;
//const string database = "numbers.txt";
//
//struct node{
//    int aNum;
//    string rNum;
//    node *next;
//};
//
//int romanConversion(const string &romanNumeral)
//{
//    //Dictionary for conversion
//    map<char, int> roman_to_arabic{{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}}; //Binary Search tree/ dictionary
//    int sum = 0;
//    for (long unsigned int i = 0; i < romanNumeral.length(); i++)
//    {
//        int curr = roman_to_arabic[romanNumeral[i]];
//        // Get the next roman numeral value or 0 if there is no next numeral
//        int next = (i + 1 < romanNumeral.length()) ? roman_to_arabic[romanNumeral[i + 1]] : 0; //Bounds checking
//        sum += (next > curr) ? -curr : curr; //Determining roman numeral placement for addition to sum
//    }
//    return sum;
//}
//
///* Converts arabic to roman numerals for each iteration if the value is greater than the arabic numeral
// it will subtract that value and add its respective value in roman numeral form if value is greater than arabic numeral
// continue iteration through arrays*/
//string arabicConversion(int arabicNumeral,string romanNumeral = "")
//{
//    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
//    string symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
//
//    for (int i = 0; i < 13 && arabicNumeral > 0; i++) //Iterate to find greater and matching element
//    {
//        while (arabicNumeral >= values[i]) // while that element is greater or equal to will subtract and print corresponding numeral to empty string
//        {
//            arabicNumeral -= values[i];
//            romanNumeral += symbols[i];
//        }
//    }
//    return romanNumeral;
//}
//
//node linkList(node *&head, int arab, const string &roman)
//{
//    // Create a new node and set its fields to the input values.
//    node *newNode = new node;
//    newNode->aNum = arab;
//    newNode->rNum = roman;
//
//    // Set the new node's next pointer to the current head node, effectively inserting it at the beginning of the list.
//    newNode->next = head;
//
//    // Update the head pointer to point to the new node.
//    head = newNode;
//
//    // Return the head node.
//    return *head;
//}
//
///**
// * This function merges two sorted linked lists into a new sorted list.
// *
// * @param left - a pointer to the head node of the first list to be merged
// * @param right - a pointer to the head node of the second list to be merged
// * @param sVal - an additional input value that determines whether the lists are merged based on arabic numbers or roman numerals
// * @return a pointer to the head node of the merged list
// */
//node* mergeLists(node* left, node* right,int sVal)
//{
//    node* merge; // Pointer to the current node in the merged list
//
//    /* Base cases */
//    if (left == nullptr)
//        return right;
//    else if (right == nullptr)
//        return left;
//
//    // Determine whether to compare arabic numbers or roman numerals
//    if(sVal == 1)
//    {
//        // Compare the roman numerals of the nodes in each list
//        if(left->rNum <= right->rNum)
//        {
//            merge = left;
//            merge->next = mergeLists(left->next, right, sVal);
//        }
//        else
//        {
//            merge = right;
//            merge->next = mergeLists(left, right->next, sVal);
//        }
//    }
//    else
//    {
//        // Compare the arabic numbers of the nodes in each list
//        if(left->aNum <= right->aNum)
//        {
//            merge = left;
//            merge->next = mergeLists(left->next, right, sVal);
//        }
//        else
//        {
//            merge = right;
//            merge->next = mergeLists(left, right->next, sVal);
//        }
//    }
//
//    return merge; // Return a pointer to the head of the merged list
//}
//
///**
// * This function recursively sorts and merges a linked list using the merge sort algorithm. It divides the
// * list into two halves using the fast and slow pointer approach, then recursively sorts each half before merging
// * them together. The merge process involves comparing the values of the nodes in each half and adding them to a
// * new list in sorted order. Once one half has been fully merged, the remaining nodes from the other half are
// * simply appended to the end of the new list. The final result is a sorted linked list.
// *
// * @param head - a reference to the head node of the list to be sorted
// * @param sVal - an additional input value that may be used in the merge process
// * @return a pointer to the head node of the sorted list
// */
//
//node* mergeSort(node *&head, int sVal)
//{
//    // Base case: the list is empty or has only one node, so it is already sorted.
//    if (head == nullptr || head->next == nullptr)
//    {
//        return head;
//    }
//
//    // Find the middle node of the list using the slow and fast pointer technique.
//    node* slow = head;
//    node* fast = head->next;
//    while (fast != nullptr && fast->next != nullptr)
//    {
//        slow = slow->next;
//        fast = fast->next->next;
//    }
//    node* mid = slow->next;
//    slow->next = nullptr;
//
//    // Recursively sort the two halves of the list.
//    node* left = mergeSort(head, sVal);
//    node* right = mergeSort(mid, sVal);
//
//    // Merge the sorted halves of the list and return the new head node.
//    return head = mergeLists(left, right, sVal);
//}
//
//// This function searches the linked list for a node that matches the input search value.
//// It iterates through the linked list using a while loop until it finds a match or reaches the end.
//// If a match is found, it returns true, otherwise it returns false.
//bool searchList(node* head, const string &search)
//{
//    node* ptr = head; // pointer to traverse the linked list
//    while (ptr != nullptr) // while there are still nodes to traverse
//    {
//        if (to_string(ptr->aNum) == search || ptr->rNum == search) // if current node matches search value
//        {
//            return true; // return true if match is found
//        }
//        ptr = ptr->next; // move on to the next node in the list
//    }
//    return false; // return false if the end of the list is reached without a match
//}
//
//void printSort(node* head,int sortVal)
//{
//    if(head == nullptr)
//    {
//        return;
//    }
//    if(sortVal == 1) // sorting by roman numeral
//    {
//        cout << head->rNum << endl; // output roman numeral
//    }
//    else // sorting by arabic numeral
//    {
//        cout << head->aNum << endl; // output arabic numeral
//    }
//
//    printSort(head->next,sortVal); // recursively call printSort on the next node in the list
//}
//
//void fileWrite(ofstream &outfile,node *head)
//{
//    if(head == nullptr)
//    {
//        return;
//    }
//    if(outfile.good()) // check if the output file is good to write
//    {
//        outfile << setw(17) << left << head-> rNum << head->aNum << endl; // write roman and arabic numerals to file
//    }
//
//    fileWrite(outfile,head->next); // recursively call fileWrite on the next node in the list
//}
//void print(node* head)
//{
//    if(head == nullptr)
//    {
//        return;
//    }
//    cout << setw(17) << left << head-> rNum << head->aNum << endl; // output roman and arabic numerals
//
//    print(head->next); // recursively call print on the next node in the list
//}
//
//int main ()
//{
//    string fileName,line;
//    cout <<"Enter File Name: ";
//    cin >> fileName;
//
//    // Open the input file with the given filename
//    ifstream infile(fileName);
//
//    // Open the output file with name 'database'
//    ofstream outfile(database);
//
//    // If the input file is open
//    if (infile)
//        while (infile.good())
//        {
//            // Create a new linked list
//            node *head = nullptr;
//
//            // Read lines from the input file
//            while(getline(infile, line))
//            {
//                // If file opening fails, exit
//                if (infile.fail())
//                {
//                    cout << "File opening failed" << endl;
//                    break;
//                }
//
//                // Find the index of the first space in the line
//                long unsigned int spaceIndex = line.find(' ');
//
//                // If the first character in the line is not a space
//                if ((line[0] != ' '))
//                {
//                    bool flag = false;
//
//                    // Extract the Roman numeral string from the line
//                    line = line.substr(0, spaceIndex);
//
//                    // Convert the Roman numeral string to an Arabic numeral
//                    int arab = romanConversion(line);
//
//                    // Check if the Roman numeral string contains only valid characters
//                    for (char i: line)
//                    {
//                        if (i != 'I' && i != 'V' && i != 'X' && i != 'L' && i != 'C' && i != 'D' && i != 'M') {
//                            flag = true;
//                            break;
//                        }
//                    }
//
//                    // If the Roman numeral string is valid, add it to the linked list
//                    if(!flag)
//                    {
//                        linkList(head, arab, line);
//                    }
//                    else // If the Roman numeral string is invalid, skip it
//                    {
//                        continue;
//                    }
//
//                }
//                else // If the first character in the line is a space
//                {
//                    // Extract the Arabic numeral string from the line
//                    string newLine = line.substr(spaceIndex);
//
//                    // Convert the Arabic numeral string to an integer
//                    int arabicNumerals = stoi(newLine);
//
//                    // If the Arabic numeral is out of range, skip it
//                    if(arabicNumerals < 1 || arabicNumerals >= 4999)
//                    {
//                        continue;
//                    }
//                    else // If the Arabic numeral is in range, convert it to a Roman numeral and add it to the linked list
//                    {
//                        string roman = arabicConversion(arabicNumerals);
//                        int arab = stoi(line);
//                        linkList(head,arab,roman);
//                    }
//                }
//            }
//
//            int input;
//            do{
//                // Display menu options
//                cout << "1. Search" << endl;
//                cout << "2. Sort" << endl;
//                cout << "3. Exit" << endl;
//
//                // Get user input
//                cin >> input;
//
//                // If the user selects option 1, search the linked list for a value
//                if(input == 1)
//                {
//                    string searchVal;
//                    cout << "Please enter something to search for: " ;
//                    cin >> searchVal;
//
//                    // Call the searchList function and display the result
//                    bool TF = searchList(head,searchVal);
//                    if(TF)
//                    {
//                        cout << searchVal << " found\n";
//                    }
//                    else
//                    {
//                        cout << searchVal << " not found\n";
//                    }
//                }
//
//                // If the user selects option 2, sort the linked list and print it
//                if(input == 2)
//                {
//                    int sortBy;
//                    //Submenu for user choice
//                    cout << "1. Sort by Roman numeral" << endl;
//                    cout << "2. Sort by Arabic numeral" << endl;
//                    cin >> sortBy;
//                    //Sort the linked list on user value
//                    mergeSort(head,sortBy);
//                    //Print sorted values to console
//                    printSort(head,sortBy);
//                }
//
//
//            }while(input != 3);
//            //Writes the linked list contents to the file
//            fileWrite(outfile,head);
//            //Print the entirety of the linked list to the console
//            print(head);
//        }
//    //Closes files to prevent memory leakage
//    infile.close();
//    outfile.close();
//}
