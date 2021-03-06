const int MATRIX_SIZE = 5;

void rotate(int matrix[][MATRIX_SIZE], int n)
{     
    int countLayers = n/2;
    for(int layer=0; layer < countLayers; layer++)
    {
        int topLeftPos = layer;
        int bottomRightPos = n-layer-1;
        int diff = 0;
        for(int i= topLeftPos; i<bottomRightPos; i++)
        {   
            //int diff=i-topLeftPos;   
            //save top-left
            int temp=matrix[topLeftPos][i];
            //bottom-left ->top-left
            matrix[topLeftPos][i]=matrix[bottomRightPos-diff][topLeftPos];
            //bottom-right -> bottom-left
            matrix[bottomRightPos-diff][topLeftPos]=matrix[bottomRightPos][bottomRightPos-diff];
            //top-right -> bottom-right
            matrix[bottomRightPos][bottomRightPos-diff]=matrix[i][bottomRightPos];
            //top-left -> top-right
            matrix[i][bottomRightPos]=temp; 
            diff++;
        }
    }
}


void printMatrix(int matrix[][MATRIX_SIZE], int size){
     for(int i=0;i<size;i++)
    {
         for(int j=0;j<size;j++)
         {
              cout<< matrix[i][j]<<" ";   
         }   
         cout<<endl;
    }
     
}

int main()
{
    int matrix[][MATRIX_SIZE] = {{3,6,7,8,9},{3,1,2,3,1},{8,4,5,6,0},{7,7,8,9,2},{1,6,5,4,3}};
    rotate(matrix, MATRIX_SIZE);
    printMatrix(matrix, MATRIX_SIZE);
    return 0;
}