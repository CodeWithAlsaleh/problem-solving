#define all(x) x.begin() , x.end()
class Router {
    int maxSize = 0;
    queue<tuple<int,int,int>> packets;
    map<tuple<int,int,int>, int> check;
    unordered_map<int, deque<int>> packetGroup;

    void removePacket() {
        auto packet = packets.front();
        int destination = get<1>(packet);
        
        check.erase(packet);
        packetGroup[destination].pop_front();
        packets.pop();
    }
    
public:
    Router(int memoryLimit) {
        maxSize = memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        tuple<int,int,int> t = make_tuple(source, destination, timestamp);
        
        // Check if the packet is already in the Router
        if(check.find(t) != check.end())
            return false;

        // Add the packet
        check[t] = 1;
        packets.push(t);
        packetGroup[destination].push_back(timestamp);

        // If we exceed the limit remove the oldest packet
        if(packets.size() > maxSize)
            removePacket();

        return true;
    }
    
    vector<int> forwardPacket() {
        if(packets.empty())
            return {};

        auto packet = packets.front();
        removePacket();

        return {get<0>(packet), get<1>(packet), get<2>(packet)};
    }
    
    int getCount(int destination, int startTime, int endTime) {
            
        auto &timestamps = packetGroup[destination];
        
        auto start_it = lower_bound(all(timestamps) , startTime);
        
        auto end_it = upper_bound(all(timestamps) , endTime);
        
        // Count elements in range [startTime, endTime]
        return distance(start_it, end_it);
    }
};
