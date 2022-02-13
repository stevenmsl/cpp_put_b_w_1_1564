#include "solution.h"
#include "util.h"
#include <unordered_map>
#include <numeric>
#include <algorithm>
using namespace sol1564;
using namespace std;

/* takeaways
   - update each room's height to its effective height
     - it won't accept boxes taller than its
       predecessors as they won't get to it
       anyway
   - try with the shortest box first as taller ones
     will stop the shorter ones coming to the room
     if they can't get in
*/
/* C++ notes
   - size_t will not become negative so you can't
     check if a variable of type size_t becomes
     negative as it will never happen
*/

int Solution::maxBoxes(vector<int> &boxes, vector<int> &ws)
{
  int gate = ws[0];
  for (auto i = 0; i < ws.size(); i++)
  {
    /*
       set the new gate for those who come after me
    */
    gate = min(gate, ws[i]);
    /*
      - adjust to the minimum height of the rooms
        that come before you as boxes execeed
        that height won't reach me anyway
    */
    ws[i] = gate;
  }

  sort(boxes.begin(), boxes.end());

  auto b = 0;
  /* c++ notes
     - auto w = ws.size()
       - won't work as w is of
         type size_t and won't
         allow it goes into
         negative
       - w-- will eventually become
         a huge number instead of
         a negative one
  */
  int w = ws.size() - 1;
  auto count = 0;
  while (b < boxes.size() && w >= 0)
  {
    if (boxes[b] <= ws[w])
    {
      count += 1;
      w--; // next room on the left
      b++; // next taller box
    }
    else
      w--;
  }

  return count;
}