// huoqiang.c

#include <ansi.h>
#include <weapon.h>

inherit STAFF;
void init()
{
        add_action("do_shoot","shoot");
}
void create()
{
	set_name("������ǹ", ({"helan huoqiang", "huoqiang"}));
	set_weight(5000);

	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "֧");
		set("long", "һ֧������ǹ����ϧֻ�ܷ�һǹ��\n");
		set("no_put", 1);
		set("no_pawn", 1);
		set("value", 0);
		set("material", "bamboo");
		set("wield_msg", "$N���һ֧���͵�ľ����ǹ�������С�\n");
		set("unwield_msg", "$N�����еĻ�ǹ���ر��ϡ�\n");
	}
	init_staff(30);
	setup();
}
int do_shoot(string arg)
{
       object me, obj;

       me = this_player();
      if (!arg)
      return notify_fail("��Ҫ��˭��\n");
if (me->is_busy())
return notify_fail("����æ���أ�\n");


       if( !objectp(obj = present(arg, environment(me)) ))
               return notify_fail("��Ҫ����Ķ�������û�С�\n");
if (obj==me)
   return notify_fail("�Լ����Լ�!\n");
       message_vision(HIR "\n$N��׼$ņ�־���һǹ���飡ǹ��һ�Ż��������$n�������ˣ�\n\n" NOR,
                       me, obj);

me->start_busy(3);
obj->set_temp("last_damage_from",me);
       obj->die();
me->add_temp("bwdhpk",1);
message("channel:chat", HIC"������ս����"HIR + " "+obj->query("name")+"��"+me->query("name")+"�û�ǹ�����ˣ�\n"NOR,users() );
       return 1;
}
