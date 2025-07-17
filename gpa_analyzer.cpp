#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

// Structure to hold subject information
struct Subject {
    string name;
    string grade;
    int credit;
    double gradePoint;
};

// Structure to hold term information
struct Term {
    int termNumber;
    double tgpa;
    int credits;
    vector<Subject> subjects;
};

class GPAAnalyzer {
private:
    map<string, double> gradeToPoint;
    vector<Term> terms;
    int totalTerms;
    double overallCGPA;
    
public:
    GPAAnalyzer() {
        // Initialize grade to point mapping
        gradeToPoint["O"] = 10.0;
        gradeToPoint["A+"] = 9.0;
        gradeToPoint["A"] = 8.0;
        gradeToPoint["B+"] = 7.0;
        gradeToPoint["B"] = 6.0;
        gradeToPoint["C"] = 5.0;
        gradeToPoint["D"] = 4.0;
        gradeToPoint["E"] = 0.0;
        gradeToPoint["F"] = 0.0;
        gradeToPoint["G"] = 0.0;
        gradeToPoint["I"] = 0.0;
        
        totalTerms = 0;
        overallCGPA = 0.0;
    }
    
    void printHeader() {
        cout << "\n";
        cout << "=========================================\n";
        cout << "         GPA ANALYZER TOOL (C++)        \n";
        cout << "=========================================\n";
        cout << "\n";
    }
    
    void printSeparator() {
        cout << "-----------------------------------------\n";
    }
    
    bool isValidGrade(const string& grade) {
        return gradeToPoint.find(grade) != gradeToPoint.end();
    }
    
    void inputTerms() {
        cout << "Enter the number of terms/semesters: ";
        cin >> totalTerms;
        
        while (totalTerms <= 0) {
            cout << "Please enter a valid number of terms (> 0): ";
            cin >> totalTerms;
        }
        
        terms.clear();
        terms.resize(totalTerms);
        
        for (int termIndex = 0; termIndex < totalTerms; termIndex++) {
            cout << "\n";
            cout << "=========================================\n";
            cout << "           TERM " << (termIndex + 1) << " DATA ENTRY\n";
            cout << "=========================================\n";
            
            terms[termIndex].termNumber = termIndex + 1;
            inputSubjectsForTerm(termIndex);
            calculateTGPAForTerm(termIndex);
            
            // Calculate and display current CGPA after this term
            calculateCurrentCGPA(termIndex + 1);
            displayTermResults(termIndex);
        }
    }
    
    void inputSubjectsForTerm(int termIndex) {
        int numSubjects;
        cout << "\nEnter the number of subjects for Term " << (termIndex + 1) << ": ";
        cin >> numSubjects;
        
        while (numSubjects <= 0) {
            cout << "Please enter a valid number of subjects (> 0): ";
            cin >> numSubjects;
        }
        
        terms[termIndex].subjects.clear();
        terms[termIndex].subjects.resize(numSubjects);
        
        cout << "\nEnter subject details for Term " << (termIndex + 1) << ":\n";
        printSeparator();
        
        for (int i = 0; i < numSubjects; i++) {
            cout << "\nSubject " << (i + 1) << ":\n";
            
            cout << "Subject name: ";
            cin.ignore();
            getline(cin, terms[termIndex].subjects[i].name);
            
            cout << "Grade (O, A+, A, B+, B, C, D, E, F, G, I): ";
            cin >> terms[termIndex].subjects[i].grade;
            
            // Convert to uppercase for consistency
            transform(terms[termIndex].subjects[i].grade.begin(), 
                     terms[termIndex].subjects[i].grade.end(), 
                     terms[termIndex].subjects[i].grade.begin(), ::toupper);
            
            while (!isValidGrade(terms[termIndex].subjects[i].grade)) {
                cout << "Invalid grade! Please enter a valid grade (O, A+, A, B+, B, C, D, E, F, G, I): ";
                cin >> terms[termIndex].subjects[i].grade;
                transform(terms[termIndex].subjects[i].grade.begin(), 
                         terms[termIndex].subjects[i].grade.end(), 
                         terms[termIndex].subjects[i].grade.begin(), ::toupper);
            }
            
            cout << "Credit: ";
            cin >> terms[termIndex].subjects[i].credit;
            
            while (terms[termIndex].subjects[i].credit <= 0) {
                cout << "Please enter a valid credit (> 0): ";
                cin >> terms[termIndex].subjects[i].credit;
            }
            
            terms[termIndex].subjects[i].gradePoint = gradeToPoint[terms[termIndex].subjects[i].grade];
        }
    }
    
    void calculateTGPAForTerm(int termIndex) {
        double totalWeightedPoints = 0.0;
        int totalCredits = 0;
        
        for (const auto& subject : terms[termIndex].subjects) {
            totalWeightedPoints += subject.gradePoint * subject.credit;
            totalCredits += subject.credit;
        }
        
        terms[termIndex].credits = totalCredits;
        
        if (totalCredits > 0) {
            terms[termIndex].tgpa = totalWeightedPoints / totalCredits;
            terms[termIndex].tgpa = round(terms[termIndex].tgpa * 100.0) / 100.0;
        } else {
            terms[termIndex].tgpa = 0.0;
        }
    }
    
    void calculateCurrentCGPA(int upToTerm) {
        double totalWeightedGPA = 0.0;
        int totalCredits = 0;
        
        for (int i = 0; i < upToTerm; i++) {
            totalWeightedGPA += terms[i].tgpa * terms[i].credits;
            totalCredits += terms[i].credits;
        }
        
        if (totalCredits > 0) {
            overallCGPA = totalWeightedGPA / totalCredits;
            overallCGPA = round(overallCGPA * 100.0) / 100.0;
        } else {
            overallCGPA = 0.0;
        }
    }
    
    void displayTermResults(int termIndex) {
        cout << "\n";
        cout << "=========================================\n";
        cout << "         TERM " << (termIndex + 1) << " RESULTS\n";
        cout << "=========================================\n";
        
        // Display subject-wise table for this term
        cout << "\nSUBJECT-WISE BREAKDOWN (TERM " << (termIndex + 1) << "):\n";
        cout << "+------------------------+-------+--------+-------------+\n";
        cout << "| Subject                | Grade | Credit | Grade Point |\n";
        cout << "+------------------------+-------+--------+-------------+\n";
        
        for (const auto& subject : terms[termIndex].subjects) {
            cout << "| " << left << setw(22) << subject.name 
                 << " | " << setw(5) << subject.grade 
                 << " | " << setw(6) << subject.credit 
                 << " | " << setw(11) << fixed << setprecision(2) << subject.gradePoint 
                 << " |\n";
        }
        cout << "+------------------------+-------+--------+-------------+\n";
        
        // Display TGPA for this term
        cout << "\nTGPA for Term " << (termIndex + 1) << ": " << fixed << setprecision(2) << terms[termIndex].tgpa << "\n";
        
        // Display CGPA if more than one term
        if (termIndex > 0) {
            cout << "Current CGPA (after " << (termIndex + 1) << " terms): " << fixed << setprecision(2) << overallCGPA << "\n";
        }
        
        // Performance feedback for current status
        double performanceGPA = (termIndex == 0) ? terms[termIndex].tgpa : overallCGPA;
        cout << "\nCURRENT PERFORMANCE: ";
        if (performanceGPA >= 9.0) {
            cout << "Outstanding! Keep up the excellent work!\n";
        } else if (performanceGPA >= 8.0) {
            cout << "Excellent performance! Well done!\n";
        } else if (performanceGPA >= 7.0) {
            cout << "Good performance! You're doing well!\n";
        } else if (performanceGPA >= 6.0) {
            cout << "Above average performance. There's room for improvement.\n";
        } else if (performanceGPA >= 5.0) {
            cout << "Average performance. Consider studying harder.\n";
        } else {
            cout << "Below average performance. Please focus on improvement.\n";
        }
        
        cout << "\n";
        printSeparator();
        cout << "\n";
    }
    
    void displayFinalResults() {
        cout << "\n";
        cout << "=========================================\n";
        cout << "          FINAL SUMMARY                  \n";
        cout << "=========================================\n";
        
        // Display term-wise summary
        cout << "\nTERM-WISE SUMMARY:\n";
        cout << "+------+--------+--------+--------+\n";
        cout << "| Term | TGPA   | Credits| CGPA   |\n";
        cout << "+------+--------+--------+--------+\n";
        
        for (int i = 0; i < totalTerms; i++) {
            // Calculate CGPA up to this term for display
            calculateCurrentCGPA(i + 1);
            cout << "| " << setw(4) << (i + 1) 
                 << " | " << setw(6) << fixed << setprecision(2) << terms[i].tgpa
                 << " | " << setw(6) << terms[i].credits
                 << " | " << setw(6) << fixed << setprecision(2) << overallCGPA
                 << " |\n";
        }
        cout << "+------+--------+--------+--------+\n";
        
        // Calculate final CGPA
        calculateCurrentCGPA(totalTerms);
        
        cout << "\n";
        cout << "=========================================\n";
        cout << "YOUR OVERALL CGPA FROM THE GIVEN " << totalTerms << " TERMS: " << fixed << setprecision(2) << overallCGPA << "\n";
        cout << "=========================================\n";
        
        // Display grade interpretation
        cout << "\nGRADE INTERPRETATION:\n";
        printSeparator();
        cout << "O  = 10 (Outstanding)\n";
        cout << "A+ = 9  (Excellent)\n";
        cout << "A  = 8  (Very Good)\n";
        cout << "B+ = 7  (Good)\n";
        cout << "B  = 6  (Above Average)\n";
        cout << "C  = 5  (Average)\n";
        cout << "D  = 4  (Below Average)\n";
        cout << "E/F/G/I = 0 (Fail/Incomplete)\n";
        
        cout << "\n";
        printSeparator();
        
        // Performance feedback
        cout << "OVERALL PERFORMANCE: ";
        if (overallCGPA >= 9.0) {
            cout << "Outstanding! Keep up the excellent work!\n";
        } else if (overallCGPA >= 8.0) {
            cout << "Excellent performance! Well done!\n";
        } else if (overallCGPA >= 7.0) {
            cout << "Good performance! You're doing well!\n";
        } else if (overallCGPA >= 6.0) {
            cout << "Above average performance. There's room for improvement.\n";
        } else if (overallCGPA >= 5.0) {
            cout << "Average performance. Consider studying harder.\n";
        } else {
            cout << "Below average performance. Please focus on improvement.\n";
        }
        
        // Additional statistics
        cout << "\nSTATISTICS:\n";
        printSeparator();
        cout << "Total Terms: " << totalTerms << "\n";
        
        int totalCredits = 0;
        for (const auto& term : terms) {
            totalCredits += term.credits;
        }
        cout << "Total Credits: " << totalCredits << "\n";
        
        // Find highest and lowest TGPA
        if (totalTerms > 1) {
            double highestTGPA = terms[0].tgpa;
            double lowestTGPA = terms[0].tgpa;
            int highestTerm = 1, lowestTerm = 1;
            
            for (int i = 1; i < totalTerms; i++) {
                if (terms[i].tgpa > highestTGPA) {
                    highestTGPA = terms[i].tgpa;
                    highestTerm = i + 1;
                }
                if (terms[i].tgpa < lowestTGPA) {
                    lowestTGPA = terms[i].tgpa;
                    lowestTerm = i + 1;
                }
            }
            
            cout << "Highest TGPA: " << fixed << setprecision(2) << highestTGPA << " (Term " << highestTerm << ")\n";
            cout << "Lowest TGPA: " << fixed << setprecision(2) << lowestTGPA << " (Term " << lowestTerm << ")\n";
        }
        
        cout << "\n";
    }
    
    void addAdditionalTerms() {
        char choice;
        cout << "\nDo you want to add one more term? (y/n): ";
        cin >> choice;
        
        bool addedTerms = false;
        
        while (choice == 'y' || choice == 'Y') {
            totalTerms++;
            terms.resize(totalTerms);
            int newTermIndex = totalTerms - 1;
            addedTerms = true;
            
            cout << "\n";
            cout << "=========================================\n";
            cout << "         ADDITIONAL TERM " << totalTerms << " DATA ENTRY\n";
            cout << "=========================================\n";
            
            terms[newTermIndex].termNumber = totalTerms;
            inputSubjectsForTerm(newTermIndex);
            calculateTGPAForTerm(newTermIndex);
            
            // Calculate and display current CGPA after this additional term
            calculateCurrentCGPA(totalTerms);
            displayTermResults(newTermIndex);
            
            cout << "Do you want to add another term? (y/n): ";
            cin >> choice;
        }
        
        // If additional terms were added, show updated final results
        if (addedTerms) {
            cout << "\n";
            cout << "=========================================\n";
            cout << "        UPDATED FINAL SUMMARY           \n";
            cout << "=========================================\n";
            displayFinalResults();
        }
    }
    
    void run() {
        char continueChoice;
        
        do {
            printHeader();
            
            // Input all terms
            inputTerms();
            
            // Display final summary
            displayFinalResults();
            
            // Ask if user wants to add more terms
            addAdditionalTerms();
            
            // Ask to continue
            cout << "Do you want to calculate GPA for another set of terms? (y/n): ";
            cin >> continueChoice;
            
        } while (continueChoice == 'y' || continueChoice == 'Y');
        
        cout << "\nThank you for using GPA Analyzer!\n";
        cout << "Program by: GPA Analyzer Tool\n";
        cout << "\nPress Enter to exit...";
        cin.ignore();
        cin.get();
    }
};

int main() {
    GPAAnalyzer analyzer;
    analyzer.run();
    return 0;
}
