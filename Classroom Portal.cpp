#include<iostream>
#include <cstdlib>
#include <fstream>
#include <conio.h>
#include <windows.h>
using namespace std;
class person{
	string message;               
	string gender;
	person *prev;
	person *next;
	string name;
	string subject;
	string password;
	bool quiz;	
	string roll_no;
	int p_count;
	int a_count;
	int marks;
public:
	void set_quiz(bool a){
		quiz=a;
	}
	bool get_quiz(){
		return quiz;
	}
	void set_message(string i){
		message=i;
	}
	string get_message(){
		return message;
	}
	void set_gender(string s){
		gender=s;
	}
	string get_gender(){
		return gender;
	}
	
	void set_prev(person *a){
		prev=a;
	}
	person *get_prev(){
		return prev;
	}
	void set_next(person *b){
		next=b;
	}
	person *get_next(){
		return next;
	}
	void set_subject(string s){
		subject=s;
	}
	string get_subject(){
		return subject;
	}
	void set_name(string s){
		name=s;
	}
	string get_name(){
		return name;
	}
	void set_password(string s){
		password=s;
	}
	string get_password(){
		return password;
	}
	void set_marks(int n){
		marks=n;
	}
	int get_marks(){
		return marks;
	}
	void set_p_count(int i){
		p_count=i;
	}
	int get_p_count(){
		return p_count;
	}
	void set_a_count(int i){
		a_count=i;
	}
	int get_a_count(){
		return a_count;
	}
	void set_roll_no(string a){
		roll_no=a;
	}
	string get_roll_no(){
		return roll_no;
	}
	person(person *a,string nam,string gender,string subj,string passw,string m,bool n,string roll,int a_coun,int p_coun,int mar,person *b){
		marks=mar;
		a_count=a_coun;
		p_count=p_coun;
		roll_no=roll;
		quiz=n;
		set_prev(a);
		name=nam;
		set_gender(gender);
		subject=subj;
		password=passw;
		set_next(b);	
		message=m;
	} 
};
class classroom{
	person *sroot;
	person *troot;
	string hard_questions[5];
	char hard_answer[5];
	string easy_questions[5];
	char easy_answer[5];
	int date;
	void save_quiz_data(){
		ofstream qdata;
		qdata.open("quizh.txt", ios :: app);
		for(int i=0 ; i<5 ; i++){
			qdata<<date;
			qdata<<endl;
			qdata<<hard_questions[i];
			qdata<<endl;
			qdata<<hard_answer[i];
		}
		qdata.close();
		ofstream pdata;
		pdata.open("quize.txt", ios :: app);
		for(int i=0 ; i<5 ; i++){
			pdata<<easy_questions[i];
			pdata<<endl;
			pdata<<easy_answer[i];
		}
		pdata.close();
	}
	void read_quiz_data(){
		ifstream idata;
		idata.open("quizh.txt");
		if(idata.is_open()){
			idata>>date;
			idata>>hard_questions[0];
			idata>>hard_answer[0];
			while(!idata.eof() ){
				for(int i=1 ; i<5 ; i++){
					idata>>hard_questions[i];
					idata>>hard_answer[i];	
				}	
			}
			idata.close();
		}
		ifstream jdata;
		jdata.open("quize.txt");
		if(jdata.is_open()){
			jdata>>easy_questions[0];
			jdata>>easy_answer[0];
			while(!idata.eof() ){
				for(int i=1 ; i<5 ; i++){
					idata>>easy_questions[i];
					idata>>easy_answer[i];	
				}	
			}
			idata.close();
		}
	}
	void teacher_login(){
		if(troot==NULL){
			teacher_registration();
		}
		char optr;
		tl:
		system("cls");
		cout<<"\n\n\n\t\t________________________________________";
		cout<<"\n\t\t|>>>>>>- Check-in's Teacher's Login-<<<<<<";
		cout<<"\n\t\t|";
		cout<<"\n\t\t| a) Login";
		cout<<"\n\t\t| b) Back";
		cout<<"\n\t\t| Select --> ";
		cin>>optr;
		if(optr=='a'){
			string o;
			system("cls");
			cout<<"\n\n\n\t\t________________________________________";
			cout<<"\n\t\t|>>>>>>- Check-in's Teacher's Login-<<<<<<";
			cout<<"\n\t\t|";
			cout<<"\n\t\t| Enter Your Name : ";			
			cin>>o;
			cout<<"\n\t\t| Enter Your Password : ";
			string pass;
			cin>>pass;
		    person *t=troot;
			if(pass==t->get_password()){
				system("cls");
				teachers_home(t);
				system("cls");
			}
			else{
				Beep(523,500);
				cout<<"\n\t\t| Password Not Match";
				cout<<"\n\t\t| ";
				system("pause");
				system("cls");
				goto tl;
			}		
		}
		else if(optr=='b'){
			system("cls");
			homepage();
		}
		else{
			Beep(523,500);
			cout<<"\n\t\t| Wrong Selection";
			cout<<"\n\t\t| ";
			system("pause");
			system("cls");
			goto tl;
		}
		system("cls");
	}
	void teacher_registration(){
		system("cls");
		cout<<"\n\n\n\t\t__________________________________________________";
		cout<<"\n\t\t|>>>>>>- Check-in's Teacher's Registration -<<<<<<";
		cout<<"\n\t\t|";
		cout<<"\n\t\t| Enter Your Name : ";
		string n;
		cin>>n;
		cout<<"\n\t\t| Enter Your Gender : ";
		string g;
		cin>>g;
		cout<<"\n\t\t| Enter Your Subject title : ";
		string s;
		cin>>s;
		p:
		cout<<"\n\t\t| Enter Your Password : ";
		string p;
		cin>>p;
		cout<<"\n\t\t| Re-Enter Your Password : ";
		string r;
		cin>>r;
		if(p==r){
			cout<<"\n\t\t| Congrats Your Account is Created";
		}
		else{
			cout<<"\n\t\t| Password not Match";
			cout<<"\n\t\t| ";
			system("pause");
			system("cls");
			goto p;
		}
		person *t= new person(NULL,n,g,s,p,"NULL",false,"NULL",0,0,0,NULL);
		troot=t;
		cout<<"\n\t\t| ";
		system("pause");
		system("cls");
		cout<<"\n\t\t| Your User_name is : "<<t->get_name();
        cout<<"\n\t\t| Your Password is : "<<t->get_password();
        cout<<"\n\t\t| ";
		system("pause");
        system("cls");
	}
	void student_attendence(person *t){
		char ot;
		sa:
		system("cls");
		cout<<"\n\n\n\t\t__________________________________________________________";
		cout<<"\n\t\t|>>>>>>- Check-in's Teacher's Student Attendence -<<<<<<";
		cout<<"\n\t\t|";
		cout<<"\n\t\t| a) Add Attendance";
		cout<<"\n\t\t| b) Back";
		cout<<"\n\t\t| Select --> ";
		cin>>ot;
		if(ot=='a'){
			if(sroot==NULL){
				cout<<"\n\t\t| No Student Yet Joined";
			}
			else{
				cout<<"\n\t\t| Day : "<<date++;
				person *s=sroot;
				char st;
				int p=0,q=0,t=0;
				while(s!=NULL){
					att:
					cout<<"\n\t\t| Roll No.: "<<s->get_roll_no()<<"\tName : "<<s->get_name()<<"\tStatus (p or a) : ";
					cin>>st;
					if(st=='P'|| st=='p'){
						s->set_p_count(s->get_p_count()+1);	
						p++;
						t++;
					}
					else if(st=='a' || st=='A'){
						s->set_a_count(s->get_a_count()+1);
						q++;
						t++;
					}
					else{
						cout<<"\n\t\t| Wrong Entry";
						cout<<"\n\t\t| ";
						system("pause");
						system("cls");
						goto att;
					}
					s=s->get_next();
				}
				cout<<"\n\t\t| Total Students : "<<t;
				cout<<"\n\t\t| Total Present : "<<p;
				cout<<"\n\t\t| Total absent : "<<q;
			}
			cout<<"\n\t\t| ";
			system("pause");
			system("cls");
			teachers_home(t);
		}
		else if(ot=='b'){
			cout<<"\n\t\t| ";
			system("pause");
			system("cls");
			teachers_home(t);	
		}
		else{
			cout<<"\n\t\t| Wrong Selection";
			cout<<"\n\t\t| ";
			system("pause");
			system("cls");
			goto sa;	
		}
	}
	void remove(person *t){
		system("cls");
		cout<<"\n\n\n\t\t_______________________________________________________";
		cout<<"\n\t\t|>>>>>>- Check-in's Student's Remove Section-<<<<<<";
		cout<<"\n\t\t| ";
		if(sroot==NULL){
			cout<<"\n\t\t| No Students Joint Yet";
		}
		else{
			person *s = sroot;
			cout<<"\n\t\t| Enter Roll No. That You Want to Remove (000): ";
			string r;
			cin>>r;
			bool check=true;
			while(s!=NULL && check){
				if(r==s->get_roll_no()){
					if(s->get_prev()==NULL){
						person *temp=s;
						sroot=s->get_next();
						delete temp;
						check=false;
					}
					else if(s->get_next()==NULL){
						person *tem=s;
						person *temp=s->get_prev();
						temp->set_next(NULL);
						delete tem;
						check=false;
					}
					else{									
						person *temp=s;
						person *p=s->get_prev();
						person *n=s->get_next();
						p->set_next(n);
						n->set_prev(p);
						delete temp;
						check=false;
					}
				}
				else{
					s=s->get_next();
				}	
			}
			if(!check){
				cout<<"\n\t\t| Delete Successfully";
			}
			else{
				cout<<"\n\t\t| Not Found";
			}
			cout<<"\n\t\t| ";
			system("pause");
			system("cls");
			teachers_home(t);
		}
	}
	void student_login(){
		char q;
		sl:
		system("cls");
		cout<<"\n\n\n\t\t________________________________________";
		cout<<"\n\t\t|>>>>>>- Check-in's Student's Login-<<<<<<";
		cout<<"\n\t\t|";
		cout<<"\n\t\t|a) Login";
		cout<<"\n\t\t|r) Register";
		cout<<"\n\t\t|b) Back To Homepage";
		cout<<"\n\t\t|Select --> ";
		cin>>q;
		person *s=sroot;
		if(q=='a'){
			string n;
			system("cls");
			cout<<"\n\n\n\t\t__________________________________________";
			cout<<"\n\t\t|>>>>>>- Check-in's Student's Login-<<<<<<";
			cout<<"\n\t\t|";
			cout<<"\n\t\t| Enter Your Name : ";
			cin>>n;
			string p;
			cout<<"\n\t\t|";
			cout<<"\n\t\t| Enter Password : ";
			cin>>p;
			if(sroot==NULL){
				Beep(523,500);
				cout<<"\n\t\t|You Have To Registered First";
				cout<<"\n\t\t| ";
				system("pause");
				system("cls");
				goto sl;
			}
			else if(sroot!=NULL){
				while(s!=NULL){
					if(n==s->get_name()){
						if(p==s->get_password()){
							student_home(s);
							cout<<"\n\t\t| ";
							system("pause");
							system("cls");
							goto sl;
						}
						else{
							Beep(523,500);
							cout<<"\n\t\t|Name and Password not Matched";
							cout<<"\n\t\t|";
							system("pause");
							system("cls");
							goto sl;
						}	
					}
					s=s->get_next();
				}
			}
			cout<<"\n\t\t|";
			system("pause");
			system("cls");
			goto sl;
		}
		else if(q=='r'){
			string a;
			system("cls");
			cout<<"\n\n\n\t\t_________________________________________________";
			cout<<"\n\t\t|>>>>>>- Check-in's Student's Registration-<<<<<<";
			cout<<"\n\t\t|";
			cout<<"\n\t\t| Enter Your Name : ";
			cin>>a;
			cout<<"\n\t\t|";
			cout<<"\n\t\t| Enter Your Gender : ";
			string b;
			cin>>b;
			cout<<"\n\t\t|";
			cout<<"\n\t\t| Enter Your Roll No. : ";
			string c;
			cin>>c;
			if(sroot!=NULL){
				person *a=sroot;
				while(a!=NULL){
					if(a->get_roll_no()==c){
						cout<<"\n\t\t|";
						cout<<"\n\t\t| Roll Number Already Exsists";
						cout<<"\n\t\t|";
						system("pause");
						system("cls");
						goto sl;
					}
					a=a->get_next();
				}
			}
			cout<<"\n\t\t|";
			cout<<"\n\t\t| Enter Subject Name : ";
			string d;
			cin>>d;
			s:
			cout<<"\n\t\t|";
			cout<<"\n\t\t| Enter Your Password : ";
			string p;
			cin>>p;
			cout<<"\n\t\t|";
			cout<<"\n\t\t| Re-Enter Your Name : ";
			string r;
			cin>>r;
			if(p==r){
				cout<<"\n\t\t|";
				cout<<"\n\t\t| Congrats Your Account is Created";
			}
			else{
				cout<<"\n\t\t|";
				cout<<"\n\t\t| Password not Match";
				cout<<"\n\t\t|";
				system("pause");
				system("cls");
				goto s;
			}
			person *s1=new person(NULL,a,b,d,p,"NULL",true,c,0,0,0,NULL);
			if(sroot==NULL){
				s1->set_prev(NULL);
				s1->set_next(NULL);
				sroot=s1;
			}
			else{
				while(s->get_next()!=NULL){
					s=s->get_next();				
				}
				s->set_next(s1);
				s1->set_prev(s);
				s1->set_next(NULL);
			}
			cout<<"\n\t\t|";
			cout<<"\n\t\t| Your Name is : "<<s1->get_name();
			cout<<"\n\t\t|";
			cout<<"\n\t\t| Your Password is : "<<s1->get_password();
			cout<<"\n\t\t|";
			system("pause");
			system("cls");
			goto sl;
		}
		else if(q=='b'){
			cout<<endl;
			system("cls");
			homepage();
		}
		else{
			Beep(523,500);
			cout<<"\n\t\t|";
			cout<<"\n\t\t| !!Wrong Entry!!";
			cout<<"\n\t\t|";
			system("pause");
			system("cls");
			goto sl;
		}
		system("cls");
	}
	void teachers_home(person *t){
		char o;
		tp:
		system("cls");
		cout<<"\n\n\n\t\t________________________________________________";
		cout<<"\n\t\t|>>>>>>- Check-in's Teacher's Portal -<<<<<<";
		cout<<"\n\t\t|";
		cout<<"\n\t\t| Subject : "<<t->get_subject();  
		cout<<"\n\t\t| Welcome : "<<t->get_name()<<"\t\tStatus : Online";
		cout<<"\n\t\t| a) Student Attendence";
		cout<<"\n\t\t| q) Quiz";
		cout<<"\n\t\t| m) Add Message Announcement";
		cout<<"\n\t\t| p) Personal Info";
		cout<<"\n\t\t| r) Delete a Student";
		cout<<"\n\t\t| c) Change Password";
		cout<<"\n\t\t| d) Students Records";
		cout<<"\n\t\t| l) Log out";
		cout<<"\n\t\t| Select --> ";
		cin>>o;
		if(o=='a'){
			student_attendence(t);
			cout<<endl;
			system("pause");
			system("cls");
			goto tp;
		}
		else if(o=='q'){
			set_quiz(t);
			cout<<"\n\t\t| ";
			system("pause");
			system("cls");
			goto tp;
		}
		else if(o=='m'){
			system("cls");
			cout<<"\n\n\n\t\t_________________________________________________________";
			cout<<"\n\t\t|>>>>>>- Check-in's Teacher's Add Message -<<<<<<";
			cout<<"\n\t\t|";
			cout<<"\n\t\t| Enter Public Message Or Announcement (use _ for space) : ";
			string m;
			cin>>m;
			t->set_message(m);
			cout<<"\n\t\t| ";
			system("pause");
			system("cls");
			goto tp;
		}
		else if(o=='p'){
			system("cls");
			cout<<"\n\n\n\t\t_________________________________________________________";
			cout<<"\n\t\t|>>>>>>- Check-in's Teacher's Personal Info -<<<<<<";
			cout<<"\n\t\t|";
			cout<<"\n\t\t| Name : "<<t->get_name();
			cout<<"\n\t\t| Gender : "<<t->get_gender();
			cout<<"\n\t\t| Subject : "<<t->get_subject();
			cout<<"\n\t\t| Password : "<<t->get_password();
			cout<<"\n\t\t| ";
			system("pause");
			system("cls");
			goto tp;
		}
		else if(o=='r'){
			remove(t);
			cout<<"\n\t\t| "; 
			system("pause");
			system("cls");
			goto tp;
		}
		else if(o=='c'){
			change_password(t);
			cout<<"\n\t\t| ";
			system("pause");
			system("cls");
			goto tp;
		}
		else if(o=='d'){
			system("cls");
			cout<<"\n\n\n_________________________________________________________________________";
			cout<<"\n|>>>>>>- Check-in's Students  -<<<<<<";
			cout<<"\n|";
			if(sroot==NULL){
				cout<<"\n\t\t| No Student Joint Yet";
			}	
			else{
				person *s=sroot;
				cout<<"\n|Roll no.\tName\tGender\tPresent\tAbsent\tTotal Days\tMarks"<<endl;
				while(s!=NULL){
					cout<<s->get_roll_no()<<"\t\t"<<s->get_name()<<"\t"<<s->get_gender()<<"\t"<<s->get_p_count()<<"\t"<<s->get_a_count()<<"\t\t"<<date<<"\t"<<s->get_marks();
					cout<<endl;
					s=s->get_next();
				} 
			}
			cout<<"\n\t\t| ";
			system("pause");
			system("cls");
			goto tp;
		}
		else if(o=='l'){
			system("cls");
			teacher_login();
		}
		else{
			Beep(523,500);
		 	cout<<"\n\t\t| Wrong Selection";
			cout<<"\n\t\t| ";
			system("pause");
			system("cls");
			goto tp;
		}
	}
	void student_home(person *s){
		person *t=troot;
		char w;
		sp:
		system("cls");
		cout<<"\n\n\n\t\t________________________________________________";
		cout<<"\n\t\t|>>>>>>- Check-in's Student's Portal -<<<<<<";
		cout<<"\n\t\t|";
		cout<<"\n\t\t| Subject : "<<s->get_subject(); 
		cout<<"\n\t\t|";
		cout<<"\n\t\t| Welcome : "<<s->get_name()<<"\t\tStatus : Online"; 
		cout<<"\n\t\t| a) Dashboard";
		cout<<"\n\t\t| q) Quiz";
		cout<<"\n\t\t| m) Message Announcement";
		cout<<"\n\t\t| p) Personal Info";
		cout<<"\n\t\t| c) Change Password";
		cout<<"\n\t\t| d) Student Records";
		cout<<"\n\t\t| l) Log out";
		cout<<"\n\t\t|";
		cout<<"\n\t\t| Select --> ";	
		cin>>w;
		if(w=='a'){
			system("cls");
			cout<<"\n\n\n\t\t________________________________________________";
			cout<<"\n\t\t|>>>>>>- Check-in's Student's Dashboard -<<<<<<";
			cout<<"\n\t\t|";
			if(troot!=NULL){
				if(s->get_p_count()==0 && s->get_a_count()==0 && t->get_message()=="NULL"){
					cout<<"\n\t\t| No Thing Updated Yet";
				}
				if(s->get_a_count()!=0 || s->get_p_count()!=0){
					cout<<"\n\t\t| Attendence has been Uploaded";
				}
				if(t->get_message()!="NULL"){
					cout<<"\n\t\t| No Message Delivered yet";	
				}
				if(t->get_quiz()){
					cout<<"\n\t\t| Quiz Has been Uploaded";
				}
			}
			cout<<"\n\t\t| No Thing Updated Yet";
			cout<<"\n\t\t| ";
			system("pause");
			system("cls");
			goto sp;
		}
		else if(w=='q'){
			system("cls");
			cout<<"\n\n\n\t\t__________________________________________";
			cout<<"\n\t\t|>>>>>>- Check-in's Student's Quiz -<<<<<<";
			cout<<"\n\t\t|";
			if(troot!=NULL){
				if(t->get_quiz()){
					if(s->get_quiz()){
					get_quiz(s);
				}
				else{
					cout<<"\n\t\t| ";
					cout<<"\n\t\t| You Alraedy Appared in Quiz";
				}
				}
			}
			else{
				cout<<"\n\t\t| ";
				cout<<"\n\t\t| No Quiz Uploaded Yet";
			}
			cout<<"\n\t\t| ";
			system("pause");
			system("cls");
			goto sp;
		}
		else if(w=='m'){
		    system("cls");
			cout<<"\n\n\n\t\t________________________________________________";
			cout<<"\n\t\t|>>>>>>- Check-in's Student's Message -<<<<<<";
			cout<<"\n\t\t|";
			if(troot!=NULL){
				if(t->get_message()=="NULL"){
					cout<<"\n\t\t| No Message Announce Yet";
				}
				else{
					cout<<"\n\t\t|Message : "<<t->get_message();
				}	
			}
			else{
				cout<<"\n\t\t| No Message Announce Yet";
			}
			cout<<"\n\t\t| ";
			system("pause");
			system("cls");
			goto sp;
		}
		else if(w=='p'){
			system("cls");
			cout<<"\n\n\n\t\t________________________________________________";
			cout<<"\n\t\t|>>>>>>- Check-in's Student's Personal Info -<<<<<<";
			cout<<"\n\t\t|";
			cout<<"\n\t\t| Name : "<<s->get_name();
			cout<<"\n\t\t| Gender : "<<s->get_gender();
			cout<<"\n\t\t| Subject : "<<s->get_subject();
			cout<<"\n\t\t| Roll no. : "<<s->get_roll_no();
			cout<<"\n\t\t| Password : "<<s->get_password();
			cout<<"\n\t\t| ";
			system("pause");
			system("cls");
			goto sp;
		}
		else if(w=='c'){
			change_spassword(s);
			cout<<"\n\t\t| ";
			system("pause");
			system("cls");
			goto sp;
		}
		else if(w=='d'){
			system("cls");
			cout<<"\n\n\n________________________________________________";
			cout<<"\n|>>>>>>- Check-in's Student's Record -<<<<<<";
			cout<<"\n|";
			cout<<"\n| Roll no.\tName\tGender\tPresent\tAbsent\tTotal Days\tMarks"<<endl;
			cout<<"\n| "<<s->get_roll_no()<<"\t\t"<<s->get_name()<<"\t"<<s->get_gender()<<"\t"<<s->get_p_count()<<"\t"<<s->get_a_count()<<"\t\t"<<date<<"\t"<<s->get_marks();				 
			cout<<"\n| ";
			system("pause");
			system("cls");
			goto sp;
		}
		else if(w=='l'){
			system("cls");
			student_login();
		}
		else{
			cout<<"\n\t\t| !!Wrong Selection !!";
			cout<<"\nWrong Selection";
			cout<<"\n\t\t| ";
			system("pause");
			system("cls");
			goto sp;
		}
	}
	void change_password(person *t){
		string p;
		cl:
		system("cls");
		cout<<"\n\n\n\t\t_____________________________________________________";
		cout<<"\n\t\t|>>>>>>- Check-in's Teacher's Change Password -<<<<<<";
		cout<<"\n\t\t|";
		cout<<"\n\t\t| Enter Your Old Password : ";
		cin>>p;
		if(p==t->get_password()){
			string n;
			cp:
			cout<<"\n\t\t| Enter New Password : ";
			cin>>n;
			string r;
			cout<<"\n\t\t| Re-Enter Password : ";
			cin>>r;
			if(n==r){
				cout<<"\n\t\t| Your Password is Updated";
				t->set_password(n);
				cout<<"\n\t\t| New Password is : "<<t->get_password();
				cout<<"\n\t\t| ";
				system("pause");
				system("cls");
				teachers_home(t);
			}
			else{
				Beep(523,500);
				cout<<"\n\t\t| Both Password Not Match"<<endl;
				cout<<"\n\t\t| c) Continue";
				cout<<"\n\t\t| b) Back";
				char ad;
				cout<<"\n\t\t| Select -- > ";
				cin>>ad;
				if(ad=='b'){
					cout<<"\n\t\t| ";
					system("pause");
					system("cls");
					teachers_home(t);
				}
				cout<<"\n\t\t| ";
				system("pause");
				system("cls");
				goto cp;
			}
		}
		else{
			Beep(523,500);
			cout<<"\n\t\t| Your Password is Not Matach";
			cout<<"\n\t\t| c) Continue";
			cout<<"\n\t\t| b) Back";
			char ad;
			cout<<"\n\t\t| Select -- > ";
			cin>>ad;
			if(ad=='b'){
				cout<<"\n\t\t| ";
				system("pause");
				system("cls");
				teachers_home(t);
			}
			cout<<"\n\t\t| ";
			system("pause");
			system("cls");
			goto cl;
		}
	}
	void change_spassword(person *s){
		string p;
		cl2:
		system("cls");
		cout<<"\n\n\n\t\t_____________________________________________________";
		cout<<"\n\t\t|>>>>>>- Check-in's Student's Change Password -<<<<<<";
		cout<<"\n\t\t|";
		cout<<"\n\t\t| Enter Your Old Password : ";
		cin>>p;
		if(p==s->get_password()){
			string n;
			cp2:
			cout<<"\n\t\t| Enter New Password : ";
			cin>>n;
			string r;
			cout<<"\n\t\t| Re-Enter Your Old Password : ";
			cin>>r;
			if(n==r){
				cout<<"\n\t\t| Your Old Is Updated";
				s->set_password(n);
				cout<<"\n\t\t| New Password is : "<<s->get_password()<<endl;
				cout<<"\n\t\t| ";
				system("pause");
				system("cls");
				student_home(s);
			}
			else{
				Beep(523,500);
				cout<<"\n\t\t| Both Password Not Match";
				cout<<"\n\t\t| ";
				cout<<"\n\t\t| c) Continue";
				cout<<"\n\t\t| b) Back";
				cout<<"\n\t\t| ";
				char ad;
				cout<<"\n\t\t| Select -- > ";
				cin>>ad;
				if(ad=='b'){
					cout<<"\n\t\t| ";
					system("pause");
					system("cls");
					student_home(s);
				}
				cout<<"\n\t\t| ";
				system("pause");
				system("cls");
				goto cp2;
			}
		}
		else{
			Beep(523,500);
			cout<<"\n\t\t| Your Password is Not Matach";
			cout<<"\n\t\t| ";
			cout<<"\n\t\t| c) Continue";
			cout<<"\n\t\t| b) Back";
			cout<<"\n\t\t| ";
			char ad;
			cout<<"\n\t\t| Select -- > ";
			cin>>ad;
			if(ad=='b'){
				cout<<"\n\t\t| ";
				system("pause");
				system("cls");
				student_home(s);
			}
			cout<<"\n\t\t| ";
			system("pause");
			system("cls");
			goto cl2;
		}
	}
	void set_quiz(person *t){
		system("cls");
		cout<<"\n\n\n\t\t__________________________________________________";
		cout<<"\n\t\t|>>>>>>- Check-in's Teacher's Set Quiz -<<<<<<";
		cout<<"\n\t\t|";
		for(int i=0 ; i<5 ; i++){
			cout<<"\n\t\t| Enter "<<i<<" Hard Question (use _ for space) :: ";
			cin>>hard_questions[i];	
			cout<<"\n\t\t| Enter "<<i<<" Hard Answer ('y' or 'n') :: ";
			cin>>hard_answer[i];
		}
		for(int i=0 ; i<5 ; i++){
			cout<<"\n\t\t| Enter "<<i<<" Easy Question (use _ for space) :: ";
			cin>>easy_questions[i];	
			cout<<"\n\t\t| Enter "<<i<<" Easy Answer ('y' or 'n') :: ";
			cin>>easy_answer[i];
		}
		t->set_quiz(true);
		cout<<"\n\t\t| ";
		system("pause");
		system("cls");
		teachers_home(t);
	}
	void get_quiz(person *s){
        DWORD start_time, check_time;
        start_time=GetTickCount();
        check_time=start_time+5000;
		char ans='n';
		bool check=true;
		system("color F4");
		for(int j=0 ; j<5 ; j++){
			cout<<"\n\t\t| Question "<<j<<" : -"<<endl;
        	cout<<"\n\t\t|"<<hard_questions[j]<<endl;
			while(!kbhit() && check){
				
				cout<<"\n\t\t| Please enter the Answer ('y' or 'n') : "; 
				system("color F0");
            	while((check_time>GetTickCount())){
                	if (kbhit()){
                    	cin>>ans;
                    	if(ans==hard_answer[j]){
                    		s->set_marks(s->get_marks()+5);
						}
						else{
							s->set_marks(s->get_marks()-5);
							Beep(523,500);
						}
						cout<<"\n\t\t| Data accepted"<<endl;
                	}
                	else{
                		check=false;
					}
            	}
            	cout<<"\n\t\t| Time-out: 5 seconds"<<endl;
            	cout<<"\n\t\t| Timer again set to 0"<<endl;
            	start_time=GetTickCount();
            	check_time=start_time+5000;
        	}	
        	s->set_quiz(false);
			check=true;	
		}
		bool checki=true;
		for(int j=0 ; j<5 ; j++){
        	cout<<"\n\t\t| Question "<<j<<" : -"<<endl;
        	system("color F4");
        	cout<<"\n\t\t| "<<easy_questions[j]<<endl;
			while(!kbhit() && checki){
			
            cout<<"\n\t\t| Please enter the Answer ('y' or 'n') : ";
            system("color F0");
            while((check_time>GetTickCount())){
                if (kbhit()){
                    cin>>ans;
                    if(ans==easy_answer[j]){
                    	s->set_marks(s->get_marks()+5);
					}
					else{
						s->set_marks(s->get_marks()-5);
						Beep(523,500);
					}
                    cout<<"\n\t\t| Data accepted"<<endl;
                    //return 0;                	
					}
					else{
                		checki=false;
					}
            	}
            	cout<<"\n\t\t| Time-out: 5 seconds"<<endl;
            	cout<<"\n\t\t| Timer again set to 0"<<endl;
            	start_time=GetTickCount();
            	check_time=start_time+5000;
			}
			checki=true;		
		}
	}
	void save_student_data(){
		ofstream sdata;
		sdata.open("student.txt", ios :: app);
		if(sroot!=NULL){
			person *s1=sroot;
			while(s1!=NULL){
				sdata<<endl;
				sdata<<s1->get_roll_no();
				sdata<<endl;
				sdata<<s1->get_name();
				sdata<<endl;
				sdata<<s1->get_gender();
				sdata<<endl;
				sdata<<s1->get_p_count();
				sdata<<endl;
				sdata<<s1->get_a_count();
				sdata<<endl;
				sdata<<s1->get_marks();
				sdata<<endl;
				sdata<<s1->get_password();
				sdata<<endl;
				sdata<<s1->get_subject();
				sdata<<endl;
				sdata<<s1->get_quiz();
				sdata<<endl;
				s1=s1->get_next();
			}
			sdata.close();
		}
	}
	void save_teacher_data(){
		ofstream mdata;
		if(troot!=NULL){
			person *t=troot;
			mdata.open("teacher.txt", ios :: app);
			mdata<<endl;
			mdata<<t->get_name();
			mdata<<endl;
			mdata<<t->get_gender();
			mdata<<endl;
			mdata<<t->get_quiz();
			mdata<<endl;
			mdata<<t->get_password();
			mdata<<endl;
			mdata<<t->get_subject();
			mdata<<endl;
			mdata<<t->get_message();
			mdata<<endl;
			mdata.close();
		}
	}
	void read_teacher_data(){
		ifstream kdata;
		kdata.open("teacher.txt");
		if(kdata.is_open()){
			string name,gender,subject,password,message;
			bool marks;
			kdata>>name;
			kdata>>gender;
			kdata>>marks;
			kdata>>password;
			kdata>>subject;
			kdata>>message;
			person *t=new person(NULL,name,gender,subject,password,message,marks,"NULL",0,0,0,NULL);
			if(troot==NULL){
				troot=t;
				t->set_prev(NULL);
			}
			kdata.close();
		}
	}
	void read_student_data(){
		string roll,name,gender,subject,password;
		int p_count,a_count,marks;
		ifstream tdata;
		bool at;
		tdata.open("student.txt");
		if(tdata.is_open()){
			tdata>>roll;
			tdata>>name;
			tdata>>gender;
			tdata>>p_count;
			tdata>>a_count;
			tdata>>marks;
			tdata>>password;
			tdata>>subject;
			tdata>>at;
			person *s=new person (NULL,name,gender,subject,password,"NULL",at,roll,a_count,p_count,marks,NULL);
			if(sroot==NULL){
				sroot=s;
				s->set_prev(NULL);
			}
			person *a=sroot;
			while(!tdata.eof()){
				tdata>>roll;
				tdata>>name;
				tdata>>gender;
				tdata>>p_count;
				tdata>>a_count;
				tdata>>marks;
				tdata>>password;
				tdata>>subject;
				tdata>>at;
				person *s1=new person (NULL,name,gender,subject,password,"NULL",at,roll,a_count,p_count,marks,NULL);
				a->set_next(s1);
				s1->set_prev(a);
				s1->set_next(NULL);
				a=a->get_next();		
			}
			tdata.close();
			
			person *tem=a;
			person *temp=a->get_prev();
			temp->set_next(NULL);
			delete tem;
		}
	}
public: 
	classroom(){
		sroot=NULL;
		troot=NULL;
		date=0;
	}
	void homepage(){
		char choice;
		hp:
		cout<<"\n\n\n\t\t__________________________________";
		cout<<"\n\t\t|>>>>>>- Check-in's Homepage-<<<<<<";
		cout<<"\n\t\t|";
		cout<<"\n\t\t|t) Teacher's Login";
		cout<<"\n\t\t|s) Student's Login";
		if(sroot!=NULL && troot!=NULL){
			cout<<"\n\t\t|x) Close Window and Save";	
		}
		if(sroot==NULL && troot==NULL){
			read_teacher_data();
			read_student_data();
			if(troot!=NULL){
				person *a=troot;
				if(a->get_quiz()){
					
					read_quiz_data();
				}	
			}
		}
		cout<<"\n\t\t|";
		cout<<"\n\t\t|Select --> ";
		cin>>choice;
		if(choice=='t'){
			system("cls");
			teacher_login();
			system("cls");
		}
		else if(choice=='s'){
			system("cls");
			student_login();
		}
		if(sroot!=NULL && troot!=NULL){
			if(choice=='x'){
				std::ofstream ofs;
				ofs.open("student.txt", std::ofstream::out | std::ofstream::trunc);
				ofs.close();
				std::ofstream ofsl;
				ofsl.open("teacher.txt", std::ofstream::out | std::ofstream::trunc);
				ofsl.close();
				person *q=troot;
				if(q->get_quiz()){
					std::ofstream ofa;
					ofa.open("quizh.txt", std::ofstream::out | std::ofstream::trunc);
					ofa.close();
					std::ofstream ofal;
					ofal.open("quize.txt", std::ofstream::out | std::ofstream::trunc);
					ofal.close();
					save_quiz_data();
				}
				save_student_data();
				save_teacher_data();
				exit(0);				 
			}
		}
		else{
			Beep(523,500);
			cout<<"\n\t\t__________________________________";
			cout<<"\n\t\t| !!Wrong Entry!!";
			cout<<"\n\t\t|";
			system("pause");
			system("cls");
			goto hp;
		}
		
	}
};
int main(){
	
	system("color F0");
	static string class_id="DSA123";
	label:	
	string id;
	cout<<"\n\n\n\t\t____________________________________";
	cout<<"\n\t\t|>>>>>>- Welcome To Classroom Portal -<<<<<<";
	cout<<"\n\t\t|";
	cout<<"\n\t\t|Enter Class ID --> ";
	cin>>id;
	if(id==class_id){
		classroom m;
		system("cls");
		m.homepage();
		system("cls");
		
	}
	else{
		Beep(523,500);
		cout<<"\n\t\t____________________________________";
		cout<<"\n\t\t|Your Id is Not Valid";
		cout<<"\n\t\t|Kindly Contact To Administration";
		cout<<"\n\t\t|";
		system("pause");
		system("cls");
		goto label;
	}
	
	return 0;
}
