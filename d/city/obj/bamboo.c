// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// created 3/31/1997 by snowcat
#include <weapon.h>

inherit STAFF;
inherit F_LIQUID;

void create()
{
  set_name("ϸ������Ͳ", ({ "bamboo", "long bamboo" }) );
  set_weight(600);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long", "����һ���߰ѳ��������������Ͳ��\n");
    set("unit", "��");
    set("value", 120);
    set("max_liquid", 100); 
    set("wield_msg", "$N���ϸ������Ͳ��˳�ֻε���һ�������ˮ��\n");
    set("unwield_msg", "$N��ϸ������Ͳ������䡣\n");
  }

  set("liquid", ([
    "type": "water",
    "name": "��Ȫ�����",
    "remaining": 90,
  ]) );
  init_staff(2);
  setup();
}