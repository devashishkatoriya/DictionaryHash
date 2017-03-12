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
#define LIMIT 30
 
//Class Definitions 
class Entry                                                      //Entry Class - Linked List Implementation
{ 
public : 
    char word[LIMIT],meaning[LIMIT];
    Entry *next;
}; 
 
class HashTable                                                     //Hash Table Class 
{ 
    Entry *ht[MAX];
    void insert(Entry *);
    inline int HashFunc(char []); 
public : 
    HashTable() 
    { 
        for(int i=0;i<MAX;i++) 
        {
            ht[i] = NULL;
        } 
    }
    void clr() 
    { 
        for(int i=0;i<MAX;i++) 
        {
            ht[i] = new Entry;
            strcpy(ht[i]->word,"");
            strcpy(ht[i]->meaning,"");
            ht[i]->next = NULL;
        } 
    } 
    void construct(); 
    void display(); 
    void search();
    void delete_word();
}; 
 
void HashTable::construct()                                           //Function for Insertion 
{
    Entry *B;
    B = new Entry();
    cout<<"\nEnter Entry Details :- ";
    cout<<"\nEnter Word   \t: ";
    cin>>B->word;
    cout<<"Enter Meaning\t: ";
    cin>>B->meaning;
    B->next = NULL;
    insert(B);
} 
 
void HashTable::insert(Entry *B)                                         //Insertion
{ 
    int pos; 
    pos = HashFunc(B->word);
    if(ht[pos]==NULL)
    {
        ht[pos] = B;
    }
    else
    {
        B->next = ht[pos]->next;
        ht[pos]->next = B;
    }
    cout<<"\nWord inserted Successfully!";
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
    Entry *curr;
    cout<<"\n\t\tDictionary";
    cout<<"\n---------------------------------------------"; 
    cout<<"\nWord - Meaning";
    cout<<"\n---------------------------------------------"; 
    for(int i=0;i<MAX;i++) 
    {
        curr = ht[i];
        cout<<"\n";
        while(curr!=NULL)
        {
            cout<<curr->word<<" - "<<curr->meaning<<", ";
            curr = curr->next;
        }
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
    if(strcmp(ht[pos]->word,word)==0)
    {
        cout<<"\nWord   \t: "<<ht[pos]->word;
        cout<<"\nMeaning\t: "<<ht[pos]->meaning;
        return; 
    } 
    else 
    { 
        Entry *temp;
        temp = ht[pos]->next;
        while(temp!=NULL)
        {
            if (strcmp(temp->word, word) == 0)
            {
                cout << "\nWord   \t: " << temp->word;
                cout << "\nMeaning\t: " << temp->meaning;
                return;
            }
            temp = temp->next;
        }
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
    if(strcmp(ht[pos]->word,word)==0)
    {
        ht[pos] = ht[pos]->next;
        cout<<"\nWord deleted Successfully!";
        return;
    }
    Entry *temp,*prev;
    prev = ht[pos];
    temp = prev->next;
    while(temp!=NULL)
    {
        if (strcmp(temp->word, word) == 0)
        {
            prev->next = temp->next;
            cout<<"\nWord deleted Successfully!";
            return;
        }
        temp = temp->next;
        prev = prev->next;
    }
    cout<<"\nWord NOT found!";
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

Program to implement Dictionary using Hash Table.

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 1 to Insert new Word
 2 to Display Dictionary
 3 to Search a word
 4 to Delete a word
 -1 to Clear whole Dictionary
  0 to Quit
Enter your choice : 1
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Enter Entry Details :-
Enter Word      : computer
Enter Meaning   : pc

Word inserted Successfully!

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 1 to Insert new Word
 2 to Display Dictionary
 3 to Search a word
 4 to Delete a word
 -1 to Clear whole Dictionary
  0 to Quit
Enter your choice : 1
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Enter Entry Details :-
Enter Word      : laptop
 laptop
Enter Meaning   : notebook

Word inserted Successfully!

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 1 to Insert new Word
 2 to Display Dictionary
 3 to Search a word
 4 to Delete a word
 -1 to Clear whole Dictionary
  0 to Quit
Enter your choice : 1
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Enter Entry Details :-
Enter Word      : eclipse
Enter Meaning   : hide

Word inserted Successfully!

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 1 to Insert new Word
 2 to Display Dictionary
 3 to Search a word
 4 to Delete a word
 -1 to Clear whole Dictionary
  0 to Quit
Enter your choice : 2
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

                Dictionary
---------------------------------------------
Word - Meaning
---------------------------------------------

eclipse - hide,




laptop - notebook,


computer - pc,
---------------------------------------------
MAX is 10

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 1 to Insert new Word
 2 to Display Dictionary
 3 to Search a word
 4 to Delete a word
 -1 to Clear whole Dictionary
  0 to Quit
Enter your choice : 1
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Enter Entry Details :-
Enter Word      : structure
Enter Meaning   : organisation

Word inserted Successfully!

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 1 to Insert new Word
 2 to Display Dictionary
 3 to Search a word
 4 to Delete a word
 -1 to Clear whole Dictionary
  0 to Quit
Enter your choice : 1
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Enter Entry Details :-
Enter Word      : data
Enter Meaning   : statistics

Word inserted Successfully!

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 1 to Insert new Word
 2 to Display Dictionary
 3 to Search a word
 4 to Delete a word
 -1 to Clear whole Dictionary
  0 to Quit
Enter your choice : 2
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

                Dictionary
---------------------------------------------
Word - Meaning
---------------------------------------------
data - statistics,
eclipse - hide,




laptop - notebook,


computer - pc, structure - organisation,
---------------------------------------------
MAX is 10

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 1 to Insert new Word
 2 to Display Dictionary
 3 to Search a word
 4 to Delete a word
 -1 to Clear whole Dictionary
  0 to Quit
Enter your choice : 3
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Enter word to Search : structure

Word    : structure
Meaning : organisation

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 1 to Insert new Word
 2 to Display Dictionary
 3 to Search a word
 4 to Delete a word
 -1 to Clear whole Dictionary
  0 to Quit
Enter your choice : 4
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Enter word to Delete : computer

Word deleted Successfully!

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 1 to Insert new Word
 2 to Display Dictionary
 3 to Search a word
 4 to Delete a word
 -1 to Clear whole Dictionary
  0 to Quit
Enter your choice : 2
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

                Dictionary
---------------------------------------------
Word - Meaning
---------------------------------------------
data - statistics,
eclipse - hide,




laptop - notebook,


structure - organisation,
---------------------------------------------
MAX is 10

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 1 to Insert new Word
 2 to Display Dictionary
 3 to Search a word
 4 to Delete a word
 -1 to Clear whole Dictionary
  0 to Quit
Enter your choice : 4
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Enter word to Delete : structure

Word deleted Successfully!

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 1 to Insert new Word
 2 to Display Dictionary
 3 to Search a word
 4 to Delete a word
 -1 to Clear whole Dictionary
  0 to Quit
Enter your choice : 2
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

                Dictionary
---------------------------------------------
Word - Meaning
---------------------------------------------
data - statistics,
eclipse - hide,




laptop - notebook,



---------------------------------------------
MAX is 10

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 1 to Insert new Word
 2 to Display Dictionary
 3 to Search a word
 4 to Delete a word
 -1 to Clear whole Dictionary
  0 to Quit
Enter your choice : 0
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Thank you for using this program :)
 
*/