#include <bits/stdc++.h>
using namespace std;


struct DONTHUC{
	int somu;
	double heso;
	
	DONTHUC(double _heso = 0,int _somu=0){
		heso = _heso;
		somu  = _somu;
	}
	
	DONTHUC& operator = (const DONTHUC &rhs){
		if (this == &rhs) return *this;
		this->heso = rhs.heso;
		this->somu = rhs.somu;
		return *this;
	}
};


struct Node{
	DONTHUC* data;
	Node* next;
	
	Node(DONTHUC* _data = nullptr){
		this->data = _data;
		this->next = nullptr;
	}
	
};

struct DATHUC{
	Node* head;
	Node* tail;
	DATHUC(){
		this->head = nullptr;
		this->tail = nullptr;
	}
};

void Nhap(DATHUC &B, double heso, int somu){
    DONTHUC* temp = new DONTHUC(heso,somu);
    Node* node = new Node(temp);
    if (B.head == nullptr){
        B.head = node;
        B.tail = node;
    }
    else{
        B.tail->next = node;
        B.tail = node;
    }
}

void Xuat(DATHUC B){
    Node* temp = B.head;
    
    if (temp->data->heso == 0);
    else if (temp->data->heso == 1) cout << "x^" << temp->data->somu;
    else if (temp->data->heso == -1) cout << "-x^" << temp->data->somu;
    else {
        if (temp->data->somu == 0) cout << temp->data->heso;
        else if (temp->data->somu == 1) cout << temp->data->heso << "x";
        else cout << temp->data->heso << "x^" << temp->data->somu;
    }
    
    temp = temp->next;
    while (temp != nullptr){
        if (temp->data->heso > 0) {
            if (temp->data->heso == 1) {
                if (temp->data->somu == 0) cout << "+" << temp->data->heso;
                else if (temp->data->somu == 1) cout << "+x";
                else cout << "+x^" << temp->data->somu;
            } else {
                if (temp->data->somu == 0) cout << "+" << temp->data->heso;
                else if (temp->data->somu == 1) cout << "+" << temp->data->heso << "x";
                else cout << "+" << temp->data->heso << "x^" << temp->data->somu;
            }
        } else if (temp->data->heso == 0) continue;
        else {
            if (temp->data->heso == -1) {
                if (temp->data->somu == 0) cout << temp->data->heso;
                else if (temp->data->somu == 1) cout << "-x";
                else cout << "-x^" << temp->data->somu;
            } else {
                if (temp->data->somu == 0) cout << temp->data->heso;
                else if (temp->data->somu == 1) cout << temp->data->heso << "x";
                else cout << temp->data->heso << "x^" << temp->data->somu;
            }
        }
        temp = temp->next;
    }
}

double TinhDaThuc(DATHUC B, double x){
    Node* temp = B.head;
    double result = temp->data->heso * pow(x, temp->data->somu);
    temp = temp->next;
    while (temp != nullptr) {
        result += temp->data->heso * pow(x,temp->data->somu);
        temp = temp->next;
    }
    return result;
}

int main() {
    DATHUC B;
    int N;
    
    cin >> N;
    for (int test = 0; test < N; test++){
		double heso; int somu;
		cin >> heso >> somu;
		Nhap(B,heso,somu);
    }
    
    
    cout << "Da thuc vua nhap la: "; Xuat(B);
    double x; cin >> x;
    cout << "\nVoi x=" << x << ", gia tri da thuc la: "
         << setprecision(2) << fixed << TinhDaThuc(B, x);
    return 0;
}
