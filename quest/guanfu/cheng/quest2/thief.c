#include <ansi.h>

inherit NPC;



void create()

{

	set_name("С͵", ({ "thief", "xiao tou","tou" }));

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

	

	set("max_qi", 300);

	set("max_jing", 300);

	set("neili", 500);

	set("max_neili", 500);

	set("jiali", 50);

	set("combat_exp", 70000);

	set("score", 10);



	set_skill("force", 70);

	set_skill("taiji-shengong", 70);

	set_skill("dodge", 70);

	set_skill("tiyunzong", 70);

	set_skill("unarmed", 70);

	set_skill("taiji-quan", 70);

	set_skill("parry", 70);

	set_skill("sword", 70);

        



	map_skill("force", "taiji-shengong");

	map_skill("dodge", "tiyunzong");

	map_skill("unarmed", "taiji-quan");

        map_skill("parry", "taiji-quan");
        set_temp("apply/attack", 20);
        set_temp("apply/defense",50);
        set_temp("apply/armor", 50);
        set_temp("apply/damage", 20);

	set("chat_chance", 5);
	set("chat_msg", ({
		(: random_move :)
	}) );
    



	

	set("chat_chance_combat", 40);

	set("chat_msg_combat", ({

		(: exert_function, "recover" :),

	}) );



	setup();

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
                message_vision(HIC "С͵���·�ߵ��Ӳݣ������ˡ�\n" NOR,this_object());
                destruct(this_object());
                }
        else call_out("leave",30);
}
