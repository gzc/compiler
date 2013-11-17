

    int a[9];
    int s[9];
    int i; 
    for(i=0;i<9;i++)
	a[i] = 9-i;
    int p = 0;
    s[p++] = 0;
    s[p++] = 8;
    int low;
    int high;
    int q;
    while(p>0)
    {
	high = s[--p];
	low = s[--p];
	if(low >- high)
	    break;
	int x = a[low];
	int k = low;
	int j = high+1;
	int temp;
	while(i<j)
	{
	    while(a[++i]< x && i<high);
	    while(a[--j]>x);
	    if(i<j)
	    {
		temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	    }
	}
	a[low] = a[j];
	a[j] = x;
	q = j;
	if((q-low) > (high-q))
	{
	    s[p++] = low;
	    s[p++] = q-1;
	    if(high >q)
	    {
		s[p++] = q+1;
		a[p++] = high;

	    }
	}
	else
	{
	    s[p++] = q+1;
	    s[p++] = high;
	    if(q>low)
	    {
		s[p++] = low;
		s[p++] = q-1;

	    }
	}
    
    }


