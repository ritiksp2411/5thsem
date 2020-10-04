#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>

using namespace std;
int B;
string ltrim(const string &);
string rtrim(const string &);
void tokenize(std::string const &str, const char* delim,
            std::vector<std::string> &out);
void merge(vector<int>& v, int s, int mid, int e)
{
    int n1 = (mid - s + 1);
    int n2 = (e - mid);
    int Left[n1], Right[n2];
    for (int i=0; i<n1; i++) Left[i] = v[s + i];
    for (int j=0; j<n2; j++) Right[j] = v[mid+1+j];
    int i = 0, j = 0;
    for (int k = s; k <= e; k++) {
        if (j >= n2 || (i < n1 && Left[i] <= Right[j])) v[k] = Left[i++];
        else v[k] = Right[j++];
    }
}

int mergesort(vector<int>& v, int s, int e)
{
    if (s < e) {
        int mid = (s + e) / 2;
        int count = mergesort(v, s, mid) + mergesort(v, mid + 1, e);
        int j = mid + 1;
        for (int i = s; i <= mid; i++){
            while (j <= e && v[i] > v[j] * B) j++;
            count += j - (mid + 1);
        }
        merge(v, s, mid, e);
        return count;
    }
    else
        return 0;
}

int countBinversions(vector<int> v) {
  /* Add your code here. Define appropriate parameters and call this function from main */
  int numBinversions = 0;
  int n=v.size();
  numBinversions=mergesort(v,0,n-1);
  return numBinversions;
}


int main (int argc, char * argv[]) {

  //cout << "Nu of args " << argc << argv[argc-1];

  string filename = argv[argc-1];

  string line;
  ifstream myfile (filename);

  if (myfile.is_open())
  {
    // int numTestCases = getline (myfile,line);

    getline (myfile,line);

    int numTestCases = stoi(ltrim(rtrim(line)));

    for (int i=0; i < numTestCases; i++)
    {
      std::vector<int> A;          // Vector to store the sequence of numbers
      int b;

      std::vector<string> Astr;
      const char* delim = " ";
      getline (myfile,line);
      tokenize(line, delim, Astr);
      
      cout << " Sequence is ";
      // Read in the numbers in the sequence into Vector A
      for (auto &s : Astr) {

        int i = stoi(ltrim(rtrim(s)));
        A.push_back(i);
        cout << i <<" ";

      }

      // Read in the number b
      getline (myfile,line);
      b = stoi(ltrim(rtrim(line)));

      cout << "\nB is " << b << '\n';
      B=b;
      int inv_count=countBinversions(A);
      cout << "No. of B-inversions are : " << inv_count << endl;
    }


    myfile.close();
  }

  else cout << "Unable to open file"; 

  return 0;
}


/* You do not need to modify the code from here below */


void tokenize(std::string const &str, const char* delim,
            std::vector<std::string> &out)
{
    char *token = strtok(const_cast<char*>(str.c_str()), delim);
    while (token != nullptr)
    {
        out.push_back(std::string(token));
        token = strtok(nullptr, delim);
    }
}
string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
