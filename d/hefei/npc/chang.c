inherit NPC;
inherit F_BANKER;

void create()
{
        set_name("���ϰ�", ({"chang laoban", "chang"}));
        set("title", "Ǯׯ�ƹ�");
        set("gender", "����");
        set("age", 34);

        set("str", 22);
        set("int", 24);
        set("dex", 18);
        set("con", 18);

        set("kee", 500); 
        set("max_qi", 500);
        set("gin", 100);
        set("max_jing", 100);
        set("sen",300);
        set("max_jing",300);
        set("combat_exp",300000);
        set("shen_type", 1);
        set("attitude", "peaceful");
        set("env/wimpy", 50);

        set_skill("unarmed", 150);
        set_skill("dodge", 150);
        set_skill("parry", 200);
		set_skill("cuff",120);
		set_skill("force",120);

        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/damage", 240);

        setup();
        carry_object(__DIR__"obj/cloth")->wear();
}

void init()
{
        add_action("do_check", "check");
        add_action("do_check", "chazhang");
        add_action("do_convert", "convert");
        add_action("do_convert", "duihuan");
        add_action("do_deposit", "deposit");
        add_action("do_deposit", "cun");
        add_action("do_withdraw", "withdraw");
        add_action("do_withdraw", "qu");
        delete_temp("busy");
}



