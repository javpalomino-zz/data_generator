#include<bits/stdc++.h>

using namespace std;

map<string, vector<string> > dictionary;
set<string> all_words;

#define DEBUG

void read_file(string file_name, string key) {
    ifstream file;

    file.open(file_name.c_str(), ios::in);

    if(!file.is_open()) {
        puts("Failed to open");
    }
    else {
        puts("File open");
    }

    string line;

    while(getline(file, line)) {
        if(all_words.find(line) != all_words.end())
            continue;

        all_words.insert(line);
        dictionary[key].push_back(line);
    }

    file.close();
}

void load_dictionary() {
    puts("Loading First names dictionary");
    read_file("data\\first-names.txt", "first_name");
    printf("Loaded %d first names\n", dictionary["first_name"].size());

    puts("Loading Middle names dictionary");
    read_file("data\\middle-names.txt", "middle_name");
    printf("Loaded %d middle names\n", dictionary["middle_name"].size());

    puts("Loading Last names dictionary");
    read_file("data\\names.txt", "last_name");
    printf("Loaded %d last names\n", dictionary["last_name"].size());

    puts("Loading Words dictionary");
    read_file("data\\words.txt", "word");
    printf("Loaded %d words\n", dictionary["word"].size());
}

string query(string key) {
    vector<string> *words_list = &dictionary[key];

    int random_index = rand() % words_list->size();

    return (*words_list)[random_index];
}

string get_name() {
    return  query("first_name");
}

string get_middle_name() {
    return  query("middle_name");
}

string get_last_name() {
    return  query("last_name");
}

string get_word() {
    return  query("word");
}

void init() {
    load_dictionary();
}

string get_random_word() {
    int total_weight = 10;
    int random_value = rand() % total_weight;
    int sz;
    vector<string> bucket;

    if(total_weight < 1) {
        return get_middle_name();
    }
    else if(total_weight < 3) {
        return get_last_name();
    }
    else if(total_weight < 6) {
        return get_name();
    }

    return get_word();
}

string generate_field(int min_words, int max_words) {
    string response = "";

    int number_of_words = rand() % (max_words - min_words) + min_words;

    int total = 0;

    while(total < number_of_words) {
        response += get_random_word();
        response += " ";
        total ++;
    }

    return response;
}

void generate_row() {

    cout << "(" << generate_field(2, 5) << ", " << generate_field(10, 20) << ", " << generate_field(21, 100) << ", " << generate_field(100, 200) << ")" << endl;
}

int main() {
    init();
    freopen("response.txt", "w", stdout);
    for(int i = 0 ; i < 100000 ; ++i) {
        generate_row();
    }

    return 0;
}
