// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// hulu.c 

inherit ITEM;
inherit F_LIQUID;

void create()
{
  set_name("�ͺ�«", ({"you hulu", "youhulu", "hulu", "hu"}));
  set_weight(700);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "һ��װ�����͵ĺ�«��\n");
    set("unit", "��");
    set("value", 100);
    set("max_liquid", 20);
    set("liquid", ([
      "type" : "oil",
      "name" : "����",
      "remaining" : 12,
   ]));
  }
}

