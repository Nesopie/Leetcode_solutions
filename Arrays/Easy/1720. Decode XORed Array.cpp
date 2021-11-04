//Time Complexity: O(n);
//Space Complexity: O(1)

class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        int size = encoded.size() + 1;
        vector<int> decoded(size);

        decoded[0] = first;
        for(int i = 1; i < size; i++) {
            //encoded[i] = decoded[i] ^ decoded[i + 1] -> this is given in the question
            //encoded[0] = decoded[0] ^ decoded[1] substituting i = 1
            //encoded[0] = first ^ decoded[1]
            //encoded[0] ^ first = decoded[1] ^ first ^ first
            //encoded[0] ^ first = decoded[1] ^ 0, since a ^ a = 0
            //encoded[0] ^ first = decoded[1], since a ^ 0 = a
            //In general, decoded[i] = decoded[i - 1] ^ encoded[i - 1]
            decoded[i] = encoded[i - 1] ^ decoded[i - 1];
        }

        return decoded;
    }
};
