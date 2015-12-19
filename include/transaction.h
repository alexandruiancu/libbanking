#pragma once
#include <list>
#include <string>
#include <set>
#include <vector>
#include "types.h"

class Transaction
{
 public:
  Transaction();
  int initialize();
  int set_primary_attributes(const vs &vAttrs);
  int set_primary_attribute_values(const vs &vAttrVals);
  int add_attributes(const std::vector<vs> &vAttrVals);
  int get_credit_index();
  int get_transaction_details(std::string &sTransactionDetails);

  std::vector<ps> m_primary_attrs;
  ss m_attrs;
};

typedef std::vector<Transaction> Transactions;

/* struct Node */
/* { */
/*   std::string m_sName; */
/*   float       m_nValue; */
/*   std::list<Transaction> m_children; */
/* }; */

/* int build_c_tree(Node &root, t_c_node *c_root); */





