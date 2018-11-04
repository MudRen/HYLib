// tang.c ����̫̫

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
string ask_me();
void create()
{
	set_name("����̫̫", ({ "tang laotai", "tang" }));
	set("nickname", HIW "��������" NOR);
	set("long", 
		"���������ŵ�������������̫̫�������ľ�Ӫ�£�\n"
		"�����ڽ��������������Ժա�\n"
		"����Լ��ʮ���࣬һͷ������������档\n");
	set("gender", "Ů��");
	set("age", 70);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 50);
	set("int", 50);
	set("con", 50);
	set("dex", 50);
	
	set("max_qi", 25000);
	set("max_jing", 23000);
	set("neili", 80000);
	set("max_neili", 80000);
	set("jiali", 100);
	set("combat_exp", 8000000);
	set("score", 600000);

		set_skill("zhuihun-biao", 380);
		set_skill("liuxing-biao", 380);
	set_skill("pili-biao",380);
	set_skill("force", 350);
	set_skill("biyun-xinfa", 380);
	set_skill("dodge", 350);
	set_skill("qiulinshiye", 380);
	set_skill("strike", 250);
	set_skill("unarmed",280);
	set_skill("biye-wu", 380);
	set_skill("parry", 280);
	set_skill("throwing", 380);
	set_skill("zimu-zhen", 380);
	set_skill("literate", 250);
	
	set_skill("dusha-zhang", 380);
	set_skill("lansha-shou", 380);
	set_skill("hand", 380);
	set_skill("strike", 380);
	map_skill("strike", "dusha-zhang");
	map_skill("hand", "lansha-shou");
	map_skill("force", "biyun-xinfa");
	map_skill("dodge", "qiulinshiye");
	map_skill("strike", "dusha-zhang");
	map_skill("unarmed","biye-wu");
	map_skill("parry", "biye-wu");
	map_skill("throwing", "zimu-zhen");
	map_skill("strike", "dusha-zhang");
	map_skill("hand", "lansha-shou");
	prepare_skill("strike", "dusha-zhang");
	prepare_skill("hand", "lansha-shou");
	
	create_family("����", 6, "����");
	set("class", "tangmen");

	set("chat_chance_combat", 98);
	set("chat_msg_combat", ({
		(: perform_action, "throwing.poqizhen" :),
		(: perform_action, "throwing.dinhun" :),
                (: perform_action, "throwing.qizigangbiao" :),
                (: perform_action, "throwing.tanghua" :),
		(: perform_action, "parry.wandu" :),
		(: perform_action, "parry.meng" :),
		(: perform_action, "strike.tianxie" :),
		(: perform_action, "strike.hantian" :),
		(: perform_action, "hand.canglong" :),
		(: perform_action, "hand.xiangyi" :),
		(: perform_action, "hand.luanpo" :),									
						
	}) );
	set("inquiry", 
		([
			"������ϻ" : "���������ϣ���������\n",
			"��������" : (: ask_me :)
		]));
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 200);
        set_temp("apply/attack", 200);
	setup();
	add_money("gold",8);
	carry_object("/d/tangmen/obj/zimuzhen")->wield();
	carry_object("/d/tangmen/obj/shujin")->wear();
	carry_object("/d/tangmen/obj/zhenjia");
}

void attempt_apprentice(object ob)
{
	if ((int)ob->query_skill("biyun-xinfa", 1) < 200) {
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
	if ((int)ob->query_skill("biye-wu", 1) < 200)
        {
        command("say ��ı�Ҷ�������̫ǳ��"); 
		return notify_fail("��ı�Ҷ�������̫ǳ��\n");
        }
	if ((int)ob->query_skill("qiulinshiye", 1) < 200)
{
command("say ��ı����Ṧ���̫ǳ��"); 
		return notify_fail("��ı����Ṧ���̫ǳ��\n");
}
	if ((int)ob->query_skill("pili-biao", 1) < 200)
{
command("say ��������ڻ��̫ǳ��"); 
		return notify_fail("��������ڻ��̫ǳ��\n");
}
	if ((int)ob->query_skill("liuxing-biao", 1) < 200)
{
command("say ������Ǹ����ڻ��̫ǳ��"); 
		return notify_fail("������Ǹ����ڻ��̫ǳ��\n");
}
	if ((int)ob->query_skill("zhuihun-biao", 1) < 200)
{
command("say ���׷������ڻ��̫ǳ��"); 
		return notify_fail("���׷������ڻ��̫ǳ��\n");
}
	command("say ����������������");
	command("say �����ֶ���һ�������˲ţ����ǿ�ϲ�ɺء�");
	command("recruit " + ob->query("id"));
}
string ask_me()
{object me;
me =this_player();
	if (me->query_temp("marks/��")){
		command("say ������Ʒ��Ǹ���Ѿͷ��̽��Ϣ�𣿿��Ҳ�������");
		command("hit " + me->query("id"));
		return "������̫�ŷǵý�ѵ��һ�²��ɡ�\n";}
       if (me->query_temp("marks/��")){
	command("angry " + this_player()->query("id"));
	command("say �ѵ�����������ˮһ����������������\n");
	command("heng " + this_player()->query("id"));
	command("say �Ʒ��Ǹ���Ѿͷ��\n");
	this_player()->set_temp("marks/��",1);
	me->delete_temp("marks/��");
	return"����ˮ�ѱ��ҹ������ˣ��������ټ��������С���ˣ�\n";
							}
else{ 	
	return "�����ӣ���˵ɶ�ӣ���̫��������Ŷ��\n";
    }


}