// beggar.c

inherit NPC;

void create()
{
        set_name("�Ϻ�", ({ "laohan" }) );
        set("gender", "����" );
        set("age", 53);
        set("long", "һ�����ڷ���������������Ϻ�\n");
        set("combat_exp", 100);
        set("str", 27);
        set("force", 200);
	set("attitude", "friendly");
        set("max_force", 200);
        set("force_factor", 2);
        setup();
        set("chat_chance", 5);
        set("chat_msg", ({
"�Ϻ�ͣ�����������ϵ���������������\n",
                (: random_move :)
        }) );
        set("inquiry", ([
                "���ϰ˽�" : "Ŷ�����Ƕ�ס�ںɻ�����\n",
		"������" : "������������հǳ��ˣ�\n",
		"yue" : "������������հǳ��ˣ�\n",
        ]) );
        carry_object("clone/cloth/cloth")->wear();
}

int accept_object(object me, object obj)
{
        command("smile");
        command("say ��л��λ" + RANK_D->query_respect(me) + 
"����һ�����������Ŀ��ĵģ�");
        return 1;
}
