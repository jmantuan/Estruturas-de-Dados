#include<new>
using std::nothrow;

template <typename T> struct Fila{
	T *v;
	int p, u, tam_v, n_elem;

	bool inicializar(){
		v = new(nothrow) T[1];
		if(v == nullptr) return true;

		p = u = -1;	tam_v = 1;
		n_elem = 0;
		return false;
	}	

	void terminar(){ delete[] v; }

	bool vazio(){ return (p == -1 && u == -1); }

	bool redimensionar(int n_tam){

	}

	bool enfilar(T e){
		if(p <= u)
			if(u == tam_v-1)
				if(p == 0)
					if(redimensionar(tam_v*2)) return true;
					++u;
				else 
					u = 0;
		else if(p > u)
			if(u+1 == p)
					if(redimensionar(tam_v*2)) return true;
			else
				++u;

		v[u] = e;
		++n_elem;
		return false;
	}

	bool desenfilar(){
		if(p == u)
			p = u = -1;

		else if(p < u){
			++p;
			if(4 * n_elem <= tam_v) 
				if(redimensionar(tam_v/2)) return true;
		} 
		else if(p > u){
			++p;
			if(p == tam_v-1){
				p = 0;
			}
			if(4 * n_elem <= tam_v)
				if(redimensionar(tam_v/2)) return true;
		}	
		--n_elem;
		return false;
	}
};