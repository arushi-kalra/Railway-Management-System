#include <iostream>
#include <queue>
#include <map>
#include <string.h>
#include <conio.h>
using namespace std;

void gotoxy(int x,int y)
{
    for(int j=0;j<y;j++)
    {
        cout<<"\n";
    }
    for(int i=0;i<x;i++)
    {
        cout<<"    ";
    }
}

struct details
{
    string name,phno,email;
    int adhar,seats;
    struct details * next;
};

struct details * insert_end(struct details * root,string n,string p,string e,int a,int s)
{
    struct details *root1=root;
    struct details * temp=new details;
    temp->name=n;
    temp->phno=p;
    temp->email=e;
    temp->adhar=a;
    temp->seats=s;
    temp->next=NULL;
    if(root==NULL)
    {

        root=temp;
        root1=temp;
    }
    else
    {
        while(root->next!=NULL)
        {
            root=root->next;
        }
        root->next=temp;
    }
    return root1;
}

void searching(struct details * root,int ad)
{
    while(root!=NULL)
    {
        if(root->adhar==ad)
        {
            cout<<endl<<"CUSTOMER DETAILS:    "<<endl<<"Name        :    "<<root->name<<"    "<<"Phno       :    "<<root->phno<<"    "<<"Email ID  :    "<<root->email<<"    "<<"Adhar     :    "<<root->adhar<<"    "<<"Seats     :    "<<root->seats<<endl;
            return;
        }
        root=root->next;
    }
}

int getseat(struct details * root,int ad)
{
    while(root!=NULL)
    {
        if(root->adhar==ad)
        {
            return root->seats;
        }
        root=root->next;
    }
}

struct n2
{
    string d;
    string d_time;
    string arr_time;
    int seats;
    string t_name;
    string des;
    int pnr;
    int price;
    n2*rp;
};

struct n1
{
    string s;
    n1*dp;
    n2 *rp;
};

struct n2* temp,old_temp;

struct n1 * newnode1(queue<string>* source)
{
    struct n1 * temp=new n1;
    temp->dp=NULL;
    temp->rp=NULL;
    temp->s=source->front();
    source->pop();
    return temp;
}

struct n2 * newnode2(queue<string>* dest,queue<string>* dep_time ,queue<string>* arrival_time,queue<int>* seats_ava,queue<int>* pnr_no,queue<string>* train_name,queue<string>* desc,queue<int>* price)
{
    struct n2 * temp=new n2;
    temp->rp=NULL;
    temp->d=dest->front();
    temp->arr_time=arrival_time->front();
    temp->d_time=dep_time->front();
    temp->t_name=train_name->front();
    temp->seats=seats_ava->front();
    temp->pnr=pnr_no->front();
    temp->des=desc->front();
    temp->price=price->front();
    dest->pop();
    arrival_time->pop();
    dep_time->pop();
    seats_ava->pop();
    pnr_no->pop();
    desc->pop();
    price->pop();
    train_name->pop();
    return temp;
}

struct n1* insert(queue<string>* source,queue<string>* dest,queue<string>* dep_time ,queue<string>* arrival_time,queue<int>* seats_ava,queue<int>* pnr_no,queue<string>* train_name,queue<string>* desc,queue<int>* price)
{
    struct n1 *start1,*start;struct n2*current;
    for(int i=0;i<5;i++)
    {
      if(i==0)
      {
            start=newnode1(source);
            start1=start;
      }
      start->rp=newnode2(dest,dep_time,arrival_time,seats_ava,pnr_no,train_name,desc,price);
      current=start->rp;
      for(int j=0;j<4;j++)
      {
          struct n2* tmp=newnode2(dest,dep_time,arrival_time,seats_ava,pnr_no,train_name,desc,price);
          current->rp=tmp;
          current=tmp;
      }
      start->dp=newnode1(source);
      start=start->dp;
    }
return start1;
}

void search_train(struct n1 * start,int p)
{
    while(start->dp!=NULL)
    {
        struct n2 *t=start->rp;
        cout<<endl;
        while(t!=NULL)
        {
            if(t->pnr==p)
            {
                cout<<"SOURCE           :     "<<start->s<<endl;
                cout<<"DESTINATION      :     "<<t->d<<endl;
                cout<<"TRAIN NAME       :     "<<t->t_name<<endl;
                cout<<"DEPARTURE TIME   :     "<<t->d_time<<endl;
                cout<<"ARRIVAL TIME     :     "<<t->arr_time<<endl;
                cout<<"SEATS AVAILABLE  :     "<<t->seats<<endl;
                cout<<"PNR NUMBER       :     "<<t->pnr<<endl;
                cout<<"TRAIN DESCRIPTION:     "<<t->des<<endl;
                cout<<"PRICE            :     "<<t->price<<endl;
                cout<<"\n";
            }
            t=t->rp;
        }
        cout<<endl;
        cout<<"\n";
        start=start->dp;
    }
}

update_lol(struct n1 * start,int p,int seat)
{
    while(start->dp!=NULL)
    {
        struct n2 *t=start->rp;
        cout<<endl;
        while(t!=NULL)
        {
            if(t->pnr==p)
            {
               t->seats=t->seats-seat;
            }
            t=t->rp;
        }
        cout<<endl;
        cout<<"\n";
        start=start->dp;
    }
}

update_lol2(struct n1 * start,int p,int seat)
{
    while(start->dp!=NULL)
    {
        struct n2 *t=start->rp;
        cout<<endl;
        while(t!=NULL)
        {
            if(t->pnr==p)
            {
               t->seats=t->seats+seat;
            }
            t=t->rp;
        }
        cout<<endl;
        cout<<"\n";
        start=start->dp;
    }
}

struct details *delete_details(struct details *root,int ad)
{
    struct details *root1=root;
    struct details *ptr=root;
    if(root==root1 && root->adhar==ad)
    {
        root1=root->next;
    }
    else
    {
        while(root!=NULL)
        {

            if(root->adhar==ad)
            {
                ptr->next=root->next;
                break;
            }
            else
            {
                ptr=root;
                root=root->next;
            }
        }
    }
    return root1;
};

int give_price(struct n1 * start,int p)
{
    while(start->dp!=NULL)
    {
        struct n2 *t=start->rp;
        cout<<endl;
        while(t!=NULL)
        {
            if(t->pnr==p)
            {
               return t->price;
            }
            t=t->rp;
        }
        start=start->dp;
    }
    cout<<endl<<"There's no train with the entered pnr number"<<endl;
}

int main()
{
    map <int , int> m;
    struct details * root=NULL;

    string name,email,phno;
    int choice,p,c,pnr,adhar,seat,s,d;

    queue<string>source;
    queue<string>dest;
    queue<string>dep_time;
    queue<string>arrival_time;
    queue<int>seats_ava;
    queue<int>pnr_no;
    queue<string>train_name;
    queue<string>desc;
    queue<int>price;

    source.push("DELHI");
    source.push("LUCKNOW");
    source.push("MUMBAI");
    source.push("KOLKATA");
    source.push("JAIPUR");

    dest.push("LUCKNOW");
    dest.push("CHANDIGARH");
    dest.push("AHMEDABAD");
    dest.push("THIRUVANANTHPURAM");
    dest.push("MUMBAI");
    dest.push("DELHI");
    dest.push("CHENNAI");
    dest.push("AGRA");
    dest.push("VARANSI");
    dest.push("GANDHINAGAR");
    dest.push("DELHI");
    dest.push("PUNE");
    dest.push("CHENNAI");
    dest.push("HYDERABAD");
    dest.push("KOLKATA");
    dest.push("JAIPUR");
    dest.push("SURAT");
    dest.push("CHANDIGARH");
    dest.push("KOCHI");
    dest.push("INDORE");
    dest.push("DELHI");
    dest.push("PUNE");
    dest.push("AHMEDABAD");
    dest.push("LUCKNOW");
    dest.push("KOLKATA");

    dep_time.push("6:50:00");
    dep_time.push("19:40:00");
    dep_time.push("21:00:00");
    dep_time.push("5:30:00");
    dep_time.push("9:20:00");
    dep_time.push("8:00:00");
    dep_time.push("18:30:00");
    dep_time.push("15:30:00");
    dep_time.push("4:10:00");
    dep_time.push("5:50:00");
    dep_time.push("7:15:00");
    dep_time.push("20:50:00");
    dep_time.push("22:40:00");
    dep_time.push("15:00:00");
    dep_time.push("19:25:00");
    dep_time.push("00:20:00");
    dep_time.push("23:50:00");
    dep_time.push("6:00:00");
    dep_time.push("14:05:00");
    dep_time.push("18:55:00");
    dep_time.push("14:50:00");
    dep_time.push("13:00:00");
    dep_time.push("12:00:00");
    dep_time.push("11:50:00");
    dep_time.push("10:50:00");

    arrival_time.push("6:00:00");
    arrival_time.push("14:05:00");
    arrival_time.push("18:55:00");
    arrival_time.push("14:50:00");
    arrival_time.push("13:00:00");
    arrival_time.push("6:00:00");
    arrival_time.push("14:05:00");
    arrival_time.push("18:55:00");
    arrival_time.push("14:50:00");
    arrival_time.push("13:00:00");
    arrival_time.push("4:10:00");
    arrival_time.push("5:50:00");
    arrival_time.push("7:15:00");
    arrival_time.push("20:50:00");
    arrival_time.push("22:40:00");
    arrival_time.push("22:40:00");
    arrival_time.push("15:00:00");
    arrival_time.push("19:25:00");
    arrival_time.push("00:20:00");
    arrival_time.push("23:50:00");
    arrival_time.push("6:50:00");
    arrival_time.push("19:40:00");
    arrival_time.push("21:00:00");
    arrival_time.push("5:30:00");
    arrival_time.push("9:20:00");

    seats_ava.push(2000);
    seats_ava.push(5000);
    seats_ava.push(6000);
    seats_ava.push(8000);
    seats_ava.push(9000);
    seats_ava.push(2000);
    seats_ava.push(3000);
    seats_ava.push(4000);
    seats_ava.push(10000);
    seats_ava.push(5500);
    seats_ava.push(6300);
    seats_ava.push(4800);
    seats_ava.push(7700);
    seats_ava.push(5000);
    seats_ava.push(6500);
    seats_ava.push(5400);
    seats_ava.push(3500);
    seats_ava.push(5200);
    seats_ava.push(7000);
    seats_ava.push(2500);
    seats_ava.push(11000);
    seats_ava.push(8500);
    seats_ava.push(9400);
    seats_ava.push(2600);
    seats_ava.push(5900);

    pnr_no.push(145);
    pnr_no.push(143);
    pnr_no.push(152);
    pnr_no.push(195);
    pnr_no.push(123);
    pnr_no.push(133);
    pnr_no.push(197);
    pnr_no.push(167);
    pnr_no.push(149);
    pnr_no.push(140);
    pnr_no.push(142);
    pnr_no.push(150);
    pnr_no.push(135);
    pnr_no.push(245);
    pnr_no.push(235);
    pnr_no.push(240);
    pnr_no.push(285);
    pnr_no.push(234);
    pnr_no.push(126);
    pnr_no.push(183);
    pnr_no.push(286);
    pnr_no.push(254);
    pnr_no.push(110);
    pnr_no.push(134);
    pnr_no.push(170);

    desc.push("ac");
    desc.push("non ac");
    desc.push("ac");
    desc.push("ac");
    desc.push("non ac");
    desc.push("non ac");
    desc.push("ac");
    desc.push("ac");
    desc.push("ac");
    desc.push("non ac");
    desc.push("non ac");
    desc.push("non ac");
    desc.push("ac");
    desc.push("non ac");
    desc.push("ac");
    desc.push("ac");
    desc.push("ac");
    desc.push("ac");
    desc.push("non ac");
    desc.push("ac");
    desc.push("non ac");
    desc.push("ac");
    desc.push("non ac");
    desc.push("ac");
    desc.push("ac");

    train_name.push("AC express");
    train_name.push("Chandigarh express");
    train_name.push("Gujrat Sampark Kranti express");
    train_name.push("Kerela Sampark Kranti express");
    train_name.push("Pune Duronto express");
    train_name.push("Chennai central express");
    train_name.push("Agra Duronto express");
    train_name.push("Upsana  express");
    train_name.push("Marudhar express");
    train_name.push("Paschim express");
    train_name.push("Pragati express");
    train_name.push("Chennai express");
    train_name.push("Devagiri express");
    train_name.push("Gitanjali express");
    train_name.push("Pratap express");
    train_name.push("HWH ADI express");
    train_name.push("HWH DLI KLK express");
    train_name.push("Gurudev express");
    train_name.push("Shipra express");
    train_name.push("Ajmer Shatabdi express");
    train_name.push("Ashram express");
    train_name.push("Wainganga express");
    train_name.push("Narudhar express");
    train_name.push("Rajdhani express");
    train_name.push("Jaipur to Agra Shatabdi express");

    price.push(1000);
    price.push(2000);
    price.push(2500);
    price.push(3000);
    price.push(1500);
    price.push(900);
    price.push(1000);
    price.push(2000);
    price.push(1500);
    price.push(2500);
    price.push(780);
    price.push(1400);
    price.push(2100);
    price.push(890);
    price.push(1000);
    price.push(2000);
    price.push(2400);
    price.push(1100);
    price.push(1700);
    price.push(2050);
    price.push(1080);
    price.push(1110);
    price.push(2000);
    price.push(1020);
    price.push(800);

    struct n1* start=insert(&source,&dest,&dep_time,&arrival_time,&seats_ava,&pnr_no,&train_name,&desc,&price);
    struct n1* start1=start;

  do
  {
      START:
      gotoxy(15,3);
      cout<<"WELCOME TO THE"<<"\n";
      gotoxy(15,3);
      cout<<"INDIAN RAILWAY BOOKING PORTAL"<<endl;
      gotoxy(15,3);
      cout<<"1.  TRAIN DETAILS"<<endl;
      gotoxy(15,3);
      cout<<"2.  BOOK THE TRAIN"<<endl;
      gotoxy(15,3);
      cout<<"3.  SEARCH THE TRAIN"<<endl;
      gotoxy(15,3);
      cout<<"4.  CUSTOMER DETAILS"<<endl;
      gotoxy(15,3);
      cout<<"5.  BOOKING CANCELLATION"<<endl;
      cin>>choice;

      switch(choice)
      {
          case 1:   while(start->dp!=NULL)
                    {
                        struct n2 *t=start->rp;
                        cout<<"SOURCE           :     "<<start->s<<endl;
                        cout<<endl;
                        while(t!=NULL)
                        {
                            cout<<"DESTINATION      :     "<<t->d<<endl;
                            cout<<"TRAIN NAME       :     "<<t->t_name<<endl;
                            cout<<"DEPARTURE TIME   :     "<<t->d_time<<endl;
                            cout<<"ARRIVAL TIME     :     "<<t->arr_time<<endl;
                            cout<<"SEATS AVAILABLE  :     "<<t->seats<<endl;
                            cout<<"PNR NUMBER       :     "<<t->pnr<<endl;
                            cout<<"TRAIN DESCRIPTION:     "<<t->des<<endl;
                            cout<<"PRICE            :     "<<t->price<<endl;
                            cout<<"\n";
                            t=t->rp;
                       }
                        cout<<"********************************************************************************************";
                        cout<<endl;
                        cout<<"\n";
                        start=start->dp;
                    }
                    goto START;
            break;

            case 2:     gotoxy(15,3);
                        cout<<"Enter your Name,Adhar number,Email id,Phone number and PNR number of the train you wish to BOOK."<<endl;
                        gotoxy(15,3);
                        cout<<"Also provide the number of seats you wish to book"<<endl;
                        cin>>name>>adhar>>email>>phno>>pnr>>seat;
                        root=insert_end(root,name,phno,email,adhar,seat);
                        m.insert(pair <int , int> (adhar, pnr));
                        update_lol(start,pnr,seat);
                        cout<<"BOOKING SUCCESSFUL!"<<endl;
                        d=give_price(start1,pnr);
                        s=d*seat;
                        cout<<"You have to pay Rs. "<<s<<" in total ";
                        goto START;

            break;

            case 3: gotoxy(15,3);
                    cout<<"Enter the PNR number of the train you want to SEARCH"<<endl;
                    cin>>p;
                    search_train(start1,p);
                    goto START;

            break;

            case 4:
                    {
                        gotoxy(15,3);
                        cout<<"Enter the Adhar number of the customer you wish to search about."<<endl;
                        cin>>adhar;
                        map<int , int>::iterator it ;
                        it = m.find(adhar);
                        if(it == m.end())
                            cout << "No customer with this Adhar number is present." <<endl;
                        else
                        {
                            pnr = it->second ;
                            searching(root,adhar);
                            search_train(start1,pnr);
                        }
                        goto START;

            break;
                    }

            case 5:     {
                            gotoxy(15,3);
                            cout<<"Enter your Adhar number and the PNR number."<<endl;
                            cin>>adhar>>pnr;
                            int s = getseat(root,adhar);
                            update_lol2(start,pnr,s);
                            root=delete_details(root,adhar);
                            map<int , int>::iterator i ;

                            if(s!=0)
                            {
                                i=m.find(adhar);
                                m.erase(i);
                            }
                            goto START;

            break;

                        }

            default:    gotoxy(15,3);
                        cout<<"Enter a valid choice."<<endl;
                        goto START;

            break;

      }

    }while(choice!=0);

    return 0;
}
