
inherit NPC;
#include <ansi.h>
void create()
{
   set_name("��Ԫ��",({ "wu yuanjia","yuanjia"}) );
        set("gender", "����" );
        set("age", 32);
   set("long", "������Ԫ��,���ϴ󽫾���\n");
    set("guard","��������󽫾�");   
   set("combat_exp",800000);
   set("attitude", "peaceful");
   set_skill("unarmed",100);
   set_skill("dodge",100);
   set_skill("parry",100);
   set_skill("force",100);
   set_skill("strike",100);
   set_skill("cuff",100);
    set("max_neili",18500);
    set("neili",18500);
    set("qi",18500);
    set("eff_qi",18500);
    set("max_qi",18500);

    set("jing",8500);
    set("eff_jing",8500);
    set("max_jing",8500);
        set_skill("force", 380+random(180));

        set_skill("unarmed", 380+random(180));
        set_skill("blade", 380+random(180));
        set_skill("parry", 380+random(180));
        set_skill("dodge", 380+random(180));
        set_skill("kuang-blade", 380+random(180));
        map_skill("blade", "kuang-blade");
        map_skill("parry", "kuang-blade");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "blade.leitingpili" :),
                (: perform_action, "blade.kuang" :),

        }) );
	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/damage", 200);
	set_temp("apply/armor", 200);



	set("jiali", 10);
  setup();

     	carry_object(__DIR__"obj/blade")->wield();
	carry_object(__DIR__"obj/gangkui")->wear();
	carry_object(__DIR__"obj/jiazhou")->wear();
}

	
  
void init()
{
	object ob;
	::init();
	if (interactive(ob = this_player()) && 
		(int)ob->query_condition("killer")) {
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob);
	}
}

int accept_fight(object me)
{
	command("say ��ү����������ɱ�ţ��������㵹ù��\n");
//	me->apply_condition("killer", 500);
	kill_ob(me);
	return 1;
}
