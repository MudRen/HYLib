
inherit ITEM;
inherit F_LIQUID;
#include <ansi.h>
void create()
{
   set_name(HIR"Ů����"NOR, ({"nver hong","jiu"}));
   set_weight(700);
   if (clonep())
     set_default_object(__FILE__);
   else {
     set("long", "����һ̳�����Ů���졣\n");
     set("unit", "̳");
     set("value",200);
     set("max_liquid",30);
   }

  
   set("liquid", ([
     "type": "alcohol",
     "name": "Ů����",
     "remaining":30,
     "drunk_supply":15,
   ]));
}

