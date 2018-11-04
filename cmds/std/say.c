// say.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
if (me->query("combat_exp") < 2000 )
{
        if ( ((int)time() - (int)me->query_temp("say_time")) < 1 )
        return notify_fail("�л��ú�˵Ŷ��ֻ�о������2000,����������ʹ��\n");
if ( strlen(arg)>40)
return notify_fail("��˵��ô�໰��ʲô! ��ˢ��?ֻ�о������2000,����������ʹ��\n");

}
	if (!arg) {
		write("���������ﲻ֪����˵Щʲô��\n");
		message("sound", me->name() + "�������ﲻ֪����˵Щʲô��\n",
			environment(me), me);
		return 1;
	}
	if( (int)me->query("qi") < (int)me->query("max_qi") / 5 ) {
		arg = replace_string(arg, " ", " ... ") + " ...";
	}
                     me->set_temp("say_time", time());
	write( CYN "��˵����" + arg + "\n" NOR);
	message("sound", CYN + me->name() + "˵����" +  arg + "\n" NOR,
		environment(me), me);

	// The mudlib interface of say
	all_inventory(environment(me))->relay_say(me, arg);

	return 1;
}

int help (object me)
{
	write(@HELP
ָ���ʽ: say <ѶϢ>
 
˵�������и�����ͬһ��������˶���������˵�Ļ���
 
ע: ��ָ����� ' ȡ��.
 
HELP
	);
	return 1;
}
