inherit ITEM;
#include <ansi.h>
void create()
{
  set_name(HIG "�����" NOR,({"wangguo","DEADLY poison"}));
  set("long", HIG
      "����һ������������������Ϊ�˼�����ǰ��ʹ��\n"
      "�������ѣ����壩�Ķ�������������˾綾������Ӹպã�\n" NOR);
  set("value",20000);
  set("unit","��");
}

void init()
{
  if(this_player()==environment())
  add_action("do_cure","die");
}

int do_cure()
{
	object me;
	me = this_player();
	if( !living(me))	return 0;
	message_vision("$N�������һ��������ȥ��\n",me);
	me->clear_condition();
	me->unconcious();
	destruct(this_object());
	me->unconcious();
  return 1;
}
