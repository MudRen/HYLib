// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// golden_armor.c

#include <armor.h>

inherit ARMOR;

void create()
{
   set_name("天兵战甲", ({ "heaven armor", "armor" }) );
   set_weight(8500);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "件");
     set("material", "gold");
     set("value", 3000);
     set("armor_prop/armor", 35);
   }
   setup();
}
