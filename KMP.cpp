
//dfa Deterministic finite state automaton
int search(string txt, vector<vector> >& dfa){
	int final_state = dfa[0].size();
	for(int i=0, j=0;i<txt.size() && j<dfa[0].size();i++){
		j = dfa[txt[i]][j];
	}
	if(j==dfa[0].size()) return i - final_state;
	else return -1;
}