class Spreadsheet {
    vector<vector<int>> spreadsheet;

    int getRow(string &cell , int startInd) {
        int row = 0;

        for(int i = startInd ; i < cell.length() ; ++i)
            row = row * 10 + (cell[i] - '0');

        return row;
    }

    void setValue(string &cell , int value) {
        int column = cell[0] - 65;
        int row = getRow(cell , 1);

        spreadsheet[row-1][column] = value;
    }

    int get(string &cell) {
        int column = cell[0] - 65;
        int row = getRow(cell , 1);

        return spreadsheet[row-1][column];
    }
public:
    Spreadsheet(int rows) {
        spreadsheet.assign(rows , vector<int>(26 , 0));
    }
    
    void setCell(string cell, int value) {
        setValue(cell , value);
    }
    
    void resetCell(string cell) {
        setValue(cell , 0);
    }
    
    int getValue(string formula) {
        string s1 = "" , s2 = "";
        bool flag = false;

        for(int i = 1 ; i < formula.length() ; ++i)
        {
            if(formula[i] == '+') {
                flag = true;
                continue;
            }

            if(!flag)
                s1 += formula[i];
            else
                s2 += formula[i];
        }
        int val1 = 0 , val2 = 0;

        if(isalpha(s1[0]))
         val1 = get(s1);
        else
         val1 = getRow(s1 , 0);

        if(isalpha(s2[0]))
         val2 = get(s2);
        else
         val2 = getRow(s2 , 0);

        return val1 + val2;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */
