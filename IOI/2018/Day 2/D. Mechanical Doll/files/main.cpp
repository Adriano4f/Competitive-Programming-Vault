#include "doll.h"
 
#include <bits/stdc++.h>
 
using namespace std;
 
vector<int> C, X, Y, state;
int s_count = 0;
 
void simulate_and_form(int32_t &idx, const int32_t original_count, int32_t &left, const vector<int> &d_adj, const int32_t &root, int32_t &offset)
{
 
    int count = original_count;
 
    while ( (size_t)offset < d_adj.size() )
    {
        if ( root == idx )
            count = original_count;
 
        if (-idx > s_count)
        {
            ++s_count;
            X.push_back(0), Y.push_back(0), state.push_back(0);
        }
        state[-idx - 1] = !state[-idx - 1];
 
        // When X
        if( state[-idx - 1] ) //                    State is X or Y
        {
            if ( 0 == X[-idx - 1] ) //              Is X for this idx defined? 
            {
                if ( count/2 <= left ) //             Unnecesary switch?
                {
                    X[-idx - 1] = root;
                    left -= count/2;
                    idx = root, count = original_count;
                    continue;
                }
                else if ( 1 == count/2 ) //           Leaf?
                {
                    X[-idx - 1] = d_adj[offset++];
                    idx = root;
                    continue;
                }
                else //                             Just continue down
                {
                    X[-idx - 1] = -s_count - 1;
                }
            }
            if ( 2 < count )
                idx = X[-idx - 1], count /= 2; // This will simulate going down
            else
                idx = root;
        }
 
 
        // When Y
        else
        {
            if ( 0 == Y[-idx - 1] ) //              Is Y for this idx defined?
            {
                if ( 1 == count/2 ) //                Leaf?
                {
                    Y[-idx - 1] = d_adj[offset++];
                    idx = root, count = original_count;
                    continue;
                }   
                else //                             Just continue down
                    Y[-idx - 1] = -s_count - 1;
            }
            if ( 2 < count )
                idx = Y[-idx - 1], count /= 2; // Same as in if above
            else
                idx = root, count = original_count;
        }
    }
    return;
}
 
void create_circuit(int M, vector<int> A)
{
    vector< vector<int> > directed_adj(M+1);
    C.assign(M+1, -1);
    A.push_back(0);
 
    int32_t log2 = static_cast<int32_t>( log( A.size()-1 ) / log(2) + 1 );
    int32_t left = (1<<log2) - (int32_t)A.size();
    int32_t idx = -1, offset = 0, root = idx;
    simulate_and_form(idx, (1<<log2), left, A, root, offset);
    answer(C, X, Y);
    return;
}
 