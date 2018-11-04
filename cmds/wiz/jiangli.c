// jiangli.c
// ��������bug�����
// idea@yqyl

inherit F_CLEAN_UP;
#include <ansi.h>

int main(object me,string arg)
{
	string id,reason,present;
	object player,gold;
	int i;
	
	if( !arg || arg=="" || sscanf(arg, "%s for %s", id, reason)!=2)
		return notify_fail("ָ���ʽ��jiangli <���id> for <��Ҫ����bug>\n");

	player = find_player(id);
	if (!player) return notify_fail("û�������\n");
	if (wizardp(player)) return notify_fail("���ܽ�����ʦ\n");
	i=random(3);
	switch (i)
	{
		case 0:
			player->add("combat_exp", 400);
			present="���� 400";
			break;
		case 1:
			player->add("potential",200);
			present="Ǳ�� 200";
			break;
		case 2:
			gold = new("/clone/money/gold");
			gold->set_amount(2);
			gold->move(player);
			present="2 gold";
			break;
	}
	tell_object(player,HBRED""+me->query("name")+"��������"+present+"��\n"NOR);
	write(HBRED"�㽱��"+player->query("name")+present+"��\n"NOR);
	
	log_file("jiangli",
		sprintf("%s(%s) ���� %s(%s) %s ��Ϊ %s  on %s\n",
		me->name(1),
		geteuid(me),
		player->name(1),
		geteuid(player),
		present,
		reason,
		ctime(time()) ));
		
	
	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ : jiangli <���id> for <��Ҫ����bug>

��������뷢��Сbug(�������--����ʧ��,��û��ɾ޴���ʧ��)
��player�Խ���.ע�������ñ�����,���bug���ⲻ��ȷ,����ʾ��
���پ���
����	jiangli tryid for ����tree����
HELP	);
	return 1;
}