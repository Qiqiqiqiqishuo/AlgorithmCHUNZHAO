bool lemonadeChange(int* bills, int billsSize){
    if (billsSize == 0)     return true;
    int count5 = 0;
    int count10 = 0; 
    for (int i=0; i<billsSize; i++) {
        if (bills[i] == 5) {
            count5++;
        }
        if (bills[i] == 10) {
            count5--;
            count10++;
        }
        if (bills[i] == 20) {
            if (count10 > 0) {
                count10--;
                count5--;
            } else {
                count5 -= 3;
            }
        }
        if (count5 < 0) {
            return false;
        }
    }
    return true;

}