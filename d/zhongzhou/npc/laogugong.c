inherit NPC;

void create()
{
        set_name("�Ϲ͹�", ({ "lao gugong","lao"}) );
        set("gender", "����" );
        set("age", 50);
        set("long", "����������������ˡ�\n");
        set("attitude", "friendly");
        set("combat_exp", 5000);
        set("shen_type", 1);
        set_skill("unarmed", 35);
        set_skill("dodge", 35);
        set_skill("parry", 35);
        set_temp("apply/attack", 15);
        set_temp("apply/defense", 15);
        setup();
        carry_object("/clone/misc/cloth")->wear();
        add_money("silver", 1);
}
