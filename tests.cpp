#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "OList.cpp"
#include "node.cpp"

TEST_CASE("Insert and toString Cases") 
{
     OList *a = new OList();
     a->insert("1");
     a->insert("3");
     CHECK(a->toString() == "1-->3-->nullptr");
     a->insert("3");
     CHECK(a->toString() == "1-->3-->3-->nullptr");
     a->insert("2");
     CHECK(a->toString() == "1-->2-->3-->3-->nullptr");
     a->insert("4");
     CHECK(a->toString() == "1-->2-->3-->3-->4-->nullptr");
}

TEST_CASE("Contains Cases") 
{
     OList *a = new OList();
     a->insert("4");
     a->insert("0");
     CHECK(a->contains("4") == true);
     CHECK(a->contains("0") == true);
     CHECK(a->contains("1") == false);
     CHECK(a->contains(" ") == false);
}

TEST_CASE("get Cases") 
{
     OList *a = new OList();
     a->insert("4");
     a->insert("0");
     CHECK(a->get(1) == "4");
     CHECK(a->get(0) == "0");
     CHECK(a->get(2) == "");
}

TEST_CASE("Remove Cases") 
{
     OList *a = new OList();
     a->insert("4");
     a->insert("0");
     a->remove(1);
     CHECK(a->toString() == "0-->nullptr");
     a->remove(0);
     CHECK(a->toString() == "nullptr");
}

TEST_CASE("Reverse Cases") 
{
     OList *a = new OList();
     a->insert("4");
     a->insert("0");
     a->reverse();
     CHECK(a->toString() == "4-->0-->nullptr");
     a->reverse();
     CHECK(a->toString() == "0-->4-->nullptr");
}
