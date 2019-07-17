#include <string>
using namespace std;
int findMinStep(string board, string hand) {
        
        int times = 0;
        for(int i=0;i<hand.size()&&!board.empty();i++)
        {
            int max_index = 0;
            int max_length = 0;
            int count = 0;
            char repeaet = hand[i];
            int j;
            for(j=0;j<board.size();j++)
            {
                
                if(board[j]==repeaet)
                    count++;
                else
                {
                    if(count>max_length)
                    {
                        max_length = count;
                        max_index = j-max_length;
                    }

                    count=0;
                    
                }
            }
            if(count>max_length)
            {
                        max_length = count;
                        max_index = j-max_length;
            }

            if(max_length>=2)
            {
                board.erase(max_index,max_length);
            }
            else if(max_length>0)
            {
                board.insert(max_index,1,repeaet);
                times++;
            }
            

        }



        return board.empty()?times:-1;
        
}


int main()
{
    string board("WWRRBBWW");
    string hand("WRBRW");
    findMinStep(board,hand);
    return 0;
}