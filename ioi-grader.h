// Adapted from IOI 2020 practice task "routers".

void quitsv(const char* msg) {
  fprintf(stderr, "SV\n%s\n", msg);
  inf.close();
  ouf.close();
  ans.close();
  if (tout.is_open())
    tout.close();
  exit(20);
}

void readSecret(InStream& ins, std::string secret) {
  if (ins.readWord() != secret)
    quitsv("secret mismatch");
  ins.eoln();
}

void readBothSecrets(std::string secret) {
  readSecret(ans, secret);
  readSecret(ouf, secret);
}

void readGraderResult(InStream& ins) {
  std::string result = ins.readWord();
  ins.eoln();
  if (result == "OK") {
    return;
  }
  if (result == "SV") {
    std::string msg = ins.eof() ? "in grader" : ins.readLine();
    quitsv(msg.c_str());
  }
  if (result == "WA") {
    if (ins.eof())
      quitf(_wa, "WA in grader");
    std::string msg = ins.readLine();
    quitf(_wa, "WA in grader: %s", msg.c_str());
  }
  if (result == "FAIL") {
    if (ins.eof())
      quitf(_fail, "FAIL in grader");
    std::string msg = ins.readLine();
    quitf(_fail, "FAIL in grader: %s", msg.c_str());
  }
  quitf(_fail, "Unknown grader result");
}

void readBothGraderResults() {
  readGraderResult(ans);
  readGraderResult(ouf);
}
