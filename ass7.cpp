#include<iostream>
using namespace std;
int key[30],c[30],n ,m;
int i;
class medical
{
    public:
    int id ;
    string name,dises,treat;

    void declare();
    void display();
    void accept();
    void search();
    void Delete();
    void update();
}h[100];
void medical :: declare()
{   
    cout<<"Enter total number of key : ";
    cin>>n;
    cout<<"Enter Keys :  ";
    for(i=0;i<n;i++)
    {
        cin>>key[i];
    }
    for(i=0;i<10;i++)
    {
        h[i].id=-1;
        c[i]=0;
    }
}
void  medical :: display()
{
    cout<<"\n id\tname\tdises\ttreatment_plan\tchain";
    for(i=0;i<10;i++)
    {
    cout<<"\n"<<h[i].id<<"\t"<<h[i].name<<"\t"<<h[i].dises<<"\t"<<h[i].treat<<"\t\t"<<c[i];
    }
}
void medical :: accept()
{
    int no,pos;
    for(i=0;i<n;i++)
    {
        no=key[i]%10;
        pos=no;
        do{
            if(h[no].id==-1)
            {
                h[no].id=key[i];
                cout<<"enter id : ";
                cin>>h[no].id;
                cout<<"Name : ";
                cin>>h[no].name;
                cout<<"dises: ";
                cin>>h[no].dises;
                cout<<"Treatment plan: ";
                cin>>h[no].treat;
               
                break;
            }
            else 
            {
                no++;
                c[pos]=no;
                
            }
        }while(no<10);
    }

}
void medical :: search()
{
    int no,pos,idd,found=0;
    cout<<"Enter pateint id to search : ";
    cin>>idd;
    for(i=0;i<n;i++)
    {
        no=idd%10;
        pos=no;
        do{
            if(h[no].id==idd)
            {
             
                found=1;
                     break;
            }
            else 
            {
                no++;
                c[pos]=no;
                
                
            }
        }while(no<10);
    }
    if(found==1)
    {
	cout<<"\nid\tname\tdises\ttreatment_plan\t\tchain";
  	cout<<"\n"<<h[i].id<<"\t"<<h[i].name<<"\t"<<h[i].dises<<"\t"<<h[i].treat<<"\t"<<c[i];
    }
    else
    {
        cout<<"\nRecord not found";
    }
}
void medical :: update()
{
    int no,pos,idd,found=0;
    cout<<"Enter pataint ID to update : ";
    cin>>idd;
    for(i=0;i<n;i++)
    {
        no=idd%10;
        pos=no;
        do{
            if(h[no].id==idd)
            {
                
                found=1;
                     break;
            }
            else 
            {
                no++;
                c[pos]=no;
                if(no>10)
                {
                    no=0;
                }
                
            }
        }while(no<10);
    }
    if(found==1)
    {
                
                cout<<"id : ";
                cin>>h[no].id;
                cout<<"Name : ";
                cin>>h[no].name;
                cout<<"dises : ";
                cin>>h[no].dises;
                 cout<<"Treatment_plan: ";
                cin>>h[no].treat;
        
        
    }
    else
    {
        cout<<"\nRecord not found";
    }
}
void medical::Delete() {
    int no, pos, idd, found = 0, it = -1;
    int m=10;
    cout << "Enter pataint id to delete: ";
    cin >> idd;

    for (int i = 0; i < n; i++) {
        no = idd % 10;
        pos = no;
        
        do {
            if (h[no].id == idd) {
                found = 1;
       
                
                break;

            } 
            else {
                no++;
            
                c[pos] = no;
            }
        } while (no <10);
    }
    
if(found==1)
{
   h[no].id=-1;
        
          h[no].name="";
          h[no].dises="";
          h[no].treat="";
        
}
    if (found == 0) {
      
        cout << "Record not found." << endl;
    }
}

int main()
{
    int ch;
    medical m;
    
     
    do
    {

        cout<<"\n1.declare\n2.insert\n3.display\n4.search\n5.delete\n6.update\n7.exit";

        cout<<"\nEnter your choice : ";
        cin>>ch;
        switch(ch)
        {
         
            case 1:
            m.declare();
            break;
            case 2:
            m.accept();
            break;
            case 3:
            m.display();
            break;
            case 4:
            m.search();
            break;
            case 5:
            m.Delete();
            break;
            case 6:
            m.update();
            break;
            case 7:
            cout<<"Thanks for visiting......!!";
            break;
            default:
            cout<<"Wrong choice";
        }
    } while (ch!=7);
    return 0;
}
