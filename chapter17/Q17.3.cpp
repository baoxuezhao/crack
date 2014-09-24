count the number of zeros in  factorial.

count the number of factor 5 from 1 to n.

int countZero(int n)
{
  int count = 0;
  
  if(n < 0)
    return -1;
    
  for(int i=5; n/i>0; i*=5)
  {
    count += (n/i);
  }
  return count;
}
