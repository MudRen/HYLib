//  antirobot1.c
//  By Jpei  Aug 1997

inherit NPC;

void create()
{
	set_name("#TICK!!!", ({ "anti robot" }));
	set("shen_type", 0);

	set("gender", "����");
	set("age", 20);
	set("long", "����һ��ר���ƻ������˵Ļ����ˡ�\n");
	set("nickname", "��������̽ -- �����˿���");

	set("max_qi", 10000);
	set("qi", 10000);
	set("max_jing", 10000);
	set("jing", 10000);
	set("attitude", "friendly");

        set("chat_chance", 40);
        set("chat_msg", ({
                (: random_move :)
        }) );
	
	setup();
}

void init()
{
	say("����������ϡ�\n");
	say("��������ϣ�����˫�ۣ�վ��������\n");
	say("���˹���ϣ�վ��������\n");
	say("��һ�����������þ������棬�ûһ���ˡ�\n");
}

void kill_ob(object ob)
{
	ob->remove_killer(this_object());
	remove_killer(ob);
	message_vision("$N��ɥ�ط��ֻ����˿��Ǹ����������ս����\n", ob);
}

void unconcious()
{
	reincarnate();
	set("eff_qi", query("max_qi"));
	set("qi", query("max_qi"));
	set("eff_jing", query("max_jing"));
	set("jing", query("max_jing"));
	set("jingli", query("eff_jingli"));
	say( "�����˿�����Ц��˵�������޵в����棡\n");
	command("hehe");
}

void die()
{
	unconcious();
}

