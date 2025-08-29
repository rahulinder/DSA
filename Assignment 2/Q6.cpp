#include<iostream>
using namespace std;

const int row=8;
const int column=8;
int matrix[row][column]={0};

void addition() {
    cout<<endl<<endl<<"----------Added----------\n";
    for(int i=0;i<8;i++) {
        for(int j=0;j<8;j++) {
            cout<<matrix[i][j]+matrix[j][i]<<"   ";
        }
        cout<<endl;
    }
};


void transpose() {
    cout<<endl<<endl<<"----------Transposded----------\n";
    for(int i=0;i<8;i++) {
        for(int j=0;j<8;j++) {
            cout<<matrix[j][i]<<"   ";
        }
        cout<<endl;
    }
};

void multiply() {
    int multi[row][column];
    cout<<endl<<endl<<"----------Multiplied----------\n";
    for(int i=0;i<8;i++) {
        for(int j=0;j<8;j++){
            
        multi[i][j]=matrix[i][j] * matrix[j][i];
        cout<<multi[i][j]<<"\t";
        }
        cout<<endl;
    }
};

int main() {

    int r,c,val;

    for(int i=0;i<8;i++) {
        
        cin>>r>>c>>val;

        matrix[r][c]=val;
    }

    cout<<"----------Filled values----------\n";

    for(int i=0;i<8;i++) {
        for(int j=0;j<8;j++) {
            cout<<matrix[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<"Choose option :\n1)Transpose\n2)Addition\n3)Multiplication\nEnter 1-3 :";
    
    int opt;
    cin>>opt;

    switch(opt) {
        case 1:
      transpose();
        break;

        case 2:
        addition();
        break;

        case 3:
        multiply();
        break;

        case 4:
        transpose();
        addition();
        multiply();
        break;

        default:
        cout<<"\n\n----------Invalid Output----------" ;
        break;
    }
    
    return 0;
}