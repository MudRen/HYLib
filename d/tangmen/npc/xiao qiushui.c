// xiao qiushui.c ����ˮ

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

string ask_me();
void create()
{
	set_name("����ˮ", ({ "xiao qiushui", "xiao" }));
	set("nickname", HIY "����" NOR);
	set("long", 
		"ԭ�����������Ʒ�����������Ϊ���Ʒ��������ŵ�����ˮ��\n"
		"���ڽ������������壬����Զ�����˳ơ���������\n"
		"����Լ��ʮ���࣬��Ȼ�ܾ���ĥ����Ȼ����һ�������\n");
	set("gender", "����");
	set("age", 20);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 28);
	set("int", 30);
	set("con", 30);
	set("dex", 32);
	
	set("max_qi", 1000);
	set("max_jing", 3000);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 100);
	set("combat_exp", 2000000);
	set("score", 700000);

	set_skill("force", 200);
	set_skill("biyun-xinfa",200);
	set_skill("dodge", 200);
	set_skill("qiulinshiye", 200);
	set_skill("strike", 200);
	set_skill("biye-wu", 200);
	set_skill("parry", 200);
	set_skill("sword", 200);
	set_skill("wuzhan-mei", 300);
	set_skill("literate", 200);

	map_skill("force", "biyun-xinfa");
	map_skill("dodge", "qiulinshiye");
	map_skill("strike", "biye-wu");
	map_skill("parry", "wuzhan-mei");
	map_skill("sword", "wuzhan-mei");
	create_family("����", 7, "����");
	set("class", "tangmen");
	
	
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "sword.lian" :),
		(: perform_action, "sword.wumei" :),
		(: perform_action, "strike.meng" :),
		(: exert_function, "recover" :),
	}) );
	set("inquiry", 
		([
			"�Ʒ�" : (: ask_me :)
		]));
	set("yu_count", 1);

	setup();
	carry_object("/d/tangmen/obj/cloth")->wear();
}
void attempt_apprentice(object ob)
{
	if ((int)ob->query_skill("biyun-xinfa", 1) < 100) {
		command("say ������Ȼ�԰���Ϊ����������Ҫ����������"); 
		command("say " + RANK_D->query_respect(ob) + 
			"�Ƿ�Ӧ���ڱ����ķ��϶��µ㹦��");
		return;
	}
	if (ob->query_int() < 30) {
		command("say ��������ע�ص��ӵ���ѧ��Ϊ��");
		command("say ���ɹ���Ҫ���������ã��������������������Զ�⾳�����Բ����ǲ��еġ�");
		command("say " + RANK_D->query_respect(ob) + "�����Ի�����Ǳ�����ڣ�������ذɡ�");
		return;
	}
	command("say �����Ʒ�������ϣ����������ˡ�");
	command("recruit " + ob->query("id"));
}
string ask_me()
{object ob;
 object me;
 me=this_player();
	if (query("yu_count") < 1){return "���Ʒ����������ҵģ���ϧ�ҵ������Ѿ����������ˡ�\n";}
	command("touch " + this_player()->query("id"));
	command("say ���Ʒ����������ҵģ�\n");
	command("sigh" );
	command("say �Դӵ��մ�������֮���Ҿͺ��Ʒ���������ˡ�\n");
	ob=new("/d/tangmen/obj/yupei");
        ob->move(this_player());
	message_vision("$N����$nһ�����塣\n", me, ob);
	add("yu_count", -1);
	return"���������彻���Ʒ��ɡ�\n";
	

							

}
