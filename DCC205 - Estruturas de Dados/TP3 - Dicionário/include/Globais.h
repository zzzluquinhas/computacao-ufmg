#include <getopt.h>
#include <sys/resource.h>

#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

#include "memlog.h"
#include "msgassert.h"

namespace args {
	inline std::string nomeEntrada = ""; // nome do arquivo de entrada
	inline std::string nomeSaida = ""; // nome do arquivo de saida
	inline std::string hashOuArv = ""; // flag para indicar se o dicionário será uma árvore ou um hash
	inline std::string nomeMemLog = ""; // nome do arquivo de memlog
}  // namespace args