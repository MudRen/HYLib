// su.c ����

#include <ansi.h>
inherit NPC;
inherit F_UNIQUE;
inherit F_MASTER;

void create()
{
	set_name("����", ({ "su quan", "su" }));
	set("title",  HIY"������"NOR"����" );
	set("long", "�����������̽����鰲ͨ�ķ��ˡ�\n");
	set("gender", "Ů��");
        set("per",30);
	set("age", 23);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("str", 35);
	set("int", 30);
	set("con", 30);
	set("dex", 38);
	
	set("max_qi", 5000);
	set("max_jing", 5000);
	set("neili", 8000);
	set("max_neili", 5000);
//	set("jiali", 100);
	set("combat_exp", 1500000);
	set("score", 2400000);
        set_skill("claw", 100);
        set_skill("strike", 100);
	set_skill("dulong-shenzhua", 200);
	set_skill("xuanming-zhang", 200);
        set_skill("force", 150);
	set_skill("shenlong-xinfa", 150);
        set_skill("dodge", 150);
	set_skill("yixingbu", 200);
        set_skill("hand", 200);
	set_skill("shenlong-bashi", 200);
        set_skill("strike", 200);
	set_skill("huagu-mianzhang", 200);
        set_skill("parry", 150);
        set_skill("staff", 150);
        set_skill("sword", 150);
        set_skill("zhaosheshu", 150);
        set_skill("yangsheshu", 150);
	set_skill("shedao-qigong", 200);
	set_skill("literate", 190);

	
	map_skill("force", "shenlong-xinfa");
	map_skill("dodge", "yixingbu");
	map_skill("hand", "juehu-shou");
	map_skill("strike", "huagu-mianzhang");
	map_skill("parry", "juehu-shou");
        map_skill("staff", "shedao-qigong");
	prepare_skill("strike", "huagu-mianzhang");
	prepare_skill("hand", "shenlong-bashi");
	prepare_skill("hand", "juehu-shou");

	create_family("������",1,"��������");

        set("inquiry", ([
		"������" :  "\nһ�������벻���������̵�(join shenlongjiao).\n",
		"���" :  "\nһ�������벻���������̵�(join shenlongjiao).\n",
		"�ں�" : "\n���겻��!�����ɸ�!��������!������ʥ!\n",
       ]) );
	set("chat_chance_combat", 50);  
	set("chat_msg_combat", ({
		(: command("smile") :),
                (: perform_action, "staff.chang" :),
                (: perform_action, "staff.chang2" :),
                (: perform_action, "staff.chang3" :),
                (: perform_action, "parry.luanhuan" :),
                (: perform_action, "parry.luanhuan" :),
                (: perform_action, "parry.juehu" :),
                (: perform_action, "parry.juehu" :),                
                (: perform_action, "parry.juehu	" :),                
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
 
