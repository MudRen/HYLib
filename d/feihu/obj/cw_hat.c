// cw_hat
//by steel
#include "ansi.h"
#include "armor.h"
inherit HEAD;
void create()
{	
  set_name(HIR"����ս��"NOR, ({ "cw_hat", "hat" }) );
  set_weight(1000);	
   if( clonep() )
  set_default_object(__FILE__);
  else {
		set("unit", "��");
		set("long", "���Ǵ���������ͷ����͸��һ�ɰ���ɫ��\n");
		set("no_put", 1);
//		//set("value", 100000);
		set("armor_prop/attack", 20);
		set("armor_prop/armor", 50);	
     }	
                setup();
 } 