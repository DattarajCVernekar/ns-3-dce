#ifndef DCE_HELPER_H
#define DCE_HELPER_H

#include <string>
#include <stdint.h>
#include <vector>
#include "ns3/node-container.h"
#include "ns3/application-container.h"

namespace ns3 {

class DceApplicationHelper
{
public:
  DceApplicationHelper ();
  void SetBinary (std::string filename);
  void SetStackSize (uint32_t stackSize);
  void SetStdinFile (std::string filename);
  void AddArgument (std::string arg);
  void AddArguments (std::string a0, std::string a1);
  void AddArguments (std::string a0, std::string a1, std::string a2);
  void AddArguments (std::string a0, std::string a1, std::string a2, std::string a3);
  void AddArguments (std::string a0, std::string a1, std::string a2, std::string a3,
                     std::string a4);
  void AddArguments (std::string a0, std::string a1, std::string a2, std::string a3,
                     std::string a4, std::string a5);
  void AddArguments (std::string a0, std::string a1, std::string a2, std::string a3,
                     std::string a4, std::string a5, std::string a6);
  void AddArguments (std::string a0, std::string a1, std::string a2, std::string a3,
                     std::string a4, std::string a5, std::string a6, std::string a7);
  void ParseArguments (std::string args);
  void ResetArguments (void);
  void AddEnvironment (std::string name, std::string value);
  void ResetEnvironment (void);
  virtual ApplicationContainer Install (NodeContainer c);
  void SetFinishedCallback (Callback<void,uint16_t,int> cb);
  void SetUid (uid_t i);
  void SetEuid (uid_t i);
  void SetGid (uid_t i);
  void SetEgid (uid_t i);

private:
  bool m_isBinary;
  std::string m_filename;
  uint32_t m_stackSize;
  std::vector<std::string> m_args;
  std::vector<std::pair<std::string,std::string> > m_envs;
  std::string m_stdinFilename;
  Callback<void,uint16_t,int> m_finishedCallback;
  uid_t m_uid;
  uid_t m_euid;
  uid_t m_gid;
  uid_t m_egid;
};

} // namespace ns3

#endif /* DCE_HELPER_H */
