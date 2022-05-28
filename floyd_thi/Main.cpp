#include"Header.h"
extern int TRONGSO[MAX][MAX];
extern int D[MAX][MAX];
extern int P[MAX][MAX];
extern int soNut;

void main() {
	int i, j, x, y, chon, ts;
	char c;
	int dinh, ngan;
	int nutDi;
	int nutDen;
	int duongDi[MAX];
	soNut = 0;


	do {
		cout << "\n1.Tao do thi";
		cout << "\n2.Them mot nut";
		cout << "\n3.Xoa mot cung";
		cout << "\n4.Tim kiem mot cung";
		cout << "\n5.Tinh bac vao cua mot nut";
		cout << "\n6.Tim duong di ngan nhat";
		cout << "\n7.Hien thi ma tran ke";
		cout << "\n8.Duyet do thi va hien thi cac canh";
		cout << "\n0.Thoat";
		cout << "\nNhap cac so chon chuc nang.(Thoat 0):";
		cin >> chon;
		
		/*while (true) {
			cout << "\nNhap x, y lon hon" << soNut << "de thoat";
			cout << endl;
			cout << "\nNhap nut x:"; cin >> x;
			cout << "\nNhap nut y:"; cin >> y;
			if (x > soNut && y > soNut) {
				cout << "xin chao" << endl;
				cout << "Trong so cua cung" << x << "," << y;
				cin >> ts;
				taoCung(x, y, ts);
			}
		}*/

		switch (chon) {
		case 1:
			x = y = 0;
			cout << "\nDo thi moi co bap nhieu nut?: ";
			cin >> soNut;
			Init();

			x = y = 0;
			while (true)
			{
				cout << "\nNhap x,y lon hon " << soNut << "de thoat" << endl;
				cout << "\nNhap nut dau x= ";
				cin >> x;
				cout << "\nNhap nut dau y= ";
				cin >> y;
				if (x < soNut && y < soNut)
				{
					cout << "\nTrong so cua cung: (" << x << "," << y << ")=";
					cin >> ts;
					taoCung(x, y, ts);
				}
				else {
					break;
				}
			}
			ghiMaTran();
			break;

		case 2:
			/*docMaTran();
			if (soNut < MAX)
			{
				++soNut;
				cout << "\nSo nut hien tai la:" << soNut;
			}
			break;*/
			docMaTran();
			cout << "\nNhap cung can them x= "; cin >> x;
			cout << "\nNhap cung can them y= "; cin >> y;
			if (x > soNut && y > soNut)
				cout << "\nKhong hop le";
			else
			{
				cout << "\nTrong so cua cung (" << x << "," << y << ")=";
				cin >> ts;
				TRONGSO[x][y] = ts;
				
				
			}
			taoCung(x, y,ts);
			ghiMaTran();
			break;
		case 3:
			cout << "\nNhap cung x can xoa:"; cin >> x;
			cout << "\nNhap cung y can xoa"; cin >> y;
			docMaTran();
			xoaCung(x, y);
			ghiMaTran();
			break;
		case 4:
			docMaTran();
			cout << "\nNhap cung x can tim"; cin >> x;
			cout << "\nNhap cung y can tim:"; cin >> y;
			if (x > soNut && y > soNut)
				cout << "\nKhong hop le";
			else
				if (TRONGSO[x][y] < vocung)
					cout << "Co cung (" << x << "," << y << ")";
			break;
		case 5:
			docMaTran();
			cout << "\nNhap dinh can biet:"; cin >> dinh;
			cout << "\nBac vao cua dinh la:" << dinh << "=" << bacDinhRa;
			break;
		case 6:
			docMaTran();
			cout << "Nhap nut di:"; cin >> nutDi;
			cout << "\nNhap nut den:"; cin >> nutDen;
			diskstra(nutDi, nutDen, &ngan, duongDi);
			break;
		case 7:
			cout << "\nXem ma tran";
			xemMaTran();
			break;
		}

	} while (chon != 0);
		system("pause");
}
	




