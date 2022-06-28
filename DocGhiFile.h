void doc_file_ds_mh(TREE& t);
void ghi_mh(TREE t, ofstream& fileout);
void ghi_file_ds_mh(TREE t);

void doc_file_ds_mh(TREE& t) {
	ifstream filein;
	filein.open("dsMonHoc.txt", ios::in);
	int n;
	int n1;
	filein >> n;//SL MH
	filein.ignore();
	for (int i = 0; i < n; i++) {
		MH mh;
		getline(filein, mh.maMH, ',');
		getline(filein, mh.tenMH, ',');		
		NODEMH* p = KhoiTaoNodeMH(mh);		
		filein >> n1;//SL CH
		filein.ignore();
		for (int j = 0; j < n1; j++) {
			//---- load 1 ch ----
			CAUHOI ch;
			filein>> ch.id;
			filein.ignore();
			getline(filein, ch.noiDung, ',');
			getline(filein, ch.A, ',');
			getline(filein, ch.B, ',');
			getline(filein, ch.C, ',');
			getline(filein, ch.D, ',');
			getline(filein, ch.DA);		
			p->listCauHoi.ds[j] = ch;
			p->listCauHoi.sl++;
		}
		Them1MH(t, p);
		
	}
	filein.close();
}

void ghi_mh(TREE t, ofstream& fileout) {
	if (t != NULL) {
		fileout << t->data.maMH << ",";
		fileout << t->data.tenMH<<","<<endl;
		fileout << t->listCauHoi.sl << endl;
		for (int j = 0; j < t->listCauHoi.sl; j++) {
			fileout << t->listCauHoi.ds[j].id << ",";
			fileout << t->listCauHoi.ds[j].noiDung << ",";
			fileout << t->listCauHoi.ds[j].A << ",";
			fileout << t->listCauHoi.ds[j].B << ",";
			fileout << t->listCauHoi.ds[j].C << ",";
			fileout << t->listCauHoi.ds[j].D<< ",";	
			fileout << t->listCauHoi.ds[j].DA << endl;
		}
		ghi_mh(t->pLeft, fileout);
		ghi_mh(t->pRight, fileout);
	}
}

void ghi_file_ds_mh(TREE t) {
	ofstream fileout;
	fileout.open("dsMonHoc.txt", ios_base::out);
	int dem = SoNodeTrongTREE(t);
	fileout<<dem<<endl;
	ghi_mh(t, fileout);
	fileout.close();
}

void doc_file_lop(DSLOP& ds_lop) {
	ifstream filein;
	filein.open("dsLop.txt", ios_base::in);
	int n;
	int n1;
	int n2;
	int n3;
	filein >> n;
	filein.ignore();
	for (int i= 0; i < n; i++) {
		ds_lop.ds[ds_lop.sl] = new LOP;
		getline(filein, ds_lop.ds[ds_lop.sl]->maLop, ',');
		getline(filein, ds_lop.ds[ds_lop.sl]->tenLop,',');
		filein.ignore();	
		ds_lop.ds[ds_lop.sl]->listSV.pHead = NULL;
		ds_lop.ds[ds_lop.sl]->listSV.pTail = NULL;
		filein >> n1;
		filein.ignore();			
		for (int j = 0; j < n1; j++) {
			SV sv;
			getline(filein, sv.maSV, ',');
			getline(filein, sv.ho, ',');
			getline(filein, sv.ten, ',');
			getline(filein, sv.phai, ',');
			getline(filein, sv.password, ',');
			filein.ignore();					
			filein >> n2;
			filein.ignore();
			for (int x = 0; x < n2; x++) {
				DT dt;
				getline(filein, dt.maMH, ',');
				filein >> dt.diem;
				filein.ignore();
				filein >> n3;
				filein.ignore();
				for (int y = 0; y < n3; y++) {
					filein >> dt.listCT.ds[y].id;
					filein.ignore();
					getline(filein, dt.listCT.ds[y].noiDung, ',');
					getline(filein, dt.listCT.ds[y].DA, ',');
					filein.ignore();
					dt.listCT.sl++;
				}
				NODEDT* k = Khoi_Tao_NODE_DT(dt);
				Them_Cuoi_DSDT(sv.listDiem, k);
			}
			NODESV* p = Khoi_Tao_NODE(sv);
			Them_Cuoi(ds_lop.ds[ds_lop.sl]->listSV, p);
			
		}
		ds_lop.sl++;
	}	
	filein.close();
}

void ghi_file_lop(DSLOP ds_lop) {
	ofstream fileout;
	fileout.open("dsLop.txt", ios_base::out);
	int n;
	int n1;
	fileout << ds_lop.sl<<endl;
	for (int i = 0; i < ds_lop.sl; i++) {
		fileout << ds_lop.ds[i]->maLop << ",";
		fileout << ds_lop.ds[i]->tenLop << "," << endl;
		n = CountSV(ds_lop.ds[i]->listSV);
		fileout << n<<endl;
		for (NODESV* k = ds_lop.ds[i]->listSV.pHead; k != NULL; k = k->pNext) {
			fileout << k->data.maSV << ",";
			fileout << k->data.ho << ",";
			fileout << k->data.ten << ",";
			fileout << k->data.phai << ",";
			fileout << k->data.password << "," << endl;
			n1 = CountDiem(k->data.listDiem);			
			fileout << n1 << endl;
			for (NODEDT* g = k->data.listDiem.pHead; g != NULL; g = g->pNext) {
				fileout << g->data.maMH << ",";
				fileout << g->data.diem << endl;
				fileout << g->data.listCT.sl << endl;
				for (int j = 0; j < g->data.listCT.sl; j++) {
					fileout << g->data.listCT.ds[j].id<<",";
					fileout << g->data.listCT.ds[j].noiDung << ",";
					fileout << g->data.listCT.ds[j].DA << ","<<endl;			
				}
			}
		}
		
	}
	fileout.close();

}


