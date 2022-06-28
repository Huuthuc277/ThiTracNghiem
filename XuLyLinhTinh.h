void swapChuoi(string &x,string &y) {
   string temp=x;
   x=y;
   y=temp;
}


string cat_ho_ten(string s, int i) {
	string ten = "";
	while(s[s.length() -1] != ' ') {
		ten.insert(ten.begin() + 0, s[s.length() -1]);
		s.pop_back();
	}
	s.pop_back();
	
	if(i == 1) {
		return s;
	}
	return ten;
}

int chuoi_to_so(string s){
	int so = 0;
	int n = s.length();
	for(int i=0; i<n; i++) {
		int x = s[i] - 48;
		so = so * 10 + x;
	}
	return so;
}

string trim(string str) {
	//Xoa khoang trong
	while (str[0] == ' ') {
		str.erase(str.begin() + 0);
	}
	while (str[str.length() - 1] == ' ') {
		str.erase(str.begin() + (str.length() - 1));
	}
	
	return str;
}

void DinhDangChuoi(string& str) {
	//Xoa khoang trong
	while (str[0] == ' ')
	{
		str.erase(str.begin() + 0);
	}
	while (str[str.length() - 1] == ' ')
	{
		str.erase(str.begin() + (str.length() - 1));
	}

	for (int i = 1; i < str.length() - 1; i++)
	{
		if (str[i + 1] == ' ' && str[i] == ' ')
		{
			str.erase(str.begin() + i);
			i--;
		}
	}
	//Viet thuong tat ca lai
	for (int i = 0; i < str.length(); i++)
	{
		if ((65 <= str[i] && str[i] <= 90) && str[i] != ' ')
		{
			str[i] = str[i] + 32;
		}
	}
	//Viet hoa
	for (int i = 0; i < str.length(); i++)
	{
		if (i == 0 && (97 <= str[i] && str[i] <= 122))
		{
			str[0] = str[0] - 32;
		}
		if (str[i] == ' ' && (97 <= str[i+1] && str[i + 1] <= 122))
		{
			str[i + 1] = str[i + 1] - 32;
		}
	}
}

void XuLyNhapPassword(string &InPut, int toadoX, int& toadoY, int LenghtMax) {
	int toadoXtam;
	string temp;
	for(int i=0; i<InPut.length(); i++) {
		temp.insert(i, "*");
	}
	char c;
	while (true)
	{
		c = getch();
		if (((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || (c >= 48 && c <= 57)||
			c == '+' || c == '-' || c == '*' || c == '/'||c=='.'||c=='_') && InPut.length() < LenghtMax) {				
			InPut.insert(InPut.begin() + (whereX() - toadoX), c);
			temp.insert(temp.begin() + (whereX() - toadoX), '*');
			if ((whereX() - toadoX) < InPut.length() - 1) {
				toadoXtam = whereX() + 1;
				gotoXY(toadoX, whereY());
				cout << "                                               ";
				gotoXY(toadoX, whereY());
				cout << temp;
				gotoXY(toadoXtam, whereY());
			}
			else
				cout << '*';
		}
		else if (c == 8 && whereX() > toadoX) {
			InPut.erase(InPut.begin() + (whereX() - toadoX) - 1);
			temp.erase(temp.begin() + (whereX() - toadoX) - 1);
			toadoXtam = whereX() - 1;
			gotoXY(toadoX, whereY());
			cout << "                                               ";
			gotoXY(toadoX, whereY());
			cout << temp;
			gotoXY(toadoXtam, whereY());
		}
		else if (c == 32 && InPut.length() < LenghtMax && InPut.length() != 0 && InPut[whereX() - toadoX - 1] != ' '){
			InPut.insert(InPut.begin() + (whereX() - toadoX), ' ');
			temp.insert(temp.begin() + (whereX() - toadoX), '*');
			if ((whereX() - toadoX) < InPut.length() - 1)
			{
				toadoXtam = whereX() + 1;
				gotoXY(toadoX, whereY());
				cout << "                                               ";
				gotoXY(toadoX, whereY());
				cout << InPut;
				gotoXY(toadoXtam, whereY());
			}
			else
				cout << c;
		}
		else if (c == 13 && InPut.length() > 0)//enter
		{
			toadoY = toadoY + 3;
			break;
		}
		else if (c == -32)
		{
			c = getch();
			if (c == 75 && whereX() > toadoX)
			{
				cout << "\b";
			}
			else if (c == 77 && whereX() < toadoX + InPut.length())
			{
				gotoXY(whereX() + 1, whereY());
			}
			else if (c == 80)
			{
				toadoY = toadoY + 3;
				break;
			}
			else if (c == 72)
			{
				toadoY = toadoY - 3;
				break;
			}
		}
	}
}

void XuLyNhap1(string & InPut, int toadoX, int& toadoY, int LenghtMax) {
	int toadoXtam;
	char c;
	while (true)
	{
		c = getch();
		if (((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || (c >= 48 && c <= 57)||
			c == '+' || c == '-' || c == '*' || c == '/'||c=='.'||c=='_') && InPut.length() < LenghtMax)
		{
			InPut.insert(InPut.begin() + (whereX() - toadoX), c);
			if ((whereX() - toadoX) < InPut.length() - 1) {
				toadoXtam = whereX() + 1;
				gotoXY(toadoX, whereY());
				cout << "                                                    ";
				gotoXY(toadoX, whereY());
				cout << InPut;
				gotoXY(toadoXtam, whereY());
			}
			else
				cout << c;
		}
		else if (c == 8 && whereX() > toadoX)
		{
			InPut.erase(InPut.begin() + (whereX() - toadoX) - 1);
			toadoXtam = whereX() - 1;
			gotoXY(toadoX, whereY());
			cout << "                                                        ";
			gotoXY(toadoX, whereY());
			cout << InPut;
			gotoXY(toadoXtam, whereY());
		}
		else if (c == 32 && InPut.length() < LenghtMax && InPut.length() != 0 && InPut[whereX() - toadoX - 1] != ' ')
		{
			InPut.insert(InPut.begin() + (whereX() - toadoX), ' ');
			if ((whereX() - toadoX) < InPut.length() - 1)
			{
				toadoXtam = whereX() + 1;
				gotoXY(toadoX, whereY());
				cout << "                                               ";
				gotoXY(toadoX, whereY());
				cout << InPut;
				gotoXY(toadoXtam, whereY());
			}
			else
				cout << c;
		}
		else if (c == 13 && InPut.length() > 0)//enter
		{
			toadoY = toadoY + 3;
			break;
		}
		else if (c == -32)
		{
			c = getch();
			if (c == 75 && whereX() > toadoX)
			{
				cout << "\b";
			}
			else if (c == 77 && whereX() < toadoX + InPut.length())
			{
				gotoXY(whereX() + 1, whereY());
			}
			else if (c == 80)
			{
				toadoY = toadoY + 3;
				break;
			}
			else if (c == 72)
			{
				toadoY = toadoY - 3;
				break;
			}
		}
	}
}

void XuLyNhap2(string &InPut, int toadoX, int& toadoY) {
	int toadoXtam;
	char c;
	while (true) {
		c = getch();
		if (((c >= 48 && c <= 57) || (c >= 65 && c <= 90)) && InPut.length() < 15)
		{
			InPut.insert(InPut.begin() + (whereX() - toadoX), c);
			if ((whereX() - toadoX) < InPut.length() - 1) {
				toadoXtam = whereX() + 1;
				gotoXY(toadoX, whereY());
				cout << "                                                 ";
				gotoXY(toadoX, whereY());
				cout << InPut;
				gotoXY(toadoXtam, whereY());
			}
			else
				cout << c;
		}
		else if ((c >= 97 && c <= 122) && InPut.length() < 15) 	{
			c = c - 32;
			InPut.insert(InPut.begin() + (whereX() - toadoX), c);
			if ((whereX() - toadoX) < InPut.length() - 1)
			{
				toadoXtam = whereX() + 1;
				gotoXY(toadoX, whereY());
				cout << "                                                 ";
				gotoXY(toadoX, whereY());
				cout << InPut;
				gotoXY(toadoXtam, whereY());
			}
			else
				cout << c;
		}
		else if (c == 8 && whereX() > toadoX) {
			InPut.erase(InPut.begin() + (whereX() - toadoX) - 1);
			toadoXtam = whereX() - 1;
			gotoXY(toadoX, whereY());
			cout << "                                                 ";
			gotoXY(toadoX, whereY());
			cout << InPut;
			gotoXY(toadoXtam, whereY());
		}
		else if (c == 13 && InPut.length() > 0) {// n?u l?h?enter
			toadoY = toadoY + 3;
			break;
		}
		else if (c == -32) {
			c = getch();
			if (c == 75 && whereX() > toadoX) {
				cout << "\b";
			}
			else if (c == 77 && whereX() < toadoX + InPut.length()) 
				gotoXY(whereX() + 1, whereY());
			else if (c == 80){
				toadoY = toadoY + 3;
				break;
			}
			else if (c == 72){
				toadoY = toadoY - 3;
				break;
			}
		}
	}
}

void XuLyNhap3(string &InPut, int toadoX, int& toadoY, int LenghtMax) {
	int toadoXtam;
	char c;
	while (true)
	{
		c = getch();
		if (((c >= 65 && c <= 90)  || (c >= 48 && c <= 57)||
			c == '+' || c == '-' || c == '*' || c == '/'||c=='.'||c=='_') && InPut.length() < LenghtMax)
		{
			InPut.insert(InPut.begin() + (whereX() - toadoX), c);
			if ((whereX() - toadoX) < InPut.length() - 1)
			{
				toadoXtam = whereX() + 1;
				gotoXY(toadoX, whereY());
				cout << "                                               ";
				gotoXY(toadoX, whereY());
				cout << InPut;
				gotoXY(toadoXtam, whereY());
			}
			else
				cout << c;
		}		
		
		else if((c >= 97 && c <= 122) && InPut.length() < LenghtMax) {
			c = c - 32;
			InPut.insert(InPut.begin() + (whereX() - toadoX), c);
			if ((whereX() - toadoX) < InPut.length() - 1)
			{
				toadoXtam = whereX() + 1;
				gotoXY(toadoX, whereY());
				cout << "                                               ";
				gotoXY(toadoX, whereY());
				cout << InPut;
				gotoXY(toadoXtam, whereY());
			}
			else
				cout << c;
		}
		else if (c == 8 && whereX() > toadoX)
		{
			InPut.erase(InPut.begin() + (whereX() - toadoX) - 1);
			toadoXtam = whereX() - 1;
			gotoXY(toadoX, whereY());
			cout << "                                               ";
			gotoXY(toadoX, whereY());
			cout << InPut;
			gotoXY(toadoXtam, whereY());
		}
		else if (c == 32 && InPut.length() < LenghtMax && InPut.length() != 0 && InPut[whereX() - toadoX - 1] != ' ')
		{
			InPut.insert(InPut.begin() + (whereX() - toadoX), ' ');
			if ((whereX() - toadoX) < InPut.length() - 1)
			{
				toadoXtam = whereX() + 1;
				gotoXY(toadoX, whereY());
				cout << "                                               ";
				gotoXY(toadoX, whereY());
				cout << InPut;
				gotoXY(toadoXtam, whereY());
			}
			else
				cout << c;
		}
		else if (c == 13 && InPut.length() > 0)//enter
		{
			toadoY = toadoY + 3;
			break;
		}
		else if (c == -32)
		{
			c = getch();
			if (c == 75 && whereX() > toadoX) {
				cout << "\b";
			}
			else if (c == 77 && whereX() < toadoX + InPut.length()) {
				gotoXY(whereX() + 1, whereY());
			}
			else if (c == 80) {
				toadoY = toadoY + 3;
				break;
			}
			else if (c == 72) {
				toadoY = toadoY - 3;
				break;
			}
		}
	}
}

void XuLyNhap4(string &InPut, int toadoX, int& toadoY, int LenghtMax) {
	int toadoXtam;
	char c;
	while (true)
	{
		c = getch();
		if ((c >= 48 && c <= 57)  && InPut.length() < LenghtMax) {
			InPut.insert(InPut.begin() + (whereX() - toadoX), c);
			if ((whereX() - toadoX) < InPut.length() - 1)
			{
				toadoXtam = whereX() + 1;
				gotoXY(toadoX, whereY());
				cout << "                                                        ";
				gotoXY(toadoX, whereY());
				cout << InPut;
				gotoXY(toadoXtam, whereY());
			}
			else
				cout << c;
		}		
		else if (c == 8 && whereX() > toadoX) {
			InPut.erase(InPut.begin() + (whereX() - toadoX) - 1);
			toadoXtam = whereX() - 1;
			gotoXY(toadoX, whereY());
			cout << "                                                             ";
			gotoXY(toadoX, whereY());
			cout << InPut;
			gotoXY(toadoXtam, whereY());
		}
		else if (c == 13 && InPut.length() > 0)// n?u l?h?enter
		{
			toadoY = toadoY + 3;
			break;
		}
		else if (c == -32)
		{
			c = getch();
			if (c == 75 && whereX() > toadoX)
			{
				cout << "\b";
			}
			else if (c == 77 && whereX() < toadoX + InPut.length())
			{
				gotoXY(whereX() + 1, whereY());
			}
			else if (c == 80)
			{
				toadoY = toadoY + 3;
				break;
			}
			else if (c == 72)
			{
				toadoY = toadoY - 3;
				break;
			}
		}
	}
}

void XuLyNhapND(string & InPut, int toadoX, int& toadoY, int LenghtMax) {
	int toadoXtam;
	char c;
	while (true)
	{
		c = getch();
		if (((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || (c >= 40 && c <= 63))  && InPut.length() < LenghtMax)
		{
			InPut.insert(InPut.begin() + (whereX() - toadoX), c);
			if ((whereX() - toadoX) < InPut.length() - 1)
			{
				toadoXtam = whereX() + 1;
				gotoXY(toadoX, whereY());
				cout << "                                               ";
				gotoXY(toadoX, whereY());
				cout << InPut;
				gotoXY(toadoXtam, whereY());
			}
			else
				cout << c;
		}
		else if (c == 8 && whereX() > toadoX)
		{
			InPut.erase(InPut.begin() + (whereX() - toadoX) - 1);
			toadoXtam = whereX() - 1;
			gotoXY(toadoX, whereY());
			cout << "                                               ";
			gotoXY(toadoX, whereY());
			cout << InPut;
			gotoXY(toadoXtam, whereY());
		}
		else if (c == 32 && InPut.length() < LenghtMax && InPut.length() != 0 && InPut[whereX() - toadoX - 1] != ' ')
		{
			InPut.insert(InPut.begin() + (whereX() - toadoX), ' ');
			if ((whereX() - toadoX) < InPut.length() - 1)
			{
				toadoXtam = whereX() + 1;
				gotoXY(toadoX, whereY());
				cout << "                                               ";
				gotoXY(toadoX, whereY());
				cout << InPut;
				gotoXY(toadoXtam, whereY());
			}
			else
				cout << c;
		}
		else if (c == 13 && InPut.length() > 0)//enter
		{
			toadoY = toadoY + 3;
			break;
		}
		else if (c == -32)
		{
			c = getch();
			if (c == 75 && whereX() > toadoX)
			{
				cout << "\b";
			}
			else if (c == 77 && whereX() < toadoX + InPut.length())
			{
				gotoXY(whereX() + 1, whereY());
			}
			else if (c == 80)
			{
				toadoY = toadoY + 3;
				break;
			}
			else if (c == 72)
			{
				toadoY = toadoY - 3;
				break;
			}
		}
	}
}

void XuLyNhapDA(string & InPut, int toadoX, int& toadoY) {
	int toadoXtam;
	char c;
	while (true) {
		c = getch();
		if ((c == 'a' || c == 'b' || c == 'c' ||  c == 'd')  && InPut.length() < 1) {
			c = c - 32;
			InPut.insert(InPut.begin() + (whereX() - toadoX), c);
			if ((whereX() - toadoX) < InPut.length() - 1)
			{
				toadoXtam = whereX() + 1;
				gotoXY(toadoX, whereY());
				cout << "                                               ";
				gotoXY(toadoX, whereY());
				cout << InPut;
				gotoXY(toadoXtam, whereY());
			}
			else
				cout << c;
		}else if((c == 'A' || c == 'B' || c == 'C' || c == 'D') && InPut.length() < 1) {			
			InPut.insert(InPut.begin() + (whereX() - toadoX), c);
			if ((whereX() - toadoX) < InPut.length() - 1)
			{
				toadoXtam = whereX() + 1;
				gotoXY(toadoX, whereY());
				cout << "                                               ";
				gotoXY(toadoX, whereY());
				cout << InPut;
				gotoXY(toadoXtam, whereY());
			}
			else
				cout << c;
		} else if (c == 8 && whereX() > toadoX)
		{
			InPut.erase(InPut.begin() + (whereX() - toadoX) - 1);
			toadoXtam = whereX() - 1;
			gotoXY(toadoX, whereY());
			cout << "                                               ";
			gotoXY(toadoX, whereY());
			cout << InPut;
			gotoXY(toadoXtam, whereY());
		}else if (c == 32 && InPut.length() < 1 && InPut.length() != 0 && InPut[whereX() - toadoX - 1] != ' ') 		{
			InPut.insert(InPut.begin() + (whereX() - toadoX), ' ');
			if ((whereX() - toadoX) < InPut.length() - 1)
			{
				toadoXtam = whereX() + 1;
				gotoXY(toadoX, whereY());
				cout << "                                               ";
				gotoXY(toadoX, whereY());
				cout << InPut;
				gotoXY(toadoXtam, whereY());
			}
			else
				cout << c;
		}
		else if (c == 13 && InPut.length() > 0)//enter
		{
			toadoY = toadoY + 3;
			break;
		}
		else if (c == -32)
		{
			c = getch();
			if (c == 75 && whereX() > toadoX)
			{
				cout << "\b";
			}
			else if (c == 77 && whereX() < toadoX + InPut.length())
			{
				gotoXY(whereX() + 1, whereY());
			}
			else if (c == 80)
			{
				toadoY = toadoY + 3;
				break;
			}
			else if (c == 72)
			{
				toadoY = toadoY - 3;
				break;
			}
		}
	}
}


void XuLyNhapCH(string &InPut, int toadoX, int& toadoY) {
	int toadoXtam;
	char c;
	while (true)
	{
		c = getch();
		if ((c >= 48 && c <= 57)  && InPut.length() < 2)
		{
			InPut.insert(InPut.begin() + (whereX() - toadoX), c);
			if ((whereX() - toadoX) < InPut.length() - 1)
			{
				toadoXtam = whereX() + 1;
				gotoXY(toadoX, whereY());
				cout << "                                                      ";
				gotoXY(toadoX, whereY());
				cout << InPut;
				gotoXY(toadoXtam, whereY());
			}
			else
				cout << c;
		}		
		else if (c == 8 && whereX() > toadoX)
		{
			InPut.erase(InPut.begin() + (whereX() - toadoX) - 1);
			toadoXtam = whereX() - 1;
			gotoXY(toadoX, whereY());
			cout << "                                                           ";
			gotoXY(toadoX, whereY());
			cout << InPut;
			gotoXY(toadoXtam, whereY());
		}
		else if (c == 13 && InPut.length() > 0)// n?u l?h?enter
		{
			toadoY = toadoY + 3;
			break;
		}
		else if (c == -32)
		{
			c = getch();
			if (c == 75 && whereX() > toadoX)
			{
				cout << "\b";
			}
			else if (c == 77 && whereX() < toadoX + InPut.length())
			{
				gotoXY(whereX() + 1, whereY());
			}
			else if (c == 80)
			{
				toadoY = toadoY + 3;
				break;
			}
			else if (c == 72)
			{
				toadoY = toadoY - 3;
				break;
			}
		}
	}
}


void demnguoc(int phut) {	
	int giay = 0; 
	while(stop==0) {
	
		if(giay == 0) {			
			giay = 59;
			phut-=1;
		}		
		if(phut == 0 && stop == 0) {		
			while(giay >= 0 && stop == 0) {
				if(giay< 10) {
					gotoXY(100, 5);
					cout<<"0"<<phut<<":0"<<giay;	
				}else {
					gotoXY(100, 5);
					cout<<"0"<<phut<<":"<<giay;		
				
				}			
				Sleep(980);
				giay--;
			
			}				
			break;
		}	
		if(phut <10 ) {
			if(giay >= 10) {
				gotoXY(100, 5);
				cout<<"0"<<phut<<":"<<giay;
			}else {
				gotoXY(100, 5);
				cout<<"0"<<phut<<":0"<<giay;
			}
		}else {
			if(giay >= 10) {
				gotoXY(100, 5);
				cout<<phut<<":"<<giay;
			}else {
				gotoXY(100, 5);
				cout<<phut<<":0"<<giay;
			}
		}
		giay-=1;
		Sleep(980);
		
	}		  
	stop=1; 
}


