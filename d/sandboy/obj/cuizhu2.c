#include <ansi.h>

inherit ITEM;

void create()
{
  set_name("���˵�"+HIG+"����"+NOR, ({ "bamboo" }));
  set_weight(8000);
  set("long","һ����ɫ"+HIG+"����"+NOR+"�Ĵ���,��ϧ��������.\n");
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("material", "bamboo");
    set("no_get",1);
       set("no_drop",1);
  }
  setup();
}
