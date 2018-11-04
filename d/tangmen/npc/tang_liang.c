// tang liang.c ����

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("����", ({ "tang liang", "tang" }));
	set("nickname", HIW "ǧ��ǧ��" NOR);
	set("long", 
		"�������ŵ�һ���֣���˵������ͬʱ����һǧ�ֲ�ͬ������\n"
		"Ҳ����ͬʱ����һǧ�ְ�����\n"
		"����Լ��ʮ���࣬˫�������������С�\n");
	set("gender", "����");
	set("age", 50);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 28);
	set("int", 30);
	set("con", 30);
	set("dex", 32);
	
	set("max_qi", 11000);
	set("max_jing", 31000);
	set("neili", 13000);
	set("max_neili", 13000);
	set("jiali", 100);
	set("combat_exp", 6000000);
	set("score", 100000);

	set_skill("force", 180);
	set_skill("biyun-xinfa",180);
	set_skill("dodge", 120);
	set_skill("qiulinshiye", 120);
	set_skill("strike", 120);
	set_skill("unarmed",100);
	set_skill("biye-wu", 120);
	set_skill("parry", 120);
	set_skill("throwing", 180);
	set_skill("liuxing-biao", 380);
	set_skill("literate", 100);
	set_skill("dusha-zhang", 180);
	set_skill("lansha-shou", 180);
	set_skill("hand", 180);
	set_skill("strike", 180);
	map_skill("force", "biyun-xinfa");
	map_skill("dodge", "qiulinshiye");
	map_skill("strike", "biye-wu");
	map_skill("unarmed","bieye-wu");
	map_skill("parry", "liuxing-biao");
	map_skill("throwing", "liuxing-biao");
	map_skill("strike", "dusha-zhang");
	map_skill("hand", "lansha-shou");
	prepare_skill("strike", "dusha-zhang");
	prepare_skill("hand", "lansha-shou");
	        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 200);
        set_temp("apply/attack", 200);
	create_family("����", 6 ,"����������");
	set("class", "tangmen");

	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "strike.meng" :),
		(: exert_function, "recover" :),
	}) );

	setup();
	carry_object("/d/tangmen/obj/zhuyebiao")->wield();
	carry_object("/d/tangmen/obj/qingduan")->wear();
}

void attempt_apprentice(object ob)
{
	if ((int)ob->query_skill("biyun-xinfa", 1) < 80) {
		command("say ������Ȼ�԰���Ϊ����������Ҫ����������"); 
		command("say " + RANK_D->query_respect(ob) + 
			"�Ƿ�Ӧ���ڱ����ķ��϶��µ㹦��");
		return;
	}
	if (ob->query_int() < 25) {
		command("say ��������ע�ص��ӵ���ѧ��Ϊ��");
		command("say ���ɹ���Ҫ���������ã��������������������Զ�⾳�����Բ����ǲ��еġ�");
		command("say " + RANK_D->query_respect(ob) + "�����Ի�����Ǳ�����ڣ�������ذɡ�");
		return;
	}
	command("say ������ѧ�������ú���ϰ�������ŷ�����");
	command("recruit " + ob->query("id"));
}