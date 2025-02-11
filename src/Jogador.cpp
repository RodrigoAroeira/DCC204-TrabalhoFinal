#include "Jogador.hpp"

#include <iomanip>
#include <iostream>
#include <memory>
#include <sstream>

#include "Leaderboard.hpp"

Jogador::Jogador(const std::string &nome)
    : mNome(nome), mJogoDaVelha(0), mLig4(0), mOthello(0), mPontosTot(0) {}

std::shared_ptr<Jogador> Jogador::fromLeaderboard(const Leaderboard &lb) {
  std::string nome;
  std::cout << "Digite o nome a ser encontrado na leaderboard: ";
  std::cin >> nome;
  return lb.getJogador(nome);
}

std::shared_ptr<Jogador> Jogador::fromInput() {
  std::string nome;
  char opt;
  do {
    std::cout << "Digite o seu nome a ser registrado: ";
    std::cin >> nome;
    std::cout << "O nome " << std::quoted(nome) << " está correto? (y/n)\n> ";

    std::cin >> opt;
  } while (std::tolower(opt) != 'y');
  return std::make_shared<Jogador>(nome);
}

std::string Jogador::linhaCSV() const {
  std::stringstream ss;
  ss << mNome << "," << mJogoDaVelha << "," << mLig4 << "," << mOthello;
  return ss.str();
}

int Jogador::getJV() const { return mJogoDaVelha; }

int Jogador::getLig4() const { return mLig4; }

int Jogador::getOthello() const { return mOthello; }

int Jogador::getPontosTot() const { return mPontosTot; }

void Jogador::setJV(int jv) { mJogoDaVelha = jv; }

void Jogador::setLig4(int lig4) { mLig4 = lig4; }

void Jogador::setOthello(int othello) { mOthello = othello; }

void Jogador::aumentarJV(int quant) { mJogoDaVelha += quant; }

void Jogador::aumentarLig4(int quant) { mJogoDaVelha += quant; }

void Jogador::aumentarOthello(int quant) { mJogoDaVelha += quant; }

bool Jogador::operator==(const Jogador &j) const { return mNome == j.mNome; }

bool Jogador::operator!=(const Jogador &j) const { return !(*this == j); }
