
inherit ITEM;
inherit F_LIQUID;

void create()
{
   set_name("�̲�", ({"tea"}));
   set_weight(100);
   if (clonep())
     set_default_object(__FILE__);
   else {
     set("long", "����һ�����̲衣\n");
     set("unit", "��");
     set("value", 30);
     set("max_liquid",30);
   }

  
   set("liquid", ([
     "type": "��",
     "name": "�̲�",
     "remaining":30,
     "drunk_supply":20,
   ]));
}

