inherit NPC;

void create()
{
   set_name("���Ϲٱ�",({ "bing" }) );
   set("gender", "����" );
   set("age", 32);
   set("long", "�����������ϳǵĹٱ��������������������ˡ�\n");
       
   set("combat_exp",800000);

   set("attitude", "peaceful");
   
    set("max_neili",8500);
    set("neili",8500);
    set("qi",8500);
    set("eff_qi",8500);
    set("max_qi",8500);

    set("jing",8500);
    set("eff_jing",8500);
    set("max_jing",8500);
        set_skill("force", 180+random(180));

        set_skill("unarmed", 180+random(180));
        set_skill("blade", 180+random(180));
        set_skill("parry", 180+random(180));
        set_skill("dodge", 180+random(180));
        set_skill("kuang-blade", 180+random(180));
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
