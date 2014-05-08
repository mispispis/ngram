#include "print.h"



int ngram_counts_maxind(ngram_t *ng, int ngsize)
{
  int i;
  int ct, ct_best = 0;
  int ind = 0;
  nextwordlist_t *nwl;
  
  
  for (i=0; i<ngsize; i++)
  {
    nwl = ng[i].nextword;
    ct = 0;
    
    while (nwl)
    {
      ct += nwl->word.count;
      nwl = nwl->next;
    }
    
    if (ct > ct_best)
    {
      ct_best = ct;
      ind = i;
    }
    
  }
  
  return ind;
}



int ngram_counts_total(ngram_t *ng, int ngsize)
{
  int i;
  int ct = 0;
  nextwordlist_t *nwl;
  
  
  for (i=0; i<ngsize; i++)
  {
    nwl = ng[i].nextword;
    
    while (nwl)
    {
      ct += nwl->word.count;
      nwl = nwl->next;
    }
  }
  
  return ct;
}


