#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <sstream>
using namespace std;

struct UserData {
    map<string, set<string>> daily_user_agents;
    map<string, set<string>> daily_ips;
    map<string, int> daily_pdf_count;
    map<string, set<string>> daily_sessions;
    vector<pair<string, string>> pdf_downloads; // {date_time, pdf_name}
};

string extractDate(const string& dateTime) {
    size_t start = dateTime.find('[') + 1;
    size_t end = dateTime.find(':');
    return dateTime.substr(start, end - start);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    string rules_line;
    cin.ignore();
    getline(cin, rules_line);
    
    map<string, int> rules;
    stringstream ss(rules_line);
    string rule;
    while (getline(ss, rule, ',')) {
        rule.erase(0, rule.find_first_not_of(" \t"));
        rule.erase(rule.find_last_not_of(" \t") + 1);
        size_t eq_pos = rule.find('=');
        if (eq_pos != string::npos) {
            string key = rule.substr(0, eq_pos);
            int value = stoi(rule.substr(eq_pos + 1));
            rules[key] = value;
        }
    }
    
    string header;
    getline(cin, header);
    
    map<string, UserData> users;
    
    for (int i = 0; i < n; i++) {
        string line;
        getline(cin, line);
        
        vector<string> fields;
        bool in_quotes = false;
        string current_field;
        
        for (char c : line) {
            if (c == '"') {
                in_quotes = !in_quotes;
                current_field += c;
            } else if (c == ' ' && !in_quotes) {
                if (!current_field.empty()) {
                    fields.push_back(current_field);
                    current_field.clear();
                }
            } else {
                current_field += c;
            }
        }
        if (!current_field.empty()) {
            fields.push_back(current_field);
        }
        
        if (fields.size() >= 8) {
            string host = fields[0];
            string client_ip = fields[1];
            string id = fields[2];
            string date = fields[3];
            string request = fields[4];
            string http_status = fields[5];
            string user_agent = fields[6];
            string session_cookie = fields[7];
            
            if (id != "-" && http_status == "200") {
                string day = extractDate(date);
                UserData& user = users[id];
                
                user.daily_user_agents[day].insert(user_agent);
                user.daily_ips[day].insert(client_ip);
                user.daily_sessions[day].insert(session_cookie);
                
                if (request.find("/document/") != string::npos && 
                    request.find(".pdf") != string::npos) {
                    user.daily_pdf_count[day]++;
                    
                    size_t start = request.find("/document/") + 10;
                    size_t end = request.find(".pdf");
                    if (start != string::npos && end != string::npos) {
                        string pdf_name = request.substr(start, end - start);
                        user.pdf_downloads.push_back({date, pdf_name});
                    }
                }
            }
        }
    }
    
    vector<pair<string, string>> violations;
    
    for (const auto& [id, user] : users) {
        if (rules.count("agent")) {
            for (const auto& [day, agents] : user.daily_user_agents) {
                if ((int)agents.size() >= rules["agent"]) {
                    violations.push_back({id, "agent=" + to_string(rules["agent"])});
                    break;
                }
            }
        }
        
        if (rules.count("ip")) {
            for (const auto& [day, ips] : user.daily_ips) {
                if ((int)ips.size() >= rules["ip"]) {
                    violations.push_back({id, "ip=" + to_string(rules["ip"])});
                    break;
                }
            }
        }
        
        if (rules.count("pdf")) {
            for (const auto& [day, count] : user.daily_pdf_count) {
                if (count >= rules["pdf"]) {
                    violations.push_back({id, "pdf=" + to_string(rules["pdf"])});
                    break;
                }
            }
        }
        
        if (rules.count("session")) {
            for (const auto& [day, sessions] : user.daily_sessions) {
                if ((int)sessions.size() >= rules["session"]) {
                    violations.push_back({id, "session=" + to_string(rules["session"])});
                    break;
                }
            }
        }
        
        if (rules.count("crawl")) {
            map<string, vector<string>> daily_pdfs;
            for (const auto& [date_time, pdf_name] : user.pdf_downloads) {
                string day = extractDate(date_time);
                daily_pdfs[day].push_back(pdf_name);
            }
            
            for (const auto& [day, pdfs] : daily_pdfs) {
                vector<string> pdf_copy = pdfs;
                sort(pdf_copy.begin(), pdf_copy.end());
                int max_seq = 1;
                int current_seq = 1;
                
                for (int i = 1; i < (int)pdf_copy.size(); i++) {
                    string prev_pdf = pdf_copy[i-1];
                    string curr_pdf = pdf_copy[i];
                    
                    if (!prev_pdf.empty() && !curr_pdf.empty() && 
                        isdigit(prev_pdf[0]) && isdigit(curr_pdf[0])) {
                        int prev_num = stoi(prev_pdf);
                        int curr_num = stoi(curr_pdf);
                        if (curr_num == prev_num + 1) {
                            current_seq++;
                            max_seq = max(max_seq, current_seq);
                        } else {
                            current_seq = 1;
                        }
                    } else {
                        current_seq = 1;
                    }
                }
                
                if (max_seq >= rules["crawl"]) {
                    violations.push_back({id, "crawl=" + to_string(rules["crawl"])});
                    break;
                }
            }
        }
    }
    
    sort(violations.begin(), violations.end());
    
    if (violations.empty()) {
        cout << "N/A" << endl;
    } else {
        for (const auto& [id, violation] : violations) {
            cout << id << " " << violation << endl;
        }
    }
    
    return 0;
}
