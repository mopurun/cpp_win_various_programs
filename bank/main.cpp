#include <iostream>
#include <string>
#include <fstream>

using namespace std;

const int person_num = 100;

class Bank{
        string name[person_num]={""};    
        int balance[person_num]={0};
    public:
           
        void addAccount(string x);
        void delAccount(string x);
        void chkAccount(string x);
        void addBalance(string x, int y);
        void subBalance(string x , int y);
        void writeFile();
        void readFile();
};



void Bank::addAccount(string x){
    int i;
    for(i=0;person_num > i;i++){
        if(name[i] == x){
            cout << name[i] << "様は既に登録されています。" << endl;
            break;
        }
        else if(name[i] == ""){
            name[i] = x ;
            cout << name[i] << "様を口座番号" << i << "に登録しました。" << endl;
            break;
        }

    }            
};
void Bank::delAccount(string x){
    string check;
    cout<< "本当に削除しますか？(y/n)" << endl;
    cin >> check;
    if(check != "y"){
        cout<< "取り消しました。" << endl;
    }
    else{
        int i;
        for(i=0;person_num > i;i++){
            if(name[i] == x){
                string y = name[i];
                name[i] = "" ;
                balance[i]=0;
                cout << y << "様のアカウントを削除しました。" << endl;
                break;
            }
        }                 
    }
    
};   
void Bank::chkAccount(string x){
    int i;
    for(i=0;person_num > i;i++){
        if(name[i] == x){
            cout << name[i] << "様のアカウント情報：口座番号" << i << "番：残高" << balance[i] << "円" << endl;
            break;
        }
    }            
};                   
void Bank::addBalance(string x, int y){
    int i ;
    for(i=0;person_num > i;i++){
        if(name[i] == x){
            balance[i] += y;
            cout << "口座番号" << i << "番：" << x << "様。" << y << "円預金しました。残高は、" << balance[i] << "円です。" << endl;
            break;
        }
    }
};

void Bank::subBalance(string x , int y){
    int i;
    for(i=0;person_num > i;i++){
        if(name[i] == x && balance[i] >= y){
            balance[i] -= y;
            cout << "口座番号" << i << "番：" << x << "様。" << y << "円引き出しました。残高は、" << balance[i] << "円です。" << endl;
            break;
        }
    }
}

void Bank::writeFile(){
    ofstream wf1;
    string filename= "output.txt";
    wf1.open(filename,ios_base::out);
    int i;
    string str1;
    for(i=0;person_num > i;i++){
        str1 += name[i] + "\n" + to_string(balance[i]) + "\n";    
    }  
    wf1 << str1 ;   
    wf1.close();
}
void Bank::readFile(){
    ifstream rf1;
    string filename= "output.txt";
    string buffer = "";
    rf1.open(filename,ios_base::in);
    int i;


    for(i=0;person_num > i;i++){        
        getline(rf1,buffer);
        if(buffer==""){
            rf1.close();
        }
        else{
            name[i]= buffer ;  
            getline(rf1,buffer);    
            balance[i] = stoi(buffer) ;
        }
    } 
    rf1.close();
    
}

int main(){

    cout << "Command:addAccount" << endl;
    cout << "Command:delAccount" << endl;
    cout << "Command:chkAccount" << endl;          
    cout << "Command:addBalance" << endl;
    cout << "Command:subBalance" << endl;
    cout << "Command:exit" << endl;

    Bank bank;
    //bank.addAccount("Satou");
    //bank.addAccount("Tanaka");    
    //bank.addAccount("Satou");    
    //bank.addBalance("Tanaka",100);
    //bank.subBalance("Tanaka",10);

   
    cout << "--------------------" << endl; 
    while(1){
        string command ="";
        string name ="";
        int value = 0;

        bank.readFile();    
       
        cout << "コマンド：";        
        cin >> command;
        if(command == "exit"){break;}        
        cout << "名前：";
        cin >> name;        
        if(command == "addAccount"){
            bank.addAccount(name);
        }
        else if(command == "delAccount"){
            bank.delAccount(name);
        }    
        else if(command == "chkAccount"){     
            bank.chkAccount(name);
        }                
        else if(command == "addBalance"){
            cout << "預金額：";  
            cin >> value;            
            if(cin.fail()){
                cin.clear();
                cin.ignore(1024,'\n');
            }
            else{          
                bank.addBalance(name,value);
            }
        }
        else if(command == "subBalance"){
            cout << "引き出し額：";                 
            cin >> value;
            if(cin.fail()){
                cin.clear();
                cin.ignore(1024,'\n');
            }
            else{  
                bank.subBalance(name,value);
            }
        }
        else if(command == "exit"){
            cout << "終了します。" << endl;
            break;
        }
        else{
            cerr << "ERROR" << endl;
        }
        cout << "--------------------" << endl;
        bank.writeFile();
    }

    return 0 ;
}

