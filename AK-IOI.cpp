#include<bits/stdc++.h>
#include<random>
using namespace std;
int a[110][110], n, x, baka[110][110];
map<long long, int> fib;
bool vis[110][110], gameover, cheat;
map<int, string> color, status, means;
map<string, int> lang;
char cl[10];
long long score;
string lo, hin, hel;
ifstream flog, fhints, fhelp;
#ifdef _WIN32
	#include<conio.h>
#else
	#include<unistd.h>
	#include<termios.h>
	char getch() {
		char buf=0;
		termios old={0};
		if(tcgetattr(0, &old)<0) {
			perror("tcsetattr()");
		}
		old.c_lflag&=~ICANON;
		old.c_lflag&=~ECHO;
		if(tcsetattr(0, TCSANOW, &old)<0) {
			perror("tcsetattr ICANON");
		}
		if(read(0, &buf, 1)<0) {
			perror("read()");
		}
		old.c_lflag|=ICANON;
		old.c_lflag|=ECHO;
		if(tcsetattr(0, TCSANOW, &old)<0) {
			perror("tcsetattr ~ICANON");
		}
		return buf;
	} 
#endif
string hints[110];
vector<string> help;
string yn[5][2]={{"ÊÇ", "·ñ"}, 
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
    cout<<hints[1];
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
	int cnt=0;
	string language, tmp;
    cout<<"ÇëÊäÈëÄãµÄÓïÑÔ/Please enter your language/Bitte geben Sie Ihre Sprache ein(zh/en/de):";
    cin>>language;
    x=lang[language];
    lo=language+"/"+language+".log";
    hin=language+"/"+language+".hints";
    hel=language+"/"+language+".help";
	flog.open(lo.c_str());
	fhints.open(hin.c_str());
	fhelp.open(hel.c_str());
	while(fhints.peek()!=EOF) {
		getline(fhints, tmp);
		hints[cnt++]=tmp;
	}
	cnt=0;
	while(fhelp.peek()!=EOF) {
		getline(fhelp, tmp);
		help.push_back(tmp);
	}
}
string ask() {
	string output;
	string h;
	cin>>h;
	if(h=="log") {
		system(cl);
		cout<<hints[11]<<endl;
	    while(flog.peek()!=EOF) {
	    	getline(flog, output);
	        cout<<output<<endl;
	    }
	    pause();
	} else if(h=="clear") {
	    system(cl);
	    string op;
	    cout<<hints[6];
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
	        cout<<hints[7]<<endl;
	        pause();
	        system(cl);
	    }
	} else if(h=="save") {
	    system(cl);
	    save(gameover);
	    cout<<hints[8]<<endl;
	    pause();
	    system(cl);
	} else if(h=="status") {
	    system(cl);
	    mean();
	    pause();
	} else if(h=="language") {
		system(cl);
		set_lang();
		cout<<hints[10]<<endl;
		pause();
	} else if(h=="help") {
	    system(cl);
		while(fhelp.peek()!=EOF) {
			getline(fhelp, output);
			cout<<output<<endl;
		}
		pause();
	} else if(h=="cheat") {
		cheat=!cheat;
	}
	return h;
}
double exe_score() {
	double score=0;
	for(int i = 1;i<=n;i++) {
		for(int j = 1;j<=n;j++) {
			if(a[i][j]) {
				score+=log2(a[i][j]);
			}
		}
	}
	for(int i = 1;i<=n;i++) {
		for(int j = 1;j<=n;j++) {
			if(!a[i][j]) {
				score+=5;
			}
		}
	}
	return score;
}
int choose() {
	int bakscore=score, best, maxx=numeric_limits<int>::min();
	memcpy(baka, a, sizeof(a));
	up();
	if(exe_score()>maxx) {
		maxx=exe_score();
		best=0;
	}
	score=bakscore;
	memcpy(a, baka, sizeof(baka));
	down();
	if(exe_score()>maxx) {
		maxx=exe_score();
		best=1;
	}
	score=bakscore;
	memcpy(a, baka, sizeof(baka));
	left();
	if(exe_score()>maxx) {
		maxx=exe_score();
		best=2;
	}
	score=bakscore;
	memcpy(a, baka, sizeof(baka));
	right();
	if(exe_score()>maxx) {
		maxx=exe_score();
		best=3;
	}
	score=bakscore;
	memcpy(a, baka, sizeof(baka));
	return best;
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
            cout<<hints[0];
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
    		cout<<hints[3]<<endl;
            pause();
    		break;
    	case 2:
    		strcpy(cl, "clear");
    		w="\033[A", s="\033[B", a="\033[D", d="\033[C", q="\033";
    		cout<<hints[4]<<endl;
            pause();
            break;
	}
    prt();
    ofstream fout("AK-IOI.txt");
    while(chk()) {
        save(false);
        memset(vis, false, sizeof(vis));
        if(!cheat) {
		    #ifdef _WIN32
		    	c=_getch();
		    #else
		    	c+=getch();
		    	c+=getch();
		    	c+=getch();
		    #endif
        	if(c==q) {
	            string op;
	            cout<<hints[5];
	            cin>>op;
	            if(op==yn[x][0]) {
	                save(gameover);
		            cout<<hints[8]<<endl;
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
		    	for(int i = 17;i<help.size();i++) {
		    		cout<<help[i].substr(4)<<endl;
				}
				string h;
				h=ask();
	        	while(h!="log"&&h!="clear"&&h!="save"&&h!="status"&&h!="language"&&h!="help"&&h!="cheat") {
	        		system(cl);
					cout<<hints[12]<<endl;
			    	for(int i = 17;i<help.size();i++) {
			    		cout<<help[i].substr(4)<<endl;
					}
					h=ask();
				}
			}
		} else {
			int chose=choose();
			if(chose==0) {
	            up();
	            spawn();
	        } else if(chose==1) {
	            down();
	            spawn();
	        } else if(chose==2) {
	            left();
	            spawn();
	        } else if(chose==3) {
	            right();
	            spawn();
	        }
			if(kbhit()){
			    #ifdef _WIN32
			    	c=_getch();
			    #else
			    	c+=getch();
			    	c+=getch();
			    	c+=getch();
			    #endif
				if(c==q) {
		            string op;
		            cout<<hints[5];
		            cin>>op;
		            if(op==yn[x][0]) {
		                save(gameover);
			            cout<<hints[8]<<endl;
		            }
		            pause();
		            return 0;
		        } else if(c=="o") {
			    	system(cl);
			    	for(int i = 17;i<help.size();i++) {
			    		cout<<help[i].substr(4)<<endl;
					}
					string h;
					h=ask();
		        	while(h!="log"&&h!="clear"&&h!="save"&&h!="status"&&h!="language"&&h!="help"&&h!="cheat") {
		        		system(cl);
						cout<<hints[12]<<endl;
				    	for(int i = 17;i<help.size();i++) {
				    		cout<<help[i].substr(4)<<endl;
						}
						h=ask();
					}
				}
			}
			this_thread::sleep_for(chrono::milliseconds(500));
		}
        prt();
    }
    gameover=true;
    fout<<gameover;
    cout<<"\033[31m"<<hints[9]<<"\033[0m\n";
    pause();
    return 0;
}
