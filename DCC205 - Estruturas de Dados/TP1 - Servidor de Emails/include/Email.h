#include <iostream>
#include <string.h>

#include "memlog.h"
#include "msgassert.h"

using namespace std;

class Email{
	private:
		string mensagem;
		int prioridade;
	public:
		Email *prox;
		Email();
		~Email();
		Email(string msg, int pri);
		string getMensagem();
		int getPrioridade();
};