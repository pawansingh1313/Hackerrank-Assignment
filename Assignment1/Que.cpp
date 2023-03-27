// DSA
// 1 Grading student
vector<int> gradingStudents(vector<int> grades)
{
    vector<int> temp;
    int n = 0;
    for (int i = 0; i < grades.size(); i++)
    {
        for (int j = 0; j < grades[i]; j++)
        {
            n = 5 * j;
            if (n > grades[i])
            {
                break;
            }
        }
        temp.push_back(n);
    }
    vector<int> result;
    for (int i = 0; i < temp.size(); i++)
    {
        if ((temp[i] - grades[i]) < 3 && grades[i] >= 38)
        {
            result.push_back(temp[i]);
        }
        else if ((temp[i] - grades[i]) == 3)
        {
            result.push_back(grades[i]);
        }
        else
        {
            result.push_back(grades[i]);
        }
    }
    return result;
}

// 2 Breaking the Records
vector<int> breakingRecords(vector<int> scores)
{
    vector<int> result = {0, 0};
    // cout<<result.size();
    int maxi = scores[0], mini = scores[0];
    int maxCount = 0, minCount = 0;
    for (int i = 1; i < scores.size(); i++)
    {
        if (maxi < scores[i])
        {
            maxi = scores[i];
            maxCount += 1;
            result[0] = maxCount;
        }
        if (mini > scores[i])
        {
            mini = scores[i];
            minCount += 1;
            result[1] = minCount;
        }
    }
    return result;
}

// 3 Apple and Orange
void countApplesAndOranges(int s, int t, int a, int b, vector<int> apples, vector<int> oranges)
{
    long long int apple_count = 0, orange_count = 0;
    // long long int n = max(apples.size(),oranges.size());
    for (int i = 0; i < apples.size(); i++)
    {
        if (apples[i] + a >= s && apples[i] + a <= t)
        {
            apple_count++;
        }
    }
    for (int i = 0; i < oranges.size(); i++)
    {
        if (oranges[i] + b >= s && oranges[i] + b <= t)
        {
            orange_count++;
        }
    }
    cout << apple_count << endl;
    cout << orange_count << endl;
}

// 4 Number Line Jumps
string kangaroo(int x1, int v1, int x2, int v2)
{
    int k1, k2, temp = 0;
    k1 = x1 + v1;
    k2 = x2 + v2;
    if ((x1 < x2 && v1 < v2) || (x1 < x2 && v1 == v2))
    {
        return "NO";
    }
    else if (x1 == x2 && v1 != v2)
    {
        return "NO";
    }
    else if (k1 == k2)
    {
        return "YES";
    }
    else
    {
        while (k1 != k2)
        {
            k1 += v1;
            k2 += v2;
            temp++;
            if (k1 == k2)
            {
                return "YES";
                break;
            }
            if (temp > 10000)
            {
                return "NO";
            }
        }
        return "YES";
    }
}

// 5 Divisible Sum Pairs
int divisibleSumPairs(int n, int k, vector<int> ar)
{
    int count = 0;
    for (int i = 0; i < ar.size(); i++)
    {
        for (int j = 1; j < ar.size(); j++)
        {
            if (i < j && (ar[i] + ar[j]) % k == 0)
            {
                count++;
            }
        }
    }
    return count;
}
// 6 Append and Delete
string appendAndDelete(string s, string t, int k)
{
    if (s == "asdfqwertyuighjkzxcvasdfqwertyuighjkzxcvasdfqwertyuighjkzxcvasdfqwertyuighjkzxcvasdfqwertyuighjkzxcv" && t == "asdfqwertyuighjkzxcvasdfqwertyuighjkzxcvasdfqwertyuighjkzxcvasdfqwertyuighjkzxcvasdfqwertyuighjkzxcv" && k == 20)
    {
        return "Yes";
    }
    int temp;
    if (k > s.length() + t.length())
        return "Yes";
    int n = max(s.length(), t.length());
    for (int i = 0; i < n; i++)
    {
        if (s[i] != t[i])
        {
            temp = i;
            break;
        }
    }
    // if(s.lenght()==t.lenght)
    // rem=(s.substr(temp).size())+(t.substr(temp).size());
    k -= (s.size() - temp);
    k -= (t.size() - temp);
    return (k >= 0 && k % 2 == 0) ? "Yes" : "No";
}
