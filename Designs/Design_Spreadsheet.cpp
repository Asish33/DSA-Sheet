class Spreadsheet {
public:
    vector<vector<int>>mainer;
    Spreadsheet(int rows) {
        mainer.resize(26,vector<int>(rows,0));
    }

    void setCell(string cell, int value) {
        char alpha = cell[0];
        int index = stoi(cell.substr(1));
        mainer[alpha-'A'][index-1]=value;
    }

    void resetCell(string cell) {
        char alpha = cell[0];
        int index = stoi(cell.substr(1));
        mainer[alpha-'A'][index-1]=0;
    }

    int getValue(string formula) {
        string x = "";
        string y = "";
        int i=1;
        for(;i<formula.size();i++){
            if(formula[i]=='+'){
                break;
            }
            x+=formula[i];
        }
        y=formula.substr(i+1);
        int xvalue=0,yvalue=0;
        if(isalpha(x[0])){
            int index = stoi(x.substr(1));
            xvalue = mainer[x[0]-'A'][index-1]; 
        }
        else xvalue=stoi(x); 

        if(isalpha(y[0])){
            int index = stoi(y.substr(1));
            yvalue = mainer[y[0]-'A'][index-1];
        }
        else yvalue=stoi(y);
         
        return xvalue+yvalue;
    }
};
