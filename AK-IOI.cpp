#include<bits/stdc++.h>
#include<random>
using namespace std;
int a[110][110], n, x;
map<long long, int> fib;
bool vis[110][110], gameover;
map<int, string> color, status, means;
map<string, int> lang;
char cl[10];
long long score;
#ifdef _WIN32
	#include<conio.h>
#else
	#include<unistd.h>
	#include<termios.h>
#endif
vector<string> lg[5]={{"                               ��־                             ", 
                       "----------------------------------------------------------------", 
                       "2024/10/3 10:42 ��д��һ������UDLR��", 
                       "2024/10/4 14:05 �ܴ˳��������ı�ΪOIer��2048��", 
                       "2024/10/4 15:07 ��д��ϻ������ܡ�", 
                       "2024/10/4 18:47 ����������CE�Ĺ��ܡ�", 
                       "2024/10/5 13:11 �����ʷ��¼��", 
                       "2024/10/5 13:27 ���Ӵ���־��", 
                       "2024/10/5 14:32 ��־����Ӣ�ġ�", 
                       "2024/10/5 15:32 ����Gameover���ж��߼���", 
                       "2024/10/5 15:51 ������յ�ͼ���ܡ�", 
                       "2024/10/5 16:11 �޸���պ�û�з����bug��", 
                       "2024/10/5 16:17 ��������ʱ����Ĺ��ܡ�", 
                       "2024/10/7 10:34 ������ʾ����Ӣ�ġ�", 
                       "2024/10/7 10:45 ������־�洢�߼���", 
                       "2024/10/7 11:21 �޸���ʾ����ʱ��Ӣ��, ��ʵ�ʲ��ǵ�bug��", 
                       "2024/10/7 11:37 ����ÿ��״̬�����塣", 
                       "2024/10/7 16:45 �������Ե��������͡�", 
                       "2024/10/7 16:48 ���������־ʱ�Ĳ�����", 
                       "2024/10/7 16:58 ��ӵ�ǿ���˳�ʱ����Ĺ��ܡ�", 
                       "2024/10/7 17:12 ͻ��ÿ��״̬������������д����ĸ��", 
                       "2024/10/11 21:35 ��������ʱ����Ĺ��ܡ�", 
                       "2024/10/11 22:06 ���Ӱ�����Ϣ��", 
                       "2024/10/19 11:38 ���Windows�û�����������ʱ���ð��س����ܡ�", 
                       "2024/10/19 11:50 ������־��������Ϣ�������ʽ��", 
                       "2024/10/19 11:55 �޸�ʲôҲû��ʱǿ���˳����ᱣ���bug��", 
                       "2024/10/19 15:35 ��־���ӵ��", 
                       "2024/10/19 15:45 ��ʾ�����ӵ��", 
                       "2024/10/19 19:09 �����������ϵͳ��Ϊ�Զ��жϣ���ֹ�������", 
                       "2024/10/19 19:28 ������o����������ָ������û��������롣", 
                       "2024/10/20 17:39 ������Ϣ���ӵ��"
                      },
                      {"                                                    log                                               ", 
                       "------------------------------------------------------------------------------------------------------", 
                       "2024/10/3 10:42 Developed a program UDLR.", 
                       "2024/10/3 14:05 Inspired by this program, it was adapted into OIer's 2048.", 
                       "2024/10/4 15:07 The basic functions have been written.", 
                       "2024/10/4 18:47 Added the function of randomly generating CE.", 
                       "2024/10/5 13:11 Added historical records.", 
                       "2024/10/5 13:27 Added this log.", 
                       "2024/10/5 14:32 Added English to the log.", 
                       "2024/10/5 15:32 Added logic for determining Gameover.", 
                       "2024/10/5 15:51 Added the function of clearing maps.", 
                       "2024/10/5 16:11 Fix bug where there are no blocks after clearing.", 
                       "2024/10/5 16:17 Added the function of saving while playing.", 
                       "2024/10/7 10:34 All prompts added in English.", 
                       "2024/10/7 10:45 Change log storage logic.", 
                       "2024/10/7 11:21 Fix bug where prompt input is in English instead of actual.", 
                       "2024/10/7 11:37 Add the meaning of each state.", 
                       "2024/10/7 16:45 Change the input type for the language.", 
                       "2024/10/7 16:48 Change the operation when output logs.", 
                       "2024/10/7 16:58 Added the function of saving when forced exit.", 
                       "2024/10/7 17:12 Highlight the abbreviated letters in the meaning of each state.", 
                       "2024/10/11 21:35 Added the function of saving while playing.", 
                       "2024/10/11 22:06 Add help information.", 
                       "2024/10/19 11:38 For Windows users, add the option to input without pressing Enter.", 
                       "2024/10/19 11:50 Change the output methods of logs, help information, etc.", 
                       "2024/10/19 11:55 Fix bug where forced exit does not save when nothing is done.", 
                       "2024/10/19 15:35 Add German to the log.", 
                       "2024/10/19 15:45 Add German as a prompt.", 
                       "2024/10/19 19:09 Change input operating system to automatic judgment to prevent input errors.", 
                       "2024/10/19 19:28 When entering 'o' followed by other commands, it will prompt the user to re-enter.", 
                       "2024/10/20 17:39 Help information added in German."
                      }, 
					  {"                                                           Journal                                                                    ", 
					   "--------------------------------------------------------------------------------------------------------------------------------------", 
					   "2024/10/3 10:42 Entwickelt ein Programm UDLR.", 
					   "2024/10/3 14:05 Inspiriert von diesem Programm wurde es in OIers 2048 adaptiert.", 
					   "2024/10/4 15:07 Die Grundfunktionen wurden geschrieben.", 
					   "2024/10/4 18:47 Hinzugefygt die Funktion der zuaulligen Generierung von CE.", 
					   "2024/10/5 13:11 Historische Aufzeichnungen wurden hinzugefygt.", 
					   "2024/10/5 13:27 Dieses Protokoll wurde hinzugefygt.", 
					   "2024/10/5 14:32 Englisch zum Protokoll hinzugefygt.", 
					   "2024/10/5 15:32 Logik hinzugefygt, um Gameover zu bestimmen.", 
					   "2024/10/5 15:51 Die Funktion zum Lvorschen von Karten wurde hinzugefygt.", 
					   "2024/10/5 16:11 Bug behoben, bei dem es nach dem Lvorschen keine Blvorcke gibt.", 
					   "2024/10/7 11:37 Fygen Sie die Bedeutung jedes Staates hinzu.", 
					   "2024/10/7 16:45 Ehndern Sie den Eingabetyp fyr die Sprache.", 
					   "2024/10/7 16:48 Ehndern Sie den Vorgang, wenn Ausgabeprotokolle ausgegeben werden.", 
					   "2024/10/7 16:58 Hinzugefygt die Funktion des Speichern beim erzwungenen Beenden.", 
					   "2024/10/7 17:12 Markieren Sie die abgekyrzten Buchstaben in der Bedeutung jedes Staates.", 
					   "2024/10/11 21:35 Hinzugefygt die Funktion des Speichern wauhrend des Spiels.", 
					   "2024/10/11 22:06 Hilfeinformationen hinzufygen.", 
					   "2024/10/19 11:38 Fyr Windows-Benutzer kvornnen Sie die Option zur Eingabe hinzufygen, ohne die Eingabetaste zu drycken.", 
					   "2024/10/19 11:50 Ehndern Sie die Ausgabemethoden von Protokollen, Hilfeinformationen usw.", 
					   "2024/10/19 11:55 Fehler behoben, bei dem erzwungene Beendigung nicht gespeichert wird, wenn nichts getan wird.", 
					   "2024/10/19 15:35 Deutsch zum Protokoll hinzufygen.", 
					   "2024/10/19 15:45 Aufforderung, deutsche Sprache hinzuzufygen.", 
					   "2024/10/19 19:09 Ehndern Sie das Eingabebetriebssystem auf automatische Beurteilung, um Eingabefehler zu vermeiden.", 
					   "2024/10/19 19:28 Bei Eingabe von \"o\" gefolgt von anderen Befehlen wird der Benutzer aufgefordert, erneut einzugeben.", 
					   "2024/10/20 17:39 Hilfeinformationen auf Deutsch hinzugefygt."
					  }};
string hints[5][110]={{"���������ȡ������(��/��):", 
                       "�밴���������...", 
                       "��������Ĳ���ϵͳ(1.Windows 2.Mac 3.Linux):", 
                       "���� w, a, s, d ������, q ���˳���", 
                       "���÷��������, ESC ���˳���", 
                       "�����Ƿ�Ҫ�������(��/��):", 
                       "������ȷ��Ҫ��յ�ͼ��(��/��):", 
                       "�����ϡ�", 
                       "������ϡ�", 
                       "��Ϸ����", 
                       "�л���ϣ���ǰ����:����", 
                       "�Ա���ʱ��Ϊ׼��", 
                       "���������롣"
                      }, 
                      {"May I ask if you would like to read the progress (yes/no):", 
                       "Please press any key to continue...", 
                       "Please enter your operating system (1. Windows 2. Mac 3. Linux):", 
                       "Please use the w, a, s, and d keys to play, and the q key to exit.", 
                       "Please use the directional keys to play and the ESC key to exit.", 
                       "May I ask if you want to save the progress (yes/no):", 
                       "Are you sure you want to clear the map? (yes/no):", 
                       "Clearing completed.", 
                       "Save completed.", 
                       "Game Over", 
                       "Switching completed, current language:English", 
                       "According to Beijing time.", 
                       "Please input again."
                      }, 
					  {"Darf ich Sie fragen, ob Sie den Fortschritt lesen mvorchten (ja/nein):", 
					   "Bitte drycken Sie eine beliebige Taste, um fortzufahren...", 
					   "Bitte geben Sie Ihr Betriebssystem ein (1. Windows 2. Mac 3. Linux):", 
					   "Bitte verwenden Sie die w-, a-, s- und d-Tasten zum Spielen und die q-Taste zum Beenden.", 
					   "Bitte verwenden Sie die Richtungstasten zum Spielen und die ESC-Taste zum Beenden.", 
					   "Darf ich fragen, ob Sie den Fortschritt speichern mvorchten (ja/nein):", 
					   "Bist du sicher, dass du die Karte lvorschen willstvor (ja/nein):", 
					   "Clearing abgeschlossen.", 
					   "Speichern abgeschlossen.", 
					   "Spiel vorbei", 
					   "Umschalten abgeschlossen, aktuelle Sprache:Deutsch", 
					   "Nach Pekinger Zeit."
					  }};
vector<string> help[5]={{"                           ����                           ", 
					     "----------------------------------------------------------", 
					     "Linuxϵͳ:", 
					     "    �������        ����", 
					     "    �������        ����", 
					     "    �������        ����", 
					     "    �������        ����", 
					     "    esc��           �˳�", 
					  	 "", 
					  	 "Windowsϵͳ:",
					  	 "    w               ����", 
					  	 "    s               ����", 
					  	 "    a               ����", 
					  	 "    d               ����", 
					  	 "    q               �˳�", 
					  	 "", 
					  	 "o                   ��ʾ������Ϣ", 
					  	 "    log             �����־", 
					  	 "    clear           ��յ�ͼ", 
					  	 "    save            �����ͼ", 
					  	 "    status          ��ʾ����״̬���������˼", 
					  	 "    language        �л�����", 
					  	 "    help            ��ʾ�˰�����Ϣ"
					 }, 
					 {
					  "                                      Help                                        ", 
					  "----------------------------------------------------------------------------------", 
					  "Linux system:", 
					  "    Directional key up           upward", 
					  "    Directional key down         downward", 
					  "    Directional key left         towards the left", 
					  "    Directional key right        towards the right", 
					  "    esc key                      exit", 
					  "", 
					  "Windows system:", 
					  "    w               upward", 
					  "    s               downward", 
					  "    a               towards the left", 
					  "    d               towards the right", 
					  "    q               exit", 
					  "", 
					  "o                   Display other information", 
					  "    log             Output Log", 
					  "    clear           Clear the map", 
					  "    save            Save the map", 
					  "    status          Display the meanings represented by various states", 
					  "    language        Switch language", 
					  "    help            Display this help information"
					 }, 
					 {"                                                          Hilfe                                                             ", 
					  "----------------------------------------------------------------------------------------------------------------------------", 
					  "Linux-System:", 
					  "    Richtungstaste nach oben          nach oben", 
					  "    Richtungstaste nach unten         nach unten", 
					  "    Richtungstaste links              nach links", 
					  "    Richtungstaste rechts             nach rechts", 
					  "    esc-Taste                         abmelden", 
					  "", 
					  "Windows-System:", 
					  "    w-Tasten                          nach oben", 
					  "    s-Tasten                          nach unten", 
					  "    a-Tasten                          nach links", 
					  "    d-Tasten                          nach rechts", 
					  "    q-Tasten                          abmelden", 
					  "", 
					  "o-Tasten                              Weitere Informationen anzeigen", 
					  "    log                               Ausgabeprotokoll", 
					  "    clear                             Karte lvorschen", 
					  "    save                              Karte speichern", 
					  "    status                            Anzeigen der Bedeutungen, die durch verschiedene Zustaunde dargestellt werden", 
					  "    language                          Sprache wechseln", 
					  "    help                              Diese Hilfe-Informationen anzeigen"
					 }};
string yn[5][2]={{"��", "��"}, 
				 {"yes", "no"}, 
				 {"ja", "nein"}};
void init() {
    map<long long, int> mp;
    mp[1]=1;
    for(int i = 2;i<=20;i++) {
        mp.insert(pair<long long, int>(i, mp[i-1]*2));
    }
    for(int i = 1;i<=20;i++) {
        fib[mp[i]]=i;
    }
	color.insert(pair<int, string>(2, "\033[48;2;241;196;15m"));
    status.insert(pair<int, string>(2, "CE"));
    means.insert(pair<int, string>(2, "2     CE  \033[1mC\033[0mompile \033[1mE\033[0mrror"));
	color.insert(pair<int, string>(4, "\033[48;2;52;152;219m"));
    status.insert(pair<int, string>(4, "JU"));
    means.insert(pair<int, string>(4, "4     JU  \033[1mJU\033[0mdging"));
	color.insert(pair<int, string>(8, "\033[48;2;142;68;173m"));
    status.insert(pair<int, string>(8, "RE"));
    means.insert(pair<int, string>(8, "8     RE  \033[1mR\033[0muntime \033[1mE\033[0mrror"));
	color.insert(pair<int, string>(16, "\033[48;2;46;70;140m"));
    status.insert(pair<int, string>(16, "TLE"));
    means.insert(pair<int, string>(16, "16    TLE \033[1mT\033[0mime \033[1mL\033[0mimit \033[1mE\033[0mxceed"));
	color.insert(pair<int, string>(32, "\033[48;2;46;70;140m"));
    status.insert(pair<int, string>(32, "MLE"));
    means.insert(pair<int, string>(32, "32    MLE \033[1mM\033[0memory \033[1mL\033[0mimit \033[1mE\033[0mxceed"));
	color.insert(pair<int, string>(64, "\033[48;2;46;70;140m"));
    status.insert(pair<int, string>(64, "ILE"));
    means.insert(pair<int, string>(64, "64    ILE \033[1mI\033[0mdleness \033[1mL\033[0mimit \033[1mE\033[0mxceed"));
	color.insert(pair<int, string>(128, "\033[48;2;46;70;140m"));
    status.insert(pair<int, string>(128, "OLE"));
    means.insert(pair<int, string>(128, "128   OLE \033[1mO\033[0mutput \033[1mL\033[0mimit \033[1mE\033[0mxceed"));
	color.insert(pair<int, string>(256, "\033[48;2;70;73;91m"));
    status.insert(pair<int, string>(256, "UKE"));
    means.insert(pair<int, string>(256, "256   UKE \033[1mU\033[0mn\033[1mK\033[0mnown \033[1mE\033[0mrror"));
	color.insert(pair<int, string>(512, "\033[48;2;231;81;57m"));
    status.insert(pair<int, string>(512, "WA"));
    means.insert(pair<int, string>(512, "512   WA  \033[1mW\033[0mrong \033[1mA\033[0mnswer"));
	color.insert(pair<int, string>(1024, "\033[48;2;215;132;40m"));
    status.insert(pair<int, string>(1024, "PC"));
    means.insert(pair<int, string>(1024, "1024  PC  \033[1mP\033[0martially \033[1mC\033[0morrect"));
	color.insert(pair<int, string>(2048, "\033[48;2;118;179;104m"));
    status.insert(pair<int, string>(2048, "AC"));
    means.insert(pair<int, string>(2048, "2048  AC  \033[1mAC\033[0mcepted"));
	color.insert(pair<int, string>(4096, "\033[48;2;229;141;134m"));
    status.insert(pair<int, string>(4096, "PE"));
    means.insert(pair<int, string>(4096, "4096  PE  \033[1mP\033[0mresentation \033[1mE\033[0mrror"));
	color.insert(pair<int, string>(8192, "\033[48;2;154;105;6m"));
    status.insert(pair<int, string>(8192, "DoJ"));
    means.insert(pair<int, string>(8192, "8192  DoJ \033[1mD\033[0menial \033[1mo\033[0mf \033[1mJ\033[0mudge"));
	color.insert(pair<int, string>(16384, "\033[48;2;194;188;164m"));
    status.insert(pair<int, string>(16384, "SJE"));
    means.insert(pair<int, string>(16384, "16384 SJE \033[1mS\033[0mpacial \033[1mJ\033[0mudge \033[1mE\033[0mrror"));
	color.insert(pair<int, string>(32768, "\033[48;2;221;196;49m"));
    status.insert(pair<int, string>(32768, "AU"));
    means.insert(pair<int, string>(32768, "32768 AU  \033[1mAU\033[0m"));
	color.insert(pair<int, string>(65536, "\033[48;2;102;198;255m"));
    status.insert(pair<int, string>(65536, "AK"));
    means.insert(pair<int, string>(65536, "65536 AK  \033[1mAK\033[0m"));
    lang.insert(pair<string, int>("zh", 0));
    lang.insert(pair<string, int>("en", 1));
    lang.insert(pair<string, int>("de", 2));
}
void prt() {
    system(cl);
    cout<<"\033[1mscore:"<<score<<endl;
    cout<<"\033[0m\033[38;2;12;12;12m";
    for(int i = 1;i<=n;i++) {
        for(int j = 1;j<=n;j++) {
            cout<<left<<color[a[i][j]]<<setw(3)<<status[a[i][j]]<<" \033[0m\033[38;2;12;12;12m";
        }
        cout<<endl;
    }
    cout<<"\033[0m";
}
void spawn() {
    random_device rd;
    mt19937 gen1(rd()), gen2(rd());
    uniform_int_distribution<int> distru(1, 4);
    int x=distru(gen1);
    int y=distru(gen2);
    while(a[x][y]!=0) {
    	x=distru(gen1), y=distru(gen2);
	}
    a[x][y]=2;
}
void up() {
    for(int i = 2;i<=n;i++) {
        for(int j = 1;j<=n;j++) {
            if(a[i][j]<=0) {
                continue;
            }
            int k=i, tmp=a[i][j];
            while(a[--k][j]==0&&k>0);
            a[i][j]=0;
            if(a[k][j]>0&&fib.count(a[k][j]+tmp)&&!(vis[k][j])&&abs(fib[a[k][j]]-fib[tmp])==0) {
                a[k][j]+=tmp;
                vis[k][j]=true;
                score+=a[k][j];
            } else {
                a[k+1][j]=tmp;
            }
        }
    }
}
void down() {
    for(int i = n-1;i>=1;i--) {
        for(int j = 1;j<=n;j++) {
            if(a[i][j]<=0) {
                continue;
            }
            int k=i, tmp=a[i][j];
            while(a[++k][j]==0&&k<=n);
            a[i][j]=0;
            if(a[k][j]>0&&fib.count(a[k][j]+tmp)&&!(vis[k][j])&&abs(fib[a[k][j]]-fib[tmp])==0) {
                a[k][j]+=tmp;
                vis[k][j]=true;
                score+=a[k][j];
            } else {
                a[k-1][j]=tmp;
            }
        }
    }
}
void left() {
    for(int i = 1;i<=n;i++) {
        for(int j = 2;j<=n;j++) {
            if(a[i][j]<=0) {
                continue;
            }
            int k=j, tmp=a[i][j];
            while(a[i][--k]==0&&k>0);
            a[i][j]=0;
            if(a[i][k]>0&&fib.count(a[i][k]+tmp)&&!(vis[i][k])&&abs(fib[a[i][k]]-fib[tmp])==0) {
                a[i][k]+=tmp;
                vis[i][k]=true;
                score+=a[i][k];
            } else {
                a[i][k+1]=tmp;
            }
        }
    }
}
void right() {
    for(int i = 1;i<=n;i++) {
        for(int j = n-1;j>=1;j--) {
            if(a[i][j]<=0) {
                continue;
            }
            int k=j, tmp=a[i][j];
            while(a[i][++k]==0&&k<=n);
            a[i][j]=0;
            if(a[i][k]>0&&fib.count(a[i][k]+tmp)&&!(vis[i][k])&&abs(fib[a[i][k]]-fib[tmp])==0) {
                a[i][k]+=tmp;
                vis[i][k]=true;
                score+=a[i][k];
            } else {
                a[i][k-1]=tmp;
            }
        }
    }
}
bool chk() {
    for(int i = 1;i<=n;i++) {
        for(int j = 1;j<=n;j++) {
            if(a[i][j]==a[i-1][j]||a[i][j]==a[i][j-1]||a[i][j]==0) {
                return true;
            }
        }
    }
    return false;
}
void save(bool gameover) {
    string op;
    ofstream fout("AK-IOI.txt");
    fout<<gameover<<endl;
    for(int i = 1;i<=n;i++) {
        for(int j = 1;j<=n;j++) {
            fout<<::a[i][j]<<" ";
        }
        fout<<endl;
    }
    fout<<score;
}
void pause() {
    cout<<hints[x][1];
    #ifdef _WIN32
    	_getch();
    #else
    	getch();
    #endif
}
void mean() {
    for(auto it = means.begin();it!=means.end();it++) {
        cout<<it->second<<endl;
    }
}
void set_lang() {
	string language;
    cout<<"�������������/Please enter your language/Bitte geben Sie Ihre Sprache ein(zh/en/de):";
    cin>>language;
    x=lang[language];
}
string ask() {
	string h;
	cin>>h;
	if(h=="log") {
		system(cl);
		cout<<hints[x][11]<<endl;
	    for(int i = 0;i<lg[x].size();i++) {
	        cout<<lg[x][i]<<endl;
	    }
	    pause();
	} else if(h=="clear") {
	    system(cl);
	    string op;
	    cout<<hints[x][6];
	    cin>>op;
	    if(op==yn[x][0]) {
	        for(int i = 1;i<=n;i++) {
	            for(int j = 1;j<=n;j++) {
	                ::a[i][j]=0;
	            }
	        }
	        spawn();
	        spawn();
	        score=0;
	        cout<<hints[x][7]<<endl;
	        pause();
	        system(cl);
	    }
	} else if(h=="save") {
	    system(cl);
	    save(gameover);
	    cout<<hints[x][8]<<endl;
	    pause();
	    system(cl);
	} else if(h=="status") {
	    system(cl);
	    mean();
	    pause();
	} else if(h=="language") {
		system(cl);
		set_lang();
		cout<<hints[x][10]<<endl;
		pause();
	} else if(h=="help") {
	    system(cl);
		for(auto i:help[x]) {
			cout<<i<<endl;
		}
		pause();
	}
	return h;
}
int main() {
    init();
    set_lang();
    ifstream fin("AK-IOI.txt");
    n=4;
    if(fin) {
        fin>>gameover;
        string op;
        if(!gameover) {
            cout<<hints[x][0];
            cin>>op;
            if(op==yn[x][0]) {
                for(int i = 1;i<=n;i++) {
                    for(int j = 1;j<=n;j++) {
                        fin>>a[i][j];
                    }
                }
                fin>>score;
                fin.close();
            } else {
                spawn();
                spawn();
            }
        } else {
            spawn();
            spawn();
        }
    } else {
        spawn();
        spawn();
    }
    gameover=false;
    string c, w, a, s, d, q;
    int sys;
    #ifdef _WIN32
    	sys=1;
    #else
    	sys=2;
    #endif
    switch(sys) {
    	case 1:
    		strcpy(cl, "cls");
    		w="w", a="a", s="s", d="d", q="q";
    		cout<<hints[x][3]<<endl;
            pause();
    		break;
    	case 2:
    		strcpy(cl, "clear");
    		w="\033[A", s="\033[B", a="\033[D", d="\033[C", q="\033";
    		cout<<hints[x][4]<<endl;
            pause();
            break;
	}
    prt();
    ofstream fout("AK-IOI.txt");
    while(chk()) {
        save(false);
	    #ifdef _WIN32
	    	c=_getch();
	    #else
	    	cin>>c;
	    #endif
        memset(vis, false, sizeof(vis));
        if(c==q) {
            string op;
            cout<<hints[x][5];
            cin>>op;
            if(op==yn[x][0]) {
                save(gameover);
	            cout<<hints[x][8]<<endl;
            }
            pause();
            return 0;
        } else if(c==w) {
            up();
            spawn();
        } else if(c==s) {
            down();
            spawn();
        } else if(c==a) {
            left();
            spawn();
        } else if(c==d) {
            right();
            spawn();
        } else if(c=="o") {
	    	system(cl);
	    	for(int i = 17;i<=22;i++) {
	    		cout<<help[x][i].substr(4)<<endl;
			}
			string h;
			h=ask();
        	while(h!="log"&&h!="clear"&&h!="save"&&h!="status"&&h!="language"&&h!="help") {
        		system(cl);
				cout<<hints[x][12]<<endl;
		    	for(int i = 17;i<=22;i++) {
		    		cout<<help[x][i].substr(4)<<endl;
				}
				h=ask();
			}
		}
        prt();
    }
    gameover=true;
    fout<<gameover;
    cout<<"\033[31m"<<hints[x][9]<<"\033[0m\n";
    pause();
    return 0;
}
