inherit NPC;

void create()
{
        set_name("�", ({ "qong han","han"}) );
        set("gender", "����" );
        set("age", 33);
        set("long", "һ�������ʵ��ĺ��ӡ�\n");
        set("attitude", "friendly");
        set("combat_exp", 5000);
        set("shen_type", 1);
        set_skill("unarmed", 40);
        set_skill("dodge", 40);
        set_skill("parry", 40);
        set_temp("apply/attack", 20);
        set_temp("apply/defense", 15);
        setup();
        carry_object("/clone/misc/cloth")->wear();
}

