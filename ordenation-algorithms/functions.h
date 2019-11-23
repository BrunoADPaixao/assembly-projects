void initializeVector(int *V, int N) {
	for (int i = 0; i < N; i++){
		V[i] = 0;
	}	
}

int *fillVector(int *V, int N){
	int val;
	for (int i = 0; i < N; i++){
		cin >> val;
		V[i] = val;
	}
	return V;
}

void printVector(int *V, int N){
	for (int i = 0; i < N; i++){
		cout << V[i] << " "<<endl;
	}
}

// BUBBLE SORT - ALGORITMO DE ORDENAÇÃO SIMPLES
void bubbleSort(int V[], int N) {
	int i, continua, aux, fim = N;
	do {
		continua = 0;
		for (i = 0; i < fim-1; i++){
			if (V[i] > V[i+1]) {
				aux = V[i];
				V[i] = V[i+1];
				V[i+1] = aux;
				continua = 1;
			}
		}
		fim--;
	}while(continua !=0);	
}

// INSERTION SORT - ALGORITMO DE ORDENAÇÃO SIMPLES
void insertionSort(int *V, int N) {
	int i, j, aux;
	for (i = 1; i < N; i++) {
		aux = V[i];
		for (j = i; (j > 0) && (aux < V[j - 1]); j--)
			V[j] = V[j-1];
		V[j] = aux;
	}
}

/*
INSERTION SORT - ALGORITMO DE ORDENAÇÃO SIMPLES
- A CADA PASSO PROCURAO MENOR VALOR DO ARRAY E O COLOCA NA PRIMEIRA POSIÇÃO DO MESMO
- DESCARTA-SE A PRIMEIRA POSICAO DO ARRAY E REPETE-SE O PROCESSO PARA A SEGUNDA POSICAO
- ISSO É FEITO PARA TODAS AS POSIÇÕES DO ARRAY
- ESTÁVEL
- MELHOR CASO O(N^2)
- PIOR CASO O(N^2)
- INEFICIENTE PARA GRANDES CONJUNTOS DE DADOS
*/
void selectionSort(int *V, int N) {
	int i, j, menor, troca;
	for (i = 0;i < N-1; i++){
		menor = i;
		for (j = i+1; j < N; j++) {
			if (V[j] < V[menor]) {
				menor = j;
			}
		}
		if (i != menor) {
			troca = V[i];
			V[i] = V[menor];
			V[menor] = troca;
		}
	}
}

/*
MERGE SORT - ALGORITMO DE ORDENAÇÃO SOFISTICADO
- ESTÁVEL
- MELHOR CASO O(N log N)
- PIOR CASO O(N log N)
- DESVANTAGENS: RECURSIVO E USA UM VETOR AUXILIAR DURANTE A ORDENAÇÃO (MAIOR USO DE MEMÓRIA)
*/
void merge(int *V, int inicio, int meio, int fim) {
	int *temp, p1, p2, tamanho, i, j, k;
	int fim1 = 0, fim2 = 0;
	tamanho = fim-inicio+1;
	p1 = inicio;
	p2 = meio+1;
	temp = (int*) malloc(tamanho*sizeof(int));
	if (temp != NULL) {
		for (i=0; i<tamanho; i++) {
			if (!fim1 && !fim2) {
				if (V[p1] < V[p2])
					temp[i] = V[p1++];
				else
					temp[i] = V[p2++];
				
				if (p1>meio) fim1=1;
				if (p1>fim) fim2=1;
			} else {
				if (!fim1)
					temp[i]=V[p1++];
				else
					temp[i]=V[p2++];
			}
		}
		for (j=0, k=inicio; j<tamanho; j++, k++)
			V[k]=temp[j];
	}
	free(temp);
}
void mergeSort(int *V, int inicio, int fim){
	int meio;
	if (inicio < fim) {
		meio = floor((inicio+fim)/2);
		mergeSort(V, inicio, meio); //DIVIDEM O VETOR RECURSIVAMENTE EM UNIDADES 
		mergeSort(V, meio+1, fim); //
		merge(V, inicio, meio, fim); // COMBINA AS 2 METADES DE FORMA ORDENADA
  	}
}