/* C++ program to implement basic stack
operations */
#include <stdio.h>
#include <ctime>
#include <iostream>
#include <string>
#include<stack>
#include<unistd.h>



using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::stack;
#define MAX 1000


struct DefineCard
{
	string suit;
	string face;
	int pointsValue;   // FACE => 10 POINTS & ACE's => 1 OR 11 (WHICHEVER IS BEST FOR PLAYER/DEALER
	int cardStatus;   // 0 = InPlay , 1 = InDeck, 2 = DiscardPile
} Deck[53]; // Deck[52] will be used when shuffling deck

class Stack {
    int top;
 
public:
    int a[MAX]; // Maximum size of Stack
 
    Stack() { top = -1; }
    bool push(int x);
    int pop();
    int peek();
    bool isEmpty();
};
 
bool Stack::push(int x)
{
    if (top >= (MAX - 1)) {
        cout << "Stack Overflow";
        return false;
    }
    else {
        a[++top] = x;
        //cout << x << " pushed into stack\n";
        return true;
    }
}
 
int Stack::pop()
{
    if (top < 0) {
        cout << "Stack Underflow";
        return 0;
    }
    else {
        int x = a[top--];
        return x;
    }
}
int Stack::peek()
{
    if (top < 0) {
        cout << "Stack is Empty";
        return 0;
    }
    else {
        int x = a[top];
        return x;
    }
}
 
bool Stack::isEmpty()
{
    return (top < 0);
}
 
// Driver program to test above functions
int main()
{
	class Stack s;
    //stack<int>s;
	srand((unsigned)time(0));
	int New_Suit = 0;
    int faceDownDealer=0;
    char playerinput;
    int cardCount=0;
    int dealersFaceDownCard, dealersFaceUpCard,dealersCardTotal=0;
	string faces[13] = { "Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };
	string suits[4] = { "Diamonds", "Clubs", "Hearts", "Spades" };
	string Status[3] = { "In Play", "In Deck", "Discard Pile" };
	int CardValue[13] = { 11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10 };
    int howManyDeck=0;
    cout<<"How many decks do you want to play with?\n"<<endl;
    cin>>howManyDeck;
	for (int x = 0; x < 52; x++)
	{

		Deck[x].face = faces[x % 13];
		Deck[x].suit = suits[New_Suit];
		Deck[x].pointsValue = CardValue[x % 13];
		Deck[x].cardStatus = 1;
		if ((x + 1) % 13 == 0)
			New_Suit++;
	}
	// cout << "Straight deck of cards.." << endl << endl;
	// for (int i = 0; i < howManyDeck; i++)
	// {
	// 	for (int x = 0; x < 52; x ++)
	// 	{
	// 		//cout << Deck[x].face << " of " << Deck[x].suit << "   " << Deck[x + 1].face << " of " << Deck[x + 1].suit << "  " << Deck[x + 2].face << " of " << Deck[x + 2].suit << "   " << Deck[x + 3].face << " of " << Deck[x + 3].suit << endl;
	// 		cout << Deck[x].face << " of " << Deck[x].suit << " : Value of " << Deck[x].pointsValue << " : " << Status[Deck[x].cardStatus] << endl;
	// 	}
	// }
	
	for (int x = 0; x < 600; x++)
	{
		int a = rand() % 52;
		int b = rand() % 52;
		
		Deck[52].face = Deck[a].face;
		Deck[52].suit = Deck[a].suit;
		Deck[52].pointsValue = Deck[a].pointsValue;
		Deck[52].cardStatus = Deck[a].cardStatus;

		Deck[a].face = Deck[b].face;
		Deck[a].suit = Deck[b].suit;
		Deck[a].pointsValue = Deck[b].pointsValue;
		Deck[a].cardStatus = Deck[b].cardStatus;

		Deck[b].face = Deck[52].face;
		Deck[b].suit = Deck[52].suit;
		Deck[b].pointsValue = Deck[52].pointsValue;
		Deck[b].cardStatus = Deck[52].cardStatus;
	}

	cout << endl << "Shufflin deck..." << endl << endl;
    usleep(3000000);
	for (int i = 0; i < howManyDeck; i++)
	{
		for (int x = 0; x < 52; x ++)
		{
			//cout << Deck[x].face << " of " << Deck[x].suit << "   " << Deck[x + 1].face << " of " << Deck[x + 1].suit << "  " << Deck[x + 2].face << " of " << Deck[x + 2].suit << "   " << Deck[x + 3].face << " of " << Deck[x + 3].suit << endl;
			//cout << Deck[x].face << " of " << Deck[x].suit << " : Value of " << Deck[x].pointsValue << " : " << Status[Deck[x].cardStatus] << endl;
            s.push(Deck[x].pointsValue);
		}
	}
    // while(!s.isEmpty())
    // {
    //     // print peek element in stack
    //     cout<<s.peek()<<" "<<endl;
    //     // remove peek element in stack
    //     s.pop();
    // }
    dealersFaceDownCard=s.pop();//dealers face down card
    cout<<"Dealers cards dealt!\n"<<endl;
    usleep(1000000);
    cout<<"Dealers face up card is: "<<s.peek();
    cout<<endl;
    cout<<endl;
    dealersFaceUpCard=s.pop();//dealers face up card
    usleep(1000000);
    cout<<"Player cards dealt!\n"<<endl;
    cout<<s.peek();
    cout<<endl;
    cardCount+=s.pop();
    cout<<s.peek();
    cout<<endl;
    cardCount+=s.pop();
    if (cardCount==21)
        cout<<"Player wins\n";
    //cout<<cardCount<<endl;
    hitOrStand:
        if(cardCount==21){
            cout<<"Blackjack!"<<endl;
            exit(0);
        }
        else if(cardCount<=21){
            cout<<"Hit or Stand?\n"<<endl;
            cin>>playerinput;
        }
        else{
            cout<<"Over 21\n";
            cout<<"Player bust!"<<endl;
            cout<<cardCount<<endl;
            exit(0);
        }
    switch (playerinput){
        case 'h':
            cout<<s.peek()<<endl;
            cardCount+=s.pop();
            cout<<cardCount<<endl;
            goto hitOrStand;
        case 's':
            cout<<"Player stands!\n";
            goto dealerCards;

    default:
        cout<<"Invalid command";
        break;
    }
    dealerCards:
        dealersCardTotal=dealersFaceDownCard+dealersFaceUpCard;
        cout<<"Dealers cards are: "<<endl;
        cout<<dealersFaceDownCard<<" "<<dealersFaceUpCard<<endl;
        checkpoint:
            if(dealersCardTotal>21){
                cout<<"Dealer bust, player wins!\n";
                exit(0);
            }
            if(dealersCardTotal>=17&&dealersCardTotal<=21){
                if (dealersCardTotal==cardCount){
                    cout<<"Tie\n";
                }
                else if (dealersCardTotal>cardCount){
                    cout<<"Dealer wins\n";
                }
                else if (cardCount>dealersCardTotal){
                    cout<<"Player wins\n";
                }
            }
            else if (dealersCardTotal<=16){
                cout<<s.peek()<<endl;
                dealersCardTotal+=s.pop();
                cout<<dealersCardTotal<<endl;
                goto checkpoint;
            }
}
    // while (cardCount<=21){
    //     if (playerinput=='h')
    //         {
    //             cout<<s.peek()<<endl;
    //             cardCount+=s.pop();
    //             cout<<cardCount<<endl;
    //             continue;
    //         }
    //         else if (playerinput=='s')
    //             {
    //                 cout<<"no more cards"<<endl;
    //                 break;
    //             }
    // }

