// suicide.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	if( me->is_busy() )
		return notify_fail("����һ��������û��ɡ�\n");

	if( !arg || arg != "-f") {
		write("���� suicide -f ȷ����ɱ��\n");
		return 1;
	}

	if( arg!="-f" ) 
		return notify_fail("��ɱ�����֣�����Ҫ��Զ������������Ͷ̥��\n");

	write(
		"������Ȼ�ն�����Ͼ����ã��벻Ҫ������ɱ��\n"
		"ѡ����ɱ��ζ�������������Ͼ���Զɾ���ˣ�����ؿ��������\n"
		"ȷ���Ļ��������������룺");
	input_to("check_password", 1, me, 1);
	return 1;
}

void check_password(string passwd, object me, int forever)
{
	object link_ob;
	string old_pass;

	link_ob = me->query_temp("link_ob");
	old_pass = link_ob->query("password");
	if( crypt(passwd, old_pass)!=old_pass ) {
		write("�������\n");
		return;
	}

	if (forever) {
		tell_object( me,
			HIR "\n\n�����Ҫ��ɱ�ˣ�������ʮ������������\n\n\n" NOR);
		me->set_temp("suicide_countdown", 30);
		me->start_busy( (: call_other, this_object(), "slow_suicide" :),
			(: call_other, this_object(), "halt_suicide" :) );
	}
}

int slow_suicide(object me)
{
	object link_ob;
	int stage;

	stage = me->query_temp("suicide_countdown");
	me->add_temp("suicide_countdown", -1);

	if( stage > 1 ) {
		if( stage%5 == 0 )
			tell_object(me, HIR "�㻹�� " + stage + " ���ʱ����Ժ��,��"HIG"halt"HIR"������ֹ��ɱ��\n" NOR);
		return 1;
	}

   if (userp(me) && !query_heart_beat(me))
        return 0;
   if( me->query("hunmi",1))
        return 0;
   if( me->query("disable_inputs",1))
        return 0;

	link_ob = me->query_temp("link_ob");
	if( !link_ob ) return 0;

	log_file("static/SUICIDE",
		sprintf("%s commits a suicide on %s\n", geteuid(me), ctime(time())) );

	seteuid(getuid());
	rm( link_ob->query_save_file() + __SAVE_EXTENSION__);
	rm( me->query_save_file() + __SAVE_EXTENSION__ );
		write("�ðɣ�������:)��\n");
	tell_room(environment(me), me->name() +
		"��ɱ�ˣ��Ժ�����Ҳ������������ˡ�\n", ({me}));
	destruct(me);
	return 0;
}

int halt_suicide(object me)
{
	tell_object(me, "���������ɱ����ͷ��\n");
	CHANNEL_D->do_channel(this_object(),"rumor",me->name(1) + "���������¸ҵػ���ȥ��");
	return 1;
}

int help (object me)
{
        write(@HELP
ָ���ʽ: suicide [-f]
 
�����Ϊĳ��ԭ���㲻�����, �����ѡ����ɱ.
��ɱ������:
 
suicide    : ����Ͷ̥
suicide -f : ��Զ�ĳ�ȥ�������, ϵͳ��Ҫ����
             ����������ȷ�����.
 
������ѡ�� :)
 
HELP
);
        return 1;
}
