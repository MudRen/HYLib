// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// golden_armor.c

#include <armor.h>

inherit ARMOR;

void create()
{
   set_name("���ս��", ({ "heaven armor", "armor" }) );
   set_weight(8500);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "��");
     set("material", "gold");
     set("value", 3000);
     set("armor_prop/armor", 35);
   }
   setup();
}
