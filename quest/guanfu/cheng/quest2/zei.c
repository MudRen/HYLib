#include <ansi.h>

inherit NPC;



void create()

{

	set_name("�ɻ���", ({ "caihua zei", "zei" }));

	set("nickname",HIW "�ӷ�"NOR);

	set("long", 

		"����ǰ��ʱ������ݼ�����Խ��������һ���ӷ���\n"

		"�������������ľ���ʧ�롣\n");

	set("gender", "����");

	set("age", 21);

	set("attitude", "peaceful");

	set("shen_type", 0);

	set("str", 20);

	set("int", 20);

	set("con", 20);

	set("dex", 20);

	

	set("max_qi", 1000);

	set("max_jing", 1000);

	set("neili", 1000);

	set("max_neili", 1000);

	set("jiali", 50);

	set("combat_exp", 150000);

	set("score", 10);



	set_skill("force", 110);

	set_skill("taiji-shengong", 110);

	set_skill("dodge", 110);

	set_skill("tiyunzong", 110);

	set_skill("unarmed", 110);

	set_skill("taiji-quan", 110);

	set_skill("parry", 110);

	set_skill("sword", 110);

        set_skill("taiji-jian",110);



	map_skill("force", "taiji-shengong");

	map_skill("dodge", "tiyunzong");

	map_skill("unarmed", "taiji-quan");

        map_skill("parry", "taiji-quan");

    	map_skill("sword", "taiji-jian");
        set_temp("apply/attack", 20);
        set_temp("apply/defense",50);
        set_temp("apply/armor", 50);
        set_temp("apply/damage", 20);
	set("chat_chance", 5);
	set("chat_msg", ({
		(: random_move :)
	}) );

    	



	

	set("chat_chance_combat", 70);

	set("chat_msg_combat", ({

		(: perform_action, "sword.sui" :),

		(: exert_function, "recover" :),

		(: random_move :)

	}) );



	setup();

	carry_object("/d/city/obj/changjian")->wield();

   	carry_object("/d/wudang/obj/greyrobe")->wear();



}


void init()
{
        remove_call_out("leave");
        call_out("leave",60);
}

void leave()
{
        object ob = this_object();
        if (!ob->is_fighting()) {
                message_vision(HIC "�ɻ������·�ߵ��Ӳݣ������ˡ�\n" NOR,this_object());
                destruct(this_object());
                }
        else call_out("leave",30);
}
