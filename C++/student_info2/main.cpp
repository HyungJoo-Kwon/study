#include "student_info.h"
#include "grade.h"
#include "median.h"
#include "func.h"


int main() 
{    
    vector<Student_info> did, didnt;
    Student_info student;

   /* struct Student_info A;
    A.name = "aa";
    A.midterm = 20;
    A.finalterm = 30;   
    bool a = (find(A.homework.begin(), A.homework.end(), 0)) == A.homework.end();
    int i = A.homework.size();
    printf("%p \n", find(A.homework.begin(), A.homework.end(), 0));
    printf("%p , %p", A.homework.begin(), A.homework.end());
    cout << a << i ;*/
    
    while (read(cin, student)) 
    {        
        if (did_all_hw(student))
            did.push_back(student);      
        else          
            didnt.push_back(student);    
    }
  
    if (did.empty())
    {        
        cout << "No student did all the homework!" << endl;        
       return 1;    // Á¾·á
    }    

    if (didnt.empty()) 
    {        
        cout << "Every student did all the homework!" << endl;
       return 1;   
    } 
     write_analysis(cout, "median", median_analysis, did, didnt);    
     write_analysis(cout, "average", average_analysis, did, didnt);    
     write_analysis(cout, "median of homework turned in", optimistic_median_analysis, did, didnt);

    return 0;
}