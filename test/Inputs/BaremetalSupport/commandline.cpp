#include <vector>
#include <string>
#include <cstring>


extern "C" char* get_commandline(int* outLen);


char** _user_get_commandline(int* outArgLen) {
  int cmdline_len;
  char* buffer = get_commandline(&cmdline_len);
  std::vector<char*> args;

  int start_pos = 0;
  while (start_pos < cmdline_len) {
    int end_pos = start_pos + 1;
    // find end position
    while (buffer[end_pos] != ' ' && end_pos < cmdline_len) {
      end_pos ++;
    }

    // copy and append
    char *arg = (char*)calloc(end_pos - start_pos + 1, sizeof(char));
    memcpy(arg, buffer + start_pos, end_pos - start_pos);
    args.push_back(arg);

    // move to new start_pos
    start_pos = end_pos + 1;
  }

  char **outbuf = (char **)calloc(args.size() + 1, sizeof(char *));
  std::copy(args.begin(), args.end(), outbuf);
  outbuf[args.size()] = nullptr;
  *outArgLen = args.size();
  return outbuf;
}

