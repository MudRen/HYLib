#include <ansi.h>;
inherit ITEM;
inherit F_FOOD;
void create()
{
     set_name(RED"Ұ��"NOR, ({"ye guo","guo"}));
     set_weight(25);
     if (clonep())
     set_default_object(__FILE__);
     else {
     set("unit", "ֻ");
     set("long", "����һֻ��ͮͮ��Ұ���������������˵ķ��㡣\n");
     set("food_remaining", 4);
     set("food_supply", 40); 
     setup();
     }
}
