// waiter.c

inherit NPC;
#include <ansi.h>;

void create()
{
	set_name("��С��", ({ "xiao er", "xiao", "waiter" }) );
	set("gender", "����" );
	set("age", 22);
	set("long",
		"��λ��С����Ц�����æ��������ʱ������ڲ����ϵ�Ĩ��������\n");
	set("combat_exp", 100);
        set("no_kill",1);
        set("no_fight",1);
        set_temp("no_kill",1);
         set("no_get",1);	
	set("attitude", "friendly");
	set("rank_info/respect", "С����");
	setup();
}

void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	if (!ob->query_temp("welcome100") || ob->query("mud_age")<1000)
	{
		ob->set_temp("welcome100","1");
tell_object(ob,HIY"��С��Ц�����˵������λ"+RANK_D->query_respect(ob)+"����ӭ����"GRN"����II��"HIY"

    �������ʲô�����׵ģ�����������ҡ�ȱǮ����Ҳ�����������
�����ݶ��ѹء������Ƕ����������˵ġ���Ȼ��Ҳ������"HIC"help"HIY"�������
�Ǹ����İ�����
    ����"HIC"help"HIY"���ܿ����ܶ������Ŀ��
    ����Ĺ��º���ڣ�����Ļ��������ǽ�ӹ��ʮ�屾С˵�������
�Թ��²�̫�ǵ��˻����˽��Щ������"HIC"help intro"HIY"�������������
��û��� MUD��Ϸ���Ǿ��ȿ���"HIC"help newbie"HIY"��������·�ɡ�"HIC"help cmds"HIY"
������������Ҷ����õ��������ʶһ������ĵ�ͼ��"HIC"help map"HIY"����
���кܶ���Ŀ�ģ������ѡ���ͼ��Ŀ"HIC"help map_all"HIY"����������Ϸ�ĵ�
ͼ����"HIC"help map_yz "HIY"���������ڴ��ĳ��еĵ�ͼ����Ȼ����Ҫ��������
�����̣����һ��Ҫ��ʹ��"HIC"chat"HIY"���������������İ����ļ�Ҳ��Ϊ
���ǵĹ��������£��������Ŷ���͵��������ϣ����������Ͼ͵����
�ˣ���ʦ�������Կ��ģ�����û��ð��ĸ����ɾ���ȥ���ѧ������
����������Ϣ���ģ���ȥ��������Ĺ��棬���µ���Ϣһ�����������
���
    ������������Ϸ����ƺ͹�����ʲô�����������뵽�����˵�
��ҳ"HIC"http://lywin.126.com����"HIY"������һ�������濼�ǵġ�\n\n"NOR);
	
}
	switch( random(2) ) {
		case 0:
			say( "��С��Ц�����˵������λ" + RANK_D->query_respect(ob)
				+ "�������ȱ��裬ЪЪ�Ȱɡ�\n");
			break;
		case 1:
			say( "��С���ò����ϵ�ë��Ĩ��Ĩ�֣�˵������λ" + RANK_D->query_respect(ob)
				+ "����������\n");
			break;
	}
}

int accept_object(object who, object ob)
{
	
	if (ob->query("money_id") && ob->value() >= 5000) 
	{
		tell_object(who, "С��һ������˵������л���ϣ��͹�����¥ЪϢ��\n");

		who->set_temp("rent_paid",1);

		return 1;
	}

	return 0;
}
