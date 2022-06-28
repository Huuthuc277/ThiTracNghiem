void GiaiPhongTREE(TREE& t) {
	if (t == NULL) 
		return;
	else {
		GiaiPhongTREE(t->pLeft);
		GiaiPhongTREE(t->pRight);
		// xoa danh sach ch
		t->listCauHoi.sl = 0;	
		delete t;
	}
}


void DeleteListDiem(DSDIEM& l) {
	//xoa ds ct
	for (NODEDT* k = l.pHead; k != NULL; k = k->pNext) {	
		k->data.listCT.sl = 0;
	}
	
	//xoa ds diem
	NODEDT *k = NULL;
	while(l.pHead != NULL) {
		k = l.pHead;
		l.pHead = l.pHead->pNext;
		delete k;
	}
}

void DeleteListSV(DSSV& l) {
	NODESV *k = NULL;
	while(l.pHead != NULL) {
		k = l.pHead;
		l.pHead = l.pHead->pNext;
		delete k;
	}
}

void ClearListSV(DSSV& l) {
	for (NODESV* k = l.pHead; k != NULL; k = k->pNext) {	
		DeleteListDiem(k->data.listDiem);
	}
	DeleteListSV(l);
}

void DeleteLop(DSLOP& ds_lop) {	
	if(ds_lop.sl == 0) {
		return;
	}

	for (int i = 0; i < ds_lop.sl; i++) {
		ClearListSV(ds_lop.ds[i]->listSV);
	}
	
	while(ds_lop.sl >0) {
		delete ds_lop.ds[ds_lop.sl];
		ds_lop.sl--;
		
	}
}

