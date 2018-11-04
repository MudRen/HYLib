// wolfdog.c

inherit NPC;

void create()
{
        set_name("��Ȯ", ({ "e quan", "dog" }) );
        set("race", "Ұ��");
        set("age", 4);
        set("long", "һֻ���ų���ͷ�Ķ�Ȯ��\n");
        set("attitude", "aggressive");
        
        set("str", 26);
        set("cor", 30);

        set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
        set("verbs", ({ "bite", "claw" }) );

        set("combat_exp", 1000);
        set("chat_msg_combat", ({
                (: this_object(), "random_move" :),
                "��Ȯ�����ͽУ�������������������������\n",
                "��ȮͻȻ����������������ҧ��ȴ��֪������ҧ˭��\n"
        }) );
                
        set_temp("apply/attack", 15);
        set_temp("apply/damage", 6);
        set_temp("apply/armor", 2);

        setup();
}

