
inherit ITEM;
inherit F_LIQUID;

void create()
{
   set_name("����", ({"bing jiu","jiu"}));
   set_weight(700);
   if (clonep())
     set_default_object(__FILE__);
   else {
     set("long", "��˵�����������ѩˮ��ɵľƣ�ζ�����á�\n");
     set("unit", "ƿ");
     set("value", 300);
     set("max_liquid", 35);
   }

  
   set("liquid", ([
     "type": "alcohol",
     "name": "����",
     "remaining": 15,
     "drunk_supply": 6,
   ]));
}

