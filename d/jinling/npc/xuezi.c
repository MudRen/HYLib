// /d/jinling/npc/xuezi.c

inherit NPC;

void create()
{
        set_name("ѧ��", ({ "student" }) );
       set("str", 19);
        set("per", 26);
        set("age", 30);

        set("long",
                "һ����ͨ��ѧ�ӣ��������Ĵ����档\n"
                "����ͣ���ĳ������š�\n");

        set("chat_chance", 3);
        set("chat_msg", ({
                "ѧ��˵��������羰����ѽ��\n",
                "ѧ���߹������߹�ȥ��\n",
                "ѧ��˵������Ի........\n",
        }));
        setup();
        carry_object(__DIR__"obj/silk-cloth")->wear();
       add_money("silver", 80);
}
