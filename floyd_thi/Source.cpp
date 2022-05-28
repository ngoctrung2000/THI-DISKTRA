#include"Header.h"
int TRONGSO[MAX][MAX];
int D[MAX][MAX];
int P[MAX][MAX];
int soNut;
void Init()
{
	int i, j;
	fstream f;
	f.open("file.txt");
	if (!f)
	{
		f << soNut << endl;
		for (int i = 0; i != soNut; i++)
		{
			for (int j = 0; j != soNut; j++)
				if (i == j)
					f << 0;
				else
					f << -1;
			f << "\n";
		}
		f.close();
	}
}
void xuatMaTran()
{
	for (size_t i = 0; i < MAX; i++)
	{
		for (size_t j = 0; j < MAX; j++)
		{
			cout << TRONGSO[i][j];
		}

	}
}
void taoCung(int node1, int node2, int ts)
{
	if (node1 != node2)
		TRONGSO[node1][node2] = ts;

}
void xoaCung(int node1, int node2)
{
	TRONGSO[node1][node2] = vocung;
}
void diskstra(int nutDi, int nutDen, int* ngan, int duongD[])
{
	int i, k, kc, nutHienTai = 0, min, kcMoi;
	int tapNut[MAX];
	int kcNgan[MAX];
	for (size_t i = 0; i < soNut; i++)
	{
		tapNut[i] = FALSE;
		kcNgan[i] = vocung;
	}
	tapNut[nutDi] = TRUE;
	kcNgan[nutDi] = 0;
	while (nutHienTai != nutDen)
	{
		min = vocung;
		kc = kcNgan[nutHienTai];
		for (size_t i = 0; i < soNut; i++)
		{
			if (tapNut[i] == FALSE) {

				kcMoi = kc + TRONGSO[nutHienTai][i];
				if (kcMoi < kcNgan[i])
				{
					kcNgan[i] = kcMoi;
					duongD[i] = nutHienTai;
				}
				if (kcNgan[i] < min)
				{
					min = kcNgan[i];
					k = i;
				}
			}

		}
		nutHienTai = k;
		tapNut[nutHienTai] = TRUE;
	}
	*ngan = kcNgan[nutDen];
}



void inLoTrinh(int x, int y) {
	int r;
	if ((P[x][y] == -1)) {
		cout << x << "-->" << y;
		return;
	}
	else {
		r = P[x][y];
		inLoTrinh(x, r);
		inLoTrinh(r, y);
	}
}

void xemMaTran()
{
	cout << "\nGia tri trong file la: ";
	cout << "\n" << soNut << "\n";
	for (int i = 0; i != soNut; i++)
	{
		for (int j = 0; j != soNut; j++)
			cout << TRONGSO[i][j] << "\t";
		cout << "\n";
	}
}
void ghiMaTran()
{
	/*FILE* f;
	fopen_s(&f, "FLOYED.txt", "wt");
	if (f!=NULL)
		return;
	fprintf(f, "%d", soNut);
	for (int i = 0; i != soNut; i++)
	{
		fprintf(f, "\n");
		for (int j = 0; j != soNut; j++)
			fprintf(f, "%d\t", maTran[i][j]);

	}
	fclose(f);*/

	//----C2
	ofstream outfile;
	outfile.open("file.txt", ios::out | ios::trunc);
	if (!outfile)
		return;
	outfile << soNut << endl;
	for (int i = 0; i != soNut; i++)
	{
		outfile << endl;
		for (int j = 0; j != soNut; j++)
			outfile << TRONGSO[i][j] << " ";
	}
	outfile.close();
}

void docMaTran()
{
	/*FILE* f;
	fopen_s(&f, "FLOYED.txt", "rt");
	if (!f)
		return;
	fscanf_s(f, "%d", &soNut);
	for (int i = 0; i != soNut; i++)
		for (int j = 0; j != soNut; j++)
			fscanf_s(f, "%d", &maTran[i][j]);
	fclose(f);*/

	//---C2
	ifstream infile;
	infile.open("file.txt");

	if (!infile)
		return;
	infile >> soNut;
	for (int i = 0; i != soNut; i++)
		for (int j = 0; j != soNut; j++)
			infile >> TRONGSO[i][j];
	infile.close();

}
void themCung(int node1, int node2, int ts)
{
	if (node1 != node2)
		TRONGSO[node1][node2] = ts;
}
int bacDinhRa(int dinh)
{
	int dem = 0;
	for (int i = 0; i < soNut; i++)
		if (TRONGSO[dinh][i] > 0)
			dem++;
	return dem;
}