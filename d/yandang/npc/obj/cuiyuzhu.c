#include <ansi.h>
#include <armor.h>

inherit HANDS;

void create()
{
	set_name( HIC"������"NOR, ({ "cui yuzhuo", "yuzhuo" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "ֻ");
                set("long", "һֻ�������,��̳�һ����β�����ķ���,\n
��������ȴ����Ƕ����Ȼ"+HIR+"�챦ʯ"+NOR+",�ƺ����԰�(an)��!\n");
		set("value",500);
		set("material", "stone");
		set("armor_prop/armor", 150);
	}
	setup();
}
void init()
{
  if(this_player()==environment())
  add_action("do_an","an");
}
int do_an(string arg)
{
object jade,me;
	if( !living(this_player()))	return 0;
if ((!arg)||((arg!="�챦ʯ")&&(arg!="����"))) return notify_fail("��Ҫ��ʲô?\n");
me = this_player();
	jade = new(__DIR__"yuchang.c");
	jade->move(me);
message_vision("$N��������,ž��һ��,"+HIC+"����"+NOR+"����,���һ��"+HIC+"�̽�.\n"NOR,this_player());
	destruct(this_object());

return 1;
}
