# include<iostream>
# include<graphics.h>
using namespace std;

void scan_fill(int x[], int y[], int edges){
    int y_min = y[0];
    int y_max = y[0];

    
    for (int i=0 ; i<edges ; i++){ // Took y_min and y_max
        if(y[i]>y_max){
            y_max = y[i];
        }
        if(y[i]<y_min){
            y_min = y[i];
        }
    }


    for (int j=y_min ; j<=y_max  ; j++){
        int insertPoints[edges], count = 0;

        for (int k=0 ; k<edges ; k++){ // Inserting intersection points
            int next = (k+1)%edges;
            if((y[k]>=j && y[next]<j)||(y[k]<j && y[next]>=j)){
                insertPoints[count++] = x[k] + ((x[next]-x[k])/(y[next]-y[k]))*(j-y[k]);
            }
        }

        int up,m;
        for (int l=1 ; l<count ; l++){ // Sorting
            up = insertPoints[l];
            m = l-1;
            while((m>=0)&&(insertPoints[m]>up)){
                insertPoints[m+1] = insertPoints[m];
                m = m-1;
            }
            insertPoints[m+1] = up;
        }

        for (int m=0 ; m<count ; m=m+2){
            line(insertPoints[m], j, insertPoints[m+1], j);
        }


    }

}



int main(){
    initwindow(1200,800,"Graphics");
    int x1[] = {100,700,500};
    int y1[] = {200,400,600};
    
    line(100,200,700,400);
    line(700,400,500,600);
    line(500,600,100,200);
    
    scan_fill(x1, y1, 3);
    
    
    getch();
    return 0;
}
