
inherit NPC;

void create()
{
        set_name("����", ({ "yan" }) );
        set("race", "Ұ��");
        set("age", 5);
        set("long", "һֻ��ɫ��ë�Ĵ���\n");
        set("max_kee", 1);
        set("limbs", ({ "ͷ��", "����", "β��" }) );
        set("verbs", ({ "bite" }) );

        set_skill("dodge", 80);

        setup();
}

