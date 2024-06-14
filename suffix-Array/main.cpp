#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using std::string, std::vector, std::cout, std::sort, std::endl;

class SuffixArray {
    char *str{};
    int *Group{};
    int *sorGroup{};
    int *suffixIDX{};
    int length{};

    struct Compartor {
        Compartor(int h, int *Group, int length) : h(h), Group(Group), Maxlength(length) {}

        bool operator()(const int &IdxA, const int &IdxB) {
            if (Group[IdxA] != Group[IdxB])
                return Group[IdxA] < Group[IdxB];
            else {
                if (IdxA + h < Maxlength and IdxB + h < Maxlength) {
                    return Group[IdxA + h] < Group[IdxB + h];
                } else {
                    return IdxA > IdxB;
                }
            }
        }

    private:
        int h, *Group, Maxlength;
    };

public:
    SuffixArray(const char *str) {
        length = strlen(str);
        this->str = new char[length + 1];

        strcpy(this->str, str);
        Group = new int[length];
        sorGroup = new int[length];
        suffixIDX = new int[length];
    }

    vector<int> getSortedSuffix() {///Complexity O( log2(n) * (n*log2(n)) )
        for (int i = 0; i < length; ++i) {
            Group[i] = str[i] - 'a';
            suffixIDX[i] = i;
        }
        sort(suffixIDX, suffixIDX + length, Compartor(0, Group, length));
        sorGroup[length - 1] = sorGroup[0] = 0;

        for (int h = 1; sorGroup[length - 1] != length - 1; h <<= 1) {
            sort(suffixIDX, suffixIDX + length, Compartor(h, Group, length));

            for (int i = 1; i < length; ++i) {
                sorGroup[i] = sorGroup[i - 1] + Compartor(h, Group, length)(suffixIDX[i - 1], suffixIDX[i]);
            }
            for (int i = 1; i < length; ++i) {
                Group[suffixIDX[i]] = sorGroup[i];
            }

        }
        vector<int> ans(suffixIDX, suffixIDX + length);

        return ans;
    }

    string getLongestCommonPrefix() {
        string ans;
        for (int i = 1; i < length; ++i) {
            string strTmp;
            for (int j = suffixIDX[i], j2 = suffixIDX[i - 1]; j < length and j2 < length; ++j2, ++j) {
                if (str[j] != str[j2]) {
                    break;
                } else
                    strTmp.push_back(str[j]);
            }
            if (strTmp.size() > ans.size()) {
                ans = strTmp;
            }
            strTmp.clear();
        }

        return ans;
    }

    SuffixArray(string str) {
        SuffixArray(str.c_str());
    }


    ~SuffixArray() {
        delete[] str;
        delete[] Group;
        delete[] sorGroup;
        delete[] suffixIDX;
    }
};

string GenerateSuffix(string str, int idx) {
    string ans;
    for (int i = idx; i < str.size(); ++i) {
        ans.push_back(str.at(i));
    }
    return ans;
}

int main() {
    char *str = "toom";
    cout << str << endl;
    SuffixArray suff(str);
    for (const auto &x: suff.getSortedSuffix()) {
        cout << x << ":  " << GenerateSuffix(str, x) << endl;
    }
    cout << "Longest common Prefix:" << suff.getLongestCommonPrefix() << endl;

    cout << "===================" << endl;
    str = "banana";
    cout << str << endl;
    SuffixArray suff2(str);
    for (const auto &x: suff2.getSortedSuffix()) {
        cout << x << ":  " << GenerateSuffix(str, x) << endl;
    }
    cout << "Longest common Prefix:" << suff2.getLongestCommonPrefix();

    return 0;
}
