//Fredrik Haupt caha6864

#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <stdio.h>
#include <string.h>

struct Person
{
  std::string fnamn;
  std::string enamn;
  std::string nummer;
};

std::vector<Person> folk;


void visa_person (std::vector<Person> v, std::string n)
{
    // Denna funktion tar emot ett telefonregister och ett förnamn på den person-post som skall visas. 
    
    // Om det finns en eller flera person-poster med detta förnamn i registret, 
    // så skall telefonnumret till dessa visas, på formen: "förnamn efternamn: telefonnummer".
    
    //std::cout << fnamn << " " << enamn << ": " << nummer << std::endl;
    
    // Om ingen person-post hittas med det sökta förnamnet, så skall följande skrivas ut.
    bool found = false;
    for(int i = 0; i < v.size(); i++){
        if(n.compare(v[i].fnamn) == 0){
            std::cout << v[i].fnamn << " " << v[i].enamn << ": " << v[i].nummer << std::endl;
            found = true;
        }    
    }
    if(found == false){
        std::cout << "Hittade inget nummer!" << std::endl;
    }
}

void skriv_hela_telefonreg (std::vector<Person> v)
{
    // Denna funktion tar emot ett telefonregister och visar samtliga poster i 
    // telefonregistret på formen: "förnamn efternamn: telefonnummer".
    for(Person p : v){
        std::cout << p.fnamn << " " << p.enamn << ": " << p.nummer << std::endl;
    }   
}


void ny_person (std::vector<Person>& v, std::string f, std::string e, std::string n)
{
    // Denna funktion tar emot ett telefonregister och ett förnamn, ett efternamn och 
    // ett telefonnummer till den nya person-post som skall skapas och läggas till i telefonboken, 
    // därefter läggs person-posten till registret.

    Person p;
    //v[0].fnamn = f;
    p.fnamn = f;
    p.enamn = e;
    p.nummer = n;
    v.push_back(p);
}

void ta_bort_person (std::vector<Person>& v, std::string f)
{
    // Denna funktion tar emot ett telefonregister och ett förnamn på den person-post 
    // som skall tas bort ur registret.
    // Om det finns fler person-poster med samma förnamn, så tas alla dessa bort.
    
    // När en person-post tas bort så skrivs namnet på person-posten ut på skärmen (förnamn efternamn), 
    // men ingen användardialog skall finnas, dvs. användaren skall inte bekräfta borttag.

    for(int i = 0; i < v.size(); i++){
        if(f == v[i].fnamn){
            std::cout << v[i].fnamn << " " << v[i].enamn << " tas nu bort." << std::endl;
            v.erase(v.begin()+i);
        }
    }    
}

int main ()
{
    // Dessa personer skall finnas med som person-poster i telefonregistret.
    /*
    "Christina", "Nyberg","0707423653"
    "Josefin", "Danielsson", "0705463245"
    "Ellen", "Lindgren", "0705643229"
    "Stig", "Ek", "0705673247"
    "Linus", "Jonasson", "0703457923"
    "Adam", "Nordin", "0203456297"
    */
    
    // Här ska du deklarera den variabel som skall innehålla ditt register!
    

    folk = {
        {"Christina", "Nyberg","0707423653"}, 
        {"Josefin", "Danielsson", "0705463245"},
        {"Ellen", "Lindgren", "0705643229"},
        {"Stig", "Ek", "0705673247"},
        {"Linus", "Jonasson", "0703457923"},
        {"Adam", "Nordin", "0203456297"}
    };
    
    // Här skall en liten kommandostyrd huvudmeny skrivas. Observera att vissa kommandon
    // behöver fler värden som skall matas in. I menyn skall följande val 
    // av Kommandon finnas:
    //  Ny person               - 'n' förnamn efternamn telefonnummer
    //  Visa en person          - 'v' förnamn
    //  Skriv hela telefonboken - 's'
    //  Ta bort en person       - 'd' förnamn
    //  Avsluta                 – 'q'
    
    char kommando;

    do{
        std::string förnamn, efternamn, nummer;
        std::cout << "Kommando: ";
        std::cin >> kommando; 
        switch (kommando){
            case 'n': std::cin >> förnamn >> efternamn >> nummer; ny_person(folk, förnamn, efternamn, nummer); break;
            case 'v': std::cin >> förnamn; visa_person(folk, förnamn); break;
            case 's': skriv_hela_telefonreg(folk); break;
            case 'd': std::cin >> förnamn; ta_bort_person(folk, förnamn); break;
            case 'q': std::cout << "Hejdå!" << std::endl; std::this_thread::sleep_for(std::chrono::seconds(1)); exit(0);
        }
    }while (kommando != 'q');
  
  return 0;
}

