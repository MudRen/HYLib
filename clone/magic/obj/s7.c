// cw_hat
//by steel
#include "ansi.h"
#include "armor.h"
inherit HEAD;
void create()
{	
  set_name(HIB"�׽�����"NOR, ({ "helmet hat", "helmethat" }) );
  set_weight(1000);	
   if( clonep() )
  set_default_object(__FILE__);
  else {
		set("unit", "��");
set("long", HIB"����һ���׽�����,�������侫�¡�\n"NOR);
                set("value", 15000);
                set("wield_neili", 5000);
                set("wield_maxneili", 5000);
                set("wield_str", 30);        
		set("armor_prop/armor",60);
		set("armor_prop/attack", 5);
     }	
                setup();
 } 
