#include <algorithm>
#include <ctime>
#include <iostream>
#include <string>
#include <fstream>
const int argomenti = 10;
const int vastità = 10;
const std::string nomeFile = "impostazioni/booleani.txt";


void Risposte(std::string risp[argomenti][vastità]) {
  // domanda non [0]
  risp[0][0] = "non ho capito";
  risp[0][1] = "non penso di avere capito";
  risp[0][2] = "mi dispiace, ma non ho capito cosa hai detto";
  // stop [1]
  risp[1][0] = "arrivederci!";
  risp[1][1] = "addio...";
  risp[1][2] = "spero di rivederti presto!";
  risp[1][3] = "vaffanculo";
  risp[1][4] = "a presto!";
  risp[1][5] = "bye bye!";
  // chi sei [2]
  risp[2][0] = "il mio nome è RoboCazzo";
  risp[2][1] = "sono RoboCazzo, il tuo incubo peggiore!";
  risp[2][2] = "il mio nome è RoboCazzo";
  // colori [3]
  risp[3][0] = "nero";
  risp[3][1] = "bianco";
  risp[3][2] = "rosso";
  risp[3][3] = "blu";
  risp[3][4] = "verde";
  risp[3][5] = "giallo";
  risp[3][6] = "viola";
  risp[3][7] = "grigio";
  risp[3][8] = "marrone";
  risp[3][9] = "rosa";
  // chi sono [4]
  risp[4][0] = "non sono ancora in grado di memorizzare le cose...";
  // insulti [5]
  risp[5][0] = "tua madre";
  risp[5][1] = "succhiami il megabyte";
  risp[5][2] = "sei la mia troia";
  risp[5][3] = "ok bro";
  // risposte random [6]
  risp[6][0] = "cazzo ridi";
  risp[6][1] = "io non riderei se fossi in te";
  risp[6][2] = "ridi ridi";
  risp[6][3] = "smash";
  risp[6][4] = "pass";
  // come stai?
  risp[7][0] = "tutto bene dai";
  risp[7][1] = "potrebbe andare meglio";
  risp[7][2] = "di merda";
  risp[7][3] = "ma cosa te ne frega";
  risp[7][4] = "sono un cazzo di robot, secondo te?";
  risp[7][5] = "boh fai tu, sono qui a parlare con te";
  // ciao
  risp[8][0] = "ciao boss";
  risp[8][1] = "allooora";
  risp[8][2] = "ao bro";
  risp[8][3] = "ue fratm";
  risp[8][4] = "salve padrone";
  risp[8][5] = "ehi, cosa posso fare per te?";
}

void intro() {
  system("clear");
  system("bash file/intro.sh");
  std::cout << "\t\t\t\t\t\033[3m\t\t\033[90mby Alfanowski\033[0m\n\n";
}

void comandi() {
  std::cout << "elenco dei comandi tecnici:\n";
  std::cout << "pulisci --> pulizia dello schermo\n";
  std::cout << "percorso --> mostra il percorso in cui si trova RoboCazzo\n";
  std::cout << "cazzo --> genera la ascii art di un pene\n";
  std::cout << "aggiusta microfono --> calibrazione del microfono\n";
  std::cout << "ascoltami --> puoi parlare a RoboCazzo\n";
  std::cout << "impostazioni --> accesso ad un rapido menu' di setting\n";
}

std::string getPhrase(int cont, bool &vocal) {
  std::string domanda;
  if (cont == 1) {
    std::cout << " Ciao, cosa vuoi che faccia?\n\n";
  }
  std::cout << "\033[31m"
            << "  >> "
            << "\033[0m";
  if (!vocal)  
    getline(std::cin, domanda);
  else if (vocal) {
    std::ifstream file("output.txt");
    std::getline(file, domanda);
    file.seekg(0, std::ios::end);
    if (file.tellg() == 0)
        std::cout << "Non ho sentito bene";
    else {
        std::cout << domanda << "\n";
        std::ofstream file("output.txt", std::ofstream::out | std::ofstream::trunc);
        file.close();
    }
    vocal = false;
  }
  std::transform(domanda.begin(), domanda.end(), domanda.begin(),
                 [](unsigned char c) { return std::tolower(c); });

  return domanda;
}

std::string elaborazione(std::string question, std::string risp[argomenti][vastità], bool &vocal) {
    std::string frase_da_dire;
  // qual è il tuo nome
  if (question.find("nome") != question.npos) {
    if (question.find("tuo") != question.npos) {
        frase_da_dire = risp[2][rand() % 3];
        std::cout << frase_da_dire;
    }
    else if (question.find("mio") != question.npos) {
        frase_da_dire = risp[4][0];
        std::cout << frase_da_dire;
    }
    else {
        frase_da_dire = risp[0][rand() % 3];
        std::cout << frase_da_dire;
    }
  }
  // chi sei
  else if (question.find("sei") != question.npos) {
    if (question.find("cosa") != question.npos or question.find("chi") != question.npos) {
        frase_da_dire = risp[2][rand() % 3];
        std::cout << frase_da_dire;
    }
    else if (question.find("brutto") != question.npos) {
        frase_da_dire = risp[5][rand() % 4];
        std::cout << frase_da_dire;
    }
    else {
        frase_da_dire = risp[0][rand() % 3];
        std::cout << frase_da_dire;
    }
  }
  // ciao
  else if (question.find("ciao") != question.npos or question.find("buongiorno") != question.npos or question.find("buonasera") != question.npos or question.find("salve") != question.npos) {
      frase_da_dire = risp[8][rand() % 6];
      std::cout << frase_da_dire;
  }
  // come ti chiami / come stai
  else if (question.find("come") != question.npos) {
    if (question.find("ti chiam") != question.npos) {
        frase_da_dire = risp[2][rand() % 3];
        std::cout << frase_da_dire;
    }
    else if (question.find("stai") != question.npos or question.find("va") != question.npos) {
        frase_da_dire = risp[7][rand() % 6];
        std::cout << frase_da_dire;
    }
    else {
        frase_da_dire = risp[0][rand() % 3];
        std::cout << frase_da_dire;
    }
  }
  // risate
  else if (question.find("ahah") != question.npos or question.find("haha") != question.npos) {
      frase_da_dire = risp[6][rand() % 3];
      std::cout << frase_da_dire;
  }
  // dimmi un colore
  else if (question.find("colore") != question.npos) {
    if (question.find("preferito") != question.npos and question.find("tuo") != question.npos or question.find("hai") != question.npos) {
        frase_da_dire = "non ho un colore preferito";
        std::cout << frase_da_dire;
    }
    else {
        frase_da_dire = risp[3][rand() % 10];
        std::cout << frase_da_dire;
    }
  }
  // insulti
  else if (question.find("vaffanculo") != question.npos or question.find("troia") != question.npos or question.find("zoccola") != question.npos or question.find("stronzo") != question.npos or question.find("merda") != question.npos or question.find("coglione") != question.npos) {
      frase_da_dire = risp[5][rand() % 4];
      std::cout << frase_da_dire;
  }
  // cosa ne pensi di...
  else if (question.find("pensi") != question.npos and question.find("cosa") != question.npos or question.find("che") != question.npos) {
      frase_da_dire = risp[6][(rand() % 2) + 3];
      std::cout << frase_da_dire;
  }
  // sega
  else if (question.find("sega") != question.npos) {
      frase_da_dire = "ti accontento bro!";
      std::cout << frase_da_dire;
      system("xdg-open https://pornhub.com/");
  }
  // cancella schermo
  else if (question == "pulisci") {
      frase_da_dire = "interfaccia pulita";
      system("clear");
      intro();
  }
  // percorso
  else if (question == "percorso") {
      frase_da_dire = "percorso stampato";
      system("pwd");
  }
  // cazzo
  else if (question == "cazzo" and question.find("cazzo") != question.npos or question.find("escimelo") != question.npos) {
        frase_da_dire = "pisellone";
        system("bash file/cazzo.sh");
    }
  // microfono 
  else if (question == "aggiusta microfono") {
    frase_da_dire = "calibrazione del microfono in corso...";
      std::cout << frase_da_dire;
    system("python3 file/avvia.py");
  }
  // ascolto vocale
  else if (question == "ascoltami") {
    std::cout << "fatto";
    frase_da_dire = " ";
    system("python3 file/ascoltami.py");
    system("sleep 4");
    vocal = true;
  }
  // impostazioni
  else if (question == "impostazioni") {
      std::cout << "impostazioni aperte...";
      frase_da_dire = " ";
      system("bash impostazioni/options.sh");
  }
  // comandi
  else if (question == "comandi") {
      frase_da_dire = " ";
      comandi();
  }
  // stop
  else if (question == "stop") {
      frase_da_dire = risp[1][rand() % 6];
      std::cout << frase_da_dire;
  }
  // domanda non compresa
  else {
      frase_da_dire = risp[0][rand() % 3];
      std::cout << frase_da_dire;
  }
  return frase_da_dire;
}

bool letturaRiga1() {
    std::string riga;
    std::ifstream fileIn(nomeFile);
    std::getline(fileIn, riga);
    fileIn.close();
    if (riga == "TRUE")
        return true;
    else
        return false;
}

void passaggioFrase(std::string fraseDaDire) {
    std::ofstream output_file("speak.txt");
    output_file << fraseDaDire;
    output_file.close();
    system("python3 dettatura.py");
}

int main() {
  srand(time(NULL));
  std::string nome, question, risp[argomenti][vastità], fraseDaDire;
  int cont = 1;
  bool vocal = false, dettatura;
  Risposte(risp);
  intro();
  do {
      question = getPhrase(cont, vocal);
      if (question != "pulisci")
          std::cout << "\u001b[36m  << \033[0m";
      fraseDaDire = elaborazione(question, risp, vocal);
      dettatura = letturaRiga1();
      if (dettatura)
          passaggioFrase(fraseDaDire);
      cont++;
      std::cout << "\n\n";
  } while (question != "stop");
  system("rm dett.mp3");
  system("clear");
}
