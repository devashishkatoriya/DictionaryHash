/* 
 * Problem Statement :- 
 * Implement all the functions of a dictionary (ADT) using hashing.
 * Data: Set of (key, value) pairs, Keys are mapped to values,
 *       Keys must be comparable, Keys must be unique
 * Standard Operations: Insert(key, value), Find(key), Delete(key)
 */ 
 
/* 
 * Created by Devashish Katoriya on 12-03-2017
 */ 
 
#include <iostream> 
#include <string.h>
 
using namespace std; 
 
#define MAX 10 
 
//Class Definitions 
class Entry                                                          //Entry Class
{ 
public : 
    char word[MAX],meaning[MAX];
}; 
 
class HashTable                                                     //Hash Table Class 
{ 
    Entry ht[MAX]; 
    void insert(Entry); 
    void insertQ(Entry); 
    inline int HashFunc(char []); 
public : 
    HashTable() 
    { 
        for(int i=0;i<MAX;i++) 
        { 
            strcpy(ht[i].word,"");
            strcpy(ht[i].meaning,"");
        } 
    } 
    bool isFull() 
    { 
        for(int i=0;i<MAX;i++) 
        { 
            if(strcmp(ht[i].word,"")==0)
            { 
                return false; 
            } 
        } 
        return true; 
    } 
    void clr() 
    { 
        for(int i=0;i<MAX;i++) 
        { 
            strcpy(ht[i].word,"");
            strcpy(ht[i].meaning,"");
        } 
    } 
    void construct(); 
    void display(); 
    void search();
    void delete_word();
}; 
 
void HashTable::construct()                                           //Function for Insertion 
{ 
    if(isFull()) 
    { 
        cout<<"\nSorry, the Dictionary is Full.";
        return; 
    } 
     
    int ch = 0; 
    cout<<"\n\n 1 for Linear Hashing."; 
    cout<<"\n 2 for Quadratic Hashing."; 
    cout<<"\nEnter which Hashing Technique to use ? "; 
    cin>>ch; 
    if(ch==1) 
    { 
        Entry B; 
        cout<<"\nEnter Entry Details :- ";
        cout<<"\nEnter Word   \t: ";
        cin>>B.word;
        cout<<"Enter Meaning\t: ";
        cin>>B.meaning;
        insert(B); 
    } 
    else if(ch==2) 
    { 
        Entry B; 
        cout<<"\nEnter Entry Details :- ";
        cout<<"\nEnter Word   \t: ";
        cin>>B.word;
        cout<<"Enter Meaning\t: ";
        cin>>B.meaning;
        insertQ(B); 
    } 
    else 
        cout<<"\nInvalid Option!"; 
} 
 
void HashTable::insert(Entry B)                                         //Insertion using Linear Probing 
{ 
    int pos; 
    pos = HashFunc(B.word);
    if(strcmp(ht[pos].word,"")==0)
    { 
        ht[pos] = B;
        cout<<"\nWord inserted Successfully!";
    } 
    else 
    { 
        int i=pos; 
        do 
        { 
            if(strcmp(ht[i].word,"")==0)
            { 
                ht[i] = B;
                cout<<"\nWord inserted Successfully!";
                break; 
            } 
            i=(i+1)%MAX; 
        }while(i!=pos); 
    } 
} 
 
void HashTable::insertQ(Entry B)                                         //Insertion using Quadratic Probing 
{ 
    int pos; 
    pos = HashFunc(B.word);
    if(strcmp(ht[pos].word,"")==0)
    { 
        ht[pos] = B;
        cout<<"\nWord inserted Successfully!";
    } 
    else 
    { 
        for(int i=1; i<(MAX-1)/2; i++) 
        { 
            if(strcmp(ht[(pos+(i*i))%MAX].word,"")==0)
            { 
                ht[(pos+(i*i))%MAX] = B;
                cout<<"\nWord inserted Successfully!";
                break; 
            } 
        } 
    } 
} 
 
inline int HashTable::HashFunc(char key[MAX])                             //Hash Function
{ 
    int i,total = 0; 
    for(i=0;key[i]!='\0';i++) 
        total += key[i]; 
    return total % MAX; 
} 
 
void HashTable::display()                                               //Display
{ 
    cout<<"\n\t\tDictionary";
    cout<<"\n---------------------------------------------"; 
    cout<<"\nPos.\tWord\t\tMeaning";
    cout<<"\n---------------------------------------------"; 
    for(int i=0;i<MAX;i++) 
    { 
        cout<<"\n"<<i<<"\t"<<ht[i].word<<"\t\t"<<ht[i].meaning;
    } 
    cout<<"\n---------------------------------------------"; 
    cout<<"\nMAX is "<<MAX; 
} 
 
void HashTable::search()                                                //Search 
{ 
    char word[MAX];
    int pos; 
    cout<<"\nEnter word to Search : ";
    cin>>word;
    pos = HashFunc(word);
    if(strcmp(ht[pos].word,word)==0)
    {
        cout<<"\nWord   \t: "<<ht[pos].word;
        cout<<"\nMeaning\t: "<<ht[pos].meaning;
        return; 
    } 
    else 
    { 
        int i=pos; 
        do 
        { 
            if(strcmp(ht[i].word,word)==0)
            {
                cout << "\nWord   \t: " << ht[i].word;
                cout << "\nMeaning\t: " << ht[i].meaning;
                return; 
            } 
            i=(i+1)%MAX; 
        }while(i!=pos); 
        cout<<"\nWord NOT found!";
    } 
}

void HashTable::delete_word()                                                //Delete
{
    char word[MAX];
    int pos;
    cout<<"\nEnter word to Delete : ";
    cin>>word;
    pos = HashFunc(word);
    if(strcmp(ht[pos].word,word)==0)
    {
        strcpy(ht[pos].word,"");
        strcpy(ht[pos].meaning,"");
        cout<<"\nWord deleted Successfully!";
        return;
    }
    else
    {
        int i=pos;
        do
        {
            if(strcmp(ht[i].word,word)==0)
            {
                strcpy(ht[i].word,"");
                strcpy(ht[i].meaning,"");
                cout<<"\nWord deleted Successfully!";
                return;
            }
            i=(i+1)%MAX;
        }while(i!=pos);
        cout<<"\nWord NOT found!";
    }
}
 
//main() 
int main() 
{ 
    HashTable obj; 
    char choice; 
    int ch; 
    cout<<"\nProgram to implement Dictionary using Hash Table.";
    do 
    { 
        ch = 0; 
        choice = 'n'; 
        cout<<"\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"; 
        cout<<"\n 1 to Insert new Word";
        cout<<"\n 2 to Display Dictionary";
        cout<<"\n 3 to Search a word";
        cout<<"\n 4 to Delete a word";
        cout<<"\n 5 for IsFull";
        cout<<"\n -1 to Clear whole Dictionary";
        cout<<"\n  0 to Quit"; 
        cout<<"\nEnter your choice : "; 
        cin>>ch; 
        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"; 
        switch(ch) { 
            case 1 : 
                obj.construct(); 
                break; 
            case 2 : 
                obj.display(); 
                break; 
            case 3 : 
                obj.search(); 
                break;
            case 4 :
                obj.delete_word();
                break;
            case 5 :
                if(obj.isFull()) 
                    cout<<"\nYes, the Dictionary is Completely Full.";
                else 
                    cout<<"\nNo, the Dictionary is Not full.";
                break; 
            case -1 : cout<<"\nAre you sure, you want to clear dictionary (y/n) ? ";
                cin>>choice; 
                if(choice=='y'||choice=='Y') 
                { 
                    obj.clr(); 
                    cout<<"\nDictionary Cleared Successfully!";
                } 
                else 
                    cout<<"\nCancelled!"; 
            case 0 : break; 
            default : cout<<"\nInvalid Option!"; 
        } 
         
        /* 
        if(ch!=0) 
        { 
            cout<<"\n\n\n\n\n\n\nPress any key to continue..."; 
            cin.ignore(); 
            cin.get(); 
        } 
        */ 
    }while(ch!=0); 
     
    cout<<"\nThank you for using this program :) \n\n"; 
    return 0; 
} 
 
/* OUTPUT 

 
*/