#include<vector>
using namespace std;
class Solution {
public:
   bool isValidSudoku(vector<vector<char>>& board) {
				        
   	
 		int row_num[9][9]={0},col_num[9][9]={0},box_num[9][9]={0};

		for(int i=0;i<board.size();i++)
			for(int j=0;j<board.size();j++)
			{

				int num = board[i][j]-'0';
				int box = i/3*3+j/3;

				if(row_num[i][num]||col_num[j][num]||box[box][num])
					return false;

				row_num[i][num]=col_num[j][num]=box[box][num]=1;


					

			}
			
	





	   
			
				        
				        
	return true;				        
   }
};
