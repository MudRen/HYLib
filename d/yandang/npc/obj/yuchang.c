#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
	set_name(HIC"�㳦��"NOR, ({ "yuchang","sword"}) );
	set_weight(6000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "��С�Ľ���ã����,���ֺ�����һ������.\n
��£(close)���ܳ�Ϊһֻ����.\n");
		set("value", 80000);
		set("material", "steel");
	}
	init_sword(880);
      set("wield_msg",
"��---��----��----------$N���쳤Х,һ�Ѷ�С��"+HIC+"��"+NOR+"����������!\n");
	set("unwield_msg","$N��"+HIC+"�̽�"+NOR+"С�ĵ��պ�.\n");
       setup();
}
void init()
{
  if(this_player()==environment())
  add_action("do_close","close");
}
int do_close()
{
object jade,me;
me = this_player();
	if( !living(me))	return 0;
	jade = new(__DIR__"cuiyuzhu.c");
	jade->move(me);
message_vision("$N��"+HIC+"�㳦��"+NOR+"�ϳ�һֻС�ɵ�"+HIC+"������.\n"NOR,this_player());
	destruct(this_object());

return 1;
}
