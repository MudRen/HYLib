
inherit ITEM;
inherit F_LIQUID;

void create()
{
   set_name("ţƤ�ƴ�", ({"jiudai"}));
   set_weight(700);
   if (clonep())
     set_default_object(__FILE__);
   else {
     set("long", "һ������װ�׾ƵĴ�ƴ������װ�ðˡ������ľơ�\n");
     set("unit", "��");
     set("value", 20);
     set("max_liquid", 15);
   }

  
   set("liquid", ([
     "type": "alcohol",
     "name": "�׾�",
     "remaining": 15,
     "drunk_supply": 6,
   ]));
}

