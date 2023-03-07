#include<iostream>
#include<cstdlib>
#include<unordered_set>
#include<ctime>
#include<vector>
#include<conio.h>
using namespace std;
#include<string>
class Game
{
    private:
        int arr[4][4], tries,matrix_size;
        string name ;

    public:
        Game(string name,int tries,int matrix_size)
        {
            this->name=name;
            this->tries=tries;
            this->matrix_size;
        }
        int get_tries()
        {
            return tries;
        }
        void tries_updation()
        {
            tries--;
            if(tries==0)
                End_Of_Game();
        }
        void create_Game();
        void display_Game();

        // scan code operations
        int up_key();
        int down_key();
        int left_key();
        int right_key();
        vector<int> detect_pointer();

        // getInput
        int read_key();

        // result

        void End_Of_Game();
        int Winning_Condition();

};
void Game:: create_Game()
{
    int n=15,i,j,num;
    unordered_set<int> s;
    for(int i=0;i<n;i++)
        s.insert(i+1);
    srand(time(NULL));
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            while(!s.empty())
            {
                 num = rand()%(n+1);
                if(s.find(num)!=s.end())
                 {
                      arr[i][j]=num;
                      s.erase(num);
                      break;
                 }
                else
                   continue;
            }

        }
       arr[3][3]=0;
    }

}
void Game:: display_Game()
{
    cout<<endl<<"Hello "<<name<<" ,   Remaining moves: "<<tries<<endl<<endl;

    for(int i=0;i<12;i++)
        cout<<"--";
    cout<<"\n";
    for(int i=0;i<4;i++)
    {
        cout<<"|";
        for(int j=0;j<4;j++)
        {
                if(arr[i][j]!=0)
                {
                    if(arr[i][j]/10==0)
                      cout<<" "<<arr[i][j]<<" |  ";
                    else
                      cout<<" "<<arr[i][j]<<"|  ";
                }
                else
                     cout<<"  "<<" |  ";


        }
        cout<<"\n";
    }
    for(int i=0;i<12;i++)
        cout<<"--";
}
int Game::Winning_Condition()
{
    int n=16,flag=0;
    int i,j,nums[16],k=-1;
    for(int i=0;i<n;i++)
        nums[i]=i+1;
    nums[n-1]=0;
    for(i=0;i<matrix_size;i++)
    {
        for(j=0;j<matrix_size;j++)
        {
            k++;
            if(arr[i][j]==nums[k])
                continue;
            else
            {
                 flag=1;
                 return 1;
            }
        }
    }
    if(flag==0)
    {
      system("cls");
      cout<<"\n\n\n\n\n\n";
      cout<<" PLAYER : "<<name<<"\n\n\n   YOU WON!"<<endl<<endl;
      getch();
      return 0;
    }
}
void Game:: End_Of_Game()
{
    system("cls");
    cout<<"\n\n\n\n\n\n";
    cout<<" PLAYER : "<<name<<"\n\n\n   YOU LOOSE!"<<endl<<endl;
    getch();
    
}
vector<int> Game:: detect_pointer()
{
    vector<int>index;
    for(int i=0;i<4;i++)
    {    for(int j=0;j<4;j++)
          {
              if(arr[i][j]==0)
            {
                index.push_back(i);
                index.push_back(j);
                return index;
            }
          }
    }
    return index;
}
int Game:: read_key()
{
    int ch;
    ch= _getch();
    if(ch==0)
        ch=_getch();
    return ch;
}
int Game:: up_key()
{
    int temp;
    vector<int> index;
   index= detect_pointer();
   if(index[0]==3)  // Failure of operation
        return 0;
   else
   {
        int i=index[0];
        int j= index[1];
        // swap
        temp= arr[i][j];
        arr[i][j]= arr[i+1][j];
        arr[i+1][j]=temp;
        return 1;

   }

}

int Game:: down_key()
{
    int temp;
    vector<int> index;
    index= detect_pointer();
   if(index[0]==0)  // Failure of operation
        return 0;
   else
   {
        int i=index[0];
        int j= index[1];
        // swap
        temp= arr[i][j];
        arr[i][j]= arr[i-1][j];
        arr[i-1][j]=temp;
        return 1;

   }

}

int Game:: left_key()
{
    int temp;
    vector<int> nullindex;
    nullindex= detect_pointer();
   if(nullindex[1]==3)  // Failure of operation
        return 0;
   else
   {
        int i=nullindex[0];
        int j= nullindex[1];
        // swap
        temp= arr[i][j];
        arr[i][j]= arr[i][j+1];
        arr[i][j+1]=temp;
        return 1;

   }

}

int Game:: right_key()
{
    int temp;
    vector<int> nullindex;
    nullindex= detect_pointer();
   if(nullindex[1]==0)  // Failure of operation
        return 0;
   else
   {
        int i=nullindex[0];
        int j= nullindex[1];
        // swap
        temp= arr[i][j];
        arr[i][j]= arr[i][j-1];
        arr[i][j-1]=temp;
        return 1;

   }
}
int main()
{
    string name;
    int tries=10,valid,remaning;
    cout<<endl<<"Player Name :  ";
    getline(cin,name);
    cout<<endl<<endl;
    Game player(name,tries,4);
    player.create_Game();
    player.display_Game();

    while( player.Winning_Condition())
    { 
       remaning=player.get_tries();
         if(remaning==0)
        {
             player.End_Of_Game();
             exit(0);
        }
        int key=player.read_key();
        cout<<key;
        switch(key)
        {
            case 72 :
                    valid= player.up_key();
                    if(valid==1)
                        player.tries_updation();
                    system("cls");
                    player.display_Game();
                    break;
            case 80 :
                    valid= player.down_key();
                        if(valid==1)
                        player.tries_updation();
                    system("cls");
                    player.display_Game();
                    break;
            case 75 :
                    valid= player.left_key();
                        if(valid==1)
                        player.tries_updation();
                    system("cls");
                    player.display_Game();
                    break;
            case 77:
                    valid = player.right_key();
                        if(valid==1)
                        player.tries_updation();
                    system("cls");
                    player.display_Game();
                    break;
            case 101:
                    exit(0);

        }
    }
}
