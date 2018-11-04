// tang fang.c �Ʒ�

#include <ansi.h>

string ask_me();
inherit NPC;
inherit F_MASTER;
inherit F_DEALER;
inherit F_UNIQUE;
void create()
{
	set_name("�Ʒ�", ({ "tang fang", "tang" }));
	set("long", 
		"�����ݲ԰ף������㲣����������ӷ·𻹴���\n"
		"��ۡ�\n"
		"����Լ��ʮ���ࡣ\n");
	set("gender", "Ů��");
	set("age", 20);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 20);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	
	set("max_qi", 1800);
	set("max_jing", 12000);
	set("neili", 11000);
	set("max_neili", 11000);
	set("jiali", 60);
	set("combat_exp", 1900000);
	set("score", 80000);

	set_skill("force", 100);
	set_skill("biyun-xinfa", 100);
	set_skill("dodge", 100);
	set_skill("qiulinshiye", 200);
	set_skill("strike", 80);
	set_skill("unarmed",80);
	set_skill("biye-wu", 80);
	set_skill("parry", 100);
	set_skill("throwing", 100);
	set_skill("sword",100);
	set_skill("wuzhan-mei", 100);
	set_skill("zhuihun-biao",320);
	set_skill("literate", 100);
	set_temp("apply/attack", 30);
	set_temp("apply/defense", 30);
	set_temp("apply/damage", 30);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 200);
        set_temp("apply/attack", 200);
	map_skill("force", "biyun-xinfa");
	map_skill("dodge", "qiulinshiye");
	map_skill("strike", "biye-wu");
	map_skill("unarmed","biye-wu");
	map_skill("parry", "wuzhan-mei");
	map_skill("sword", "wuzhan-mei");
	map_skill("throwing","zhuihun-biao");
	
	create_family("����", 7, "����");
	set("class", "tangmen");

	
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: command("unwield changjian") :),
		(: command("unwield changjian") :),
		(: command("unwield changjian") :),
		(: command("unwield changjian") :),
		(: command("unwield changjian") :),
		(: command("unwield changjian") :),
		(: command("unwield changjian") :),
		(: command("unwield changjian") :),
		(: command("wield changjian") :),
		(: command("wield changjian") :),
		(: command("wield changjian") :),
		(: command("wield changjian") :),
		(: command("wield biao") :),
		(: command("wield biao") :),
		(: command("wield biao") :),
		(: command("wield biao") :),
                (: perform_action, "sword.lian" :),
		(: perform_action, "sword.wumei" :),
		(: perform_action, "strike.meng" :),
		(: exert_function, "recover" :),
		(: command("unwield biao") :),
		(: command("unwield biao") :),
		(: command("unwield biao") :),
		(: command("unwield biao") :),
		(: command("wield changjian") :),
		(: command("wield changjian") :),
		(: command("wield changjian") :),
		(: command("wield changjian") :),
		(: command("unwield changjian") :),
		(: command("unwield changjian") :),
		(: command("unwield changjian") :),
		(: command("unwield changjian") :),
		(: command("unwield changjian") :),
		(: command("unwield changjian") :),
        }) );
	set("chat_chance", 10);
	set("chat_msg", ({
		"�Ʒ�����̾���������ᰴס���ң�����ÿ���Զ���ĺ��档\n",
		"�Ʒ��������ĵز�Ū�˼������ң������������Ҳ��֪������������������....��\n",
		"�Ʒ����ᴵ��һ�����������̴�㣬�������Ỻ��������ա� \n",
	}) );
	set("inquiry", 
		([
			"����" : (: ask_me :)
		]));


	setup();
	carry_object("/d/tangmen/obj/gangbiao1")->wield();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/tangmen/obj/shuxiu")->wear();
}

void attempt_apprentice(object ob)
{
	if ((int)ob->query_skill("biyun-xinfa", 1) < 100) {
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
	command("say �ðɣ��Ҿ��������...");
	command("recruit " + ob->query("id"));
}
string ask_me()
{object me;
me=this_player();
	if (me->query_temp("marks/��")){return "���˰ɣ�������Ҳ��֪�����ɵ���Ϣ�����߰ɡ�\n";}
	command("ah " + this_player()->query("id"));
	command("say ��֪�������𣡣��Դ����ϴδ������ź��ʧȥ����Ϣ��\n");
	command("sigh");
	this_player()->set_temp("marks/��",1);
	return "��̫̫Ϊ���·ǳ���������Ҳ�����Ҽ����ˡ�\n";
	   

}
	
int accept_object(object who, object ob)
{
	object book;
	book = new("/d/tangmen/obj/throwbook");
        if ((string)ob->query("name")=="����") {
              if(!query("yl_trigger")) {
		say(
"�Ʒ�˵�����ⲻ�����ɵ�������̫лл���ˣ���Ȼû�м������ɣ�\n"
"�ܼ�����������,���Ѿ�����ο�ˡ�\n"
"�Ʒ����Ƶ�̾��һ������������һ�������ܾ��������Ǹ���ĳ�л�ɡ�\n"
"�Ʒ���" + book->query("name") + "������" + who->query("name") + "��\n");
		book->move(who);
                set("yl_trigger", 1);
              }
           else say("�Ʒ���ĿԲ����˵�������������ô�������ᰡ��\n");
        call_out("destroy", 1, ob);
	return 1;
	}
		return 0;
}
void destroy(object ob)
{
        destruct(ob);
        return;
}