https://www.quora.com/How-do-I-split-a-string-by-space-into-an-array-in-c++

vector<string> inputWords;

string input, word;

cin >> input;

stringstream s(input);

while (getline(s, word, ';')) {

inputWords.push_back(word);

}

vector<string>::iterator it;

for(it=inputWords.begin();it!=inputWords.end();it++)

{

cout<<*it<<endl;

}

