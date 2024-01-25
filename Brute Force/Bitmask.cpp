/*
    Goes through all 2^N subsets of a set 
    
    Complexity: O(2^N)
*/

for(int mask = 0; mask < (1 << n); mask++)
{
    for(int bit = 0; bit < n; bit++)
    {
        if(mask & (1 << bit))
        {
            // Do something
        }else{
            // Do something else
        }
    }
}