#include<iostream>
#include<string>
#include<map>
using namespace std;
class Robo
{
    public:
    char team;
    char num;
    int HP;
    bool alive;
    Robo(){
        team='N';
        num='N';
        HP=0;
        alive=false;
    }
    virtual void die(){
        HP=0;
        alive=false;
    }
    void get_damage(int num_damage){
        HP-=num_damage;
        if(HP<=0){die();}
    }

     virtual void show(){
        cout<<endl<<endl;
        cout<<"Team:"<<team<<endl;
        cout<<"Num:"<<num<<endl;
        cout<<"HP:"<<HP<<endl;
     }
    virtual void init(){};
   virtual void shoot(int){};

};
class B:public Robo{
    public:
    int CD;
    B(){
        CD=0;
    }
    void shoot(int num_shoot){
        CD+=15*num_shoot;
        if(CD>200)die();
    }
    void die(){
        Robo::die();
        CD=0;
    }
    void show(){
        Robo::show();
        cout<<"CD:"<<CD<<endl;
        cout<<"Type:B"<<endl;
    }
    void init(){
        HP=100;
    }
};
class Y:public Robo{
    public:
    int CD;
    Y(){
        CD=0;
    }
    void shoot(int num_shoot){
        CD+=30*num_shoot;
        if(CD>300)die();
    }
    void die(){
        Robo::die();
        CD=0;
    }
    void show(){
        Robo::show();
        cout<<"CD:"<<CD<<endl;
        cout<<"Type:Y"<<endl;
    }
    void init(){
        HP=200;
    }
};
class S:public Robo{
    public:
    int CD;
    S(){
        CD=0;
    }
    void shoot(int num_shoot){
        CD+=15*num_shoot;
        if(CD>300)die();
    }
    void die(){
        Robo::die();
        CD=0;
    }
    void show(){
        Robo::show();
        cout<<"CD:"<<CD<<endl;
        cout<<"Type:S"<<endl;
    }
    void init(){
        HP=200;
    }
};
class G:public Robo{
    public:
    void die(){
        Robo::die();
    }
    void show(){
        Robo::show();
        cout<<"Type:G"<<endl;
    }
    void init(){
        HP=200;
    }
};

Robo * CK[20];
string  order;
int  num_CK=0;

map <char,int> R_TEAM,B_TEAM;


void order_A(){
    switch (order[2])
    {
    case 'B':
        CK[num_CK]=new B;
        break;
    case 'Y':
        CK[num_CK]=new Y;
        break;
    case 'S':
        CK[num_CK]=new S;
        break;
    case 'G':
        CK[num_CK]=new G;
        break;
    
    default:
        break;
    }
    CK[num_CK]->team=order[1];
    CK[num_CK]->num=order[3];
    CK[num_CK]->init();
    if(order[1]=='R')R_TEAM[order[3]]=num_CK;
    else B_TEAM[order[3]]=num_CK;
    num_CK++;
}


void order_F(){
    int num_damage_get=order[3]-'0';
    for(int i=4;order[i]>='0'&&order[i]<='9';++i){
        num_damage_get*=10;
        num_damage_get+=order[i]-'0';
    }
    cout<<"Damage given:"<<num_damage_get<<endl;
    if(order[1]=='R')CK[R_TEAM[order[2]]]->get_damage(num_damage_get);
    else CK[B_TEAM[order[2]]]->get_damage(num_damage_get);
}

void order_H(){
    int num_shoot=order[3]-'0';
    for(int i=4;order[i]>='0'&&order[i]<='9';++i){
        num_shoot*=10;
        num_shoot+=order[i]-'0';
    }
    cout<<"Num_shoot:"<<num_shoot<<endl;
    if(order[1]=='R')CK[R_TEAM[order[2]]]->shoot(num_shoot);
    else CK[R_TEAM[order[2]]]->shoot(num_shoot);
}

void get_order(){


     cin>>order;


        switch (order[0])
        {
        case  'A':
            order_A();
            break;
        case 'F':
            order_F();
            break;
        case 'H':
            order_H();
            break;
        default:
            break;
        }
        
}

void show_all(){
    for(int i=0;i<num_CK;++i){
         CK[i]->show();
    }
}

int main(){
    while (1)
    {
        get_order();
        show_all();
    }
    
    return 0;
}
