#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

class Data
{
private:
    string SubjectName;
    int Mark;
    int GradePoint;
    int Credits;
public:
    Data(string SubjectName, int Mark, int GradePoint,int Credits)
    {
        this->SubjectName = SubjectName;
        this->Mark = Mark;
        this->GradePoint = GradePoint;
        this->Credits = Credits;
    }
    void setSubjectName(string SubjectName)
    {
        this->SubjectName = SubjectName;
    }
    void setMark(int Mark)
    {
        this->Mark = Mark;
    }
    void setGradePoint(int GradePoint)
    {
        this->GradePoint = GradePoint;
    }
    void setCredits(int Credits)
    {
        this->Credits = Credits;
    }
    string getSubjectName()
    {
        return SubjectName;
    }
    int getMark()
    {
        return Mark;
    }
    int getGradePoint()
    {
        return GradePoint;
    }
    int getCredits()
    {
        return Credits;
    }
    int GradePointCalculator(int Mark)
    {
        int GradePoint = ((Mark - 1) / 10)+1;
        if (GradePoint < 3) return 0;
        else return GradePoint;
    }
};



int main()
{
    int NumberofSubjects;
    vector<Data> data;
    Data dataTemp("",0,0,0);
    string SubjectNameTemp;
    int MarkTemp;
    int CreditsTemp;
    int TotalGradePoints=0;
    int TotalCredits=0;
    cout << "CGPA Calculator App" << endl;
    cout << "Number of Subjects:" << endl;
    cin >> NumberofSubjects;
    cin.ignore(1, '\n');
    cout << "Format: SubjectName - Grade" << endl;
    for (int i = 0; i < NumberofSubjects; i++)
    {
        cout << "Subject " << i+1 << ": \nName: ";
        getline(cin, SubjectNameTemp);
        dataTemp.setSubjectName(SubjectNameTemp);
        cout << "Mark: ";
        cin >> MarkTemp;
        cin.ignore(1, '\n');
        dataTemp.setMark(MarkTemp);
        cout << "Credits: ";
        cin >> CreditsTemp;
        cin.ignore(1, '\n');
        dataTemp.setCredits(CreditsTemp);
        dataTemp.setGradePoint(dataTemp.GradePointCalculator(dataTemp.getMark()));
        data.push_back(dataTemp);
        cout << endl;
    }
    for (Data d : data)
    {
        cout << d.getSubjectName() << ": " << d.getMark() << ", "<<d.getCredits()<<" credits\t(Grade Point : " << d.getGradePoint() << ")" << endl;
        TotalGradePoints += (d.getGradePoint() * d.getCredits());
        TotalCredits += d.getCredits();
    }
    cout << "Total grade points: " << TotalGradePoints << endl;
    cout << "Total credits: " << TotalCredits << endl;
    cout << "Your SGPA: " << setprecision(4)<<TotalGradePoints / float(TotalCredits) << endl;
}

