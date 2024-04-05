#include <iostream>
#include <vector>

#define STUDENT_ID "23K0018"
#define DEFAULT_LEVEL "Low"
#define DEFAULT_COST 300
#define MAX_PORTS 23

using namespace std;

const string protocols_list[6] = { "HTTPS", "FTP", "UDP", "ICMP", "SSH", "SNMP" };

class SecurityTool {
protected:
    string securityLevel;
    int numDevices;
    float cost;
public:
    SecurityTool(string level, int devices, float cost) 
        : numDevices(devices), cost(cost <= 0 ? DEFAULT_COST : cost)
    {
        if (!(level == "High" || level == "Medium" || level == "Low"))
            this->securityLevel = DEFAULT_LEVEL;
        else
            this->securityLevel = level;
    }

    void performScan() {
        cout << "generic-security scan performed" << endl;
    }
};

class FirewallTool : public SecurityTool {
private:
    vector<int> ports;
    vector<string> protocols;
public:
    FirewallTool(string level, float cost) : SecurityTool(level, 10, cost) { this->generateList(); }

    void generateList() {
        int digit = STUDENT_ID[6]-'0';
        ports.reserve(23);
        for (int i = 1; i <= MAX_PORTS; i++)
            ports.push_back(digit + i);
    }

    void addProtocol(string protocol) {
        for (int i = 0; i < 6; i++) {
            if (protocol == protocols_list[i]) {
                protocols.push_back(protocol);
                return;
            }
        }
        cout << "Invalid protocol" << endl;
    }

    void performScan() {
        cout << "Performing scan level [" << securityLevel << "]:\n";
        cout << "Allowing traffic from [protocols]:\n";
        for (string protocol : protocols)
            cout << protocol << '\n';
        if (securityLevel == "Low")
            cout << "TCP\nDNS\n";
        cout << "Allowing traffic from [ports]:\n";
        for (int port : ports)
            cout << port << '\n';
        if (securityLevel != "High") {
            int last = ports[22];
            for (int i = 1; i <= (securityLevel == "Medium" ? 2 : 5); i++)
                cout << last+i << '\n';
        }
    }
};

int main() {
    cout << "Fasih Hasan Khan\n23k0018\n\n";

    FirewallTool tool("Medium", 10);
    tool.addProtocol("HTTPS");
    tool.performScan();
    return 0;
}