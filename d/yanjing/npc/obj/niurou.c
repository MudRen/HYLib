 

inherit ITEM;
inherit F_FOOD;

void create()
{
set_name("ţ��",({"niu rou","meat"}));
set_weight(600);
  if (clonep())
    set_default_object(__FILE__);
  else {
set("long","һ���кõ�ţ��,�¾������.\n");
set("unit","��");
set("value",250);
    set("food_remaining", 5);
    set("food_supply", 35);
set("eat_msg","$N����Ƭ$nϸϸ��ҧ�˼���.\n");
  }
}
