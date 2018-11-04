// renwoxing.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
int ask_bijian();

void create()
{
	set_name("������", ({ "ren woxing", "ren","woxing" }));
	set("title", BLU "������̽���"NOR );
	set("long", "ֻ����һ�ų��������ף���ɫѩ�ף����ް��Ѫɫ��üĿ���㣬
������ߣ�һͷ�ڷ���������һϮ������\n");
	set("gender", "����");
	set("class", "scholar");
	set("age", 55);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 30);
	set("per", 27);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	
	set("max_qi", 20000);
	set("max_jing", 20000);
	set("neili", 23000);
	set("max_neili", 23000);
	set("jiali", 100);
	set("combat_exp", 15000000);
	set("score", 500000);

	set("chat_chance_combat", 80);
       set("chat_msg_combat", ({
                (: perform_action, "sword.sanjue" :),
               
       }) );

	set_skill("literate", 100);
	set_skill("force", 300);
	set_skill("dodge", 300);
	set_skill("unarmed", 300);
	set_skill("parry", 300);
	set_skill("sword", 300);
	set_skill("changquan", 300);
	set_skill("hunyuan-yiqi", 380);
	set_skill("lingxu-bu", 380);
	set_skill("damo-jian", 380);
	set_skill("taiji-jian", 380);
	set_skill("huifeng-jian", 380);
	set_skill("taishan-sword", 300);
	set_skill("hengshan-jian", 300);
	set_skill("hengshan-sword", 300);
	set_skill("huashan-sword", 300);
	set_skill("songshan-sword", 380);

	map_skill("dodge", "lingxu-bu");
	map_skill("force", "hunyuan-yiqi");
	map_skill("unarmed", "changquan");
	map_skill("sword", "damo-jian");
	map_skill("parry", "damo-jian");
        set_temp("apply/attack", 500);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 550);
        set("inquiry", ([
                "�Ƚ�" :  (: ask_bijian :),
                "����" :  (: ask_bijian :),
                "��ľ��" : "Ҫ�ú�ľ��Ϸ����ȿ�����Ľ�����\n",
	]) );
 	setup();
	carry_object("/d/wudang/obj/bluecloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();
}

int ask_bijian()
{
	object obj, me = this_player(), ob = this_object();
	message_vision("$N����˵���������������Ұݼ�����ǰ�����������ָ�̡���\n
$nЦ���������ÿ������������Ҽ�į���ɶ�л��������\n", me, ob );
	message_vision("$N���������ҡ���\n
$n���˵�ͷ��˵��������ֻ��������Ľ�����������Ĺ�
�У���˵����Ҳδ����ʤ�����㡣��\n\n", me, ob);
	say(HIR"�����д��һ���������ֽ�������"NOR);
	COMBAT_D->do_attack(ob, me, query_temp("weapon"));
	if( (int)me->query("qi") < 0 || !present(me, environment()))
	{
		say("������̾�˿�����˵��������һ�С���\n");
		return 1;
	}
	command("enable sword taiji-jian");
	say(HIR"�����д��һ�������䵱��������"NOR);
	COMBAT_D->do_attack(ob, me, query_temp("weapon"));
	if( (int)me->query("qi") < 0 || !present(me, environment()))
	{
		say("������̾�˿�����˵�����������С���\n");
		return 1;
	}
	command("enable sword huifeng-jian");
	say(HIR"�����д��һ���������ҽ�������"NOR);
	COMBAT_D->do_attack(ob, me, query_temp("weapon"));
	if( (int)me->query("qi") < 0 || !present(me, environment()))
	{
		say("������̾�˿�����˵�����������С���\n");
		return 1;
	}
	command("enable sword songshan-sword");
	say(HIR"�����д��һ��������ɽ��������"NOR);
	COMBAT_D->do_attack(ob, me, query_temp("weapon"));
	if( (int)me->query("qi") < 0 || !present(me, environment()))
	{
		say("������̾�˿�����˵�����������С���\n");
		return 1;
	}
	command("enable sword taishan-sword");
	say(HIR"�����д��һ������̩ɽ��������"NOR);
	COMBAT_D->do_attack(ob, me, query_temp("weapon"));
	if( (int)me->query("qi") < 0 || !present(me, environment()))
	{
		say("������̾�˿�����˵�����������С���\n");
		return 1;
	}
	command("enable sword huashan-sword");
	say(HIR"�����д��һ��������ɽ��������"NOR);
	COMBAT_D->do_attack(ob, me, query_temp("weapon"));
	if( (int)me->query("qi") < 0 || !present(me, environment()))
	{
		say("������̾�˿�����˵�����������С���\n");
		return 1;
	}
	command("enable sword hengshan-sword");
	say(HIR"�����д��һ��������ɽ��������"NOR);
	COMBAT_D->do_attack(ob, me, query_temp("weapon"));
	if( (int)me->query("qi") < 0 || !present(me, environment()))
	{
		say("������̾�˿�����˵�����������С���\n");
		return 1;
	}
	command("enable sword hengshan-jian");
	say(HIR"�����д��һ��������ɽ��������"NOR);
	COMBAT_D->do_attack(ob, me, query_temp("weapon"));
	if( (int)me->query("qi") < 0 || !present(me, environment()))
	{
		say("������̾�˿�����˵����������û�����С���\n");
		return 1;
	}

	obj = new("/d/heimuya/obj/heimu-ling");
	obj -> move(me);
	say("������˵��������λ" + RANK_D->query_respect(me)+"�����Ҿ�����һ���ľ��ɡ���\n");
	return 1;
}
