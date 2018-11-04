// waiter.c

inherit NPC;
#include <ansi.h>;

void create()
{
	set_name("��ˮ��", ({ "lin shuixian", "lin" }) );
	set("gender", "Ů��" );
	set("age", 18);
	set("long",
		"��λ����Ư����С�������˲���Ŀ�⣬���������������Ҳ��ʱ����......\n");
	set("combat_exp", 100);
	set("attitude", "friendly");
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
        add_action("do_yao","want");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
tell_object(ob,"��ˮ��Ц��������˵����
    �����ڿ�ʼ���㽫Ҫ�������Ŀ��顣������Ҫͨ��һ���Թ���Ȼ����ᵽ���
��¥���Ż�Ԫ������һ�����ڻ��������ʮ����֣������������ս���ڷ���¥����
��Ԫ����û�л�ͷ��·����ֻ�еȴ�һ���Ӻ��Զ��ͻ�㳡���롣
    ˳����һ�£�����Ҫ(want)��ͷ��ˮ����\n\n");
        ob->set_temp("comehere",1);
}

int do_yao()
{
	object ob,kele,hbb;
	ob = this_player();

        if (ob || interactive(ob))
        if ( ob->query_temp("comehere") )
        {
        if (ob->query("gender")=="����")
		tell_object(ob, "��ˮ�ɵݸ�����ͷ��ˮ��ʱ�˻�š����һ�ѣ�����˵��������¥�ϼ���\n");
        if (ob->query("gender")=="Ů��")
		tell_object(ob, "��ˮ�ɰ�����һ�ۣ���ͷ��ˮ�����˹�����'�������԰ɡ�'\n");
	kele = new(__DIR__"obj/kele");
	hbb = new(__DIR__"obj/hbb");
	kele->move(ob);
	hbb->move(ob);
        ob->delete_temp("comehere");
        return 1;
        }
        return 0;
}
