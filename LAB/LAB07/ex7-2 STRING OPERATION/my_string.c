// my_string.c
#include <iostream>
#include "my_string.h"


myString::myString (const char *s) {
	//	int len = strlen(s);
	int len = 0;
	while (s[len]!='\0') {
		len++;
	}
	// Note: because strlen() does not include the '\0' character, it should be len+1
	p = new char[len+1];
	// strcpy(p,s);
	for(int i=0; i<len; i++) {
		p[i]=s[i];
		cout<<"p["<<i<<"]="<<p[i]<<endl;
	}
	p[len]='\0';
}
myString::myString (const myString &s) {
	p = new char[strlen(s.p)+1];
}

ostream& operator<< (ostream &out, const myString &s) {
	out<<s.p;
}
myString operator+ (const myString &s, const myString &t) {
	char* str = new char[strlen(s.p) + strlen(t.p) + 1];
//	for(int i=0; i<strlen(s.p); i++) str[i]=s.p[i];
//	for(int i=0; i<strlen(t.p); i++) str[i+strlen(s.p)]=t.p[i];
//	str[strlen(s.p)+strlen(t.p)]='\0';
	strcpy(str,s.p);
	strcpy(str+strlen(s.p),t.p);
	return myString(str);
}
myString operator+ (const myString &s, const char* t) {
	char* str = new char[strlen(s.p) + strlen(t) + 1];
//	for(int i=0; i<strlen(s.p); i++) str[i]=s.p[i];
//	for(int i=0; i<strlen(t); i++) str[i+strlen(s.p)]=t[i];
//	str[strlen(s.p)+strlen(t)]='\0';
	strcpy(str, s.p);
	strcpy(str+strlen(s.p), t);
	return myString(str);
}
myString operator+ (const char* t, const myString &s) {
	char* str = new char[strlen(t) + strlen(s.p) + 1];
	for(int i=0; i<strlen(t); i++) str[i]=t[i];
	for(int i=0; i<strlen(s.p); i++) str[i+strlen(t)]=s.p[i];
	str[strlen(t)+strlen(s.p)]='\0';
	return myString(str);
}
bool myString::operator<= (const myString &s){
	return (strlen(p)<=strlen(s.p))? true : false;
}

