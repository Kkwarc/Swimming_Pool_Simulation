// #include <iostream>
// #include <fstream>
// #include <cstdlib>

// using namespace std;

// void Pytanie::wczytaj()
// {
//    fstream plik;
//    plik.open("test.txt",ios::in);

//    if(plik.good()==false)
//    {
//       cout<<"Nie udalo sie otworzyc pliku!";
//       exit(0);
//    }

//    int nr_linii=(nr_pytania-1)*6+1;
//    int aktualny_nr=1;
//    string linia;

//    while(getline(plik,linia))
//    {
//       if(aktualny_nr==nr_linii) tresc=linia;
//       if(aktualny_nr==nr_linii+1) a=linia;
//       if(aktualny_nr==nr_linii+2) b=linia;
//       if(aktualny_nr==nr_linii+3) c=linia;
//       if(aktualny_nr==nr_linii+4) d=linia;
//       if(aktualny_nr==nr_linii+5) poprawna=linia;
//       aktualny_nr++;
//    }

//    plik.close();

// }

// void Pytanie::zadaj()
// {
//    cout<<endl<<tresc<<endl;
//    cout<<a<<endl;
//    cout<<b<<endl;
//    cout<<c<<endl;
//    cout<<d<<endl;
//    cout<<"------------------------"<<endl;
//    cout<<endl<<"Odpowiedz: ";
//    cin>>odpowiedz;
// }

// void Pytanie::sprawdz()
// {
//    if(odpowiedz==poprawna)
//    {
//       punkt=1;
//    }
//    else punkt=0;
// }


// int main()
// {

//    Pytanie p[5];
//    int suma=0;
//    for(int i=0; i<=4; i++)
//    {
//       p[i].nr_pytania=i+1;
//       p[i].wczytaj();
//       p[i].zadaj();
//       p[i].sprawdz();
//       suma+=p[i].punkt;
//    }

//    cout<<"KONIEC QUIZU! PUNKTY = "<<suma;

//    return 0;
// }