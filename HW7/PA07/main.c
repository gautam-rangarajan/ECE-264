#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "answer07.h"

static void Tree_printInorder (BusinessNode * tn)
{
  if(tn == NULL)
    {
      return;
    }
  Tree_printInorder(tn->left);
  printf("%s %s %s\n", tn->stars, tn->name, tn->address);
  Tree_printInorder(tn->right);
}


int main(int argc, char ** argv)
{
  BusinessNode * search = load_tree_from_file("yelp_businesses.tsv");
  Tree_printInorder(search);
  destroy_tree(search);
  return EXIT_SUCCESS;
}
