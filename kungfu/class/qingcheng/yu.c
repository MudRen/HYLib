// yu.c

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("��׺�", ({ "yu canghai", "yu", "canghai" }));
	set("gender", "����");
	set("age", 52);
	set("long", "�����ΰ�С�������������أ�ٲȻһ�ɴ���ʦ����\n");
	set("class", "taoist");
	set("combat_exp", 8000000);
	set("class", "taoist");
	set("shen_type", -1);
	set("max_neili", 22500);
	set("neili", 22500);
	set("max_jing", 21500);
	set("max_qi", 22500);
	set("jiali", 250);
	set("apprentice_available", 3);

	set_skill("sword", 200);
	set_skill("dodge", 200);
	set_skill("parry", 200);
	set_skill("strike", 200);
	set_skill("unarmed", 200);
	set_skill("force", 200);
	set_skill("hammer", 150);
	set_skill("throwing", 350);
	set_skill("literate", 100);
//	set_skill("qingzi9da", 150);
	set_skill("qingzi9da", 380);
	set_skill("liuhe-dao", 380);
//	set_skill("chengzi18po", 150);
	set_skill("chengzi18po", 380);
	set_skill("pixie-sword", 180);
	set_skill("songfeng-jian", 380);
	set_skill("chuanhua", 380);
	set_skill("wuying-leg", 380);
	set_skill("cuixin-strike", 380);
	set_skill("qingming-xuangong", 380);
	map_skill("force", "qingming-xuangong");
	map_skill("unarmed", "wuying-leg");
	map_skill("strike", "cuixin-strike");
	map_skill("dodge", "chuanhua");
	map_skill("parry", "songfeng-jian");
	map_skill("sword", "songfeng-jian");
	prepare_skill("unarmed", "wuying-leg");
	prepare_skill("strike", "cuixin-strike");

	set("no_get",1);
	set("chat_chance_combat", 90);
	set("chat_msg_combat", ({		
		(: perform_action, "sword.chan" :),
		(: perform_action, "sword.dieying" :),
		(: perform_action, "strike.cuixin" :),
		(: perform_action, "unarmed.fanti" :),
		(: exert_function, "powerup" :),
		(: exert_function, "regenerate" :),
		(: exert_function, "recover" :),
	}) );
		  set_temp("apply/armor", 200);
		  set_temp("apply/damage", 200);
	set_temp("apply/attack",200);
	set_temp("apply/defense",200);
	create_family("�����", 5, "����");
	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/wudang/obj/bluecloth")->wear();
	carry_object(__DIR__"key");
}

void init()
{
    add_action("do_qiecuo","qiecuo");
}

void attempt_apprentice(object ob)
{
	if( query("apprentice_available") ) {
		if( find_call_out("do_recruit") != -1 )
			command("say ������һ��һ������");
		else
			call_out("do_recruit", 2, ob);
	} else {
		command("say �ϵ������Ѿ������������ӣ���������ͽ�ˡ�");
	}
}

void do_recruit(object ob)
{
	if( (int)ob->query("int") < 20 )
		command("say ��������԰������������ҿ�"+RANK_D->query_respect(ob)+"���ʺ���ѧ������");
	else {
		command("say �ã��ܺá�");
		command("recruit " + ob->query("id") );
	}
}

int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
	add("apprentice_availavble", -1);
}
