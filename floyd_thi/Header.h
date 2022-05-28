#pragma once
#include <iostream>
#include <cstdio>
#include <fstream>
#define vocung 3000
#define MAX 50
#define TRUE 1
#define FALSE 0
using namespace std;

void Init();
void xuatMaTran();
void taoCung(int  node1, int node2, int ts);
void xoaCung(int node1, int node2);
void diskstra(int nutDi, int nutDen, int* ngan, int duongD[]);
void inLoTrinh(int x, int y);
void ghiMaTran();
void docMaTran();
int bacDinhRa(int dinh);
void xemMaTran();
void themCung(int node1, int node2, int ts);

