#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <fstream>

using namespace std;

ofstream fout("./BIN/input_data.txt");
int d1 = 0, d2 = 0, d3 = 0, d4 = 0, d5 = 0, d6 = 0, d7 = 0, d8 = 0, d9 = 0, d10 = 0;
int r1 = 0,r2 = 0,r3 = 0,r4 = 0,r5 = 0,r6 = 0,r7 = 0,r8 = 0,r9 = 0,r10 = 0,r11 = 0,r12 = 0,r13 = 0,r14 = 0,r15 = 0,r16 = 0,r17 = 0,r18 = 0,r19 = 0,r20 = 0;

enum Tagset 
{
	chess, dance, football, reading, film, basketball, music, English, study, programming
};

enum Dept
{
	D001,D002,D003,D004,D005,D006,D007,D008,D009,D010,D011,D012,D013,D014,D015,D016,D017,D018,D019,D020
};

enum LeisureTime
{
	t1, t2, t3, t4, t5, t6, t7
};

enum DeptSheldue 
{
	t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20
};

string setTag(int x) 
{
	switch (x) 
    {
	case chess: d1++; return "chess";
	case dance: d2++; return "dance";
	case football: d3++; return "football";
	case reading: d4++; return "reading";
	case film: d5++; return "film";
	case basketball: d6++; return "basketball";
	case music: d7++; return "music";
	case English: d8++; return "English";
	case study: d9++; return "study";
	case programming: d10++; return "programming";
	default: return "";
	}
}

string setDept(int x)
{
	switch (x)
    {
    case D001:  r1++; return "D001";
    case D002:  r2++; return "D002";
    case D003:  r3++; return "D003";
    case D004:  r4++; return "D004";
    case D005:  r5++; return "D005";
    case D006:  r6++; return "D006";
    case D007:  r7++; return "D007";
    case D008:  r8++; return "D008";
    case D009:  r9++; return "D009";
    case D010:  r10++; return "D010";
    case D011:  r11++; return "D011";
    case D012:  r12++; return "D012";
    case D013:  r13++; return "D013";
    case D014:  r14++; return "D014";
    case D015:  r15++; return "D015";
    case D016:  r16++; return "D016";
    case D017:  r17++; return "D017";
    case D018:  r18++; return "D018";
    case D019:  r19++; return "D019";
    case D020:  r20++; return "D020";
	default: return "";
	}
}

string setTime(int x) 
{                                                      
	switch (x) 
    {
	case t1: return "8:00~10:00";
	case t2: return "10:00~12:00";
	case t3: return "12:00~14:00";
	case t4: return "14:00~16:00";
	case t5: return "16:00~18:00";
	case t6: return "18:00~20:00";
	case t7: return "20:00~22:00";
	default: return "";
	}
}

string setSheldue(int x)
{
	switch (x)
	{
	case t9: return "8:00~9:00";
	case t10: return "9:00~10:00";
	case t11: return "10:00~11:00";
	case t12: return "11:00~12:00";
	case t13: return "12:00~13:00";
	case t14: return "13:00~14:00";
	case t15: return "14:00~15:00";
	case t16: return "15:00~16:00";
	case t17: return "16:00~17:00";
	case t18: return "17:00~18:00";
	case t19: return "18:00~19:00";
	case t20: return "19:00~19:30";
	default: return "";
	}
}

vector<int> randVector(int num) 
{
	vector<int> result;
	result.reserve(num);
	for (int i = 0; i < num; i++)
	{
		result.push_back(i);
	}
	int p1;
	int p2;
	int temp;
	int count = num;

	while (--num)
	{
		p1 = num;
		p2 = rand() % num;
		temp = result[p1];
		result[p1] = result[p2];
		result[p2] = temp;
	}
	return result;
}
vector<int> ve = randVector(1);

void setShelduer(int count, string x[]) {
	ve = randVector(12);
	for (int i = 1; i <= count; i++) {
		x[i - 1] = setSheldue(ve[i - 1]);
	}
	ve.clear();
}

void setLt(int count, string x[]) 
{
	ve = randVector(7);
	for (int i = 1; i <= count; i++)
    {
		x[i - 1] = setTime(ve[i-1]);
	}
	ve.clear();
}

void outputTime(string day, string x[]) 
{
	for (int j = 0; j < 8; j++)
		if (x[j].length() == 0) break;
		else
		{
			if (x[j].length() != 0&&x[j + 1].length() != 0) 
                fout << "\t\t\t\t\"" << day << "." << x[j] << "\"," << endl;
			if (x[j].length() != 0&&x[j + 1].length() == 0&&day == "Sun") 
                fout << "\t\t\t\t\"" << day << "." << x[j] << "\"" <<endl;
		}
}

class Student 
{
	public:
		string student_no;
		string tag[11];
		string application_dept[6];
		string Mon[8];
		string Tues[8];
		string Wed[8];
		string Thur[8];
		string Fri[8];
		string Sat[8];
		string Sun[8];
}Stu[301];

class Department {
	public:
		int num;
		int sum;
		string dept_no;
		string tag[11];
		string Mon[2];
		string Tues[2];
		string Wed[2];
		string Thur[2];
		string Fri[2];
		string Sat[2];
		string Sun[2];
}Dept[21];

void outputTimed(int i, string day, string x[]) {
	
	for (int j = 0; j < 2; j++)
		if (x[j].length() == 0 || Dept[i].sum == 0) break;
		else
		{
			if (Dept[i].sum == 1) {
				Dept[i].sum = 0;
				fout << "\t\t\t\t\"" << day << "." << x[j] << "\"" << endl;
				break;
			}
			else{
				Dept[i].sum--; 
				fout << "\t\t\t\t\"" << day << "." << x[j] << "\"," << endl;
			}
		}
}

int main() 
{
	srand((unsigned)time(NULL));
	vector<int>::iterator it;
	int sum = 0, ram;
	//随机学生产生各项数据
    for (int k = 1; k <= 300; k++) 
    {   	
		setLt(rand() % 4, Stu[k].Mon);                                                    //随机学生产生空闲时间
		setLt(rand() % 4, Stu[k].Tues);
		setLt(rand() % 4, Stu[k].Wed);
		setLt(rand() % 4, Stu[k].Thur);
		setLt(rand() % 4, Stu[k].Fri);
		setLt(rand() % 4+1, Stu[k].Sat);
		setLt(rand() % 4+1, Stu[k].Sun);

		if (k <= 9)Stu[k].student_no = "03150200" + to_string(k);                      //随机产生学生编号
		else if (k <= 99)Stu[k].student_no = "0315020" + to_string(k);
		else Stu[k].student_no = "031502" + to_string(k);

		ve = randVector(20);
		for (int p = rand() % 4 + 2; p > 0; p--) 
        {                                        //随机学生志愿标签
			Stu[k].application_dept[p-1] = setDept(ve[p-1]);
		}
		ve.clear();

		ve = randVector(10);                          //随机兴趣标签
		for (int p = rand() % 9 + 2; p > 0; p--) 
        {                                       
			Stu[k].tag[p-1] = setTag(ve[p-1]);
		}
		ve.clear();
	}
    cout << d1 << " " << d2 << " " << d3 << " " << d4 << " " << d5 << " " << d6 << " " << d7 << " " << d8 << " " << d9 << " " << d10 << endl;
	d1 = d2 = d3 = d4 = d5 = d6 = d7 = d8 = d9 = d10 = 0;
     //随机产生部门各项数据
	for (int k = 1; k <= 20; k++) 
    {
       
		ram = rand() % 3;
		setShelduer(ram, Dept[k].Mon);                                         //随机部门产生空闲时间
		sum += ram;
		ram = rand() % 3;
		setShelduer(ram, Dept[k].Tues);
		sum += ram;
		ram = rand() % 3;
		setShelduer(ram, Dept[k].Wed);
		sum += ram;
		ram = rand() % 3;
		setShelduer(ram, Dept[k].Thur);
		sum += ram;
		ram = rand() % 3;
		setShelduer(ram, Dept[k].Fri);
		sum += ram;
		ram = rand() % 2+1;
		setShelduer(ram, Dept[k].Sat);
		sum += ram;
		ram = rand() % 2+1;
		setShelduer(ram, Dept[k].Sun);
		sum += ram;
		if (sum < 3) Dept[k].sum = 2;
		else Dept[k].sum = sum % 3 + 2; 
		sum = 0;

		Dept[k].num = rand() % 6 + 10;                                               //随机产生部门人数

		if (k <= 9)Dept[k].dept_no = "D00" + to_string(k);                           //随机产生部门编号
		else if (k <= 20) Dept[k].dept_no = "D0" + to_string(k);

		ve = randVector(10);
		for (int p = rand() % 9 + 2; p > 0; p--) 
        {                                      //随机部门兴趣标签
			Dept[k].tag[p-1] = setTag(ve[p-1]);
		}
		ve.clear();
	}
    cout << d1 << " " << d2 << " " << d3 << " " << d4 << " " << d5 << " " << d6 << " " << d7 << " " << d8 << " " << d9 << " " << d10 << endl;
	fout << "{" << endl << "\t\"students\": [" << endl;
	//学生信息统一输出
	for (int i = 1; i <301; i++)                                                        
	{
		fout << "\t\t{" << endl;

		fout << "\t\t\t\"free_time\": [" << endl;                                       // 输出空闲时间
		outputTime("Mon", Stu[i].Mon);
		outputTime("Tues", Stu[i].Tues);
		outputTime("Wed", Stu[i].Wed);
		outputTime("Thur", Stu[i].Thur);
		outputTime("Fri", Stu[i].Fri);
		outputTime("Sat", Stu[i].Sat);
		outputTime("Sun", Stu[i].Sun);
		fout << "\t\t\t]," << endl;
		
		fout << "\t\t\t\"student_no\": " << "\"" << Stu[i].student_no << "\"," << endl; // 输出学生编号
		
		fout << "\t\t\t\"applications_department\": [" << endl;                         // 输出兴趣部门编号
		for (int j = 0; j < 5; j++) {
			if (Stu[i].application_dept[j].length() != 0&&Stu[i].application_dept[j + 1].length() != 0) 
                fout << "\t\t\t\t\"" << Stu[i].application_dept[j] << "\"," << endl;
			else if (Stu[i].application_dept[j].length() != 0&&Stu[i].application_dept[j + 1].length() == 0) 
                fout << "\t\t\t\t\"" << Stu[i].application_dept[j] << "\"" << endl << "\t\t\t]," << endl;
		}
		
		fout << "\t\t\t\"tags\": [" << endl;                                            // 输出兴趣标签
		for (int j = 0; j < 10; j++)
			if (Stu[i].tag[j].length()!=0&&Stu[i].tag[j+1].length() != 0) 
                fout << "\t\t\t\t\"" << Stu[i].tag[j] << "\"," << endl;
			else if (Stu[i].tag[j].length() != 0&&Stu[i].tag[j + 1].length() == 0) 
                fout << "\t\t\t\t\"" << Stu[i].tag[j] << "\"" << endl << "\t\t\t]" << endl;
		
		if (i == 300) fout << "\t\t}" << endl;
		else fout << "\t\t}," << endl;
	}
	fout << "\t]," << endl;

	fout<< "\t\"departments\": [" << endl;
	//输出部门信息	
	for (int i = 1; i <= 20; i++) 
    {
		fout << "\t\t{" << endl;

		fout << "\t\t\t\"event_shedules\": [" << endl;                                       // 输出空闲时间
		outputTimed(i, "Mon", Dept[i].Mon); 
		outputTimed(i, "Tues", Dept[i].Tues); 
		outputTimed(i, "Wed", Dept[i].Wed);
		outputTimed(i, "Thur", Dept[i].Thur);
		outputTimed(i, "Fri", Dept[i].Fri); 
		outputTimed(i, "Sat", Dept[i].Sat); 
		outputTimed(i, "Sun", Dept[i].Sun); 
		fout << "\t\t\t]," << endl;

		fout << "\t\t\t\"member_limit\": " << Dept[i].num << "," << endl;                     //输出部门人数限制

		fout << "\t\t\t\"department_no\": \"" << Dept[i].dept_no << "\"," << endl;                

		fout << "\t\t\t\"tags\": [" << endl;                                          //输出部门编号
		for (int j = 0; j < 10; j++)                                                  //输出部门兴趣标签
			if (Dept[i].tag[j].length() != 0&&Dept[i].tag[j + 1].length() != 0) 
                fout << "\t\t\t\t\"" <<Dept[i].tag[j] << "\"," << endl;
			else if (Dept[i].tag[j].length() != 0&&Dept[i].tag[j + 1].length() == 0) 
                fout << "\t\t\t\t\"" << Dept[i].tag[j] << "\"" << endl << "\t\t\t]" << endl;
	
		if (i == 20) fout << "\t\t}" << endl;
		else fout << "\t\t}," << endl;
	}
	fout << "\t]" << endl;
	fout << "}" << endl;
    cout << r1 << " " << r2 << " " << r3 << " " << r4 << " " << r5 << " " << r6 << " " << r7 << " " << r8 << " " << r9 << " " << r10 << " "<< r11 << " "<< r12 << " "<< r13 << " "<< r14 << " "<< r15 << " "<< r16 << " "<< r17 << " "<< r18 << " "<< r19 << " "<< r20 << " "<< endl;
	system("pause");
	return 0;
	}
