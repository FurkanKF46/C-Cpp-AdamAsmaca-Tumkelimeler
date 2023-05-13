#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;
vector<string> kelimeleriokuma(const string& filename){
    ifstream dosya(filename);
    vector<string> words;
    string word;
    if (!dosya)
    {
        cout<<"Dosya acilamadi."<<endl;
        return words;
    }
    while (getline(dosya, word))
    {
        words.push_back(word);
    }
    dosya.close();
    return words;
    
}
string kelimesec(const vector<string>&words){
    if (words.empty())
    return "";
    srand(time(0));
    int deger=rand()%words.size();
    return words[deger];
}
bool harfsecme(char harf,const string& word){
   for (char c : word)
   {
    if (c == harf)
    {
        return true;
    }
    
   }
   return false;
   
    
}
string kelimegizleme(const string& word){
string gizlenenkelime(word.length(),'_');
return gizlenenkelime;

}
string bulunanharf(char harf,const string& word,const string& gizlenenkelime){
    string guncelleme=gizlenenkelime;
    for (size_t i = 0; i < word.length(); i++)
    {
        if (word[i]==harf)
        {
            guncelleme[i]=harf;
        }
        
    }
    return guncelleme;
    
}
void AdamAsmaca(const vector<string>& words){
    string kelime=kelimesec(words);
    string gizlikelime=kelimegizleme(kelime);
    int sayi=6;
    string tahminharfleri;
    cout<<"Adam asmaca oyununa hosgeldiniz"<<endl;
    cout<<"Kelimeyi tahmin etmek icin harf girmeniz gerekiyor"<<endl;
    while (sayi>0 && gizlikelime!=kelime)
    {
        cout<<"Tahmin edilen kelime: "<<gizlikelime<<endl;
        cout<<"Kalan deneme hakkiniz: "<<sayi<<endl;
        cout<<"Daha once tahmin ettiginiz harfler: "<<tahminharfleri<<endl;
        char harf;
        cout<<"Bir harf girin"<<endl;
        cin>>harf;
        if (harfsecme(harf,kelime))
        {
            gizlikelime=bulunanharf(harf,kelime,gizlikelime);
            cout<<"Dogru tahmin!!!"<<endl;
        }
        else{
            sayi--;
            cout<<"Yanlis tahmin!!!"<<endl;
        }
        tahminharfleri+=harf;
        cout<<endl;

    }
    if (gizlikelime==kelime)
    {
        cout<<"Tebrikler dogru tahmin ettiniz.Dogru kelime: "<<kelime<<endl;
    }
    else 
    cout<<"Maalesef dogru tahmin edemediniz: "<<kelime<<endl;
}
int main(int argc, char **argv){
    vector<string> words=kelimeleriokuma("kelimeler.txt");
    if (words.empty())
    {
        return 1;
    }
    AdamAsmaca(words);
    return 0;
}