#include <iostream>
#include <vector>
#include <time.h>
using namespace std;


void greet()
{
  cout << "=====================\n";
  cout << "Welcom to Hangman!\n";
  cout << "=====================\n";
  cout << "Instructions: Save your friend from being hanged by guessing the letters in the SecretWord.\n";
}

void display_misses(int misses)
{
  if(misses==0)
  {
    cout<<"  +---+ \n";
    cout<<"  |   | \n";
    cout<<"      | \n";
    cout<<"      | \n";
    cout<<"      | \n";
    cout<<"      | \n";
    cout<<" ========= \n";
  }
  else if(misses==1)
  {
    cout<<"  +---+ \n";
    cout<<"  |   | \n";
    cout<<"  O   | \n";
    cout<<"      | \n";
    cout<<"      | \n";
    cout<<"      | \n";
    cout<<" ========= \n";
  }
  else if(misses==2)
  {
    cout<<"  +---+ \n";
    cout<<"  |   | \n";
    cout<<"  O   | \n";
    cout<<"  |   | \n";
    cout<<"      | \n";
    cout<<"      | \n";
    cout<<" ========= \n";
  }
  else if(misses==3)
  {
    cout<<"  +---+ \n";
    cout<<"  |   | \n";
    cout<<"  O   | \n";
    cout<<" /|   | \n";
    cout<<"      | \n";
    cout<<"      | \n";
    cout<<" ========= \n";
  }
  else if(misses==4)
  {
    cout<<"  +---+ \n";
    cout<<"  |   | \n";
    cout<<"  O   | \n";
    cout<<" /|\\  | \n";
    cout<<"      | \n";
    cout<<"      | \n";
    cout<<" ========= \n";
  }
  else if(misses==5)
  {
    cout<<"  +---+ \n";
    cout<<"  |   | \n";
    cout<<"  O   | \n";
    cout<<" /|\\  | \n";
    cout<<" /    | \n";
    cout<<"      | \n";
    cout<<" ========= \n";
  }
  else if(misses==6)
  {
    cout<<"  +---+ \n";
    cout<<"  |   | \n";
    cout<<"  O   | \n";
    cout<<" /|\\  | \n";
    cout<<" / \\  | \n";
    cout<<"      | \n";
    cout<<" ========= \n";
  }

}


void display_status(vector<char> incorrect, string answer)
{
  cout<<"Incorrect Guesses: \n";

  for(int i = 0; i<incorrect.size(); i++)
  {
    cout<<incorrect[i]<<" ";
  }

  cout<<"\nsecretword:\n";

  for(int i = 0; i<answer.length(); i++)
  {
    cout<<answer[i]<<" ";
  }
}


void end_game(string answer, string secretword)
{
  if(answer==secretword)
  {
    cout<<"You saved the person from being hanged\n";
    cout<<"Congratulations!\n";
  }
  else
  {
    cout<<"Failed! The man is hanged!\n";
  }
}



int main()
{
  greet();
  
  srand ( time(NULL) );

  string predefinedList[5] = { "codingcpp", "killerman", "adulthood", "technique", "abilities" };
  int RanIndex = rand() % 5;
  string secretword = predefinedList[RanIndex];
  string answer = "_________";
  int misses = 0;
  vector<char> incorrect;
  bool guess = false;
  bool nextTrial = true;
  char letter;


  while(nextTrial && (answer!=secretword && misses < 7))
  {
    display_misses(misses);
    display_status(incorrect, answer);

    cout<<"\n\nPlease enter your guess: ";
    cin>>letter;

    for(int i = 0; i<secretword.length(); i++)
    {
      if(letter==secretword[i])
      {
        answer[i] = letter;
        guess = true;
      }
    }
    if(guess)
    {
      cout<<"\nCorrect!\n";
    }
    else
    {
      cout<<"\nIncorrect! Another portion of the person has been drawn.\n";
      incorrect.push_back(letter);
      misses++;
    }
    guess = false;

    if (answer == secretword || misses >= 7) {
        string userChoice;
        
        end_game(answer, secretword);

        cout<<"\nDo you want to play again: Yes(y) or No(n): ";
        cin>>userChoice;

        if (userChoice == "y") {

            nextTrial = true;
            answer = "_________";
            misses = 0;
            incorrect.clear();

        } else if (userChoice == "n") {


        } else {

            cout<<"\nyou have entered wrong input\n";

        }
    }
  }

    cout<<"\nThank you for paying...";
  
  return 0;
}