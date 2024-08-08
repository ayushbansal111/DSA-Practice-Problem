class Solution {
public:
    int compress(vector<char>& chars) {
        int write = 0; // Position to write the next character in the array
        int start = 0; // Start position of a group of identical characters

        while (start < chars.size()) {
            int end = start;
            // Find the end of the group of identical characters
            while (end < chars.size() && chars[end] == chars[start]) {
                end++;
            }
            
            // Write the character
            chars[write++] = chars[start];
            
            // If the group size is greater than 1, write the count
            int count = end - start;
            if (count > 1) {
                for (char c : to_string(count)) {
                    chars[write++] = c;
                }
            }

            // Move to the next group
            start = end;
        }

        return write;
    }
};
