#include <iostream>
#include <cstdlib>
#include <cstring>
#include <list>
#include <fstream>

///////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////FUNCTIONS/////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////

// GROUP IDENTICAL ELEMENTS
std::list <std::string> GroupList ( std::list <std::string> Group ) {
	int z;
	std::list <std::string> Grouped, GroupTemp;
	GroupTemp.push_back("start");
	for ( std::string x1 : Group) {
		z=0;
		for ( std::string y : GroupTemp ) {
			if ( x1 == y ) {
				z=1;
				break;
			}
		}
		if ( z == 0 ) {
			for ( std::string x2 : Group ) {
					if ( x1 == x2 ) {
						Grouped.push_back( x1 );
					}
			}
			GroupTemp.push_back( x1 );
		}
	}
	return Grouped;
}

// COUNT ELEMENTS
std::list <std::string> CountList ( std::list <std::string> Count ) {
	int a;
	std::string String, PrevCheck;
	std::list <std::string> Counted, CountTemp;
	for ( std::string e : Count ) {
		if ( e != PrevCheck ) {
			a=0;
			PrevCheck = e;
			// VERIFY THAT ELEMENTS ARE USED ONLY ONCE
			for ( std::string c : CountTemp ) {
				if ( e == c ) {
					a=1;
					break;
				}
			}
			if ( a == 0 ) {
				CountTemp.push_back(e);
				// COUNT IDENTICAL ELEMENTS
				for ( std::string f : Count ) {
					if ( e == f ) {
						a++;
					}
				}
				String = std::to_string(a) + '"' + e;
				Counted.push_back(String);
			}
		}
	}
	return Counted;
}

// RE-ARRANGE ELEMENTS BY DECREASING ORDER
std::list <std::string> SortList ( std::list <std::string> Sort ) {
	int l, j, ElemCount, ElemCountCheck, Position, m, n;
	char g, t;
	std::string Sorted[Sort.size()];
	std::list <std::string> SortedList;
	// INITIALIZE WITH A DEFAULT STRING
	for ( n=0; n<Sort.size(); n++ ) {
		Sorted[n] = "empty";
	}
	for ( std::string k : Sort ) {
	// FOR EVERY ELEMENT OF THE LIST:
		// SPLIT ELEMENTS: COUNT & ITEM
		for ( l=0 ; l<k.size() ; l++ ) {
			g = k[l];
			if ( g == '"' ) {
				ElemCount = std::stoi( k.substr(0, l) );
				break;
			}
		}
		Position=0;
		for ( std::string h : Sort ) {
		// FOR EVERY ELEMENT OF THE LIST:
			// SPLIT ELEMENTS: COUNT & ITEM
			for ( j=0 ; j<h.size() ; j++ ) {
				t = h[j];
				if ( t == '"' ) {
					ElemCountCheck = std::stoi( h.substr(0, j) );
					break;
				}
			}
			if ( k != h ) {
				if ( ElemCount < ElemCountCheck ) {
					Position++;
				}
			}
		}
		n=0;
		while ( n == 0 ) {
			if ( Sorted[Position] != "empty" ) {
				Position++;
			} else {
				n=1;
			}
		}
		//std::cout<< k<<std::endl;
		Sorted[Position] = k;
	}
	for ( m=0; m<Sort.size(); m++ ) {
		SortedList.push_back(Sorted[m]);
	}
	return SortedList;
}

// GLOBALS: SUM ELEMENTS COUNT
std::list <std::string> SumTotalList ( std::list<std::string> Totals, std::list<std::string> Sessions ) {
	int i, c, ElemCount, ElemCountCheck, match;
	char a, z;
	std::string xS, xT, Elem, ElemCheck, String;
	std::list <std::string> Finals;
	if ( Totals.size() != 0 ) {
		// IF IDENTICAL: ADD & APPEND.	ELSE: ONLY APPEND
		for ( std::string xT : Totals) {
			// SPLIT ELEMENTS: COUNT & ITEM
			for ( c=0 ; c<xT.size() ; c++ ) {
				z = xT[c];
				if ( z == '>' ) {
					ElemCount = std::stoi( xT.substr(2, c-7) );
					Elem = xT.substr(c+5);
					break;
				}
			}
			for ( std::string xS : Sessions ) {
				// SPLIT ELEMENTS: COUNT & ITEM
				for ( i=0 ; i<xS.size() ; i++ ) {
					a = xS[i];
					if ( a == '>' ) {
						ElemCountCheck = std::stoi( xS.substr(2, i-7) );
						ElemCheck = xS.substr(i+5);
						break;
					}
				}
				// IF IDENTICAL: ADD
				if ( Elem == ElemCheck ) {
					ElemCount = ElemCount + ElemCountCheck;
					break;
				}
			}
			String = "{ " + std::to_string(ElemCount) + " }   >>>   " + Elem;
			Finals.push_back(String);

		}
		// SESSION (REVERSE): IF IDENTICAL: SKIP, ELSE: APPEND
		for ( std::string xS : Sessions ) {
			match = 0;
			// SPLIT ELEMENTS: COUNT & ITEM
			for ( i=0 ; i<xS.size() ; i++ ) {
				a = xS[i];
				if ( a == '>' ) {
					Elem = xS.substr(i+5);
					break;
				}
			}
			for ( std::string xT : Totals) {
				// SPLIT ELEMENTS: COUNT & ITEM
				for ( c=0 ; c<xT.size() ; c++ ) {
					z = xT[c];
					if ( z == '>' ) {
						ElemCheck = xT.substr(c+5);
						break;
					}
				}
				// IF IDENTICAL: ADD, ELSE: APPEND
				if ( Elem == ElemCheck ) {
					match = 1;
					break;
				}
			}
			if ( match == 0 ) {
				Finals.push_back(xS);
			}
		}
	} else {
		for ( std::string xS : Sessions ) {
			Finals.push_back(xS);
		}
	}
	return Finals;
}

// GLOBALS: RE-ARRANGE ELEMENTS BY DECREASING ORDER
std::list <std::string> SortTotalList ( std::list <std::string> Sort ) {
	int l, j, ElemCount, ElemCountCheck, Position, m, n;
	char g, t;
	std::string Sorted[Sort.size()], Elem, ElemCheck;
	std::list <std::string> SortedList;
	// INITIALIZE WITH A STANDARD STRING
	for ( n=0; n<Sort.size(); n++ ) {
		Sorted[n] = "empty";
	}
	// k-h = line
	// l-j = counter to find splitter
	// g-t = examined character
	for ( std::string k : Sort ) {
	// FOR EVERY ELEMENT OF THE LIST:
		if ( k != "" ) {
			// SPLIT ELEMENTS: COUNT & ITEM
			for ( l=0 ; l<k.size() ; l++ ) {
				g = k[l];
				if ( g == '>' ) {
					ElemCount = std::stoi( k.substr(2, l-7) );
					Elem = k.substr(l+5);
					break;
				}
			}
			Position=0;
			for ( std::string h : Sort ) {
			// FOR EVERY ELEMENT OF THE LIST:
				// SPLIT ELEMENTS: COUNT & ITEM
				for ( j=0 ; j<h.size() ; j++ ) {
					t = h[j];
					if ( t == '>' ) {
						ElemCountCheck = std::stoi( h.substr(2, j-7) );
						ElemCheck = h.substr(j+5);
						break;
					}
				}
				if ( k != h ) {
					if ( ElemCount < ElemCountCheck ) {
						Position++;
					}
				}
			}
			n=0;
			while ( n == 0 ) {
				if ( Sorted[Position] != "empty" ) {
					Position++;
				} else {
					n=1;
				}
			}
			//std::cout<< k<<std::endl;
			Sorted[Position] = k;
		}
	}
	for ( m=0; m<Sort.size(); m++ ) {
		SortedList.push_back(Sorted[m]);
	}
	return SortedList;
}

///////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////START///////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////

// STARTING CRAPLOG
int main () {
	int i, count, start, diff;
	char Char;
	std::string line, temp, check;
	std::list <std::string> TEMP, IP, REQ, RES, UA, TOTAL;

	// READ FILE
	std::ifstream READ;
	READ.open("/var/log/apache2/access.log.1",std::ios::in);
	READ.seekg(0,std::ios::beg);
	while (READ) {
		getline(READ, line);
		if ( line == "" || line.rfind("192.168.", 0) == 0 || line.rfind("::1", 0) == 0 ) {
			continue;
		} else {
			// ADD TO TEMPORARY LIST TO CLEAN LOGS
			TEMP.push_back (line);
			// SPLIT TO FIND THE IP
			for ( i=0 ; i<line.size() ; i++ ) {
				Char = line[i];
				if ( Char == ' ' ) {
					if ( i==0 ) {
						continue;
					} else {
						temp = line.substr(0, i);
						IP.push_back (temp);
						break;
					}
				}
			}
			// FIND EVERYTHING ELSE
			count=0;
			for ( i=0 ; i<line.size() ; i++ ) {
				Char = line[i];
				if ( Char == '"' ) {
					switch ( count ) {
						case 0: case 3: case 4: // SKIP
							start=i;
							count++;
							break;
						case 1: // FIND REQUEST
							start = start + 1;
							diff = i - start;
							temp = line.substr(start, diff);
							REQ.push_back (temp);
							start = i;
							count++;
							break;
						case 2: // FIND RESPONSE CODE
							start = start + 2;
							diff = 3;
							temp = line.substr(start, diff);
							RES.push_back (temp);
							start = i;
							count++;
							break;
						case 5: // FIND USER-AGENT
							start = start + 1;
							diff = i - start;
							temp = line.substr(start, diff);
							UA.push_back (temp);
							start = i;
							count++;
							break;
					}
				}
			}
		}

	}
	READ.close();

	// WRITE CLEANED LOGS ON FILE
	std::ofstream WRITE;
	WRITE.open("./CLEAN.txt", std::ios::app);
	check = "zero";
	for ( std::string line : TEMP ) {
		temp = line.substr(0,15);
		if ( temp == check ) {
			WRITE<< "\n" << line << "\n";
		} else {
			if ( check != "zero" ) {
				WRITE<< "\n\n" << line << "\n";
			} else {
				WRITE<< line << "\n";
			}
			check = temp;
		}
	}
	WRITE.close();

///////////////////////////////////////STATISTICS////////////////////////////////////////////

	// ONE CLASS TO HOLD THEM ALL
	class STAT {
		public:
			std::string Element;
			int ElementCount;
	};
	STAT stat;
	STAT statCheck;

///////////////////////////////////SESSION/STATISTICS////////////////////////////////////////

	// WORK ON IPS
	IP = GroupList ( IP );
	IP = CountList ( IP );
	IP = SortList ( IP );
	// CREATE STATISTICS AND WRITE TO FILE
	for ( std::string line : IP ) {
		for ( i=0 ; i<line.size() ; i++ ) {
			Char = line[i];
			if ( Char == '"' ) {
				stat.ElementCount = std::stoi( line.substr(0, i) );
				stat.Element = line.substr(i+1);
				break;
			}
		}
		WRITE.open("./IPS", std::ios::app);
		WRITE<< "{ " << stat.ElementCount << " }   >>>   " << stat.Element << "\n\n";
		WRITE.close();
	}

	// WORK ON REQUESTS
	REQ = GroupList ( REQ );
	REQ = CountList ( REQ );
	REQ = SortList ( REQ );
	// CREATE STATISTICS AND WRITE TO FILE
	for ( std::string line : REQ ) {
		for ( i=0 ; i<line.size() ; i++ ) {
			Char = line[i];
			if ( Char == '"' ) {
				stat.ElementCount = std::stoi( line.substr(0, i) );
				stat.Element = line.substr(i+1);
				break;
			}
		}
		WRITE.open("./REQUESTS", std::ios::app);
		WRITE<< "{ " << stat.ElementCount << " }   >>>   " << stat.Element << "\n\n";
		WRITE.close();
	}

	// WORK ON RESPONSE CODES
	RES = GroupList ( RES );
	RES = CountList ( RES );
	RES = SortList ( RES );
	// CREATE STATISTICS AND WRITE TO FILE
	for ( std::string line : RES ) {
		for ( i=0 ; i<line.size() ; i++ ) {
			Char = line[i];
			if ( Char == '"' ) {
				stat.ElementCount = std::stoi( line.substr(0, i) );
				stat.Element = line.substr(i+1);
				break;
			}
		}
		WRITE.open("./RESULTS", std::ios::app);
		WRITE<< "{ " << stat.ElementCount << " }   >>>   " << stat.Element << "\n\n";
		WRITE.close();
	}

	// WORK ON USER-AGENTS
	UA = GroupList ( UA );
	UA = CountList ( UA );
	UA = SortList ( UA );
	// CREATE STATISTICS AND WRITE TO FILE
	for ( std::string line : UA ) {
		for ( i=0 ; i<line.size() ; i++ ) {
			Char = line[i];
			if ( Char == '"' ) {
				stat.ElementCount = std::stoi( line.substr(0, i) );
				stat.Element = line.substr(i+1);
				break;
			}
		}
		WRITE.open("./USER-AGENTS", std::ios::app);
		WRITE<< "{ " << stat.ElementCount << " }   >>>   " << stat.Element << "\n\n";
		WRITE.close();
	}

////////////////////////////////////GLOBAL/STATISTICS////////////////////////////////////////


	// WORK ON IPS
	IP.clear();
	TEMP.clear();
	// CREATE A LIST WITH GLOBAL'S
	READ.open("./IPS.tmp", std::ios::in);
	READ.seekg(0,std::ios::beg);
	while (READ) {
		getline(READ, line);
		if ( line != "" ) {
			IP.push_back(line);
		}
	}
	READ.close();
	// CREATE A LIST WITH SESSION'S
	READ.open("./IPS", std::ios::in);
	READ.seekg(0,std::ios::beg);
	while (READ) {
		getline(READ, line);
		if ( line != "" ) {
			TEMP.push_back(line);
		}
	}
	READ.close();
	// MERGE THE TWO LISTS (SUM IDENTICAL ELEMENTS)
	TOTAL = SumTotalList( IP, TEMP );
	// RE-ARRANGE BY DECREASING COUNT ORDER
	TOTAL = SortTotalList ( TOTAL );
	// WRITE ON FILE
	WRITE.open("./IPS");
	for ( std::string line : TOTAL ) {
		WRITE<< "\n" << line << "\n";
	}
	WRITE.close();

	// WORK ON REQUESTS
	REQ.clear();
	TEMP.clear();
	TOTAL.clear();
	// CREATE A LIST WITH GLOBAL'S
	READ.open("./REQUESTS.tmp", std::ios::in);
	READ.seekg(0,std::ios::beg);
	while (READ) {
		getline(READ, line);
		if ( line != "" ) {
			REQ.push_back(line);
		}
	}
	READ.close();
	// CREATE A LIST WITH SESSION'S
	READ.open("./REQUESTS", std::ios::in);
	READ.seekg(0,std::ios::beg);
	while (READ) {
		getline(READ, line);
		if ( line != "" ) {
			TEMP.push_back(line);
		}
	}
	READ.close();
	// MERGE THE TWO LISTS (SUM IDENTICAL ELEMENTS)
	TOTAL = SumTotalList( REQ, TEMP );
	// RE-ARRANGE BY DECREASING COUNT ORDER
	TOTAL = SortTotalList ( TOTAL );
	// WRITE ON FILE
	WRITE.open("./REQUESTS");
	for ( std::string line : TOTAL ) {
		WRITE<< "\n" << line << "\n";
	}
	WRITE.close();

	// WORK ON RESPONSE CODES
	RES.clear();
	TEMP.clear();
	TOTAL.clear();
	// CREATE A LIST WITH GLOBAL'S
	READ.open("./RESULTS.tmp", std::ios::in);
	READ.seekg(0,std::ios::beg);
	while (READ) {
		getline(READ, line);
		if ( line != "" ) {
			RES.push_back(line);
		}
	}
	READ.close();
	// CREATE A LIST WITH SESSION'S
	READ.open("./RESULTS", std::ios::in);
	READ.seekg(0,std::ios::beg);
	while (READ) {
		getline(READ, line);
		if ( line != "" ) {
			TEMP.push_back(line);
		}
	}
	READ.close();
	// MERGE THE TWO LISTS (SUM IDENTICAL ELEMENTS)
	TOTAL = SumTotalList( RES, TEMP );
	// RE-ARRANGE BY DECREASING COUNT ORDER
	TOTAL = SortTotalList ( TOTAL );
	// WRITE ON FILE
	WRITE.open("./RESULTS");
	for ( std::string line : TOTAL ) {
		WRITE<< "\n" << line << "\n";
	}
	WRITE.close();

	// WORK ON USER-AGENTS
	UA.clear();
	TEMP.clear();
	TOTAL.clear();
	// CREATE A LIST WITH GLOBAL'S
	READ.open("./USER-AGENTS.tmp", std::ios::in);
	READ.seekg(0,std::ios::beg);
	while (READ) {
		getline(READ, line);
		if ( line != "" ) {
			UA.push_back(line);
		}
	}
	READ.close();
	// CREATE A LIST WITH SESSION'S
	READ.open("./USER-AGENTS", std::ios::in);
	READ.seekg(0,std::ios::beg);
	while (READ) {
		getline(READ, line);
		if ( line != "" ) {
			TEMP.push_back(line);
		}
	}
	READ.close();
	// MERGE THE TWO LISTS (SUM IDENTICAL ELEMENTS)
	TOTAL = SumTotalList( UA, TEMP );
	// RE-ARRANGE BY DECREASING COUNT ORDER
	TOTAL = SortTotalList ( TOTAL );
	// WRITE ON FILE
	WRITE.open("./USER-AGENTS");
	for ( std::string line : TOTAL ) {
		WRITE<< "\n" << line << "\n";
	}
	WRITE.close();

	// DONE
	return 0;
}
