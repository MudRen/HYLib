// jiasi.c
#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
	int wimpy;
//	if(me->query("class") != "bandit")
//		return notify_fail("�������ɵ��˲�����װ����\n");
        seteuid(getuid());
	if (me->query("combat_exp",1)> 800000)
		return notify_fail("����ô���ˣ�װ��û�õ�!\n");

        if( !me->is_fighting() )
                return notify_fail("�㲻��ս���У�����Ҫ��װ����\n");
	if (me->is_busy() )
		return notify_fail("��������æ����!\n");

	wimpy = (int)me->query("env/wimpy");
	message_vision("$N�ҽ�һ����һͷ�Ե��ڵ��¡�\n$N���ˡ�\n",me);
	me->set_temp("disable_inputs",1);
	me->set_temp("block_msg/all",1);
	me->disable_player(HIG "<������>" NOR);
//        me->set("no_get",1);
        me->remove_all_killer();
	me->remove_all_enemy();
me->set("qi",me->query("qi")/5);
me->set("qi",me->query("jing")/5);
	me->delete("env/wimpy");
        me->start_call_out( (: call_other, __FILE__, "remove_jiasi", me, wimpy :), 
random(80 - (int) me->query_con()));
	return 1;
}

void remove_jiasi(object me, int wimpy)
{
        int i;
	object env;
	env = environment(me);
//	me->set("no_get",0);
	me->delete_temp("disable_inputs");
	me->enable_player();
	me->delete_temp("block_msg/all");
	me->set("env/wimpy",wimpy);
   	message_vision("$N�ڵ������ĵط��˸���С��������������ۡ�\n",me);
	if (env)
	{
		while (env->is_character() && environment(env))
			env = environment(env);
		if (env != environment())
                	me->move(env);
	}

//	me->move(environment(me),1);

}

int help(object me)
{
        write(@HELP
ָ���ʽ : jiasi
������ս����װ�������������Ļ��ᡣ
�������ɵ��˲�����װ����

HELP
        );
        return 1;
}
 
