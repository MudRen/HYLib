// tang wuhuo.c ���޻�

#include <ansi.h>

inherit NPC;
inherit F_MASTER;


void create()
{
	set_name("���޻�", ({ "tang wuhuo", "tang" }));
	set("nickname", HIW "���²���" NOR);
	set("long", 
		"�������ŵ��ߴ������еĽܳ��������Ϊ�˰������磬����\n"
		"���ȵ�����Ƣ��������������˳ơ����²����ƴ�����\n"
		"����Լ��ʮ���࣬Ц�ݿ��䣬˫Ŀ���о�â��˸��\n");
	set("gender", "����");
	set("age", 40);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 98);
	set("int", 90);
	set("con", 90);
	set("dex", 92);
	
	set("qi", 30000);
	set("eff_qi", 30000);
	set("max_qi", 30000);
        set("jing", 30000);
	set("eff_jing", 30000);
	set("max_jing", 30000);
	set("neili", 80000);
	set("max_neili", 80000);
	set("jiali", 60);
	set("combat_exp", 3800000);
	set("score", 60000);

	set_skill("force", 200);
	set_skill("biyun-xinfa",300);
	set_skill("dodge", 100);
	set_skill("qiulinshiye", 200);
	set_skill("strike", 100);
	set_skill("unarmed",100);
	set_skill("biye-wu", 100);
	set_skill("parry", 100);
	set_skill("throwing", 100);
	set_skill("zhuihun-biao", 300);
	set_skill("literate", 100);

	map_skill("force", "biyun-xinfa");
	map_skill("dodge", "qiulinshiye");
	map_skill("strike", "biye-wu");
	map_skill("unarmed","biye-wu");
	map_skill("parry", "zhuihun-biao");
	map_skill("throwing", "zhuihun-biao");
	
	create_family("����", 7, "����");
	set("class", "tangmen");

	set("chat_chance_combat", 90);
	set("chat_msg_combat", ({
		(: perform_action, "strike.meng" :),
		(: perform_action, "strike.meng" :),
		(: perform_action, "dodge.rain" :),
                (: perform_action, "dodge.wu" :),
	}) );

	setup();
	carry_object("/d/tangmen/obj/gangbiao1")->wield();
	carry_object("/d/tangmen/obj/qingduan")->wear();
}

void attempt_apprentice(object ob)
{
	if ((int)ob->query_skill("biyun-xinfa", 1) < 70) {
		command("say ������Ȼ�԰���Ϊ����������Ҫ����������"); 
		command("say " + RANK_D->query_respect(ob) + 
			"�Ƿ�Ӧ���ڱ����ķ��϶��µ㹦��");
		return;
	}
	if (ob->query_int() < 24) {
		command("say ��������ע�ص��ӵ���ѧ��Ϊ��");
		command("say ���ɹ���Ҫ���������ã��������������������Զ�⾳�����Բ����ǲ��еġ�");
		command("say " + RANK_D->query_respect(ob) + "�����Ի�����Ǳ�����ڣ�������ذɡ�");
		return;
	}
	command("say ������ѧ�������ú���ϰ�������ŷ�����");
	command("recruit " + ob->query("id"));
}
