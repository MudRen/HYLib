// yuanwai.c
inherit NPC;

void create()
{
        set_name("��Ա��", ({ "hou yuanwai", "hou" }));
        set("long",
                "��Ա���˵���ⳤ�����ϵ��׸���˭Ҳ��֪���������ж���\n"
                "�Ҳơ�����Լ��ʮ��ͷ�����ĸ���̬̬��\n");
        set("gender", "����");
        set("age", 52);

        set("combat_exp", 1200000);
        set_skill("unarmed", 450);
        set_skill("force", 620);
        set_skill("dodge", 350);
        set_temp("apply/attack", 135);
        set_temp("apply/defense", 142);

        setup();
        carry_object(__DIR__"obj/jinduan")->wear();
        add_money("silver",120);
}

