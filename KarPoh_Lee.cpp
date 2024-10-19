#include<iostream>
#include<fstream>
#include<string>
#include <iomanip> 
using namespace std;

int invoicenum=1200;
struct DoctorProfiles		
{
	string name;
	string contactno;
	string address;
	string country;
	string section;
	string jointime;
};

struct PatientProfiles
{
	string name;
	string contactno;
	string emergencycontact;
	string country;
	string bloodtype;
	string age;
	
	int bednum;
	string status;
	double bodytemperature;
	string doctorassigned;
	
};

	void editprofile();//function defination
	void doctorassigned();
	void bill();
	void report();

	void sign()
	{
	
	char username[50];
	string passwrd, Cpasswrd;
		
	ofstream file("Password.txt",ios::app);
		
	cout<<" \n________________________________________________"<<endl;
	cout<<"|\t\t\t\t\t\t|"<<endl;
	cout<<"|\tJBW Hospital Management System\t\t|"<<endl;
	cout<<"|\t\t\t\t\t\t|"<<endl;
	cout<<"|_______________________________________________|"<<endl;
	
	cout<<"Sign up account"<<endl;
	
	cout<<"\nUsername : ";
	cin.ignore();
	cin.getline(username,50);
		
	cout<<"\nPassword : ";
	cin>>passwrd;	
	cout<<"\nConfirm Password : ";
	cin>>Cpasswrd;
		
	while(passwrd!=Cpasswrd)
	{
		cout<<"Your Password is different,please re-enter"<<endl;
		cout<<"\nPassword :";
		cin>>passwrd;
		cout<<"Confirm Password :";
		cin>>Cpasswrd;
	}
	
	file<<username<<"  "<<passwrd<<endl;
	file.close();		
	}


	bool login()
	{
	char Lusername[50];
	string Lpasswrd;
	
	bool loggedIn = false;
	
	ifstream read("Password.txt");
	
	cout<<" \n________________________________________________"<<endl;
	cout<<"|\t\t\t\t\t\t|"<<endl;
	cout<<"|\tJBW Hospital Management System\t\t|"<<endl;
	cout<<"|\t\t\t\t\t\t|"<<endl;
	cout<<"|_______________________________________________|"<<endl;
	
	
	do
	{
	/*bool continueLogin = true;
	while(continueLogin)*/
		cout<<"\nUser Name :";
		cin.ignore();
		cin.getline(Lusername,50);
		cout<<"\nPassword :";
		cin>>Lpasswrd;
		
		string fileusername,filepasswrd;
		/*bool loggedIn = false;*/
		while(read>>fileusername>>filepasswrd)
		{
			if(fileusername == string(Lusername) && filepasswrd == Lpasswrd)
			{
				cout<<"\nLogin Successful"<<endl;
				loggedIn = true;
				break;
			}
		}

		if(!loggedIn)
		{
			char choice;
			cout<<"Invalid username or password.Do you want try again?(Y / N)";
			cin>>choice;
			
			if(choice!='Y'&& choice!='y')
			{
				read.close();
				exit(0);
			}
			read.clear();
			read.seekg(0,ios::beg); //reset file pointer to the beginning
		}
	}while(!loggedIn);
	
	read.close();
	return loggedIn;
	}


void resetpassword()
{
    char username[50];
    string newPasswrd, CnewPasswrd,Resetusername,ResetPasswrd;
	
	ifstream file("Password.txt");
	ofstream Resetfile("Reset.txt");

	cout<<" \n________________________________________________"<<endl;
	cout<<"|\t\t\t\t\t\t|"<<endl;
	cout<<"|\tJBW Hospital Management System\t\t|"<<endl;
	cout<<"|\t\t\t\t\t\t|"<<endl;
	cout<<"|_______________________________________________|"<<endl;

    cout << "Reset Password" << endl;
    do
	{
    cout << "\nUsername : ";
    cin.ignore();
    cin.getline(username, 50);

    cout << "\nNew Password : ";
    cin >> newPasswrd;
    cout << "\nConfirm New Password : ";
    cin >> CnewPasswrd;

    if (newPasswrd == CnewPasswrd)
    {
        cout << "\nPassword reset successful" << endl;
        
        while(file>>Resetusername>>ResetPasswrd)
        {
        	if(Resetusername ==string(username))
        	{
        		Resetfile<<Resetusername<<" "<<newPasswrd<<endl;
			}
			else
			{
				Resetfile<<Resetusername<<" "<<ResetPasswrd<<endl;
			}
		}
		
		file.close();
		Resetfile.close();
		
		remove("Password.txt");
		rename("Reset.txt","Password.txt");
    }
    else
    {
        cout << "\nYour Password is different, password reset failed." << endl;
    }
	}while(newPasswrd!=CnewPasswrd);
    
}

main()
{
	int dboard,bed_num,age,option,menu;
	char Pname[50], status[100],d_assigned[50],admission[100];
	double body_temp;
	char username[50];
    string newPasswrd, CnewPasswrd;
	string passwrd, Cpasswrd, Pcontact,date;
	
	cout<<" \n________________________________________________"<<endl;
	cout<<"|\t\t\t\t\t\t|"<<endl;
	cout<<"|\tJBW Hospital Management System\t\t|"<<endl;
	cout<<"|\t\t\t\t\t\t|"<<endl;
	cout<<"|_______________________________________________|"<<endl;
	
	cout<<"Sign up\t\t[1]"<<endl;
	cout<<"Login\t\t[2]"<<endl;
	cout<<"Reset Password \t[3]"<<endl;
	cout<<"\nPlease select :";
	cin>>option;
	
	if(option == 1)
	{
		sign();
	}
	else if(option == 2)
	{
		login();
	}        
	else if(option == 3)
	{
		resetpassword();
	}
	else
	{
        cout << "\nInvalid Option. Please try again." << endl;
        // repeat until correct user input
        while (option < 1 || option > 3) 
		{
            cout << "\nPlease Select: ";
            cin >> option;
            if (option == 1)
			{
                sign();
            }
			else if (option == 2) 
			{
                bool loggedIn = login();
                
                if (loggedIn) 
				{
                    cout << "---------Login Successful----------" << endl;
                    break;
                } 
                
				else 
				{
                    cout << "Invalid username or password" << endl;  
                }
                
            } 
            
			else if (option == 3) 
			{
            resetpassword();
            
            } 
            
			else 
			{
                cout << "\nInvalid Option. Please try again." << endl;
            }
            
        }
    }
	
	cout<<"\nWelcome to JBW Hospital Management System"<<endl;
	
	do
	{
	
		cout<<"\nMain Menu[0] :";
		cin>>menu;
		
		if(menu!=0)
		{
			cout<<"please keyin valid data!!!";
		}
		
	}while(menu!=0);
		
	do
	{
		if(menu == 0)	
		{
		
	
		cout<<" \n________________________________________________"<<endl;
		cout<<"|\t\t\t\t\t\t|"<<endl;
		cout<<"|\tJBW Hospital Management System\t\t|"<<endl;
		cout<<"|\t\t\t\t\t\t|"<<endl;
		cout<<"|_______________________________________________|"<<endl;
		
		cout<<"[1] Patient Registration"<<endl;
		cout<<"[2] Appointment"<<endl;
		cout<<"[3] Edit Profiles"<<endl;
		cout<<"[4] Assign Doctor"<<endl;
		cout<<"[5] Billing & Payment"<<endl;
		cout<<"[6] Reports"<<endl;
		cout<<"[7] Logout "<<endl;
		
		do{
		
		cout<<"\nPlease Select :";
		cin>>dboard;
		
		if(dboard >=8 || dboard<=0)
		{
			cout<<"invalid please select (1-7) !!!";
		}
		
		  }while(dboard >=8 || dboard<=0);
		  
		}
		do{
	
			switch(dboard)
			{
				
				case 1:
				
				do
				{
				
				ofstream write("Register.txt",ios::app);
				
				cout<<" \n________________________________________________"<<endl;
				cout<<"|\t\t\t\t\t\t|"<<endl;
				cout<<"|\tJBW Hospital Management System\t\t|"<<endl;
				cout<<"|\t\t\t\t\t\t|"<<endl;
				cout<<"|_______________________________________________|"<<endl;
				
				cout<<"Bed Number :";
   				cin>>bed_num;
   				cout<<"Name : ";
			    cin.ignore();
			    cin.getline(Pname, 50);
			    cout<<"Status : ";
			    cin.getline(status, 100);
			    cout<<"Body Temperature : ";
			    cin>>body_temp;
			    cout<<"Age : ";
			    cin>>age;
			    cout<<"Doctor Assigned : ";
			    cin.ignore();
			    cin.getline(d_assigned, 50);
			    cout<< "Admission : ";
			    cin.getline(admission, 100);
				
				write<<bed_num<<"\t"<<status<<"\t"<<Pname<<"\t"<<body_temp<<"\t"<<d_assigned<<"\t"<<admission<<endl;
				write.close();
				
				cout<<"\nDo you want back to the menu [0]"<<endl;
				cout<<"Do you want to re-enter the information [1]"<<endl;
				
				cout<<"Please select :";
				cin>>menu;
				}while(menu == 1);
				
				break;
				
				case 2:  
				 
				do{
				cout<<" \n________________________________________________"<<endl;
				cout<<"|\t\t\t\t\t\t|"<<endl;
				cout<<"|\tJBW Hospital Management System\t\t|"<<endl;
				cout<<"|\t\t\t\t\t\t|"<<endl;
				cout<<"|_______________________________________________|"<<endl;
				
				cout<<"\nAppointment -"<<endl;
				
				cout<<"Patient Name :";
				cin.ignore();
				cin.getline(Pname,50);	
				cout<<"Patient contact :";
				cin>>Pcontact;
				cout<<"Doctor Assign :";
				cin.ignore();
				cin.getline(d_assigned,50);  
				cout<<"Date/Time :";
				cin>>date;
				
				cout<<"\nDo you want back to the menu [0]"<<endl;
				cout<<"Do you want to re-enter the information [1]"<<endl;
				
				cout<<"Please select :";
				cin>>menu;
				}while(menu == 1);
				
				break;
								
				case 3:
					
				do
				{
				editprofile();
					// content
				cout<<"\nDo you want back to the menu [0]"<<endl;
				cout<<"Do you want to re-enter the information [1]"<<endl;
				
				cout<<"Please select :";
				cin>>menu;	
				}while(menu == 1);

					break;
					
				case 4:
				do
				{
				doctorassigned();
					// content
				cout<<"\nDo you want back to the menu [0]"<<endl;
				cout<<"Do you want to re-enter the information [1]"<<endl;
				
				cout<<"Please select :";
				cin>>menu;	
				}while(menu == 1);
				
					break;
				
				case 5:
				do
				{
				bill();
					// content
				cout<<"\nDo you want back to the menu [0]"<<endl;
				cout<<"Do you want to re-enter the information [1]"<<endl;
				
				cout<<"Please select :";
				cin>>menu;	
				}while(menu == 1);
									
					break;
				
				case 6:
				do
				{
					report();
					// content
				cout<<"\nDo you want back to the menu [0]"<<endl;
				cout<<"Do you want to re-enter the information [1]"<<endl;
				
				cout<<"Please select :";
				cin>>menu;	
				}while(menu == 1);
					
					break;
				
				case 7:
					cout<<"----------------------------------"<<endl;
					cout<<"\nThank you for using this system"<<endl;
					cout<<"----------------------------------"<<endl;
					exit(0);
					break;
					
				default:   
				 cout<<"Invalid option,please try again"<<endl;	
			}
			
		}while(dboard <1 || dboard >6);
		
	}while(menu == 0);
	
}



void editprofile()
{
		
			cout<<" \n________________________________________________"<<endl;
				cout<<"|\t\t\t\t\t\t|"<<endl;
				cout<<"|\tJBW Hospital Management System\t\t|"<<endl;
				cout<<"|\t\t\t\t\t\t|"<<endl;
				cout<<"|_______________________________________________|"<<endl;
				
				cout<<"\nProfiles Edit -"<<endl;
				cout<<"Doctor Profiles\t\t(1)"<<endl;
				cout<<"Patient Profiles\t(2)"<<endl;
				
				char choice;
				cout<<"\nEnter your choice( 1 or2 ) :";
				cin>>choice;
				
				if (choice == '1') 
				{
		        DoctorProfiles dprofile;
		
		        cout << "Enter Name: ";
		        cin.ignore();
		        getline(cin,dprofile.name);
		        
		        cout << "Enter Contact No: ";
		        cin.ignore();
		        getline(cin,dprofile.contactno);
		        
		        cout << "Enter Address: ";
		        cin.ignore();
		        getline(cin,dprofile.address);
		        
		        cout << "Enter Country: ";
		        cin.ignore();
		        getline(cin,dprofile.country);
		        
		        cout << "Enter Section: ";
		        cin.ignore();
		        getline(cin,dprofile.section);
		        
		        cout << "Enter Join Time: ";
		        cin.ignore();
		        getline(cin,dprofile.jointime);

 			   } 
	
	else if (choice == '2') 
	{
        PatientProfiles pprofile;

        cout << "Enter Name: ";
        cin.ignore();
        getline(cin,pprofile.name);
        
        cout << "Enter Contact No: ";
        cin.ignore();
        getline(cin,pprofile.contactno);
        
        cout << "Enter Guardian/Emergency Cont: ";
        cin.ignore();
        getline(cin,pprofile.emergencycontact);
        
        cout << "Enter Country: ";
        cin.ignore();
        getline(cin,pprofile.country);
        
        cout << "Enter Blood Type: ";
        cin.ignore();
        getline(cin,pprofile.bloodtype);
        
        cout << "Enter Age: ";
        cin.ignore();
        getline(cin,pprofile.age);

        cout << "Enter Bed Number: ";
        cin >> pprofile.bednum;
        
        cout << "Enter Status: ";
        cin.ignore();
        getline(cin,pprofile.status);
        
        cout << "Enter Body Temperature: ";
        cin >> pprofile.bodytemperature;
        
        cout << "Enter Doctor Assigned: ";
        cin.ignore();
        getline(cin,pprofile.doctorassigned);

    } 
    
	else
	{
        cout << "Invalid choice." << endl;
    }
    
	
}
	
	
	
	
	
	
	void doctorassigned()
	{
		using namespace std;
		char doctorname[50];
		int assignroom;
	
		
			cout<<" \n________________________________________________"<<endl;
				cout<<"|\t\t\t\t\t\t|"<<endl;
				cout<<"|\tJBW Hospital Management System\t\t|"<<endl;
				cout<<"|\t\t\t\t\t\t|"<<endl;
				cout<<"|_______________________________________________|"<<endl;
				
				cout<<"\nDoctor Assigned -"<<endl;
				cout<<"Doctor name:";
				cin.ignore();
				cin.getline(doctorname,50);	
				
				cout<<"Assign room number:";
				cin>>assignroom;
					
	}
	
void bill()
{
    ifstream read("Register.txt");
    string line;

    using namespace std;
    string name;
    int contactnum;
    string address;
    string date;
    string d_assigned;
    double ammount;

    cout << " \n________________________________________________" << endl;
    cout << "|\t\t\t\t\t\t|" << endl;
    cout << "|\tJBW Hospital Management System\t\t|" << endl;
    cout << "|\t\t\t\t\t\t|" << endl;
    cout << "|_______________________________________________|" << endl;


    bool patientFound = false;

    cout << "Name:";
    cin.ignore();
    getline(cin, name);
    cout<<"please key in ammount:";
    cin>>ammount;
    
    cout << "\nBill -" << endl;

    while (getline(read, line))
	{
        stringstream ss(line);
        string bed_num, status, patientName, body_temp, d_assigned, admission;
        getline(ss, bed_num, '\t');
        getline(ss, status, '\t');
        getline(ss, patientName, '\t');
        getline(ss, body_temp, '\t');
        getline(ss, d_assigned, '\t');
        getline(ss, admission, '\t');

        if (patientName == name) 
		{
            // 找到匹配的患者姓名
            patientFound = true;

			cout<<"\n";
			cout<<"Patient Information:"<<name;
			cout<<"\t\tDoctor Information:"<<d_assigned;
			cout<<"\n\n\n";
			
			cout<<"Invoice number:"<<++invoicenum;
			cout<<"\tadmissiondate"<<admission;
			cout<<"\t\tAmount:RM"<<ammount;
			cout<<endl;
			cout<<endl;
			cout<<"Item";
			cout<<"\t\t\t\t\t\t\tAmount(RM)"<<endl;
			cout<<"Hospitalization expenses\t\t\t\t\t20"<<endl;
			cout<<"Doctor consultation fees\t\t\t\t\t88"<<endl;
			cout<<"Drug expenses\t\t\t\t\t\t\t59.90"<<endl;
			cout<<"other expenses\t\t\t\t\t\t\t30"<<endl;
			cout<<endl;
			
			cout<<"\t\t\t\t\t\t\tSubTotal:RM812.50"<<endl;
			cout<<"\t\t\t\t\t\t\tTax(3%)\t:RM12"<<endl;
			cout<<"\t\t\t\t\t\t\tTotal\t:RM800.50"<<endl;
			cout<<endl;
		
			cout<<"\t\t\t\t\tTHANK YOU"<<endl;
		
		        break; // break loop after found same name
    }
    
    
    
	}
    if (!patientFound) 
	{
        cout << "Patient not found in the records. Please try again." << endl;
    }

    read.close();
}

	
	




void report()
{
    cout << " \n________________________________________________" << endl;
    cout << "|\t\t\t\t\t\t|" << endl;
    cout << "|\tJBW Hospital Management Report\t\t|" << endl;
    cout << "|\t\t\t\t\t\t|" << endl;
    cout << "|_______________________________________________|" << endl;
    
    cout << "\nReport -" << endl;

    cout << "\n";
    cout << setw(10) << "Bednumber" << setw(15) << "PatientName" << setw(15) << "Status" << setw(25) << "Bodytemperature" << setw(15) << "Doctorassigned" << setw(15) << "Admission" << endl;

    ifstream read("Register.txt");
    read.seekg(0, ios::beg); // to make sure file read from top to bottom

    string bed_num, status, Pname, body_temp, d_assigned, admission;

    int i = 1;

    while (read >> bed_num) 
	{
        read.ignore(); 
        getline(read, status,'\t');
        read.ignore();
        getline(read, Pname,'\t');
        read >> body_temp;
        read.ignore();
        getline(read, d_assigned,'\t');
        getline(read, admission);
        
        cout << setw(10) << bed_num << setw(15) << Pname << setw(15) << status << setw(25) << body_temp << setw(15) << d_assigned << setw(15) << admission << endl;
    }

    read.close();
}


		

	