// Deamon:/adm/daemons/autorebootd.c
/* �������jjgodΪģ�⻪������ȸ�дԭwaiwai���Զ�����ϵͳ��
    �Զ��������������Ǳ�Ҫ�ģ�����ʦƽʱ�����ߵ�ʱ�򣬿���ͨ��
    �����ָ�ԭ����״̬��ԭ��waiwai���Ǹ�ϵͳ̫��������15����
    ����ʱ��ȻҪд15������������200���ӵ���ʱ����Ҫд200��
    ���������Ǻ�Ц�������ڸ�Ϊֻ��Ҫ2�������͹��ˣ����۶೤��
    ����ʱ�������Լ����á�*/

#include <ansi.h>
#include <net/daemons.h>

inherit F_DBASE;
private void count_time(int min);
void auto_reboot_start();
void auto_reboot_done();
void create()
{
//	object *ob = users();������ʵ������������ʱ�Ͳ������˳�����ռ����Դ������Ϸ��һ������û�е�ʱ��
//	int i;		 ���������ͽ��ɴ˳����йܵģ���Խ��Խ�鷳���������ˣ�����Ȥ��������Ĵ����Լ����ɡ�
	seteuid(ROOT_UID);
	set("channel_id", "�Զ���ʱ��������");
/*	for(i=0; i<sizeof(ob); i++){
		if (wizhood(ob[i])=="(admin)")
		{
		tell_object(ob[i],ob[i]->name()+"����Ϊ��Ϊ������㻹���ߣ������Զ��������鲻�����أ�\n");
		log_file("AUTOREBOOT", sprintf("autoreboot����ʧ�ܣ�\n"));
		return;
		}
		else {*/
		CHANNEL_D->do_channel( this_object(), "sys", "�Զ���ʱ���������Ѿ�������");
		call_out("auto_reboot_start", 86400+random(500));// 2���Զ�����
//		call_out("auto_reboot_start", 2);// 2���Զ�����
/*		call_out("auto_reboot_start",20);
		log_file("AUTOREBOOT", sprintf("autoreboot�����ɹ���\n"));
		return;
		}
	}*/
}

void auto_reboot_start()
{
	remove_call_out("auto_reboot_start");
	message("system",RED"���������顿"BLU"���ڿ�ʼ����II�Զ���������ʱ������5���ӣ�\n" NOR,users());
	call_out("count_time",60,5); // "15"��ָ��������ʱʱ��15���ӣ������Լ��޸�
}

private void count_time(int min)
{
	min--;
	if( min ) {
		message("system",RED"���������顿"BLU"��λ��ң��뺣��II�Զ���������" + chinese_number(min) +"���ӵ�ʱ�䣡\n"NOR,users() );
		call_out("count_time", 60, min); // ���ߴ�һ��м�����ʱ��
	} else {
		message("system",RED"���������顿"BLU"��λ��ң�����II�����Զ�����������\n"NOR,users() );
		call_out("auto_reboot_done", 3+random(8)); // ������
	}
}

void auto_reboot_done()
{
	int i,j;
	object *ob, link_ob;
	string id;
	j=0;
	seteuid(getuid());
//	set("channel_id", "���̾���"); // ��δ��̵Ĵ��뿴��ȥ�Ͳ���˳�ۣ��϶�д�Ĳ�̫�ã���̫�����ҾͲ�������
//	ob=users();
//	i=sizeof(ob);
//	for( i=0;i<sizeof(ob);i++) {
//	id = (string) ob[i]->query("id");
//	if (!id) continue;
//	if(!environment(ob[i]) )        continue;
//	if( !objectp(link_ob = ob[i]->query_temp("link_ob")) ) continue;
//	if( (int)link_ob->save() && (int)ob[i]->save() ) j = 1;
//	else CHANNEL_D->do_channel( this_object(), "sys", ob[i]->query("name")+"�����Զ�����ʧ�ܡ�");
//	}
//	CHANNEL_D->do_channel( this_object(), "sys", "�����Զ����̳ɹ���");
	shutdown(0);
	return;
}
