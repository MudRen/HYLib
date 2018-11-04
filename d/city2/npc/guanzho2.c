// guanzho2.c
#include <ansi.h>
inherit NPC;

void create()
{
	set_name("������", ({ "yi"}) );
	set("gender", "����");
	set("age", 30);
	set("long",
		"��һ��������⣬һ�������ɷ��ģ��������������η��\n");
	set("combat_exp", 10000);
        set("shen_type", -1);
	set("attitude", "friendly");

	set("apply/attack", 20);
	set("apply/defense", 20);


	set_skill("unarmed", 40);
	set_skill("sword", 20);
	set_skill("parry", 40);
	set_skill("dodge", 40);
	setup();

        carry_object("/d/city/obj/duanjian")->wield();
        carry_object("/clone/misc/cloth")->wear();
	add_money("silver", 1);
}

void init()
{

	object me, ob;

	::init();

	ob = this_player();
	me = this_object();
	
	if (interactive(ob) 
	&& !environment(ob)->query("no_fight"))
	{
		if( !ob->query_temp("warned") ) {
			command("say ����ģ������������鲻�ã�С���������㣡");
		}
		else if( ob->query_temp("stay") < 10 ) ob->add_temp("stay", 1);
		else {
			command("say �󵨿�ͽ�������ɣ�\n");
//			me->set_leader(ob);
			remove_call_out("kill_ob");
			call_out("kill_ob", 1, ob); 
		}
	}       
        remove_call_out("leave");
        call_out("leave",30);

}

void leave()
{
        object ob = this_object();
        if (!ob->is_fighting()) {
                message_vision(HIC "�������·�ߵ��Ӳݣ������ˡ�\n" NOR,this_object());
                destruct(this_object());
                }
        else call_out("leave",30);
}

