// rake.c

#include <weapon.h>

 inherit HAMMER;

void create()
{
  set_name("�ųݶ���", ({ "ding pa", "pa","rake" }) );
  set_weight(9000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("value", 1000);
    set("material", "iron");
    set("long", "һ�������ľųݸְҡ�\n");
    set("wield_msg", "$N����һ��$n������һ���ٹ�ͷ����\n");
  }
 init_hammer(200);
  setup();
}


