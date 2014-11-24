#include "ass6_12CS10008_translator.h"
#include <boost/program_options.hpp>

extern FILE *yyin;
extern vector <string> allstrings;

namespace po = boost::program_options;

int gblcount=0;						// Label count in asm file
std::map<int, int> labels;			// map from quad number to label number
ofstream out;						// asm file stream
vector <quad> array;				// quad array
string sfilepath;					// asm file name
string inputfile;					// input file name

string removeExtension(const string filename) { // Remove extension from file name
	size_t lastdot = filename.find_last_of('.');
	if (lastdot == string::npos) return filename;
	return filename.substr(0, lastdot); 
}
void findlabels() { // Find all the target for labels from the jump statements
	for (vector<quad>::iterator it = array.begin(); it!=array.end(); it++) {
		int i;
		switch (it->op) {
			case LT:
			case GT:
			case LE:
			case GE:
			case EQOP:
			case NEOP:
			case GOTOOP:
			i = atoi(it->result.c_str());
			labels [i] = 1;
			break;
			default:
			break;
		}
	}
	int count = 0;
	for (std::map<int,int>::iterator it=labels.begin(); it!=labels.end(); ++it)
		it->second = count++;
//	for (std::map<int,int>::iterator it=labels.begin(); it!=labels.end(); ++it)
//		std::out << it->first << " => " << it->second << '\n';
}
inline bool isInteger(const std::string & s) {
	if(s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false ;
	char * p ;
	strtol(s.c_str(), &p, 10) ;
	return (*p == 0) ;
}
void computeActivationRecord(symtab* st) {
	int param = 8;
	int local = -4;
	for (list <sym>::iterator it = st->table.begin(); it!=st->table.end(); it++) {
		if (it->category =="param") {
			st->ar [it->name] = param;
			param +=it->size;			
		}
		else {
			if (it->name=="retVal") continue;
			else {
				st->ar [it->name] = local;
				local -=it->size;
			}
		}
	}
	/*
	for (std::map<string,int>::iterator it=st->ar.begin(); it!=st->ar.end(); ++it)
		std::out << it->first << " => " << it->second << '\n';
	out << endl;
	*/
}
void genasm() {
	array = qarr.array;
	findlabels();
	list<symtab*> tablelist;
	for (list <sym>::iterator it = gTable->table.begin(); it!=gTable->table.end(); it++) {
		if (it->nest!=NULL) tablelist.push_back (it->nest);
	}
	for (list<symtab*>::iterator iterator = tablelist.begin(); 
		iterator != tablelist.end(); ++iterator) {
		computeActivationRecord(*iterator);
	}
	ofstream asmfile;
	asmfile.open (sfilepath.c_str());

	asmfile << "\t.file	\"test.c\"\n";
	for (list <sym>::iterator it = table->table.begin(); it!=table->table.end(); it++) {
		if (it->category!="function") {
			if (it->type->cat==_CHAR) { // Global char
				if (it->init!="") {
					asmfile << "\t.globl\t" << it->name << "\n";
					asmfile << "\t.type\t" << it->name << ", @object\n";
					asmfile << "\t.size\t" << it->name << ", 1\n";
					asmfile << it->name <<":\n";
					asmfile << "\t.byte\t" << atoi( it->init.c_str()) << "\n";
				}
				else {
					asmfile << "\t.comm\t" << it->name << ",1,1\n";
				}
			}
			if (it->type->cat==_INT) { // Global int
				if (it->init!="") {
					asmfile << "\t.globl\t" << it->name << "\n";
					asmfile << "\t.data\n";
					asmfile << "\t.align 4\n";
					asmfile << "\t.type\t" << it->name << ", @object\n";
					asmfile << "\t.size\t" << it->name << ", 4\n";
					asmfile << it->name <<":\n";
					asmfile << "\t.long\t" << it->init << "\n";
				}
				else {
					asmfile << "\t.comm\t" << it->name << ",4,4\n";
				}
			}
		}
	}
	if (allstrings.size()) {
		asmfile << "\t.section\t.rodata\n";
		for (vector<string>::iterator it = allstrings.begin(); it!=allstrings.end(); it++) {
			asmfile << ".LC" << it - allstrings.begin() << ":\n";
			asmfile << "\t.string\t" << *it << "\n";	
		}	
	}
	asmfile << "\t.text	\n";
	for (vector<quad>::iterator it = array.begin(); it!=array.end(); it++) {
		if (labels.count(it - array.begin())) {
			asmfile << ".L" << (2*gblcount+labels.at(it - array.begin()) + 2 )<< ": " << endl;
		}
		asmfile << &*it;
	//	it->print();
	}
	asmfile << 	"\t.ident\t	\"Compiled by Aseem Patni\"\n";
	asmfile << 	"\t.section\t.note.GNU-stack,\"\",@progbits\n";
	asmfile.close();
}
vector<string> params;
ostream& operator<<(ostream& os, const quad* q) {
	optype op = q->op;
	string result = q->result;
	string arg1 = q->arg1;
	string arg2 = q->arg2;
	if(op==PARAM){
		params.push_back(result);
		return os;
	}
	os << "\t";
	switch(op) {
		// Binary Operations
		case ADD: {
			if (isInteger(arg2))
				os << "addl \t$" << atoi(arg2.c_str()) << ", " << table->ar[arg1] << "(%ebp)";
			else {
				os << "movl \t" << table->ar[arg1] << "(%ebp), " << "%eax" << endl;
					os << "\tmovl \t" << table->ar[arg2] << "(%ebp), " << "%edx" << endl;
				os << "\taddl \t%edx, %eax\n";
				os << "\tmovl \t%eax, " << table->ar[result] << "(%ebp)";
			}
			break;
		}
		case SUB:{
			os << "movl \t" << table->ar[arg1] << "(%ebp), " << "%eax" << endl;
			os << "\tmovl \t" << table->ar[arg2] << "(%ebp), " << "%edx" << endl;
			os << "\tsubl \t%edx, %eax\n";
			os << "\tmovl \t%eax, " << table->ar[result] << "(%ebp)";
			break;
		}
		case MULT: {
			os << "movl \t" << table->ar[arg1] << "(%ebp), " << "%eax" << endl;
			if (isInteger(arg2))
				os << "\timull \t$" << atoi(arg2.c_str()) << ", " << "%eax" << endl;
			else
				os << "\timull \t" << table->ar[arg2] << "(%ebp), " << "%eax" << endl;
			os << "\tmovl \t%eax, " << table->ar[result] << "(%ebp)";
			break;			
		}
		case DIVIDE: {
			os << "movl \t" << table->ar[arg1] << "(%ebp), " << "%eax" << endl;
			os << "\tcltd" << endl;
			os << "\tidivl \t" << table->ar[arg2] << "(%ebp)" << endl;
			os << "\tmovl \t%eax, " << table->ar[result] << "(%ebp)";
			break;			
		}

		// Bit Operators /* Ignored */
		case MODOP:			os << result << " = " << arg1 << " % " << arg2;				break;
		case XOR:			os << result << " = " << arg1 << " ^ " << arg2;				break;
		case INOR:			os << result << " = " << arg1 << " | " << arg2;				break;
		case BAND:			os << result << " = " << arg1 << " & " << arg2;				break;
		// Shift Operations /* Ignored */
		case LEFTOP:		os << result << " = " << arg1 << " << " << arg2;				break;
		case RIGHTOP:		os << result << " = " << arg1 << " >> " << arg2;				break;

		case EQUAL:	{
			if(isInteger(arg1))
				os << "movl\t$" << atoi(arg1.c_str()) << ", " << "%eax" << endl;
			else
				os << "movl\t" << table->ar[arg1] << "(%ebp), " << "%eax" << endl;
			os << "\tmovl \t%eax, " << table->ar[result] << "(%ebp)";
			break;
		}			
		case EQUALSTR:	{
			os << "movl \t$.LC" << arg1 << ", " << table->ar[result] << "(%ebp)";
			break;
		}
		case EQUALCHAR:	{
			os << "movb\t$" << atoi(arg1.c_str()) << ", " << table->ar[result] << "(%ebp)";
			break;
		}					
		// Relational Operations
		case EQOP: {
			os << "movl\t" << table->ar[arg1] << "(%ebp), %eax\n";
			os << "\tcmpl\t" << table->ar[arg2] << "(%ebp), %eax\n";
			os << "\tje .L" << (2*gblcount+labels.at(atoi( result.c_str() )) +2 );
			break;
		}
		case NEOP: {
			os << "movl\t" << table->ar[arg1] << "(%ebp), %eax\n";
			os << "\tcmpl\t" << table->ar[arg2] << "(%ebp), %eax\n";
			os << "\tjne .L" << (2*gblcount+labels.at(atoi( result.c_str() )) +2 );
			break;
		}
		case LT: {
			os << "movl\t" << table->ar[arg1] << "(%ebp), %eax\n";
			os << "\tcmpl\t" << table->ar[arg2] << "(%ebp), %eax\n";
			os << "\tjl .L" << (2*gblcount+labels.at(atoi( result.c_str() )) +2 );
			break;
		}
		case GT:{
			os << "movl\t" << table->ar[arg1] << "(%ebp), %eax\n";
			os << "\tcmpl\t" << table->ar[arg2] << "(%ebp), %eax\n";
			os << "\tjg .L" << (2*gblcount+labels.at(atoi( result.c_str() )) +2 );
			break;
		}
		case GE:{
			os << "movl\t" << table->ar[arg1] << "(%ebp), %eax\n";
			os << "\tcmpl\t" << table->ar[arg2] << "(%ebp), %eax\n";
			os << "\tjge .L" << (2*gblcount+labels.at(atoi( result.c_str() )) +2 );
			break;
		}
		case LE:{
			os << "movl\t" << table->ar[arg1] << "(%ebp), %eax\n";
			os << "\tcmpl\t" << table->ar[arg2] << "(%ebp), %eax\n";
			os << "\tjle .L" << (2*gblcount+labels.at(atoi( result.c_str() )) +2 );
			break;
		}
		case GOTOOP:{
			os << "jmp .L" << (2*gblcount+labels.at(atoi( result.c_str() )) +2 );
			break;
		}
		// Unary Operators
		case ADDRESS:{
			os << "leal\t" << table->ar[arg1] << "(%ebp), %eax\n";
			os << "\tmovl \t%eax, " <<  table->ar[result] << "(%ebp)";
			break;
		}
		case PTRR: {
			os << "movl\t" << table->ar[arg1] << "(%ebp), %eax\n";
			os << "\tmovl\t(%eax),%eax\n";
			os << "\tmovl \t%eax, " <<  table->ar[result] << "(%ebp)";
			break;	
		}
		case PTRL: {
			os << "movl\t" << table->ar[result] << "(%ebp), %eax\n";
			os << "\tmovl\t" << table->ar[arg1] << "(%ebp), %edx\n";
			os << "\tmovl\t%edx, (%eax)";
			break;
		} 			
		case UMINUS:{
			os << "negl\t" << table->ar[arg1] << "(%ebp)";
			break;
		}
		case BNOT:			os << result 	<< " = ~" << arg1;				break;
		case LNOT:			os << result 	<< " = !" << arg1;				break;
		case ARRR: {
			os << "movl\t" << table->ar[arg2] << "(%ebp), "<<"%eax" << endl;
			os << "\tmovl\t" << table->ar[arg1] << "(%ebp,%eax,1), "<<"%eax" << endl;
			os << "\tmovl \t%eax, " <<  table->ar[result] << "(%ebp)";
			break;
		}	 			
		case ARRL: {
			os << "movl\t" << table->ar[arg1] << "(%ebp), "<<"%eax" << endl;
			os << "\tmovl\t" << table->ar[arg2] << "(%ebp), "<<"%edx" << endl;
			os << "\tmovl\t" << "%edx, " << table->ar[result] << "(%ebp,%eax,1)";
			break;
		}	 
		case _RETURN: {
			if(result!="") os << "movl\t" << table->ar[result] << "(%ebp), "<<"%eax";
			else os << "nop";
			break;
		}
		case PARAM: {
			params.push_back(result);
			break;
		}
		case CALL: {
			// Function Table
			symtab* t = gTable->lookup (arg1)->nest;
			int i;	// index
			for (list <sym>::iterator it = t->table.begin(); it!=t->table.end(); it++) {
				i = distance ( t->table.begin(), it);
				if (it->category== "param") {
					os << "movl \t" << table->ar[params[i]] << "(%ebp), " << "%eax" << endl;
					os << "\tmovl \t%eax, " << (t->ar[it->name]-8 )<< "(%esp)\n\t";
				}
				else break;
			}
			params.clear();
			os << "call\t"<< arg1 << endl;
			os << "\tmovl\t%eax, " << table->ar[result] << "(%ebp)";
			break;
		}
		case FUNC: {
			os <<".globl\t" << result << "\n";
			os << "\t.type\t"	<< result << ", @function\n";
			os << result << ": \n";
			os << ".LFB" << gblcount <<":" << endl;
			os << "\t.cfi_startproc" << endl;
			os << "\tpushl \t%ebp" << endl;
			os << "\t.cfi_def_cfa_offset 8" << endl;
			os << "\t.cfi_offset 5, -8" << endl;
			os << "\tmovl \t%esp, %ebp" << endl;
			os << "\t.cfi_def_cfa_register 5" << endl;
			table = gTable->lookup(result)->nest;
			os << "\tsubl\t$" << table->table.back().offset << ", %esp";
			break;
		}		
		case FUNCEND: {
			os << "leave\n";
			os << "\t.cfi_restore 5\n";
			os << "\t.cfi_def_cfa 4, 4\n";
			os << "\tret\n";
			os << "\t.cfi_endproc" << endl;
			os << ".LFE" << gblcount++ <<":" << endl;
			os << "\t.size\t"<< result << ", .-" << result;
			break;

		}
		default:			os << "op";							break;
	}
	os << endl;
	return os;
}


// A helper function to simplify the main part.
template<class T>
ostream& operator<<(ostream& os, const vector<T>& v)
{
	copy(v.begin(), v.end(), ostream_iterator<T>(os, " ")); 
	return os;
}

void translate() {
	gTable = new symtab("Global");
	table = gTable;
	yyin = fopen(inputfile.c_str(),"r"); 
//	out << "here" << inputfile;
	yyparse();
	table = gTable;
	table->computeOffsets();
	table->print(1);
	qarr.print();
	genasm();
}
int  main (int ac, char* av[]) {
	int x;
	string ofilepath;
	
	try {

		po::options_description desc("Allowed options");
		desc.add_options()
		("help", "produce help message")
		("debug", po::value<int>(&x), "set debugging on/off")
		("sfilepath,s", po::value< vector<string> >(), "filename for generated .s file")
		("ofilename,l", po::value< vector<string> >(), "filename for generated log file")
		("input-file,i", po::value< vector<string> >(), "input file name")
		;

		po::positional_options_description p;
		p.add("input-file", -1);

		po::variables_map vm;
		po::store(po::command_line_parser(ac, av).
			options(desc).positional(p).run(), vm);
		po::notify(vm);

		if (vm.count("help")) {
			out << desc << "\n";
			return 0;
		}

		if (vm.count("input-file"))	inputfile = vm["input-file"].as< vector<string> >()[0];
		else inputfile = "test.c";

		if (vm.count("ofilename")) ofilepath = vm["ofilename"].as< vector<string> >()[0];
		else ofilepath = removeExtension(inputfile) = "quad.log";

		if (vm.count("sfilepath")) sfilepath = vm["sfilepath"].as< vector<string> >()[0];
		else sfilepath = removeExtension(inputfile) = "asm.s";


		out.open (ofilepath.c_str());
	}
	catch(exception& e) {
		cerr << "error: " << e.what() << "\n";
		return 1;
	}
	catch(...) {
		cerr << "Exception of unknown type!\n";
	}

//    std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
  //  std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!

	cout << "Input file is " << inputfile << endl;
	cout << "Assembly file generated is " << sfilepath << endl;
	cout << "Quads and Symbol Table are stored in " << ofilepath <<  endl << endl;
//	inputfile = "test.c";
	translate();
};