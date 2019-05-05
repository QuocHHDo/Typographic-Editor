#include <iostream>
#include <string> 
#include <vector>
using namespace std;

vector<string> tokenizer(string line) { 
    vector <string> words;
    string word = "";
    bool found = false;
    for (int i = 0, len = line.length(); i < len; ++i) {
        if (!isspace(line.at(i))) {
            found = true;
            word += line.at(i);
            continue;
        }
        if (found) {
            words.push_back(word);
            word ="";
            found = false;
        }
    }
    if (found) words.push_back(word);
    return words;
}
	
int main() {
        string align;
        int width;
        string text;
        vector <string> wlist;
        while (true) {
            cout << "> ";
            getline(cin, text);
            if (text == "") break;
            
            vector <string> text_wlist = tokenizer(text);
            wlist.insert(wlist.end(), text_wlist.begin(), text_wlist.end());
        }
//        for (int i = 0, len = wlist.size(); i < len; ++i)
//        cout << i + 1 << ": " << wlist.at(i) << endl;
	
	while (true) { 
		
	cout << "Enter left|right|center and paragraph width: ";
	cin >> align >> width; 
	if (width == 0) break; //PART (6)
	if (align == "center" || align == "right" || align == "left") {// FINDING LONGESTWORD 
	    string word = "";
	    string longestWord = "";
        

		for (int i = 1; i < wlist.size(); ++i) {
			if (wlist.at(i).size() > longestWord.size()) {
				longestWord = wlist.at(i);
			}
		}
 //        cout << longestWord.size() << endl;	

	if (longestWord.size() > width) {
		cout << "Paragraph width too small to fit the longest word of size " << longestWord.size() << "..." << endl;
		continue;
	}
	
	// PART (4)
	string box; 
	if (width >= 10) {
		for( int i = 0; i < (width/10); ++i) { //for every 10 unit of width
		box.append("---------+");
		}
		if (width % 10 != 0) {
			for(int i = 0; i < (width % 10); ++i) {
				box.append("-");
			}
		}
	}
		if (width < 10) {
		    for (int i = 0; i < width; ++i) {
		        box.append("-");
		    }
	}

	cout << "+" << box << "+" << endl;
	
	
    string totalText = "";
	int totalLength = 0;  
	int remainSpace = 0;
	int updateSpace = 0; 
	string newText = "";
	int updateLength = 0;
	string updateText = "";
	
	if (align == "left") {
	   	    
	    for (unsigned int i = 0; i < wlist.size(); ++i) { //ex: ok bye width = 7
	        totalLength = wlist.at(i).size(); // 3
			if (updateLength != 0) {
				totalLength = updateLength; // 6
			}
	        totalText = wlist.at(i); // ok
			if (updateText != "") {
				totalText = updateText + wlist.at(i); // ok_bye
			}
	         remainSpace = width - totalLength; // 5
	         if (updateSpace != 0) {
			 remainSpace = updateSpace; // 1
			 }

	       	
			if (remainSpace == 0) { //  
	            cout << "|" << totalText << "|" << endl;
			    updateText = "";
	            updateSpace = 0;
	            updateLength = 0;
	            
	        } 
	        else if (remainSpace == 1) { // 
	            cout << "|" << totalText + " " << "|" << endl; //output: |ok_bye_| 
	            updateText = "";
	            updateSpace = 0;
	            updateLength = 0;
	        }

	        else if (remainSpace > 1 && wlist.at(i) != wlist.back() ) { // if remainSpace > 1 and i is not last word
	            updateLength = totalLength + wlist.at(i+1).size() + 1; // updateLength = 6
	            remainSpace = width - updateLength; // remainSpace = 1
	            
	            
	            if (remainSpace < 0) {
	                int spacing = width - totalLength - 1;
					string space = ""; 
					for (int j = 0; j <= spacing; ++j) {
						space.append(" ");
					}
	                cout << "|" << totalText << space << "|" << endl;   
					updateText = "";
					updateSpace = 0;
					updateLength = 0;
	                
	            }
				
	            else if (remainSpace >= 0) {
	                updateText = totalText + " "; // updateText = ok_  
					updateSpace = remainSpace; // 1
					totalText = "";
	                totalLength = 0;
	                                    
	                }
	        }
	        else if (remainSpace > 1 && wlist.at(i) == wlist.back()) { // if remain space > 1 but i is the last word
	            int spacing = width - totalLength - 1; //  //Do I need -1?
	            string space = "";
	            for (int j = 0; j <= spacing; ++j) {
	                space.append(" ");
	            }
	            cout << "|" << totalText << space << "|" << endl; // 
				updateText = "";
	            updateSpace = 0;
	            updateLength = 0;
	            } 
	    }
	}
	if (align == "right") {
	    for (unsigned int i = 0; i < wlist.size(); ++i) { //ex: hello ok width = 8
	        totalLength = wlist.at(i).size(); //2
			if (updateLength != 0) {
				totalLength = updateLength; // 5
			}
	        totalText = wlist.at(i); // hi
			if (updateText != "") {
				totalText = updateText + wlist.at(i); // hi
			}
	         remainSpace = width - totalLength; // 5 - 5
	         if (updateSpace != 0) {
			 remainSpace = updateSpace; // 
			 }

	       	
	       	 if (remainSpace == 0) { //  
	            cout << "|" << totalText << "|" << endl;
			    updateText = "";
	            updateSpace = 0;
	            updateLength = 0;
	            
	        } 
	        else if (remainSpace == 1) { // 
	            cout << "|" << " " + totalText << "|" << endl;
	            updateText = "";
	            updateSpace = 0;
	            updateLength = 0;
	        }

	        else if (remainSpace > 1 && wlist.at(i) != wlist.back() ) { // if remainSpace > 1 and i is not last word
	            updateLength = totalLength + wlist.at(i+1).size() + 1; // updateLength = 5
	            remainSpace = width - updateLength; // remainSpace = 0
	            
	            
	            if (remainSpace < 0) {
	                int spacing = width - totalLength - 1;
					string space = ""; 
					for (int j = 0; j <= spacing; ++j) {
						space.append(" ");
					}
	                cout << "|" << space << totalText << "|" << endl;   
					updateText = "";
					updateSpace = 0;
					updateLength = 0;
	                
	            }
	
	            else if (remainSpace >= 0) {
	                updateText = totalText + " "; // updateText =  
					updateSpace = remainSpace; // 
					totalText = "";
	                totalLength = 0;
	                                    
	                }
	        }
	        else if (remainSpace > 1 && wlist.at(i) == wlist.back()) { // if remain space > 1 but i is the last word
	            int spacing = width - totalLength - 1; //  //Do I need -1?
	            string space = "";
	            for (int j = 0; j <= spacing; ++j) {
	                space.append(" ");
	            }
	            cout << "|" << space << totalText << "|" << endl; // 
				updateText = "";
	            updateSpace = 0;
	            updateLength = 0;
	            } 
	    }
		}
	if (align == "center") {
			    for (unsigned int i = 0; i < wlist.size(); ++i) { //text: hello, width 7
	        totalLength = wlist.at(i).size(); // 5
			if (updateLength != 0) {
				totalLength = updateLength; // 
			}
	        totalText = wlist.at(i); // hello
			if (updateText != "") {
				totalText = updateText + wlist.at(i); //  
			}
	         remainSpace = width - totalLength; // 2
	         if (updateSpace != 0) {
			 remainSpace = updateSpace; // 
			 }

	       	
	       	 if (remainSpace == 0) { // if total words is the same as width
	            cout << "|" << totalText << "|" << endl;
			    updateText = "";
	            updateSpace = 0;
	            updateLength = 0;
	            
	        } 
	        else if (remainSpace == 1) { // if total words + space is same as width
	            cout << "|" << totalText + " " << "|" << endl;
	            updateText = "";
	            updateSpace = 0;
	            updateLength = 0;
	        }

	        else if (remainSpace > 1 && wlist.at(i) != wlist.back() ) { // if remainSpace > 1 and i is not last word
	            updateLength = totalLength + wlist.at(i+1).size() + 1; // updateLength = 8,
	            remainSpace = width - updateLength; // remainSpace = 2
	            
	            
	            if (remainSpace < 0) {
	                int spacing = width - totalLength; // maybe remove - 1?
					string space = ""; 
				if (spacing % 2 == 0) { // even {
					for (int j = 0; j < spacing/2; ++j) {
	                space.append(" ");
					}					// remaining space 4
					cout << "|" << space << totalText << space << "|" << endl;
				}	
				if (spacing % 2 != 0) { //odd
					for (int j = 0; j < spacing/2; ++j) {
	                space.append(" ");
					}					// remaining space 4
					cout << "|" << space << totalText << space << " " << "|" << endl;
				}
					updateText = "";
					updateSpace = 0;
					updateLength = 0;
	                
	            }
	
	            else if (remainSpace >= 0) {
	                updateText = totalText + " "; // updateText = hello_ , 
					updateSpace = remainSpace; // 2
					totalText = "";
	                totalLength = 0;
	                                    
	                }
	        }
	        else if (remainSpace > 1 && wlist.at(i) == wlist.back()) { // if remain space > 1 but i is the last word
	            int spacing = width - totalLength; // 7-5 = 2 // maybe -1 ?*** 
	            string space = "";
				
				if (spacing % 2 == 0) { // even {
					for (int j = 0; j < spacing/2; ++j) { //maybe = sign?
	                space.append(" "); // maybe "" instead of " " 
					}					// remaining space 4
					cout << "|" << space << totalText << space <<  "|" << endl;
				}	
				if (spacing % 2 != 0) { //odd
					for (int j = 0; j < spacing/2; ++j) {
	                space.append(" ");
					}					// remaining space 4
					cout << "|" << space << totalText << space << " " << "|" << endl;
				}
				updateText = "";
	            updateSpace = 0;
	            updateLength = 0;
	            } 
	    }
		}
	
	cout << "+" << box << "+" << endl;
	} // PUT  MAIN CODE INSIDE THIS BRACE!!
  else { 
		cout << "Invalid justification command..." << endl;
		} 
	}

	cout << "Bye..." << endl;
	return 0;
}
