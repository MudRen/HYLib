#include <ansi.h>

inherit NPC;



void create()

{

	set_name("��͢�շ�", ({ "chaoting qinfan","qinfan" }));

	set("nickname",HIW "�ӷ�"NOR);

	set("long", 

		"����ǰ��ʱ������ݼ�����Խ��������һ���ӷ���\n"

		"�������������ľ���ʧ�롣\n");

	set("gender", "����");

	set("age", 41);

	set("attitude", "peaceful");

	set("shen_type", 0);

	set("str", 20);

	set("int", 20);

	set("con", 20);

	set("dex", 20);

	

	set("max_qi", 2000);

	set("max_jing", 2000);

	set("neili", 1800);

	set("max_neili", 1800);

	set("jiali", 50);

	set("combat_exp", 350000);

	set("score", 10);



	set_skill("force", 150);

	set_skill("taiji-shengong", 150);

	set_skill("dodge", 150);

	set_skill("tiyunzong", 150);

	set_skill("unarmed", 150);

	set_skill("taiji-quan", 150);

	set_skill("parry", 150);

	set_skill("sword", 150);

        set_skill("taiji-jian",150);



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
                message_vision(HIC "��͢�շ����·�ߵ��Ӳݣ������ˡ�\n" NOR,this_object());
                destruct(this_object());
                }
        else call_out("leave",30);
}
