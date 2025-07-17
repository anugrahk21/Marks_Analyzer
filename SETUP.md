# GPA Analyzer - Setup and Troubleshooting Guide

## Quick Start

### Windows Users
1. **Easy Method**: Double-click `run.bat`
2. **Manual Method**: Open Command Prompt and run:
   ```cmd
   g++ -std=c++11 -Wall -Wextra -O2 -o gpa_analyzer.exe gpa_analyzer.cpp
   gpa_analyzer.exe
   ```

### Using Build Scripts
- `build.bat` - Default build
- `build.bat debug` - Build with debug symbols
- `build.bat release` - Optimized release build  
- `build.bat clean` - Clean build files

## System Requirements

### Minimum Requirements
- Windows 7 or later
- C++ compiler (g++, MSVC, or Clang)
- 50 MB free disk space
- Command Prompt or PowerShell

### Recommended Setup
- Windows 10/11
- MinGW-w64 or Visual Studio Build Tools
- 100 MB free disk space

## Installation Options

### Option 1: MinGW Installation
1. Download MinGW-w64 from: https://www.mingw-w64.org/
2. Install and add to PATH
3. Verify: `g++ --version`

### Option 2: Visual Studio Build Tools
1. Download Visual Studio Build Tools
2. Install C++ build tools
3. Use Developer Command Prompt
4. Compile with: `cl /EHsc gpa_analyzer.cpp`

### Option 3: Code::Blocks/Dev-C++
1. Install Code::Blocks or Dev-C++
2. Open `gpa_analyzer.cpp`
3. Build and run from IDE

## Troubleshooting

### Common Issues

#### 1. "g++ is not recognized"
**Solution:**
- Install MinGW or Visual Studio Build Tools
- Add compiler to system PATH
- Restart Command Prompt

#### 2. Compilation Errors
**C++11 not supported:**
```cmd
g++ -std=c++11 -o gpa_analyzer.exe gpa_analyzer.cpp
```

**Missing headers:**
- Ensure all standard headers are available
- Update compiler if necessary

#### 3. Runtime Issues
**Program crashes on startup:**
- Check for missing DLL files
- Recompile with static linking: `g++ -static -o gpa_analyzer.exe gpa_analyzer.cpp`

**Input validation errors:**
- Ensure proper input format
- Check for buffer overflow in long subject names

#### 4. Display Issues
**Unicode characters not displaying:**
- Use Command Prompt with UTF-8 support
- Or stick to ASCII characters

**Table formatting broken:**
- Ensure console width is at least 80 characters
- Use full-screen mode if necessary

### Performance Tips

#### For Large Number of Subjects
- Program handles up to 1000 subjects efficiently
- Memory usage scales linearly with subject count

#### For Multiple Terms
- Can handle unlimited previous terms
- Calculation time is O(n) where n is number of terms

### Advanced Usage

#### Batch Processing
Create a text file with inputs and redirect:
```cmd
gpa_analyzer.exe < input.txt
```

#### Output Redirection
Save results to file:
```cmd
gpa_analyzer.exe > results.txt
```

#### Silent Mode (for automation)
Modify source code to disable interactive prompts for batch processing.

## Testing

### Unit Tests
Run with sample inputs from `sample_input.txt`:
- Test Case 1: Basic TGPA calculation
- Test Case 2: CGPA with previous terms
- Test Case 3: Mixed performance grades
- Test Case 4: Edge cases and validation

### Stress Testing
- 100+ subjects
- 50+ previous terms
- Very long subject names
- Extreme GPA values

## Customization

### Modifying Grade Scale
Edit the `gradeToPoint` map in constructor:
```cpp
gradeToPoint["A++"] = 11.0;  // Add new grade
```

### Changing Display Format
Modify `displayResults()` function:
- Table width and formatting
- Decimal places for GPA
- Performance feedback messages

### Adding New Features
Common additions:
- Grade point average by subject category
- Semester-wise trend analysis
- Export to CSV/Excel
- Graphical progress charts

## File Structure Details

```
Marks_Analyzer/
├── gpa_analyzer.cpp     # Main source (850+ lines)
├── run.bat             # Quick start script
├── build.bat           # Advanced build script
├── Makefile           # Make build system
├── README.md          # Main documentation
├── SETUP.md           # This file
├── sample_input.txt   # Test cases
└── .git/              # Git repository
```

## Security Notes

- Input validation prevents buffer overflow
- No dynamic memory allocation vulnerabilities
- Safe string handling with std::string
- No external dependencies

## Contributing

### Code Style
- Follow Google C++ Style Guide
- Use meaningful variable names
- Comment complex algorithms
- Maintain consistent indentation

### Testing
- Test all input validation
- Verify calculations manually
- Check edge cases
- Test on different compilers

### Documentation
- Update README.md for new features
- Add examples for new functionality
- Document any API changes

## Support

### Getting Help
1. Check this documentation
2. Review sample inputs
3. Test with simple cases first
4. Check compiler and system requirements

### Reporting Issues
Include:
- Operating system and version
- Compiler version
- Complete error messages
- Steps to reproduce
- Sample input that causes issues

### Feature Requests
- Describe the feature clearly
- Explain use cases
- Suggest implementation approach
- Consider backward compatibility

## License and Credits

This project is open source under MIT License.
Created for educational purposes and student use.

### Third-party Dependencies
- Standard C++ Library (STL)
- No external dependencies required

### Acknowledgments
- Based on standard GPA calculation methods
- Inspired by academic grading systems
- Community feedback and suggestions
