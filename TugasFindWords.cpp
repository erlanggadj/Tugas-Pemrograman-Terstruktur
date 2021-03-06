#include <iostream>
#include <cstring>

using namespace std;
const int cols = 16, rows = 15;

 char words[rows][cols] = {"tgbwwinterwsesn",
                        	"aaunttmmhfoodnb",
                            "jlwcqldzmpmvdmr",
                            "asagmquwvvbsohi",
                            "bwplotanadtpgnc",
                            "rewngodjcpnatnk",
                            "eeotwosbqharrsa",
                            "azcgeswewnaknpb",
                            "dinnerqodlwdcar",
                            "onopkwmparktzcc",
                            "qbfrogmamwpweey",
                            "lqzqnnmrzjjsclg",
                            "mosgzczetdbooto",
                            "pdcrzmsngrdnrpz",
                            "ohnkzwaterjgtra"};

char *getWordVertical(int a){
	static char b[16];
	
	for(int i=0;i<15;i++){
		b[i] = *(*(words + i) + a);
	}
	return b;
}

char *reverse(char *a){
    static char b[16];
    for(int i = 0; i < 15 ;i++){
        b[i] = * (a+14-i);
    	}
    return b;
}

bool searchVertical(char *a){
	bool lean;
	char *save;
	
	for(int i = 0;i<15;i++){
		save = getWordVertical(i);
		char *x = strstr(save,a);
		char *y = strstr(reverse(save),a);
		
		if (x || y){
			lean = true;
			break;
		} else {
			lean = false;
		} 
	}
	return lean;	
}

bool searchHorizontal(char *a){
	bool lean;
	char * save;
	
	for(int i = 0;i<15;i++){
                save = words[i];
		if (strstr(save,a) || strstr(reverse(save),a) ){
			lean = true;
			break;
		} else {
			lean = false;
		}
	}	
	return lean;
}

int main(){
    char word[16];
    int n;
    cin>>n;
    cin.ignore(1, '\n');
    for (int i=0; i<n; i++){
        cin.getline(word, 16, '\n');
        if (searchVertical(word) || searchHorizontal(word) == true)
            cout << "Ada\n";
        else
            cout << "Tidak Ada\n";
    }
    return 0;
}
