#include <vector>
#include <string>

using namespace std;

const int MAX_ROWS = 512;
const int MAX_COLS = 512;

int moveNext(int nexti, int nextj, int N, int M, vector<string> & grid, int m[][MAX_COLS]){
    int counter = 0;

    if(nexti < 0 || nextj >= M) //outside boundaries
        return 0;

    if(grid[nexti].at(nextj) == '1') //not free cell
        return 0;

    if(nexti == 0 && nextj == M-1) // the end, 1 path found
        return (1 % 1000003);
    else{
        if(m[nexti][nextj] < 0){ //subpath not travelled
            counter = (moveNext(nexti-1,nextj,N,M,grid,m) % 1000003); //TOP
            counter += (moveNext(nexti,nextj+1,N,M,grid,m) % 1000003); //RIGHT
            m[nexti][nextj] = counter % 1000003;
        }else
            counter = m[nexti][nextj] % 1000003;
    }

    return counter % 1000003;
}


int count_the_paths(vector<string> grid) {

    int counter = 0;
    int N = grid.size();//rows
    if(N <= 0)
        return 0;

    int M = grid[0].length();//cols
    if(M <= 0)
        return 0;

    if(N == 1 && M == 1)
        return 1;//single cell in grid
    if((N == 1 && M == 2) || (N == 2 && M == 1))
        return 1;//two cells in grid (end and start)

    int m[MAX_ROWS][MAX_COLS];//matrix for pathsCount

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            m[i][j]=-1;
        }
    }

    m[N-1][0] = 0; //start
    m[0][M-1] = 0; //end

    counter = (moveNext(N-2,0,N,M,grid,m)% 1000003); //move TOP
    counter += (moveNext(N-1,1,N,M,grid,m) % 1000003); //move RIGHT

    /*for(int ii=0;ii<N;ii++){
        for(int jj=0;jj<M;jj++){
            cout<<" "<< m[ii][jj] <<" ";
        }
        cout<< endl;
    }*/

    return counter % 1000003;
}


int main(){

    string str1 = "";
    /*string str2 = "";
    string str3 = "";
    string str4 = "";
    string str5 = "";

    for(int i=0;i<512;i++){
        str1.append("0");
        str2.append("0");
        str3.append("0");
        str4.append("0");
        str5.append("0");
    }
    string arr[] = {str1,str2,str3,str4,str5};

    std::vector<string> grid (arr, arr + sizeof(arr) / sizeof(string) );*/

    vector<string> grid;
    for(int i=0;i<512;i++){
        for(int j=0;j<512;j++){
            str1.append("0");
        }
        grid.push_back(str1);
    }

    int temp = count_the_paths(grid);
    cout<< "No. of possible paths: " << temp ;

    return true;
}


