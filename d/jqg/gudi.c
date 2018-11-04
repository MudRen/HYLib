// gudi.c

#include <ansi.h>
#include <room.h>

inherit ROOM;

void init()
{
        add_action("do_pa", "pa");
        add_action("do_tiao", "tiao");
        add_action("do_jian", "jian");        
}

void create()
{
       set("short", HIG"�ȵ�"NOR);
       set("long", @long
�������ȵף�ȴ��������ԭ����һ����ˮ��̶(tan������Χ�����м��ô�
����������������ʮ���䳲(fengchao)�����ڳ��Ϸ�����ȥ�Ķ���һЩ����˶
����ɫ�Ұ׵�������䣬���������˶���ʯ(shi)��
long);
       set("item_desc", ([
          "fengchao": HIY"���߽����߹۲죬ֻ���䳲֮�Ժ���������ʵ���˹���Ϊ��\n"NOR,
          "tan": HIC"���Ŀ��̶����ȥ������ˮ̶������ɭɭ�����������������ˣ��ƺ�����������\n"+
                    "һ���������ס�\n"NOR,
          "shi":"һ�����СС�Ķ���ʯ�����̲�ס���(jian)����������\n",
       ]));

       set("objects", ([
                "/d/gumu/npc/yufeng" : 1,
       ]));

       set("outdoors", "�����");
       setup();
}

int do_pa(string arg)
{
	object me;

	me=this_player();
	if (me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ģ�\n");
	if ( !arg || arg != "yabi")
       		return notify_fail("��Ҫ��������\n");
	message_vision(YEL"$N���������������ȥ��\n"NOR, me);
	me->move(__DIR__"yabi7");
	me->add_temp("tengacc",1);
        me->start_busy(1);
	tell_room(environment(me), me->name() + "�����������������������\n", ({ me }));
	return 1;
}

int do_tiao(string arg)
{
	object me;
	me=this_player();
	if (me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ģ�\n");
	if ( !arg || arg != "tan")
       		return notify_fail("��Ҫ��������\n");
	message_vision(HIY"$N��ͨһ����ӿ��������ˮ̶��\n"NOR, me);
	me->move(__DIR__"guditan1");
	tell_room(environment(me), me->name() + "�Ӱ�������������\n", ({ me }));
        message_vision (HIB"$Nֻ����ͷ���εģ�������ڱ����ˮ�У���ס�Ĳ�����\n"NOR,me);
	return 1;
}

int do_jian(string arg)
{
        object me,ob;
        me=this_player();
        if (me->is_busy() || me->is_fighting())
                return notify_fail("����æ���ģ�\n");
        if ( !arg || arg != "shi")
                return notify_fail("��Ҫ����ʲô��\n");
        if ((int)me->query_encumbrance() * 100 / (int)me->query_max_encumbrance() >= 100) 
                return notify_fail("��ĸ��ɹ����ˣ�\n");
        switch  (random(3)){
        case 0: ob = new(__DIR__"obj/shi1"); break;
        case 1: ob = new(__DIR__"obj/shi2"); break;
        case 2: ob = new(__DIR__"obj/shi3"); break;
        }
        ob->move(me);
        message_vision("$N���������ӵ��ϼ�����һ��"+ob->name()+"��\n",me);
        return 1;
}
