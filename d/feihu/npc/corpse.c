// tufeitou.c

inherit NPC;

void create()
{
	set_name("��ʬ", ({ "flash corpse","corpse leader","corpse" }) );
	set("gender", "����");
	set("age", 45+random(10));
   //         set("str",999);
            set("per", 10);
	set("long",
		"��һ������������ˣ�̫�����ˣ�����������η��\n");
	set("combat_exp", 280000+random(900000));

        set("shen_type", -1);
	set("attitude", "aggressive");

         set("force_factor",2+random(100));
         set("max_qi",300+random(5990));
         set("max_jing",300+random(5990));
         set("max_sen",300+random(5990));
        set("max_neili",300+random(5990));
        set("max_mana",300+random(5990));
        set_temp("apply/attack", 100+random(200));
        set_temp("apply/defense", 100+random(200));
        set_temp("apply/armor", 200+random(300));
        set_temp("apply/damage", 100+random(200));

	set("chat_chance", 5);
	set("chat_msg", ({
		"��ʬ�ٺٵعֽ���: ���±���!\n",
	}) );

	set_skill("strike", 180+random(50));
	set_skill("unarmed", 150+random(50));
	set_skill("parry", 150+random(50));
	set_skill("dodge", 150+random(50));

	setup();
//       carry_object("d/city/npc/obj/gangjian")->wield();
       carry_object("/clone/misc/cloth")->wear();
	add_money("coin", 1);
}
