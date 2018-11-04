// Npc : /u/poq/sdxl/npc/dumang.c ����
// by poq@jyqx 97/7

inherit NPC;

void create()
{
    set_name("����", ({ "du mang", "mang" }) );
    set("race", "Ұ��");
    set("age", 4);
    set("long", "һ����ڴ�ϸ������ͷ������\n");
    set("attitude", "peaceful");

    set("str", 26);
    set("cor", 30);

    set("limbs", ({ "ͷ��", "����", "�ߴ�", "β��" }) );
    set("verbs", ({ "bite" }) );

    set("combat_exp", 10000);

    set_temp("apply/attack", 15);
    set_temp("apply/damage", 6);
    set_temp("apply/armor", 2);

    setup();
}

void die()
{
    object ob,ob1;
    ob = this_object();
    message_vision("$Nȫ��Ť�������ڻ��裬��ͷʼ�����Զ������������ã���춽�ֱ������\n", this_object());
    ob1 = new(__DIR__"dan");
    if (ob1) ob1->move(environment());
    destruct(this_object());
}
