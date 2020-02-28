#include <iostream>

using namespace std;

/*/
   ASCII:
   97 to 122 lower case
   65 to 90 upper case
   32 diff
/*/

class String {
private:
    char* buffer = new char();
    unsigned int sz = 0;
    
public:
    
//A)
    String() {}
    String(char x) {
        buffer = &x;
        sz++;
    }
    String(const char* x) {
        while (x[sz] != NULL){
            sz++;
        }
        buffer = new char(sz);
        memcpy(buffer , x , sz);
    }

//B) ==========================
    void operator = (const String* s) {
        String* x = new String(s->buffer);
        delete this->buffer;
        this->buffer = x->buffer;
        this->sz = x->sz;
    }

    void operator = (char* s) {
        String* x = new String(s);
        delete this->buffer;
        this->buffer = x->buffer;
        this->sz = x->sz;
    }

//C) ===========================
    String operator+(char* c) {
        String* p = new String(c);
        String a = String();

        a.sz = p->sz + this->sz;

        a.buffer = new char(a.sz);
        memcpy(a.buffer, this->buffer, this->sz);
        memcpy(a.buffer + this->sz, p->buffer, p->sz);
        delete p;
        return a;
    }


//D) ============================
    void operator +=(const String* s) {
        String* a = new String();

        a->sz = s->sz + this->sz;

        a->buffer = new char(a->sz);
        delete this->buffer;
        memcpy(a->buffer, this->buffer, this->sz);
        memcpy(a->buffer + this->sz, s->buffer, s->sz);
        this->buffer = a->buffer;
        this->sz = a->sz;
    }

//E)
    unsigned int size() {
        return this->sz;
    }
    
//F)
    unsigned int index(char c) {
        for (unsigned int i = 0; i < this->sz; i++) {
            if (*(this->buffer + i) == c) {
                return i + 1;
            }
        }
        return 0;
    }

//G)
    String* toUpCase(unsigned int begin, unsigned int end) {
        String* s = new String(this->buffer);
        begin--;
        if (end > s->sz)
            end = s->sz;
        for (int i = begin; i < end ; i++) {
            if (s->buffer[i] >= 97 && s->buffer[i] <= 122) {
                s->buffer[i] = char(int(s->buffer[i]) - 32);
            }
        }
        return s;
    }

//H)
    String* toLowCase(unsigned int begin, unsigned int end) {
        String* s = new String(this->buffer);
        begin--;
        if (end > s->sz)
            end = s->sz;
        for (int i = begin; i < end; i++) {
            if (s->buffer[i] >= 65 && s->buffer[i] <= 90) {
                s->buffer[i] = char(int(s->buffer[i]) + 32);
            }
        }
        return s;
    }

//I)
    String* toogle(unsigned int begin, unsigned int end) {
        String* s = new String(this->buffer);
        begin--;
        if (end > s->sz)
            end = s->sz;
        for (unsigned int i = begin; i < end; i++) {
            if (s->buffer[i] >= 97 && int(s->buffer[i]) <= 122) {
                s->buffer[i] = char(int(s->buffer[i]) - 32);
            }
            else if (int(s->buffer[i]) >= 65 && int(s->buffer[i]) <= 90) {
                s->buffer[i] = char(int(s->buffer[i]) + 32);
            }
        }
        return s;
    }

//J) ==============================
    char operator[] (int i) {
        if (i - 1 > sz) {
            return NULL;
        }
        else {
            return buffer[i - 1];
        }
    }

//K) ==============================
    bool operator== (String* s) {

        if (this->sz != s->sz)
            return false;

        String* x = new String(this->buffer);
        String* y = new String(s->buffer);

        x = x->toLowCase(1, x->sz);
        y = y->toLowCase(1, y->sz);

        unsigned int len = x->sz;

        for (unsigned int i = 0; i < len; i++){
            if (x->buffer[i] != y->buffer[i]) {
                delete x, y;
                return false;
            }
        }
        delete x, y;
        return true;
    }

    bool operator != (String s) {
       
        String x = String(this->buffer);
        String y = String(s.buffer);

        x = x.toLowCase(1, x.sz);
        y = y.toLowCase(1, y.sz);

        unsigned int xcnt = 0;
        unsigned int ycnt = 0;

        for (unsigned int i = 0; i < x.sz; i++){
            xcnt += int(x.buffer[i]);
        }
        for (unsigned int i = 0; i < y.sz; i++){
            ycnt += int(y.buffer[i]);
        }

        if (xcnt != ycnt)
            return true;
        else
            return false;
    }

    bool operator > (String s) {
        String x = String(this->buffer);
        String y = String(s.buffer);

        x = x.toLowCase(1, x.sz);
        y = y.toLowCase(1, y.sz);

        unsigned int len = 0;

        len = (x.sz > y.sz) ? y.sz : x.sz;

        for (unsigned int i = 0; i < len; i++) {

            if (int(x.buffer[i]) > int(y.buffer[i]))
                return false;

            else if (int(x.buffer[i]) < int(y.buffer[i]))
                return true;
        }

        if (x.sz > y.sz)
            return true;
        else
            return false;
    }

    bool operator < (String s) {
        String x = String(this->buffer);
        String y = String(s.buffer);

        x = x.toLowCase(1, x.sz);
        y = y.toLowCase(1, y.sz);

        unsigned int len = 0;

        len = (x.sz > y.sz) ? y.sz : x.sz;

        for (unsigned int i = 0; i < len; i++) {

            if (int(x.buffer[i]) < int(y.buffer[i]))
                return false;

            else if (int(x.buffer[i]) > int(y.buffer[i]))
                return true;
        }

        if (x.sz < y.sz)
            return true;
        else
            return false;
    }

    bool operator >= (String s) {
        String x = String(this->buffer);
        String y = String(s.buffer);

        x = x.toLowCase(1, x.sz);
        y = y.toLowCase(1, y.sz);

        unsigned int len = 0;

        len = (x.sz > y.sz) ? y.sz : x.sz;

        for (unsigned int i = 0; i < len; i++) {

            if (int(x.buffer[i]) > int(y.buffer[i]))
                return false;

            else if (int(x.buffer[i]) < int(y.buffer[i]))
                return true;
        }

        if (x.sz >= y.sz)
            return true;
        else
            return false;
    }

    bool operator <= (String s) {
        String x = String(this->buffer);
        String y = String(s.buffer);

        x = x.toLowCase(1, x.sz);
        y = y.toLowCase(1, y.sz);

        unsigned int len = 0;

        len = (x.sz > y.sz) ? y.sz : x.sz;

        for (unsigned int i = 0; i < len; i++) {

            if (int(x.buffer[i]) < int(y.buffer[i]))
                return false;

            else if (int(x.buffer[i]) > int(y.buffer[i]))
                return true;
        }

        if (x.sz <= y.sz)
            return true;
        else
            return false;
    }

//L)

    friend ostream& operator<<(ostream& stream, const String* s) {

        for (unsigned int i = 0; i < s->sz; i++) {
            stream << *(s->buffer + i);
        }

        return stream;
    }

    friend istream& operator>>(istream& stream, String* s) {
        char* p = new char();
        stream >> p;
        String* x = new String(p);
        s->buffer = x->buffer;
        s->sz = x->sz;
        return stream;
    }
};

int main() {
    int begin, end = 0;
    char i = 0;
    bool run = true;
    bool check;
    char* input = new char();
    char c = char();
    String* stg1 = new String();
    String* stg2 = new String();
    while (run) {
        cout << "STRING A: " << stg1 << endl;
        cout << "STRING B: " << stg2 << endl;
        cout << "ITEM: ";
        cin >> i;
        switch (i){
        case 'a':
            cout << "CRIAR STRING: " << endl;

            cout << "STRING A: ";
            cin >> stg1;

            cout << "STRING B: ";
            cin >> stg2;

            break;
            /*
        case 'b':
            cout << "ATRIBUICAO A = B: " << endl;

            stg1 = stg2;

            break;

    
            
        case 'c':
            cout << "CONCATENACAO A = B + '' : " << endl;
            cout << "NOVA STRING:";
            cin >> input;

            stg1 = stg2 + input;

            break;
            
        case 'd':
            cout << "ATRIBUICAO A += B: " << endl;

            stg1 += stg2;

            break;
            */

        case 'e':
            cout << "TAMANHO DA STRING A: " << stg1->size() << endl;
            cout << "TAMANHA DA STRING B: " << stg2->size() << endl;
            break;

        case 'f':
            cout << "INDEX: ";
            cin >> c;
            cout << "INDEX NA STRING A: " << stg1->index(c) << endl;
            cout << "INDEX NA STRING B: " << stg2->index(c) << endl;

            break;

        case 'g':
            cout << "METODO UPCASE: " << endl;
            cout << "COMECO: ";
            cin >> begin;
            cout << "FIM: ";
            cin >> end;

            stg1 = stg1->toUpCase(begin, end);
            stg2 = stg2->toUpCase(begin, end);

            break;

        case 'h':
            cout << "METODO LOWERCASE: " << endl;
            cout << "COMECO: ";
            cin >> begin;
            cout << "FIM: ";
            cin >> end;

            stg1 = stg1->toLowCase(begin, end);
            stg2 = stg2->toLowCase(begin, end);

            break;

        case 'i':
            cout << "METODO TOGGLE: " << endl;
            cout << "COMECO: ";
            cin >> begin;
            cout << "FIM: ";
            cin >> end;

            stg1 = stg1->toogle(begin, end);
            stg2 = stg2->toogle(begin, end);

            break;
            /*
        case 'j':
            cout << "RETORNAR char = string[i]: " << endl;
            cout << "POSICAO:";
            cin >> begin;

            c = stg1[begin];
            cout << "CHAR NA POSICAO " << begin << ": " << c << endl;

            c = stg2[begin];
            cout << "CHAR NA POSICAO " << begin << ": " << c << endl;

            break; 
            */

        case 'k':
            cout << "OPERADORES LOGICOS: " << endl;

            check = stg1 == stg2;
            cout << "A == B: " << boolalpha << check << endl;

            check = stg1 != stg2;
            cout << "A != B: " << boolalpha << check << endl;

            check = stg1 > stg2;
            cout << "A > B: " << boolalpha << check << endl;

            check = stg1 < stg2;
            cout << "A < B: " << boolalpha << check << endl;

            check = stg1 >= stg2;
            cout << "A >= B: " << boolalpha << check << endl;

            check = stg1 <= stg2;
            cout << "A <= B: " << boolalpha << check << endl;

            break;

        case 'l':
            cout << "SOBRESCREVER CIN: " << endl;
            cout << "STRING A:  ";
            cin >> stg1;
            cout << "STRING B:  ";
            cin >> stg2;

            cout << "SOBRESCREVER COUT: " << endl;
            cout << "STRING A:  " ;
            cout << stg1 << endl;
            cout << "STRING B:  " ;
            cout << stg2 << endl;
            break;

        default:
            run = false;
            break;
        }
        cout << endl;
        cout << "---------------------------------------------------------------------";
        cout << endl;
        cout << endl;
    }

    return 0;
}