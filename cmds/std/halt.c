#include <ansi.h>
// halt.c
// By Xiang@XKX (12/17/95)

int main(object me, string arg)
{
        object ob;
	if( arg && wizardp(me) ) {
		ob = present(arg, environment(me));
		if( !ob ) return notify_fail("û��������\n");
		if( !ob->is_fighting() ) return notify_fail(ob->name()+"���ڲ�æ��\n");
		ob->remove_all_enemy();
                message_vision("\n$N����ʦ������ֹͣ��$n��ս����\n", me, ob);
		return 1;
	}

        if (me->query_condition("killer") && userp(me)) {
            message_vision("$N�����ڱ�ͨ����������?\n", me);
			return notify_fail("������ʧ�ܡ�\n");
		}

    if(environment(me)->query("short")==BLU"ɽ��"NOR
       ||environment(me)->query("short")==WHT"����ʯ��"NOR
       ||environment(me)->query("short")==YEL"�Ҷ�"NOR
       ||environment(me)->query("short")==RED"���Ҷ�"NOR
       ||environment(me)->query("short")==CYN"ʯ��"NOR)
			return notify_fail("����ط�������·��������������!\n");
if( environment(me)->query("magicroom"))
			return notify_fail("����ط�������·��������������!\n");
        if (me->query_condition("huaxunshan") || me->query_condition("shaolin_song")|| me->query_condition("lingjiu_song")) {
            message_vision("$N������������������,���ϸ�������\n", me);
			return notify_fail("������ʧ�ܡ�\n");
		}
        if (present("letter", me)||present("biao",me)||present("prize",me)){
            message_vision("$N����������Ҫ��������Ʒ,�������ӣ�\n", me);
			return notify_fail("������ʧ�ܡ�\n");
		}
//        if ((int)me->query_temp("pending/exercise") != 0 && me->is_fighting()) {
//	        message_vision("$N���������е�����ǿ��ѹ�ص��վ��������\n", me);
//                me->start_busy(3);
//		me->interrupt_me();
//	}

	if (!me->is_busy() && me->is_fighting()) {
		me->remove_all_enemy();
                message_vision("\n$N�������һԾ������սȦ�����ˡ�\n", me); 
if (me->query("combat_exp") >1000000)
{
                me->start_busy(random(2));
}
		return 1;
	}
	else if ((int)me->query_temp("biguan") != 0) {
	        message_vision("$N�ڱչ���;ͻȻ������վ��������\n", me);
                me->start_busy(0);
                me->set_temp("biguan", 0);
		me->interrupt_me();
                me->force_me("quit");
	}
//	else if ((int)me->query_temp("pending/exercise") != 0) {
//	        message_vision("$N���������е�����ǿ��ѹ�ص��վ��������\n", me);
//		me->interrupt_me();
//	}
	else if (!me->is_busy()) 
		return notify_fail("�����ڲ�æ��\n");
	else if ((int)me->query_temp("pending/respirate") != 0)
		me->interrupt_me();
	me->interrupt_me();
        if (me->is_busy()) write("�����ں�æ��ͣ��������\n");
	return 1;
}

