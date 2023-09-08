#include <iostream>
#include <map>

void countDuplicates(char arr[])
{
    std::map<char, int> map = {};
    int i = 0;

    while (arr[i] != '\0')
    {
        map[arr[i]]++;
        ++i;
    }

    for (auto it = map.begin(); it != map.end(); ++it)
    {
        if (it->second > 1)
            std::cout << it->first << " (" << it->second << " times)\n";
    }
}
int main(void)
{
    char arr[10] = {};
    std::cout << "Enter a series of characters: ";
    std::cin >> arr;
    countDuplicates(arr);
    return EXIT_SUCCESS;
}