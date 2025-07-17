# GPA Analyzer Tool (C++)

A comprehensive C++ console application for calculating Term GPA (TGPA) and Cumulative GPA (CGPA) for students.

## Features

### 📚 Subject Management
- Input multiple subjects with their details
- Support for subject name, grade, and credit hours
- Validation for all inputs

### 🎯 Grade System
- **O** = 10 (Outstanding)
- **A+** = 9 (Excellent)
- **A** = 8 (Very Good)
- **B+** = 7 (Good)
- **B** = 6 (Above Average)
- **C** = 5 (Average)
- **D** = 4 (Below Average)
- **E/F/G/I** = 0 (Fail/Incomplete)

### 📊 GPA Calculations
- **TGPA (Term GPA)**: `Σ(grade_point × credit) / Σ(credits)` for each term
- **CGPA (Cumulative GPA)**: Progressive calculation after each term entry
- **Progressive Display**: Shows current CGPA after each term is entered
- Results rounded to 2 decimal places
- Formula: `(TGPA1×Credits1 + TGPA2×Credits2 + ... + TGPAn×Creditsn) / (Total Credits)`

### 💡 Additional Features
- Beautiful ASCII table formatting
- **Multi-term support**: Enter all terms at once
- **Smart CGPA display**: Shows CGPA only when more than 1 term
- **Clear final message**: "YOUR OVERALL CGPA FROM THE GIVEN N TERMS: X.XX"
- **Term-wise analysis**: Individual TGPA calculation for each term
- **Additional term option**: Add more terms after completing initial N terms
- **Comprehensive statistics**: Highest/lowest TGPA, total credits
- **Performance feedback**: Real-time feedback after each term
- **Final summary**: Complete term-wise breakdown and analysis
- Option to restart or exit after calculations
- Input validation and error handling

## Requirements

- C++ compiler (g++ recommended)
- Windows Command Prompt or PowerShell
- C++11 or later standard

## Installation & Usage

### Method 1: Using the Batch File (Recommended for Windows)
1. Double-click `run.bat`
2. The program will automatically compile and run

### Method 2: Manual Compilation
```cmd
# Compile the program
g++ -std=c++11 -Wall -Wextra -O2 -o gpa_analyzer.exe gpa_analyzer.cpp

# Run the program
gpa_analyzer.exe
```

### Method 3: Using Makefile (if you have make installed)
```cmd
# Compile
make

# Run
make run

# Clean build files
make clean
```

## How to Use

1. **Start the Program**: Run the compiled executable
2. **Enter Number of Terms**: Input the total number of terms/semesters
3. **For Each Term**:
   - Enter the number of subjects for that term
   - For each subject, enter:
     - Subject name
     - Grade (O, A+, A, B+, B, C, D, E, F, G, I)
     - Credit hours
   - View TGPA for the current term
   - View CGPA (only shown if more than 1 term)
   - See performance feedback
4. **Final Summary**: View comprehensive results including:
   - Term-wise summary table
   - "YOUR OVERALL CGPA FROM THE GIVEN N TERMS: X.XX"
   - Statistics (highest/lowest TGPA, total credits)
   - Overall performance analysis
5. **Add More Terms**: Option to add additional terms after completing initial N terms
6. **Continue or Exit**: Choose to calculate for another set or exit

## Sample Output

```
=========================================
         GPA ANALYZER TOOL (C++)        
=========================================

Enter the number of terms/semesters: 3

=========================================
           TERM 1 DATA ENTRY
=========================================

Enter the number of subjects for Term 1: 3

Subject 1:
Subject name: Data Structures
Grade (O, A+, A, B+, B, C, D, E, F, G, I): A
Credit: 4

Subject 2:
Subject name: Mathematics
Grade (O, A+, A, B+, B, C, D, E, F, G, I): A+
Credit: 3

Subject 3:
Subject name: Physics
Grade (O, A+, A, B+, B, C, D, E, F, G, I): B+
Credit: 3

=========================================
         TERM 1 RESULTS
=========================================

SUBJECT-WISE BREAKDOWN (TERM 1):
+------------------------+-------+--------+-------------+
| Subject                | Grade | Credit | Grade Point |
+------------------------+-------+--------+-------------+
| Data Structures        | A     | 4      | 8.00        |
| Mathematics            | A+    | 3      | 9.00        |
| Physics                | B+    | 3      | 7.00        |
+------------------------+-------+--------+-------------+

TGPA for Term 1: 8.00
Current CGPA (after 1 term): 8.00

CURRENT PERFORMANCE: Excellent performance! Well done!

[... continues for Terms 2 and 3 ...]

=========================================
          FINAL SUMMARY                  
=========================================

TERM-WISE SUMMARY:
+------+--------+--------+--------+
| Term | TGPA   | Credits| CGPA   |
+------+--------+--------+--------+
| 1    | 8.00   | 10     | 8.00   |
| 2    | 8.50   | 12     | 8.27   |
| 3    | 9.00   | 11     | 8.55   |
+------+--------+--------+--------+

=========================================
YOUR OVERALL CGPA FROM THE GIVEN 3 TERMS: 8.55
=========================================

STATISTICS:
Total Terms: 3
Total Credits: 33
Highest TGPA: 9.00 (Term 3)
Lowest TGPA: 8.00 (Term 1)

OVERALL PERFORMANCE: Excellent performance! Well done!

Do you want to add one more term? (y/n): n
```

## File Structure

```
Marks_Analyzer/
├── gpa_analyzer.cpp    # Main C++ source code
├── Makefile           # Build configuration
├── run.bat            # Windows batch file for easy compilation
└── README.md          # This documentation
```

## Code Structure

- **GPAAnalyzer Class**: Main class handling all functionality
- **Subject Structure**: Stores individual subject information
- **PreviousTerm Structure**: Stores previous term GPA data
- **Grade Mapping**: Fixed mapping of grades to points
- **Input Validation**: Comprehensive validation for all inputs
- **Console UI**: ASCII-formatted tables and user-friendly interface

## Error Handling

- Input validation for grades, credits, and GPA values
- Handles invalid inputs gracefully
- Provides clear error messages and retry options

## Performance Feedback

The program provides performance feedback based on GPA:
- **9.0+**: Outstanding
- **8.0-8.99**: Excellent
- **7.0-7.99**: Good
- **6.0-6.99**: Above Average
- **5.0-5.99**: Average
- **Below 5.0**: Below Average

## Contributing

Feel free to contribute to this project by:
- Adding new features
- Improving the user interface
- Fixing bugs
- Adding more grade systems support

## License

This project is open source and available under the MIT License.

## Author

Created as a comprehensive GPA calculation tool for students to track their academic performance.