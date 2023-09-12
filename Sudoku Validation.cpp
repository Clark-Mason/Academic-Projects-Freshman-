////Mason Clark
////MXC220017
//#include <iostream>
//#include <iomanip>
//#include <fstream>
//#include <cctype>
//#include <vector>
//#include <sstream>
//
//using namespace std;
//
///**
// * Validates the columns of a Sudoku grid for duplicates of the numbers 1-9.
// * @param ptr Pointer to the first element of the Sudoku grid.
// * @param puzzle_name The name of the puzzle being validated.
// * @param fails A vector of strings to which validation failure messages will be appended.
// * @return A boolean value indicating whether any column has multiple instances of the same number.
// */
//bool columnValidation(int *ptr,const string &puzzle_name,vector<string>&fails)
//{
//    // Initialize flag variable to false
//    bool flagC = false;
//    // Set start pointer to current pointer
//    int *start_ptr = ptr;
//    // Iterate over each column of the grid
//    for(int i = 1; i <= 9; i++)
//    {
//        // Initialize array to keep count of digits
//        int* digit_count = new int[9];
//        // Set start pointer for array
//        int* digit_start = digit_count;
//        // Initialize all digit counts to zero
//        for(int y = 0; y < 10; y++)
//        {
//            *digit_count = 0;
//            digit_count++;
//        }
//        // Reset digit count pointer to start
//        digit_count = digit_start;
//        // Iterate over each row in the column
//        for(int j = 0; j < 9; j++)
//        {
//            // Increment digit count for current cell value
//            digit_count += *ptr;
//            *digit_count += 1;
//            digit_count -= *ptr;
//            // Move pointer to next row in column
//            ptr += 9;
//        }
//        // Reset digit count pointer to start
//        digit_count = digit_start;
//        // Iterate over each digit from 1 to 9
//        for(int x = 1; x <= 9;x++)
//        {
//            stringstream ss;
//            digit_count++;
//            // If the digit count is greater than 1, add error message to fails vector and set flag to true
//            if(*digit_count > 1)
//            {
//                ss << setw(4) << left << puzzle_name << "\tinvalid\t" << "column " << i << " has multiple " << x << "s"<< endl;
//                fails.push_back(ss.str());
//                flagC = true;
//            }
//        }
//        // Delete digit count array to free memory
//        digit_count = digit_start;
//        delete[] digit_count;
//        // Reset pointer to start of grid
//        ptr = start_ptr;
//        // Move pointer to next column in grid
//        ptr += i;
//    }
//    // Return flag variable
//    return flagC;
//}
//
//
///**
// * This function validates each row in a Sudoku puzzle by checking that each digit
// * (1-9) appears exactly once. If any digit appears more than once in a row, an error
// * message is added to the `fails` vector, and the function returns `true`.
// *
// * @param ptr: A pointer to the first element in the row to be validated.
// * @param puzzle_name: The name of the puzzle being validated (for error reporting).
// * @param fails: A reference to a vector of error messages.
// *
// * @return: `true` if any row contains duplicate digits, `false` otherwise.
// */
//bool rowValidation(int *ptr, const string &puzzle_name, vector<string>&fails)
//{
//    // Initialize a flag to indicate whether any row contains duplicate digits
//    bool flagR = false;
//
//    // Save the starting pointer, so we can reset to the beginning of each row
//    int *start_ptr = ptr;
//
//    // Loop through each row (there are 9 rows in a Sudoku puzzle)
//    for(int i = 1; i <= 9; i++)
//    {
//        // Create an array to keep track of how many times each digit appears in the row
//        int* digit_count = new int[10];
//        int* digit_start = digit_count;
//        for(int y = 0; y < 10; y++)
//        {
//            *digit_count = 0;
//            digit_count++;
//        }
//        digit_count = digit_start;
//
//        // Loop through each element in the row, updating the digit_count array accordingly
//        for(int j = 0; j < 9; j++)
//        {
//            digit_count += *ptr;
//            *digit_count += 1;
//            digit_count -= *ptr;
//            ptr ++;
//        }
//
//        // Loop through each digit, checking if it appears more than once in the row
//        digit_count = digit_start;
//        for(int x = 1; x <= 9;x++)
//        {
//            stringstream ss;
//            digit_count++;
//            if(*digit_count > 1)
//            {
//                // If a digit appears more than once, add an error message to the `fails` vector
//                ss << setw(4) << left << puzzle_name <<"\tinvalid\t" << "row " << i << " has multiple " << x << "s"<< endl;
//                fails.push_back(ss.str());
//                flagR = true;
//            }
//        }
//
//        // Free memory used by the digit_count array
//        digit_count = digit_start;
//        delete[] digit_count;
//
//        // Reset the pointer to the beginning of the row
//        ptr = start_ptr;
//        ptr += i * 9;
//    }
//
//    // Return the flag indicating whether any row contained duplicate digits
//    return flagR;
//}
//
///**
//The function 'gridValidation' takes a pointer to an integer array representing a Sudoku grid, a string puzzle_name, and a vector of strings fails. It validates each of the nine 3x3 grids in the Sudoku grid for duplicate digits from 1 to 9.
//
//For each grid, the function creates a dynamically allocated integer array to store the count of each digit in the grid. It then iterates through each cell of the grid and updates the count of the corresponding digit in the array. If the count of any digit in the grid is greater than 1, it creates an error message with the name of the puzzle, the name of the grid, and the duplicate digit, and adds it to the fails vector.
//
//After processing each grid, the function returns a boolean flag that indicates whether there were any invalid grids with duplicate digits. The dynamically allocated memory for the integer array is deleted before the function returns.
//*/
//bool gridValidation(int *ptr, const string &puzzle_name, vector<string>&fails)
//{
//    // Set the starting position of the first 3x3 box
//    int *box_start = ptr;
//    // Flag to indicate whether there were any validation errors
//    bool flagG = false;
//    // Loop through each of the 9 3x3 boxes in the puzzle
//    for(int i = 0; i < 9; i++)
//    {
//        // Determine the name of the current 3x3 box based on its position
//        string gridName;
//        if(i == 0)
//        {
//            gridName = "upper left";
//        }
//        if(i == 1)
//        {
//            gridName = "upper middle";
//        }
//        if(i == 2)
//        {
//            gridName = "upper right";
//        }
//        if(i == 3)
//        {
//            gridName = "left";
//        }
//        if(i == 4)
//        {
//            gridName = "middle";
//        }
//        if(i == 5)
//        {
//            gridName = "right";
//        }
//        if(i == 6)
//        {
//            gridName = "lower left";
//        }
//        if(i == 7)
//        {
//            gridName = "lower middle";
//        }
//        if(i == 8)
//        {
//            gridName = "lower right";
//        }
//        // Initialize an array to count the occurrences of each digit in the box
//        int* digit_count = new int[10];
//        // Set a pointer to the beginning of the digit count array
//        int* digit_start = digit_count;
//        // Initialize each element of the digit count array to 0
//        for(int y = 0; y <= 9; y++)
//        {
//            *digit_count = 0;
//            digit_count++;
//        }
//        digit_count = digit_start;
//        // Loop through each cell in the current 3x3 box and increment the digit count array for each digit found
//        for(int j = 0; j < 9; j++)
//        {
//            // Increment the digit count for the current digit
//            digit_count += *ptr;
//            *digit_count += 1;
//            digit_count -= *ptr;
//            // Move the pointer to the next cell in the current row
//            if(j % 3 == 2)
//            {
//                ptr += 7;
//            }
//            else
//            {
//                ptr++;
//            }
//        }
//        // Loop through each digit from 1 to 9 and check if it appears more than once in the current box
//        for(int x = 1; x <= 9;x++)
//        {
//            // Create a string stream to store any validation errors
//            stringstream ss;
//            // Increment the digit count pointer to the next element in the array
//            digit_count++;
//            // If the current digit appears more than once in the box, add an error message to the vector of fails
//            if(*digit_count > 1)
//            {
//                ss << setw(4) << left << puzzle_name  << "\tinvalid\t" << gridName << " has multiple " << x << "s"<< endl;
//                fails.push_back(ss.str());
//                // Set the flag to indicate that there was a validation error
//                flagG = true;
//            }
//        }
//        //Moves starting box pointer
//        if(i % 3 == 2)
//        {
//            box_start += 21;
//        }
//        else
//        {
//            box_start += 3;
//        }
//        // Frees up memory to prevent memory leakage
//        digit_count = digit_start;
//        delete[] digit_count;
//        //Moves pointer to next grid
//        ptr = box_start;
//    }
//    return flagG;
//}
//
//// Main function that reads in a file containing Sudoku puzzles,
//// validates each puzzle, and prints the results
//int main()
//{
//    string line, puzzleName, fileName;
//
//    // Prompt user for file name containing Sudoku puzzles
//    cin >> fileName;
//
//    // Attempt to open file
//    ifstream infile(fileName);
//
//    // If file is opened successfully, validate puzzles
//    if(infile.good())
//    {
//        // Create vector to store validation error messages
//        vector<string> fails;
//
//        // Read in each puzzle from file
//        while(getline(infile,line))
//        {
//            // Store puzzle name for error reporting
//            string puzzle_name = line;
//
//            // Initialize pointer to array of puzzle values
//            int *ptr = new int[81];
//
//            // Keep a copy of the starting address for resetting pointer later
//            int *start_ptr = ptr;
//
//            // Read in puzzle values from file and dynamically allocates them to array
//            int spaceCount = 0;
//            while (getline(infile, line) && !line.empty())
//            {
//                for(char i: line)
//                {
//                    if(isspace(i))
//                    {
//                        *ptr = 0;
//                        ptr++;
//                        spaceCount++;
//                        continue;
//                    }
//                    *ptr = i - '0';
//                    ptr++;
//                }
//            }
//
//            // Reset pointer to starting address for validation functions
//            ptr = start_ptr;
//
//            // Validate puzzle using column, row, and grid validation functions
//            bool cFlag = columnValidation(ptr, puzzle_name, fails);
//            bool rFlag = rowValidation(ptr, puzzle_name, fails);
//            bool gFlag = gridValidation(ptr, puzzle_name, fails);
//
//            // Print any validation error messages
//            for(const string &x: fails)
//            {
//                cout << x;
//            }
//
//            // Clear validation error messages for next puzzle
//            fails.clear();
//
//            // Print solved message if no errors and no empty spaces
//            if(!cFlag && !rFlag && !gFlag && spaceCount == 0)
//            {
//                cout << setw(4) << left << puzzle_name << '\t' << "solved" << endl;
//
//            }
//
//            // Print valid message if no errors and at least one empty space
//            if(!cFlag && !rFlag && !gFlag && spaceCount > 0)
//            {
//                cout << setw(4) << left << puzzle_name << '\t' << "valid" << endl;
//            }
//
//            // Free memory used for puzzle values
//            delete[] ptr;
//        }
//    }
//
//    // Close input file
//    infile.close();
//
//    return 0;
//}
