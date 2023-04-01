#include "ArvAVL.h"

void ArvAVL::RotacaoDireita(No *&p) {
	No *aux = p->esq;
	p->esq = aux->dir;
	aux->dir = p;
	p = aux;
}

void ArvAVL::RotacaoEsquerda(No *&p) {
	No *aux = p->dir;
	p->dir = aux->esq;
	aux->esq = p;
	p = aux;
}

void ArvAVL::RotacaoDuplaDireita(No *&p) {
	No *aux = p->esq->dir;
	p->esq->dir = aux->esq;
	aux->esq = p->esq;
	p->esq = aux->dir;
	aux->dir = p;
	p = aux;
}

void ArvAVL::RotacaoDuplaEsquerda(No *&p) {
	No *aux = p->dir->esq;
	p->dir->esq = aux->dir;
	aux->dir = p->dir;
	p->dir = aux->esq;
	aux->esq = p;
	p = aux;
}

void ArvAVL::Balanceamento() {
	BalanceamentoRecursivo(raiz);
}

void ArvAVL::BalanceamentoRecursivo(No *&p) {
	if(!p) {
		return;
	} else {
		if(raiz->FatorBalanceamento() == -2) {
			if(raiz->esq->FatorBalanceamento() == -1) {
				RotacaoDireita(raiz);
			} else if(raiz->esq->FatorBalanceamento() == 1) {
				RotacaoDuplaDireita(raiz);
			}
		} else if(raiz->FatorBalanceamento() == 2) {
			if(raiz->dir->FatorBalanceamento() == 1) {
				RotacaoEsquerda(raiz);
			} else if(raiz->dir->FatorBalanceamento() == -1) {
				RotacaoDuplaEsquerda(raiz);
			}
		}
		if(abs(raiz->FatorBalanceamento()) > 1) {
			BalanceamentoRecursivo(p->esq);
			BalanceamentoRecursivo(p->dir);
		}
	}

	if(p) p->RecalculaAltura();
}

void ArvAVL::InsereRecursivo(No *&p, Verbete *item) {
	if(!p) {
		p = new No(item);
	} else {
		if(item->palavra < p->chave->palavra) {
			InsereRecursivo(p->esq, item);

		} else if(item->palavra > p->chave->palavra) {
			InsereRecursivo(p->dir, item);
		} else {
			if(item->tipo == p->chave->tipo) {
				p->chave->InsereSignificado(item->significados);
				delete item;
			} else
				InsereRecursivo(p->dir, item);
		}
	}
	p->RecalculaAltura();
}

void ArvAVL::RemoveRecursivo(No *&p, Verbete *item) {
	if(p) {
		if(item->palavra < p->chave->palavra) {
			RemoveRecursivo(p->esq, item);
		} else if(item->palavra > p->chave->palavra) {
			RemoveRecursivo(p->dir, item);
		} else {
			if(item->tipo == p->chave->tipo) {
				if(!p->esq && !p->dir) {
					delete p;
					p = nullptr;
				} else if(!p->esq) {
					No *aux = p;
					p = p->dir;
					delete aux;
				} else if(!p->dir) {
					No *aux = p;
					p = p->esq;
					delete aux;
				} else {
					No *aux = p->esq;
					while(aux->dir) {
						aux = aux->dir;
					}
					Verbete *troca = p->chave;
					p->chave = aux->chave;
					aux->chave = troca;
					RemoveRecursivo(p->esq, item);
				}
			} else {
				RemoveRecursivo(p->dir, item);
			}
		}
	}

	if(p) p->RecalculaAltura();
}

void ArvAVL::RemoveVerbeteComSignificadoRecursivo(No *&p) {
	if(p) {
		RemoveVerbeteComSignificadoRecursivo(p->esq);
		RemoveVerbeteComSignificadoRecursivo(p->dir);
		if(!p->chave->significados->Vazia()) {
			RemoveRecursivo(p, p->chave);
		}
	}
}

void ArvAVL::ImprimeRecursivo(No *p) {
	if(p) {
		ImprimeRecursivo(p->esq);
		std::cout << p->chave->Saida();
		ImprimeRecursivo(p->dir);
	}
}

void ArvAVL::ImprimeSaidaRecursivo(No *p, std::ofstream &saida) {
	if(p) {
		ImprimeSaidaRecursivo(p->esq, saida);
		saida << p->chave->Saida();
		ImprimeSaidaRecursivo(p->dir, saida);
	}
}

void ArvAVL::LimpaRecursivo(No *p) {
	if(p) {
		LimpaRecursivo(p->esq);
		LimpaRecursivo(p->dir);
		delete p;
	}
}