#include <iostream>
#include<string>
#include<fstream>
#include <cstdlib>
#include <time.h>
#include<conio.h>
#include<iomanip>
#define p_am 128

using namespace std;
bool r;
string user,pass,usercheck,passcheck,phrases[p_am];
int acc_amount;

ifstream finword("phrases.txt");
ofstream fout("accounts.txt",(ios::app | ios::out));

int generate_number();
string create_account();
bool username_validation();
bool log_in();
void score_decrease();
void score_increase();
void score_extract();
void leaderboard();
void play();
void credits();
void main_menu();
void player_menu();
void instructions();

int main(){

     for(int i =0;i<p_am;i++){
        getline(finword,phrases[i]);
    }
    finword.close();
    int action,action2;
    do{


main_menu();


cin>>action;
system("cls");
if(action==1){
  bool dicision;
  dicision=log_in();
  while(dicision==true){

player_menu();


cin>>action2;
system("cls");
if(action2==1){
    play();
}

else if(action2==2){
         score_extract();
    }
else if(action2==3){
        dicision=false;
}

  }


}


else if(action==2){
        cout<<create_account();
}

else if(action==3){
           instructions();
}
else if(action==4){
    leaderboard();
}
else if(action==5){
credits();

}

    }while(action!=6);
    cout<<endl<<"         Thanks for playing. See you soon!"<<endl<<endl;
}
int generate_number() {
    srand(time(NULL));
    int random = rand()%p_am+1;
    return random;
}
string create_account(){
     ifstream fin("accounts.txt");
      system ("cls");
      cout<<endl<<endl<<"      -- CREATE ACCOUNT --"<<endl<<endl;
 cout
 <<"       New username: ";
 cin.ignore();
  getline(cin,user);
    while(username_validation()==false){
        cout
 <<"       New username: ";
 cin.ignore();
  getline(cin,user);
    }
    cout<<"       New password: ";
    getline(cin,pass);
    while(!fin.eof()){
    fin>>usercheck;
    fin>>passcheck;
    if(usercheck==user){
            fin.close();
return "     - Sorry, this username already exists.";
    }
 }
 fin.close();
 fout<<user<<" "<<pass<<endl;
 ofstream score2uu("score2.txt",(ios::app | ios::out));
 score2uu<<user<<" "<<"0 0"<<endl;
 score2uu.close();
 ifstream acc("accnum.txt");
 acc>>acc_amount;
 acc.close();
 ofstream acc2("accnum.txt");
 acc2<<acc_amount+1;
 acc2.close();
return "     - Your account has successfully created.";
 }
bool username_validation(){

      for(int i =0;i<user.size();i++){
        if(user[i]==32){
            cout<<endl<<endl<<"   - Sorry ,the username cant contain any spaces."<<endl<<endl;

           return false;

        }
      }
    return true;
}
bool log_in(){









ifstream fin("accounts.txt");


    cout<<endl<<endl<<"       -- LOGIN --"<<endl<<endl;
    cout<<"     Username: ";
	cin>>user;
	cout<<"     Password: ";
    cin>>pass;
    while(!fin.eof()){
        fin>>usercheck;
        fin>>passcheck;
        if(usercheck==user&&passcheck==pass){
fin.close();
system("cls");
        cout<<endl<<endl<<endl<<"   - You have successfully logged in!"<<endl;

        return true;
        }
    }

cout<<endl<<endl
<<"   - Sorry, your username and password"<<endl
<<"     does not match or does not exist."<<endl;
				cout<<endl<<"     Press any key to return to the main menu"<<endl<<endl;
				getche();
				system("cls");
fin.close();
   return false;
}
void score_decrease(){
    ifstream acc_am("accnum.txt");
    acc_am>>acc_amount;
    acc_am.close();
   string x;
    int s,s2;
ifstream score2("score2.txt");
ofstream score1("score1.txt");
for(int i =0;i<acc_amount;i++){
    score2>>x;
    score2>>s;
    score2>>s2;
    if(x==user){
        score1<<x<<" ";
        score1<<s<<" "<<s2+1<<endl;
    }
   else{
    score1<<x<<" ";
    score1<<s<<" "<<s2<<endl;
   }
}
score1.close();
score2.close();
ofstream score2u("score2.txt");
ifstream score1u("score1.txt");
for(int i =0;i<acc_amount;i++){
    score1u>>x;
    score2u<<x<<" ";
    score1u>>s;
    score2u<<s<<" ";
    score1u>>s2;
    score2u<<s2<<endl;
}
score1u.close();
score2u.close();

}
void score_increase(){
    ifstream acc_am("accnum.txt");
    acc_am>>acc_amount;
    acc_am.close();
   string x;
    int s,s2;
ifstream score2("score2.txt");
ofstream score1("score1.txt");
for(int i =0;i<acc_amount;i++){
    score2>>x;
    score2>>s;
    score2>>s2;
    if(x==user){
        score1<<x<<" ";
        score1<<s+1<<" "<<s2<<endl;
    }
   else{
    score1<<x<<" ";
    score1<<s<<" "<<s2<<endl;
   }
}
score1.close();
score2.close();
ofstream score2u("score2.txt");
ifstream score1u("score1.txt");
for(int i =0;i<acc_amount;i++){
    score1u>>x;
    score2u<<x<<" ";
    score1u>>s;
    score2u<<s<<" ";
    score1u>>s2;
    score2u<<s2<<endl;
}
score1u.close();
score2u.close();

}
void score_extract(){
 ifstream score2("score2.txt");
 string name;
 int score,score1;
 while(!score2.eof()){
    score2>>name;
    score2>>score>>score1;
    if(name==user){
            int sr;
            if(score+score1==0){
                sr=0;
            }
    else{
            sr=(score*100)/(score+score1);
    }

        cout<<endl<<endl<<endl<<endl<<endl
        <<"              "<<user<<"'s"<<" STATS:         "<<endl<<endl
        <<"             * Words found:  "
        <<score<<endl<<endl
        <<"             * Words missed: "
        <<score1<<endl<<endl
        <<"             * Success rate: "
        <<sr<<"%";


        cout<<endl<<endl<<"             Press any key to return to the player menu"<<endl;
        getche();
system("cls");
        break;
    }


 }
score2.close();

}
void leaderboard(){
     ifstream acc_am1("accnum.txt");
    acc_am1>>acc_amount;
    acc_am1.close();
    system("cls");
    int found[acc_amount];
    int missed[acc_amount];
    int success[acc_amount];
    string users[acc_amount];
    ifstream sc("score2.txt");
    for(int i =0;i<acc_amount;i++){
        sc>>users[i];
        sc>>found[i];
        sc>>missed[i];

            if(found[i]+missed[i]==0){
                success[i]=0;
            }
    else{
            success[i]=(found[i]*100)/(found[i]+missed[i]);
    }

    }
    sc.close();
    bool c=true;
    int temp;
    string utemp;
    while(c==true){
        c=false;
        for(int i =0;i<acc_amount-1;i++){
            if(success[i]<success[i+1]){
                temp=success[i];
                utemp=users[i];
                success[i]=success[i+1];
                users[i]=users[i+1];
                success[i+1]=temp;
                users[i+1]=utemp;
                c=true;
            }
        }
    }
    cout<<endl<<endl<<endl<<endl
        <<"                                          LEADERBOARD                                                              "<<endl<<endl
        <<"    |   RANK   |    |   PLAYER   |    |   SUCCESS RATE   |    |   WORDS FOUND   |    |   WORDS MISSED   |"<<endl<<endl;
    for(int i =0;i<acc_amount;i++){
    cout<<setw(10)<<i+1<<setw(22)<<users[i]<<setw(17)<<success[i]<<"%"<<setw(23)<<found[i]<<setw(23)<<missed[i]<<endl<<endl;
    }
    cout<<endl<<endl<<"     Press any key to return to main menu"<<endl;
    getche();
    system("cls");
}
void credits(){


system("cls");
    cout<<endl
    <<"                CREDITS           "<<endl<<endl<<endl
    <<"                 OWNER      "<<endl
    <<"                -------     "<<endl
    <<"          ANDREAS DEMOSTHENOUS"<<endl<<endl<<endl
    <<"               DEVELOPER      "<<endl
    <<"               -----------     "<<endl
    <<"          ANDREAS DEMOSTHENOUS"<<endl<<endl<<endl
    <<"               PROGRAMMER      "<<endl
    <<"              ------------     "<<endl
    <<"          ANDREAS DEMOSTHENOUS"<<endl<<endl<<endl
    <<"                DESIGNER      "<<endl
    <<"               ----------     "<<endl
    <<"          ANDREAS DEMOSTHENOUS"<<endl<<endl<<endl
    <<"               INSTRUCTOR      "<<endl
    <<"                -------     "<<endl
    <<"                  FKIO  "<<endl<<endl
    <<"   Press any key to return to the main menu"<<endl;
getche();
system("cls");
}
void main_menu(){
cout<<endl<<endl<<endl
<<"        ¶                                                 ¶ "<<endl
<<"        ¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶  "<<endl
<<"        ¶                                                 ¶ "<<endl
<<"        ¶    ¶¶¶   ¶¶¶   ¶¶¶¶¶¶¶¶   ¶¶¶   ¶¶  ¶¶    ¶¶    ¶"<<endl
<<"        ¶    ¶¶¶¶ ¶¶¶¶   ¶¶¶        ¶¶¶¶  ¶¶  ¶¶    ¶¶    ¶"<<endl
<<"        ¶    ¶¶ ¶¶¶ ¶¶   ¶¶¶¶¶¶     ¶¶ ¶¶ ¶¶  ¶¶    ¶¶    ¶"<<endl
<<"        ¶    ¶¶  ¶  ¶¶   ¶¶¶        ¶¶  ¶¶¶¶  ¶¶¶¶¶¶¶¶    ¶"<<endl
<<"        ¶    ¶¶     ¶¶   ¶¶¶¶¶¶¶¶   ¶¶   ¶¶¶   ¶¶¶¶¶¶     ¶"<<endl
<<"        ¶                                                 ¶ "<<endl
<<"        ¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶";

cout<<endl<<endl<<endl
<<"        1 - LOGIN"<<endl<<endl
<<"        2 - CREATE ACCOUNT"<<endl<<endl
<<"        3 - INSTRUCTIONS"<<endl<<endl
<<"        4 - LEADERBOARD"<<endl<<endl
<<"        5 - CREDITS"<<endl<<endl
<<"        6 - EXIT"<<endl<<endl
<<"                          ACTION: ";
}
void player_menu(){




cout<<endl<<endl;
cout<<endl
<<"          PLAYER MENU "<<endl<<endl
<<"         1 - PLAY  "<<endl<<endl
<<"         2 - PROFILE"<<endl<<endl
<<"         3 - LOGOUT"<<endl<<endl<<endl<<endl<<endl
<<"                     ACTION: ";
}
void instructions(){
 cout<<endl<<endl<<endl<<
            endl<<"              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<
			endl<<"              |  Instructions: Insert letters until you  |"<<
			endl<<"              |  find the correct word/phrase. Keep in   |"<<
			endl<<"              |  mind that if you guess a wrong letter,  |"<<
			endl<<"              |  i will hang you! You have 8 lives.      |"<<
			endl<<"              |              Good luck!                  |"<<
			endl<<"              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
			cout<<endl<<endl;

            cout<<"             Press any key to return to the main menu"<<endl;
getche();
system("cls");
}
void play(){
    r=false;
string phrase;
bool found[26];
int tries=1,p;
p=generate_number();
char guess;
bool check=false;
    finword.close();
    for(int i =0;i<26;i++){
        found[i]=false;
    }
    phrase=phrases[p];

      while(check==false){
 if(tries==8){
    cout<<endl;
    cout<<"  ¶_________________"<<endl;
	cout<<"  ¶              +++++"<<endl;
	cout<<"  ¶             + A A +"<<endl;
	cout<<"  ¶             +  ^  +       "<<endl;
	cout<<"  ¶      +      + === +     +"<<endl;
	cout<<"  ¶      +      +++++++     +"<<endl;
	cout<<"  ¶     +++       +++      +++"<<endl;
	cout<<"  ¶      ++ ++++++++++++++ ++ "<<endl;
	cout<<"  ¶       +++            +++"<<endl;
	cout<<"  ¶        ++            ++"<<endl;
	cout<<"  ¶         +            +"<<endl;
	cout<<"  ¶         ++++++++++++++"<<endl;
	cout<<"  ¶           +++    +++"<<endl;
	cout<<"  ¶          +++      +++"<<endl;
	cout<<"  ¶         +++        +++" <<endl;
	cout<<"  ¶        +++          +++"<<endl;
	cout<<"  ¶       +++            +++"<<endl;
	cout<<"  ¶       +++            +++"<<endl;
	cout<<"  ¶ "<<endl;
    cout<<"  ¶"        <<endl;
	cout<<"¶¶¶¶¶ "<<endl;
 }
         else if(tries==7){
cout<<endl;
    cout<<"  ¶_________________"<<endl;
	cout<<"  ¶              +++++"<<endl;
	cout<<"  ¶             + A A +"<<endl;
	cout<<"  ¶             +  ^  +       "<<endl;
	cout<<"  ¶      +      + === +     "<<endl;
	cout<<"  ¶      +      +++++++     "<<endl;
	cout<<"  ¶     +++       +++      "<<endl;
	cout<<"  ¶      ++ ++++++++++++++ "<<endl;
	cout<<"  ¶       +++            +"<<endl;
	cout<<"  ¶        ++            +"<<endl;
	cout<<"  ¶         +            +"<<endl;
	cout<<"  ¶         ++++++++++++++"<<endl;
	cout<<"  ¶           +++    +++"<<endl;
	cout<<"  ¶          +++      +++"<<endl;
	cout<<"  ¶         +++        +++" <<endl;
	cout<<"  ¶        +++          +++"<<endl;
	cout<<"  ¶       +++            +++"<<endl;
	cout<<"  ¶       +++            +++"<<endl;
	cout<<"  ¶ "<<endl;
    cout<<"  ¶"        <<endl;
	cout<<"¶¶¶¶¶ "<<endl;

				}
        else if(tries==6){
cout<<endl;
    cout<<"  ¶_________________"<<endl;
	cout<<"  ¶              +++++"<<endl;
	cout<<"  ¶             + A A +"<<endl;
	cout<<"  ¶             +  ^  +       "<<endl;
	cout<<"  ¶             + === +     "<<endl;
	cout<<"  ¶             +++++++     "<<endl;
	cout<<"  ¶               +++      "<<endl;
	cout<<"  ¶         ++++++++++++++ "<<endl;
	cout<<"  ¶         +            +"<<endl;
	cout<<"  ¶         +            +"<<endl;
	cout<<"  ¶         +            +"<<endl;
	cout<<"  ¶         ++++++++++++++"<<endl;
	cout<<"  ¶           +++    +++"<<endl;
	cout<<"  ¶          +++      +++"<<endl;
	cout<<"  ¶         +++        +++" <<endl;
	cout<<"  ¶        +++          +++"<<endl;
	cout<<"  ¶       +++            +++"<<endl;
	cout<<"  ¶       +++            +++"<<endl;
	cout<<"  ¶ "<<endl;
    cout<<"  ¶"        <<endl;
	cout<<"¶¶¶¶¶ "<<endl;
				}
				else if(tries==5){
                    cout<<endl;
    cout<<"  ¶_________________"<<endl;
	cout<<"  ¶              +++++"<<endl;
	cout<<"  ¶             + A A +"<<endl;
	cout<<"  ¶             +  ^  +       "<<endl;
	cout<<"  ¶             + === +     "<<endl;
	cout<<"  ¶             +++++++     "<<endl;
	cout<<"  ¶               +++      "<<endl;
	cout<<"  ¶         ++++++++++++++ "<<endl;
	cout<<"  ¶         +            +"<<endl;
	cout<<"  ¶         +            +"<<endl;
	cout<<"  ¶         +            +"<<endl;
	cout<<"  ¶         ++++++++++++++"<<endl;
	cout<<"  ¶                  +++"<<endl;
	cout<<"  ¶                   +++"<<endl;
	cout<<"  ¶                    +++" <<endl;
	cout<<"  ¶                     +++"<<endl;
	cout<<"  ¶                      +++"<<endl;
	cout<<"  ¶                      +++"<<endl;
	cout<<"  ¶ "<<endl;
    cout<<"  ¶"        <<endl;
	cout<<"¶¶¶¶¶ "<<endl;
				}
						else if(tries==4){
              cout<<endl;
    cout<<"  ¶_________________"<<endl;
	cout<<"  ¶              +++++"<<endl;
	cout<<"  ¶             + A A +"<<endl;
	cout<<"  ¶             +  ^  +      "<<endl;
	cout<<"  ¶             + === +      "<<endl;
	cout<<"  ¶             +++++++      "<<endl;
	cout<<"  ¶               +++       "<<endl;
	cout<<"  ¶         ++++++++++++++ "<<endl;
	cout<<"  ¶         +            +"<<endl;
	cout<<"  ¶         +            +"<<endl;
	cout<<"  ¶         +            +"<<endl;
	cout<<"  ¶         ++++++++++++++"<<endl;
	cout<<"  ¶           "<<endl;
	cout<<"  ¶          "<<endl;
	cout<<"  ¶         " <<endl;
	cout<<"  ¶        "<<endl;
	cout<<"  ¶ "<<endl;
	cout<<"  ¶                  "<<endl;
	cout<<"  ¶ "<<endl;
    cout<<"  ¶ "        <<endl;
	cout<<"¶¶¶¶¶ "<<endl;
				}
		else if(tries==3){
 cout<<endl;
    cout<<"  ¶_________________"<<endl;
	cout<<"  ¶              +++++"<<endl;
	cout<<"  ¶             + A A +"<<endl;
	cout<<"  ¶             +  ^  +      "<<endl;
	cout<<"  ¶             + === +      "<<endl;
	cout<<"  ¶             +++++++      "<<endl;
	cout<<"  ¶                   "<<endl;
	cout<<"  ¶          "<<endl;
	cout<<"  ¶ "<<endl;
	cout<<"  ¶         "<<endl;
	cout<<"  ¶         "<<endl;
	cout<<"  ¶         "<<endl;
	cout<<"  ¶           "<<endl;
	cout<<"  ¶          "<<endl;
	cout<<"  ¶         " <<endl;
	cout<<"  ¶        "<<endl;
	cout<<"  ¶ "<<endl;
	cout<<"  ¶                  "<<endl;
	cout<<"  ¶ "<<endl;
    cout<<"  ¶ "        <<endl;
	cout<<"¶¶¶¶¶ "<<endl;
				}
		else if(tries==2){
                cout<<endl;
    cout<<"  ¶_________________"<<endl;
	cout<<"  ¶              +++++"<<endl;
	cout<<"  ¶             +     +"<<endl;
	cout<<"  ¶             +     +      "<<endl;
	cout<<"  ¶             +     +      "<<endl;
	cout<<"  ¶             +++++++      "<<endl;
	cout<<"  ¶                   "<<endl;
	cout<<"  ¶          "<<endl;
	cout<<"  ¶ "<<endl;
	cout<<"  ¶         "<<endl;
	cout<<"  ¶         "<<endl;
	cout<<"  ¶         "<<endl;
	cout<<"  ¶           "<<endl;
	cout<<"  ¶          "<<endl;
	cout<<"  ¶         " <<endl;
	cout<<"  ¶        "<<endl;
	cout<<"  ¶ "<<endl;
	cout<<"  ¶                  "<<endl;
	cout<<"  ¶ "<<endl;
    cout<<"  ¶ "        <<endl;
	cout<<"¶¶¶¶¶ "<<endl;
				}
        else if(tries==1){
                cout<<endl;
    cout<<"  ¶_________________"<<endl;
	cout<<"  ¶               ¶¶                                            "<<endl;
	cout<<"  ¶                                                             "<<endl;
	cout<<"  ¶                                                             "<<endl;
	cout<<"  ¶                                                             "<<endl;
	cout<<"  ¶                                                             "<<endl;
	cout<<"  ¶                                                             "<<endl;
	cout<<"  ¶                                                             "<<endl;
	cout<<"  ¶                                                             "<<endl;
	cout<<"  ¶                                                             "<<endl;
	cout<<"  ¶                                                             "<<endl;
	cout<<"  ¶         "<<endl;
	cout<<"  ¶          "<<endl;
	cout<<"  ¶         "<<endl;
	cout<<"  ¶       " <<endl;
	cout<<"  ¶        "<<endl;
	cout<<"  ¶       "<<endl;
	cout<<"  ¶     " <<endl;
	cout<<"  ¶"<<endl;
    cout<<"  ¶"        <<endl;
	cout<<"¶¶¶¶¶"<<endl;
				}
cout<<endl<<"       ";
for(int i=0;i<phrase.size();i++){
        if(phrase[i]<='Z'&&phrase[i]>='A'){
            cout<<phrase[i]<<" ";
        }
		else if(found[phrase[i]-97]==true){
			cout<<phrase[i]<<" ";
		}
		else if(phrase[i]==32){
			cout<<" ";
		}
		else{
            cout<<"_ ";
		}
	}
if(r==false){
cout<<"     Insert letter: ";
	cin>>guess;
}
	//letter validation
	for(int i=1;i<phrase.size();i++){
		if(guess==phrase[i]){
	    found[phrase[i]-97]=true;
		break;
		}
		if(i==phrase.size()-1){
	tries++;
	if(tries==9){
            score_decrease();
		cout<<"   - You failed!"<<endl;
		cout<<"     The correct word was "<<phrase<<endl;
		check=true;
		cout<<endl<<endl<<"  Press any key to return to the player menu"<<endl;
				getche();
				system("cls");
	}
		cout<<endl;
		}
		}

           //win validation
		for(int i=1;i<phrase.size();i++){
			if(phrase[i]!=32&&found[phrase[i]-97]==false){
				break;
			   }
			if(i==phrase.size()-1){

                    score_increase();
            if(r==true){
				cout<<endl<<endl<<"   - Congratulations! You found it! "<<endl<<endl;
				cout<<"    Press any key to return to the player menu"<<endl;
				getche();
				system("cls");
				check=true;
            }
            r=true;
			}
			}
			system("cls");
    }




	}
