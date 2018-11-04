// reboot.c

#include <login.h>
#include <ansi.h>
#include <net/daemons.h>

inherit F_DBASE;

int main(object me, string arg)
{
	string wiz_status;
	object npc;

	if( me != this_player(1) ) return 0;
	
	wiz_status = SECURITY_D->get_status(me);
	if( wiz_status != "(admin)" && wiz_status != "(arch)" && wiz_status != "(wizard)" )
		return notify_fail("ֻ�� (arch) ���ϵ���ʦ������������" + MUD_NAME + "\n");

        message("system",
                HIW     "\t\t������II����������Ӻ������������뾡��浵(save)��\n\n" NOR,
                users() );
        call_out("countdown", 60, 5);

	return 1;
}

private void countdown(int min)
{
	min--;
	if( min ) {
		message("system",
                        HIR     "\t\t������II������" + chinese_number(min) + "���Ӻ������������뾡��浵(save)��\n\n"NOR,
			users() );
		call_out("countdown", 60, min);
	} else {
		message("system",
                        HIW "\t\t������II�������������������Ժ��ٵ�½��\n"NOR,
			users() );
		call_out("do_shutdown", 3+random(8));
	}
}

private void do_shutdown()
{
	int i,j;
	object *ob, link_ob;
	string id;
	j=0;
	seteuid(getuid());
/*	set("channel_id", "���̾���"); // ��δ��̵Ĵ��뿴��ȥ�Ͳ���˳�ۣ��϶�д�Ĳ�̫�ã���̫�����ҾͲ�������
	ob=users();
	i=sizeof(ob);
	for( i=0;i<sizeof(ob);i++) {
	id = (string) ob[i]->query("id");
	if (!id) continue;
	if(!environment(ob[i]) )        continue;
	if( !objectp(link_ob = ob[i]->query_temp("link_ob")) ) continue;
	if( (int)link_ob->save() && (int)ob[i]->save() ) j = 1;
	else CHANNEL_D->do_channel( this_object(), "sys", ob[i]->query("name")+"�����Զ�����ʧ�ܡ�");
	}
	CHANNEL_D->do_channel( this_object(), "sys", "�����Զ����̳ɹ���");*/
	shutdown(0);
	return;
}

int help (object me)
{
        write(@HELP
ָ���ʽ: reboot
 
��������Ϸ, ϵͳ�Ὺʼ������ʱ, ������������𶯡�
 
HELP
);
        return 1;
}
 
