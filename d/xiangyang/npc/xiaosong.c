// guidao.c
// by cleansword
// 96-02-16 YZC disabled NPC killing, & "unknown" problem when revealed

#include <ansi.h>

inherit NPC;

string ask_me(object who);

void create()
{
	set_name("���ǹ���", ({ "gong zi", "gong" }) );
	set("title", "�ο�");
	set("gender", "����" );
	set("shen_type", -1);
	set("per", 30);
	set("age", 25);
	set("str", 25);
	set("cor", 25);
	set("cps", 25);
	set("int", 25);
	set("long",
	"���Ǹ�ü��Ŀ������깫�ӣ��������Ƿϣ�һ�����Ѭ�ˣ�������ھ�ɫ�����Կ������ӡ�\n" );

	set("combat_exp", 20000);
	set("attitude", "heroism");
	set("chat_chance_combat", 15);
	set("chat_msg_combat", ({
		"����˵��: �㵱����˱��ӵ��� ? ��֪������˭ ! \n",
		"���Ӻ�Ȼ����һ�����������棬��������;ȴ�ּ�æ���С�\n",
		"����˵��: ���뿪�� ! �Ҳ��ܴ���� !....\n"
	}) );

	set("inquiry", ([
		"������" : "�����ֵ�̩ɽ������˭�˲�ʶ��" ,
	        "���޼�" : "������������һ��Ҫ�����Ľ������Ƥ��",	
                "��Զ��" : "�䵱����֮�ף��������¡�",
                "������" : "�����ϳ�֮�����ڽ�����",
                "������"   : (: ask_me :),
	]) );

	set_skill("sword", 50);
	set_skill("dodge", 40);
	set_skill("unarmed", 50);
	set_skill("parry", 50);
	
	setup();
	carry_object("clone/weapon/changjian")->wield();
	carry_object("clone/misc/cloth")->wear();
}

string ask_me(object who)
{
	int i;
	object *ob;

	if( query("revealed") ) {
		if( is_killing(who) ) return "���Ȼ֪�����ҵ����ܣ��������������\n";
		else {
			kill_ob(who);
			who->fight_ob(this_object());
			return "֪�������ܵ��˶��������������ɣ�\n";
		}
	}

	if( (random(10) < 5) || is_fighting() )
		return "���......\n";

	set_temp("apply/attack",  50);
	set_temp("apply/defense", 50);
	set_temp("apply/damage",  120);


	message("vision",
		HIY "���ǹ�������ͻȻ�ų����ԵĹ�â��ŭ��˵�����㾹�����ܹ�������֣���\n"
		"���ǹ��Ӵ��һ�����е������³���������֮�⣬�����ܹ�����˶���������\n" 
		"������ʹ���������������棬���ͺ�����̫���񽣶˵ķ�ͬС�ɡ�\n" NOR,
		environment(), this_object() );
        set("title","�����ϳ�");
        set_name("������",({ "song", "qingshu" }));
	set("pursuer", 1);
	set("vendetta/authority", 1);
	set("chat_chance", 15);
	set("chat_msg", ({
		(: random_move :)
	}) );
	set("bellicosity", 10000);
	set("combat_exp", 300000);
        set("max_qi",1000);
        set("max_neili",1200);
        set("eff_jingli",1000);  
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.zong" :),
                (: perform_action, "unarmed.zhenup" :),
                (: perform_action, "unarmed.zhan" :),
                (: perform_action, "unarmed.ji" :),
                (: perform_action, "unarmed.jielidali" :),
                (: perform_action, "sword.lian" :),
                (: perform_action, "sword.chan" :),
                (: perform_action, "sword.chanup" :),
                (: perform_action, "sword.sui" :),
                (: perform_action, "sword.lian" :),
                (: perform_action, "sword.lian" :),
                (: perform_action, "sword.lian" :),                
        }) );
	set_skill("force", 150);
	set_skill("taiji-shengong", 200);
	set_skill("dodge", 150);
	set_skill("tiyunzong", 200);
	set_skill("unarmed", 200);
	set_skill("taiji-quan", 200);
	set_skill("parry", 200);
	set_skill("sword", 200);
	set_skill("taiji-jian", 200);
	set_skill("liangyi-jian", 150);
	set_skill("wudang-array", 200);
	set_skill("array",100);
	set_skill("taoism", 200);
	set_skill("literate", 200);
	set_skill("yitian-tulong", 200);
	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("parry", "taiji-jian");
	map_skill("sword", "taiji-jian");

        ob = all_inventory(environment());
	for(i=sizeof(ob)-1; i>=0; i--) {
		if( !userp(ob[i]) ) continue;
                if((int)ob[i]->query("combat_exp",1)<50000) continue;
		kill_ob(ob[i]);
		ob[i]->fight(this_object());
	}
	add_money("gold", 2);
	set("revealed", 1);
	return "���³���������֮�⣬�����ܹ�����˶�������\n";
}
