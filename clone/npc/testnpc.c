// liumang.c ��å

inherit NPC;
int ask_job();
void create()
{
	set_name("����", ({ "lywin", "ly win" }));
	set("gender", "����");
	set("age", 19);
	set("long", "����һ���������ֺ��е���å�����õ��ǰװ����ֵģ�Ҳ����ǰ�й�Ǯ��\n");
	
	set("combat_exp", 10000);
	set("shen_type", -1);

	set("attitude", "peaceful");
	
	set("qi",90000);
	set("max_qi",90000);
	set("eff_qi",90000);
	set("eff_jing",90000);
	set("jing",90000);
	set("max_jing",90000);

	set_skill("unarmed", 20);
	set_skill("dodge", 20);
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 10);
        set("inquiry", ([
            "qixue" : (: ask_job() :),
            "��Ѫ" : (: ask_job() :),
        ]) );

	setup();
	carry_object("/clone/misc/cloth")->wear();
}
void unconcious()
{
	reincarnate();
	set("eff_qi", query("max_qi"));
	set("qi", query("max_qi"));
	set("eff_jing", query("max_jing"));
	set("jing", query("max_jing"));
	set("jingli", query("eff_jingli"));
        this_object()->clear_condition();
	command("hehe");
}

void die()
{
	unconcious();
}

int ask_job()
{

        object ob = this_player();
        object me = this_object();
me->clear_condition();	  
                command("say ��������" + me->query("qi") + "���������� " + me->query("eff_qi") + "��");
//                command("nod" + me->query("id"));
                command("say ��������" + me->query("jing") + "���������� " + me->query("eff_jing") + "��");
                return 1;
}
