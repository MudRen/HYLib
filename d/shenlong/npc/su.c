// su.c ����

#include <ansi.h>
inherit NPC;
//inherit F_UNIQUE;
//inherit F_MASTER;

void create()
{
	set_name("����", ({ "su quan", "su" }));
	set("title",  "����" );
	set("long", "�����������̽����鰲ͨ�ķ��ˡ�\n");
	set("gender", "Ů��");
	set("age", 23);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("str", 35);
	set("int", 30);
	set("con", 30);
	set("dex", 38);
	
	set("max_qi", 4000);
	set("max_jing", 3000);
	set("neili", 4000);
	set("max_neili", 4000);
	set("jiali", 100);
	set("combat_exp", 1500000);
	set("score", 400000);

        set_skill("force", 150);
	set_skill("shenlong-xinfa", 150);
        set_skill("dodge", 180);
	set_skill("yixingbu", 160);
        set_skill("unarmed", 150);
	set_skill("shenlong-quanfa", 150);
        set_skill("parry", 150);
        set_skill("staff", 150);
        set_skill("strike", 180);
	set_skill("shedao-qigong", 120);
	set_skill("literate", 100);
	set_skill("meiren-sanshi", 180);

	map_skill("force", "shenlong-xinfa");
	map_skill("dodge", "yixingbu");
	map_skill("strike", "meiren-sanshi");
	map_skill("unarmed", "shenlong-quanfa");
	map_skill("parry", "meiren-sanshi");
        map_skill("staff", "shedao-qigong");
        set("inquiry", ([
		"������" :  "\nһ�������벻���������̵�(join shenlongjiao).\n",
		"���" :  "\nһ�������벻���������̵�(join shenlongjiao).\n",
		"�ں�" : "\n���겻��!�����ɸ�!��������!������ʥ!\n",
       ]) );
	set("chat_chance_combat", 50);  
	set("chat_msg_combat", ({
		(: command("smile") :),
		(: command("haha") :),
		(: command("chat ƾ����" + RANK_D->query_rude(this_player())+",Ҳ����̫��үͷ�϶���?\n") :),
		(: command("say ���ò��ͷ�����������\n") :),
                (: perform_action, "staff.chang" :),
                (: perform_action, "staff.chang" :),
                (: perform_action, "staff.chang" :),
                (: perform_action, "staff.chang2" :),
                (: perform_action, "staff.chang2" :),
                (: perform_action, "staff.chang2" :),
                (: perform_action, "staff.chang3" :),
                (: perform_action, "staff.chang3" :),
                (: perform_action, "staff.chang3" :),
                (: exert_function, "recover" :),
                (: exert_function, "recover" :),
                      }) );
	setup();
	carry_object("/clone/misc/cloth")->wear();
	add_money("silver", 50);
}

void init()
{
	object ob;

	::init();

	if( interactive(ob = this_player()) && !is_fighting() ) {

		remove_call_out("greeting");
		call_out("greeting", 50, ob);
	}
}

void greeting(object ob)
{
	object obj;
        if (interactive(ob))
        {
	if (obj = present("usedgao", ob))          
	   set("combat_exp",500000);
	   set("qi",10);
	   set("jing",10);
	}
	return;
}

void attempt_apprentice(object ob)
{
    if ((int)ob->query_skill("shenlong-xinfa",1) < 80 ) {
        command("say ��ı����ڹ��ķ�̫����,����ŬŬ�������һ�°�!");
		return;
    }
    if ((int)ob->query_skill("shedao-qigong",1) < 80 ) {
        command("say ��ı����ȷ�̫����,����ŬŬ�������һ�°�!");
		return;
    }
    if ((int)ob->query("shen") > -10000  ) {
        command("say �������������������������������ְ׵�����򽻵�������ذɣ�");
		return;
	}
    command("say �ܺã��ܺá�");
    command("recruit " + ob->query("id"));
}
 
