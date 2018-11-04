// bing.c �ٱ�

inherit NPC;

void create()
{
        set_name("�ٱ�", ({ "guan bing", "bing" }));
        set("age", 22+random(10));
        set("gender", "����");
        set("long", "��Ȼ�ٱ������ղ��ܺ�������ʿ��ȣ��������ǽ��������˶�������\n");
        set("attitude", "peaceful");

        set("str", 24);
        set("dex", 16);
        set("combat_exp", 815000+random(20000));
        set("shen_type", 1);

        set_skill("unarmed", 340);
        set_skill("dodge", 340);
        set_skill("parry", 340);
        set_skill("blade", 340);
        set_skill("force", 340);
        set_temp("apply/attack", 140);
        set_temp("apply/defense", 140);
        set_temp("apply/damage", 120);
        set_temp("apply/armor", 140);

        set("chat_chance_combat", 2);
        set("chat_msg_combat", ({
                "�ٱ��ȵ����󵨵��񣬾����췴���ɣ�\n",
                "�ٱ��ȵ����ܵ��˺����ܲ������㻹�ǿ�����־��ܣ�\n",
        }));
        setup();
	carry_object("/d/city/npc/obj/gangdao")->wield();
	carry_object("/d/city/npc/obj/junfu")->wear();
	carry_object("/d/city/npc/obj/jitui")->wear();

}

void init()
{
        object ob;
        ::init();
        if (interactive(ob = this_player()) && living(this_object()) &&
                (int)ob->query_condition("killer")) {
                remove_call_out("kill_ob");
                call_out("kill_ob", 0, ob);
        }
}

int accept_fight(object me)
{
        command("say ��ү����������ɱ�ţ��������㵹ù��\n");
        if (!is_killing(me->query("id")))
                me->add_condition("killer", 15);
        kill_ob(me);
        return 1;
}
