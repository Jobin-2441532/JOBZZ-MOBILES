#include <iostream>
#include <string>
using namespace std;

class Mobile {
    static const int maxmob = 100;

public:
    int count;
    string name[maxmob];
    string brand[maxmob];
    string model[maxmob];
    string date[maxmob];
    int price[maxmob];
    
    void disp()
    {
    	cout << "\t\t\t\t\tJOBZ MOBILES" << endl << endl << endl;
	}

    Mobile() {
        count = 0;
        
    }

    void addMobile() {
        if (count < maxmob) {
            cout << "\n\nEnter the details of mobile " << endl << endl;

            cout << "Enter the customer name: ";
            cin >> name[count]; 

            cout << "Enter the brand: ";
            cin >> brand[count]; 

            cout << "Enter the model: ";
            cin >> model[count]; 

            cout << "Enter the date: (dd-mm-yyyy)";
            cin >> date[count];

            cout << "Enter the price: ";
            cin >> price[count];

            count++; 
        } 
    }
    
    void searchMobile(const string &a) {
        for (int i = 0; i < count; i++) {
            if (name[i] == a) {
                cout << "Customer name = " << name[i] << endl;
                cout << "Brand = " << brand[i] << endl;
                cout << "Model = " << model[i] << endl;
                cout << "Purchase date = " << date[i] << endl;
                cout << "Price = " << price[i] << endl;
                return;
            }
        }
        cout << "No such records" << endl;
    }
};

class sales:public Mobile{
	public:
		
		void totalsale(string mm)
		{
			int total=0;
			for(int i=0;i<count;i++)
			{
				 string d = date[i].substr(3, 2);
			if(d==mm)
			total+=price[i];
	}
		cout<<"Total sales for this month ="<<total<<endl;
		
	
}

void findbrand(const string& br)
		{
			int no=1;
			for(int i=0;i<count;i++)
			{
				if(br==brand[i])
				{
			    cout << no<<")"<<"Customer name = " << name[i] << endl;
                cout << "Brand = " << brand[i] << endl;
                cout << "Model = " << model[i] << endl;
                cout << "Purchase date = " << date[i] << endl;
                cout << "Price = " << price[i] << endl<<endl<<endl ;
                no++;
				}
			}
		}
};
int main() { 
	    
    sales ob;
    ob.disp();
    int c;
    while(true){
	cout << "\n\n----------------------------------------------------------------------------------------------------"<<endl;
    cout << "\n\nEnter 1 to add sale details"<<endl;
	cout<<"Enter 2 to search from sale"<<endl;
	cout<<"Enter 3 to calculate total sales of each month"<<endl;
    cout<<"Enter 4 to find total sales of each brand"<<endl;
	cout<<"Enter 0 to exit"<<endl<<endl<<endl;
    cin >> c;

    switch(c) {
    	
    	case 0:
            	return 0;
            	break;
        case 1:
            ob.addMobile();
            break;

        case 2:
        	{
			
            string t;
            cout << "\nEnter the customer name: ";
            cin >> t; 
            ob.searchMobile(t);
            break;
        }
            case 3:
            	{
				cout<<"Enter month in number"<<endl;
				string m;
				cin>>m;
            	ob.totalsale(m);
            	break;
				}
				
				case 4:
					{
						cout<<"Enter the brand to check the totl number of sales"<<endl;
						string bra;
						cin>>bra;
						ob.findbrand(bra);
						break;
					}
            }
      }

}

