int countParentheses(char[] symbols, char[] operators, int n)
{
	const int nn = n;
	if(n == 1) return 1;
	int trues[nn][nn];
	int falses[nn][nn];
	
	for(int i=0; i<n; i++)
	{
	 	trues[i][i] = (symbols[i] == "T")?1:0;
		falses[i][i]= (symbols[i] == "F")?1:0;
	}

	for(int gap = 1; i<n; i++)
	{
		for(int start=0; start+gap<n; start++)
		{
			int end = start+gap;
			trues[start][end] = 0;
			falses[start][end] = 0;

			for(int k=start; k<end; k++)
			{
				int start_k = trues[start][k] + falses[start][k];
        		int k_end 	= trues[k+1][end] + falses[k+1][end];

				if(operators[k] == '&')
				{
					trues[start][end] += trues[start][k] * trues[k+1][end]；
					falses[start][end] += start_k*k_end - trues[start][k] * trues[k+1][end]；
				}
				else if(operators[k] == '|')
				{
					trues[start][end] += (start_k*k_end - falses[start][k] * falses[k+1][end])；
					falses[start][end] += (falses[start][k] * falses[k+1][end]；	
				}
				else
				{
					trues[start][end] += (trues[start][k] * falses[k+1][end] + falses[start][k] * trues[k+1][end]);
					falses[start][end] += (trues[start][k] * trues[k+1][end] + falses[start][k] * falses[k+1][end])；
				}
			}
		}
	}
	return trues[0][n-1];
}


int main()
{
    char symbols[] = "TTFT";
    char operators[] = "|&^";
    int n = strlen(symbols);
 
    // There are 4 ways
    // ((T|T)&(F^T)), (T|(T&(F^T))), (((T|T)&F)^T) and (T|((T&F)^T))
    cout << countParenth(symbols, operators, n);
    return 0;
}

