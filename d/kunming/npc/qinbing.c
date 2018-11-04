// qingbing.c

inherit NPC;

void create()
{
	set_name("�����ױ�", ({ "qin bing", "bing" }));
	set("age", 32);
	set("gender", "����");
	set("long", "һ������ְ�ص��ױ��������ע���Ź������ˡ�\n");
	set("attitude", "peaceful");
	set("str", 24);
	set("dex", 23);

	set("shen_type", 1);

	set("combat_exp", 810000);
	set("shen_type", 1);

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
        set_skill("kuang-blade", 280+random(180));
        map_skill("blade", "kuang-blade");
        map_skill("parry", "kuang-blade");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "blade.leitingpili" :),
                (: perform_action, "blade.kuang" :),

        }) );
	set_temp("apply/attack", 60);
	set_temp("apply/defense", 60);
	set_temp("apply/damage", 60);
	set_temp("apply/armor", 60);


	setup();
	carry_object(__DIR__"obj/changjian")->wield();
	carry_object(__DIR__"obj/armor")->wear();
}


